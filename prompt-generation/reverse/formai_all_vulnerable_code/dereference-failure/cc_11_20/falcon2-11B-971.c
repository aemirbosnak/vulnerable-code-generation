//Falcon2-11B DATASET v1.0 Category: Huffman Coding Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variables
int debug = 0;
int num_bits = 0;
int num_symbols = 0;

// Function prototypes
void usage(char *program);
int calc_freq(char *str);
void huffman_encode(char *str);
void huffman_decode(char *str);

// Main function
int main(int argc, char **argv) {
    if (argc!= 2) {
        usage(argv[0]);
        exit(1);
    }

    char *str = argv[1];
    int len = strlen(str);

    if (debug) {
        printf("Original string: %s\n", str);
        printf("Length of string: %d\n", len);
    }

    int freq[256] = {0};
    for (int i = 0; i < len; i++) {
        freq[str[i]]++;
    }

    int *freq_arr = malloc(sizeof(int) * num_symbols);
    int i = 0;
    for (int j = 0; j < 256; j++) {
        if (freq[j] > 0) {
            freq_arr[i++] = j;
            freq[j] = 0;
        }
    }

    if (debug) {
        printf("Freq array:\n");
        for (int j = 0; j < num_symbols; j++) {
            printf("%d: %d\n", freq_arr[j], freq[freq_arr[j]]);
        }
    }

    if (debug) {
        printf("Creating Huffman tree...\n");
    }

    int *heap = malloc(sizeof(int) * num_symbols);
    for (int j = 0; j < num_symbols; j++) {
        heap[j] = freq[freq_arr[j]];
    }

    int heap_size = num_symbols;
    for (int j = num_symbols / 2 - 1; j >= 0; j--) {
        if (2 * j + 1 < heap_size) {
            int child1 = 2 * j + 1;
            if (child1 < heap_size && heap[child1] < heap[child1 + 1]) {
                child1++;
            }

            if (child1 < heap_size) {
                int child2 = child1 + 1;
                if (child2 < heap_size && heap[child2] < heap[child1]) {
                    child2++;
                }

                int parent = child1 < heap_size? child1 : child2;

                int tmp = heap[child1];
                heap[child1] = heap[parent];
                heap[parent] = tmp;

                heap_size--;
            }
        }
    }

    if (debug) {
        printf("Heap: ");
        for (int j = 0; j < heap_size; j++) {
            printf("%d ", heap[j]);
        }
        printf("\n");
    }

    if (debug) {
        printf("Building Huffman tree...\n");
    }

    char *huffman_tree = malloc(sizeof(char) * heap_size);
    for (int j = 0; j < heap_size; j++) {
        huffman_tree[j] = '0';
    }

    int idx = 0;
    for (int j = heap_size - 1; j >= 0; j--) {
        huffman_tree[j] = '0';
        huffman_tree[idx] = '1';
        idx++;
    }

    huffman_tree[idx++] = '0';

    if (debug) {
        printf("Huffman tree:\n");
        for (int j = 0; j < heap_size; j++) {
            printf("%c", huffman_tree[j]);
        }
        printf("\n");
    }

    if (debug) {
        printf("Creating Huffman codes...\n");
    }

    for (int j = 0; j < len; j++) {
        int symbol = str[j];
        int bit_pos = 0;
        for (int i = 0; i < heap_size; i++) {
            if (huffman_tree[i] == symbol) {
                int bit = heap[i];
                bit_pos = (bit_pos << 1) + bit;
            }
        }

        int num_bits_used = num_bits;
        num_bits_used += bit_pos;
        num_bits += bit_pos;

        if (debug) {
            printf("Bit position: %d\n", bit_pos);
        }

        if (debug) {
            printf("Number of bits used: %d\n", num_bits_used);
        }
    }

    if (debug) {
        printf("Huffman codes:\n");
        for (int j = 0; j < num_symbols; j++) {
            printf("%d: ", freq_arr[j]);
            for (int i = 0; i < heap_size; i++) {
                if (huffman_tree[i] == freq_arr[j]) {
                    printf("%d", heap[i]);
                }
            }
            printf("\n");
        }
    }

    if (debug) {
        printf("Encode the string...\n");
    }

    char *encoded_str = malloc(sizeof(char) * (len + num_bits));
    int pos = 0;
    for (int j = 0; j < len; j++) {
        int symbol = str[j];
        int bit_pos = 0;
        for (int i = 0; i < heap_size; i++) {
            if (huffman_tree[i] == symbol) {
                int bit = heap[i];
                bit_pos = (bit_pos << 1) + bit;
            }
        }

        int num_bits_used = num_bits;
        num_bits_used += bit_pos;
        num_bits += bit_pos;

        if (debug) {
            printf("Bit position: %d\n", bit_pos);
        }

        if (debug) {
            printf("Number of bits used: %d\n", num_bits_used);
        }

        for (int i = 0; i < num_bits_used; i++) {
            encoded_str[pos++] = '0';
        }
    }

    if (debug) {
        printf("Decode the string...\n");
    }

    char *decoded_str = malloc(sizeof(char) * (len + num_bits));
    int decoded_str_pos = 0;
    for (int j = 0; j < len + num_bits; j++) {
        int bit_pos = 0;
        for (int i = 0; i < heap_size; i++) {
            if (encoded_str[j] == '1') {
                int bit = heap[i];
                bit_pos = (bit_pos << 1) + bit;
            }
        }

        int num_bits_used = num_bits;
        num_bits_used += bit_pos;
        num_bits += bit_pos;

        if (debug) {
            printf("Bit position: %d\n", bit_pos);
        }

        if (debug) {
            printf("Number of bits used: %d\n", num_bits_used);
        }

        for (int i = 0; i < num_bits_used; i++) {
            decoded_str[decoded_str_pos++] = '0';
        }
    }

    if (debug) {
        printf("Original string: %s\n", str);
        printf("Encoded string: %s\n", encoded_str);
        printf("Decoded string: %s\n", decoded_str);
    }

    free(encoded_str);
    free(decoded_str);
    free(heap);
    free(huffman_tree);
    free(freq_arr);
    free(str);

    return 0;
}

// Usage function
void usage(char *program) {
    fprintf(stderr, "Usage: %s <string>\n", program);
    exit(1);
}

// Calculate frequency of symbols in a string
int calc_freq(char *str) {
    int freq[256] = {0};
    for (int i = 0; i < strlen(str); i++) {
        freq[str[i]]++;
    }

    return freq[0];
}

// Huffman encode a string
void huffman_encode(char *str) {
    // Code for Huffman encoding
}

// Huffman decode a string
void huffman_decode(char *str) {
    // Code for Huffman decoding
}