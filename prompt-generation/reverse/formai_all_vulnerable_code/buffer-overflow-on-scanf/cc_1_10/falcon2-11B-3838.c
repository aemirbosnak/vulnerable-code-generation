//Falcon2-11B DATASET v1.0 Category: Huffman Coding Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct node {
    int freq;
    char c;
    struct node *left;
    struct node *right;
} node;

node* create_node(int freq, char c) {
    node* new_node = (node*) malloc(sizeof(node));
    new_node->freq = freq;
    new_node->c = c;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void print_tree(node* root) {
    if (root == NULL) {
        return;
    }

    printf("%c", root->c);
    print_tree(root->left);
    print_tree(root->right);
}

int main() {
    node* root = NULL;

    // Build the Huffman tree
    int freqs[MAX_SIZE] = {0};
    int frequencies[MAX_SIZE] = {0};
    char chars[MAX_SIZE] = {0};
    int count = 0;

    while (scanf("%c", &chars[count]) == 1) {
        freqs[count] = 1;
        frequencies[count] = 1;
        count++;
    }

    for (int i = 0; i < count; i++) {
        if (frequencies[i] > 0) {
            node* new_node = create_node(frequencies[i], chars[i]);
            new_node->left = NULL;
            new_node->right = NULL;

            if (root == NULL) {
                root = new_node;
            } else {
                node* current = root;
                while (current!= NULL && frequencies[i] < frequencies[current->freq]) {
                    current = current->left;
                }

                if (current == NULL) {
                    current->right = new_node;
                } else {
                    current->left = new_node;
                }
            }
        }
    }

    // In-order traversal to encode the text
    int encoded_chars[MAX_SIZE] = {0};
    int encoded_length = 0;
    node* current = root;

    while (current!= NULL) {
        if (current->left == NULL) {
            encoded_chars[encoded_length++] = current->c;
            current = current->right;
        } else {
            current = current->left;
        }
    }

    // Print the encoded text
    printf("Encoded text: ");
    for (int i = 0; i < encoded_length; i++) {
        printf("%c", encoded_chars[i]);
    }
    printf("\n");

    // Print the Huffman tree
    printf("Huffman tree:\n");
    print_tree(root);

    return 0;
}