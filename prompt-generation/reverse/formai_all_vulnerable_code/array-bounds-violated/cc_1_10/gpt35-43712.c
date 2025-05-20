//FormAI DATASET v1.0 Category: Compression algorithms ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This program demonstrates a compression algorithm based on the entropy coding
 * principles developed by Claude Shannon. The algorithm uses a variation of
 * Huffman coding to generate a variable-length code for a set of symbols based
 * on their statistical frequency of occurrence. The compressed data is stored
 * in a binary file format, consisting of the code for each symbol followed by
 * the compressed data bitstream.
 */

typedef struct huff_node huff_node_t;

struct huff_node {
    int symbol;
    int frequency;
    huff_node_t *left;
    huff_node_t *right;
};

huff_node_t *huff_tree_from_freq(int *freq)
{
    int i, j;
    huff_node_t *node, *left, *right;
    int min1_freq, min2_freq;
    int min1_index, min2_index;
    int num_symbols = 256;

    huff_node_t *heap[num_symbols];
    int heap_size = 0;

    /* Initialize the heap with leaf nodes for each non-zero symbol frequency. */
    for (i = 0; i < num_symbols; i++) {
        if (freq[i] > 0) {
            node = malloc(sizeof(huff_node_t));
            node->symbol = i;
            node->frequency = freq[i];
            node->left = NULL;
            node->right = NULL;

            heap[heap_size] = node;
            heap_size++;
        }
    }

    /* If there is only one symbol then return the root of the tree. */
    if (heap_size == 1) {
        return heap[0];
    }

    /* Build the Huffman codeword tree. */
    for (i = 0; i < heap_size - 1; i++) {
        /* Find the two minimum frequency nodes in the heap. */
        min1_freq = heap[0]->frequency;
        min1_index = 0;
        min2_freq = heap[1]->frequency;
        min2_index = 1;

        if (min2_freq < min1_freq) {
            /* Swap min1 and min2. */
            min1_freq = heap[1]->frequency;
            min1_index = 1;
            min2_freq = heap[0]->frequency;
            min2_index = 0;
        }

        for (j = 2; j < heap_size - i; j++) {
            if (heap[j]->frequency < min1_freq) {
                /* Shift min1 to min2 and set min1 to the new node. */
                min2_freq = min1_freq;
                min2_index = min1_index;
                min1_freq = heap[j]->frequency;
                min1_index = j;
            } else if (heap[j]->frequency < min2_freq) {
                /* Set min2 to the new node. */
                min2_freq = heap[j]->frequency;
                min2_index = j;
            }
        }

        /* Combine the two minimum frequency nodes into a new parent node. */
        left = heap[min1_index];
        right = heap[min2_index];
        node = malloc(sizeof(huff_node_t));
        node->symbol = -1;
        node->frequency = left->frequency + right->frequency;
        node->left = left;
        node->right = right;

        /* Remove the two children nodes and add the parent node to the heap. */
        heap[min1_index] = node;
        heap[min2_index] = heap[heap_size - i - 1];
        heap[heap_size - i - 1] = NULL;
        heap_size--;
    }

    /* Return the root of the Huffman codeword tree. */
    return node;
}

void huff_tree_free(huff_node_t *node)
{
    if (node->left != NULL) {
        huff_tree_free(node->left);
    }

    if (node->right != NULL) {
        huff_tree_free(node->right);
    }

    free(node);
}

void huff_tree_write(huff_node_t *node, FILE *out_file, unsigned int *bit_buffer, int *bit_count)
{
    if (node->symbol >= 0) {
        /* Write the symbol codeword. */
        fwrite(&node->symbol, sizeof(char), 1, out_file);
    } else {
        /* Recusively traverse the Huffman codeword tree. */
        huff_tree_write(node->left, out_file, bit_buffer, bit_count);
        huff_tree_write(node->right, out_file, bit_buffer, bit_count);
    }
}

void huff_compress(FILE *in_file, FILE *out_file)
{
    int freq[256] = {0};
    int c;
    int i, j;
    unsigned int bit_buffer = 0;
    int bit_count = 0;

    /* Count the frequency of occurrence of each symbol. */
    while ((c = fgetc(in_file)) != EOF) {
        freq[c]++;
    }

    /* Generate the Huffman codeword tree. */
    huff_node_t *root = huff_tree_from_freq(freq);

    /* Write the Huffman codeword tree to the output file. */
    huff_tree_write(root, out_file, &bit_buffer, &bit_count);

    /* Write the symbol codewords to the output file. */
    rewind(in_file);
    while ((c = fgetc(in_file)) != EOF) {
        huff_node_t *node = root;
        while (node->symbol == -1) {
            if (c & (1 << (7 - bit_count))) {
                node = node->right;
            } else {
                node = node->left;
            }

            bit_count++;
            if (bit_count == 32) {
                /* Write the bit buffer to the output file. */
                fwrite(&bit_buffer, sizeof(unsigned int), 1, out_file);
                bit_buffer = 0;
                bit_count = 0;
            }
        }

        /* Write the symbol codeword. */
        bit_buffer |= node->symbol << (32 - bit_count - 8);
        bit_count += 8;
        if (bit_count == 32) {
            /* Write the bit buffer to the output file. */
            fwrite(&bit_buffer, sizeof(unsigned int), 1, out_file);
            bit_buffer = 0;
            bit_count = 0;
        }
    }

    /* Write the final bit buffer to the output file. */
    if (bit_count > 0) {
        fwrite(&bit_buffer, sizeof(unsigned int), 1, out_file);
    }

    /* Free the Huffman codeword tree. */
    huff_tree_free(root);
}

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    FILE *in_file = fopen(argv[1], "rb");
    if (in_file == NULL) {
        printf("Error: Could not open input file '%s'\n", argv[1]);
        exit(2);
    }

    FILE *out_file = fopen(argv[2], "wb");
    if (out_file == NULL) {
        printf("Error: Could not open output file '%s'\n", argv[2]);
        exit(3);
    }

    huff_compress(in_file, out_file);

    fclose(in_file);
    fclose(out_file);

    return 0;
}