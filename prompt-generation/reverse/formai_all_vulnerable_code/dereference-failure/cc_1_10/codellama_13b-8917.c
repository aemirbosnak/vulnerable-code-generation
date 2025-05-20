//Code Llama-13B DATASET v1.0 Category: Huffman Coding Implementation ; Style: synchronous
#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    struct huffman_node {
        char c;
        int freq;
        struct huffman_node *left;
        struct huffman_node *right;
    };

    struct huffman_node *create_node(char c, int freq) {
        struct huffman_node *node = (struct huffman_node *)malloc(sizeof(struct huffman_node));
        node->c = c;
        node->freq = freq;
        node->left = NULL;
        node->right = NULL;
        return node;
    }

    struct huffman_node *build_huffman_tree(char *data, int len) {
        int i;
        struct huffman_node *nodes[256];
        for (i = 0; i < 256; i++) {
            nodes[i] = create_node(i, 0);
        }

        for (i = 0; i < len; i++) {
            nodes[data[i]]->freq++;
        }

        while (1) {
            int i, j, min_freq = 256;
            for (i = 0; i < 256; i++) {
                if (nodes[i]->freq > 0 && nodes[i]->freq < min_freq) {
                    min_freq = nodes[i]->freq;
                    j = i;
                }
            }
            if (min_freq == 256) {
                break;
            }
            nodes[j]->freq = -1;
        }

        return nodes[0];
    }

    void huffman_encode(struct huffman_node *root, char *data, int len) {
        int i;
        for (i = 0; i < len; i++) {
            struct huffman_node *node = root;
            while (node->left != NULL || node->right != NULL) {
                if (node->left != NULL && node->right != NULL) {
                    if (node->left->freq < node->right->freq) {
                        node = node->left;
                    } else {
                        node = node->right;
                    }
                } else if (node->left != NULL) {
                    node = node->left;
                } else {
                    node = node->right;
                }
            }
            node->c = data[i];
        }
    }

    int main() {
        char data[] = "this is an example for huffman coding";
        int len = strlen(data);
        struct huffman_node *root = build_huffman_tree(data, len);
        huffman_encode(root, data, len);
        printf("%s\n", data);
        return 0;
    }