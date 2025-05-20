//MISTRAL-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHAR 256
#define BUF_SIZE 1024

struct node {
    char ch;
    unsigned char freq;
    struct node *left, *right;
};

typedef struct node node;
node *root = NULL;

void huffman_encode(node *node, char *str, char code) {
    if (!node) return;

    if (!node->left && !node->right) {
        if (node->ch >= ' ' && node->ch <= '~')
            putchar(node->ch);
        putchar(code);
        return;
    }

    huffman_encode(node->left, str, code << 1);
    huffman_encode(node->right, str, code << 1 | 1);
}

void decode_huffman(node *node, int *buf, int *index) {
    if (!node) return;

    if (!node->left && !node->right) {
        putchar(node->ch);
        return;
    }

    int bit = *index % 8;
    *index += bit > 0 ? bit + 1 : bit;

    decode_huffman(node->left, buf, index);
    decode_huffman(node->right, buf, index);
}

void build_tree(char *input, int len) {
    node **heap, *temp;
    int i, freq[MAX_CHAR];

    for (i = 0; i < MAX_CHAR; i++)
        freq[i] = 0;

    for (i = 0; i < len; i++)
        freq[(unsigned char)input[i]]++;

    heap = (node **)calloc(MAX_CHAR, sizeof(node *));

    for (i = 0; i < MAX_CHAR; i++) {
        if (!heap[i]) heap[i] = (node *)calloc(1, sizeof(node));
        heap[i]->ch = i;
        heap[i]->freq = freq[i];
        heap[i]->left = heap[i]->right = NULL;
    }

    for (i = 0; i < len; i++) {
        node *n1 = heap[input[i]];
        node *n2 = root;
        while (1) {
            if (!n2) {
                root = n1;
                break;
            }
            if (n1->freq < n2->freq) {
                temp = n1;
                n1 = n2;
                n2 = temp;
            }
            if (!n2->right) {
                n2->right = n1;
                n1->left = n2;
                break;
            } else
                n2 = n2->right;
        }
    }

    free(heap);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <input file>\n", argv[0]);
        return 1;
    }

    FILE *fp_in = fopen(argv[1], "rb");
    if (!fp_in) {
        perror("Error opening file");
        return 1;
    }

    fseek(fp_in, 0, SEEK_END);
    int input_len = ftell(fp_in);
    rewind(fp_in);

    char *input = (char *)calloc(input_len + 1, sizeof(char));
    fread(input, 1, input_len, fp_in);

    build_tree(input, input_len);

    int buf[BUF_SIZE / 8];
    int index = 0;

    puts("Huffman Tree:");
    huffman_encode(root, NULL, 0);
    puts("\nEncoded sequence:");

    for (int i = 0; i < input_len; i++)
        huffman_encode(root, (char *)buf, index), putchar(input[i]);

    printf("\nDecoded sequence:\n");
    node *decoded_root = root;

    for (int i = 0; i < input_len * 8 + 8; i += 8) {
        decode_huffman(decoded_root, buf, &index);
        if (decoded_root->ch >= ' ' && decoded_root->ch <= '~')
            putchar(decoded_root->ch);
        decoded_root = decoded_root->left ? decoded_root->left : decoded_root->right;
    }

    free(input);
    free(root);
    fclose(fp_in);
    return 0;
}