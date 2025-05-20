//Code Llama-13B DATASET v1.0 Category: Huffman Coding Implementation ; Style: sophisticated
/* Huffman Coding Implementation Example Program */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Data Structures */
struct node {
    int value;
    int weight;
    struct node* left;
    struct node* right;
};

struct node* create_node(int value, int weight) {
    struct node* new_node = malloc(sizeof(struct node));
    new_node->value = value;
    new_node->weight = weight;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void free_node(struct node* node) {
    if (node == NULL) return;
    free_node(node->left);
    free_node(node->right);
    free(node);
}

void print_huffman_code(struct node* root, char* code) {
    if (root == NULL) return;
    if (root->value != 0) {
        printf("Value: %d, Weight: %d, Code: %s\n", root->value, root->weight, code);
    }
    char left_code[100], right_code[100];
    strcpy(left_code, code);
    strcpy(right_code, code);
    left_code[strlen(code)] = '0';
    right_code[strlen(code)] = '1';
    print_huffman_code(root->left, left_code);
    print_huffman_code(root->right, right_code);
}

struct node* build_huffman_tree(int* values, int size) {
    /* Build a min heap of all values */
    struct node* min_heap[size];
    for (int i = 0; i < size; i++) {
        min_heap[i] = create_node(values[i], values[i]);
    }
    /* While the heap has more than one element */
    while (size > 1) {
        /* Find the two nodes with minimum weight */
        struct node* node1 = min_heap[0];
        struct node* node2 = min_heap[1];
        for (int i = 2; i < size; i++) {
            if (min_heap[i]->weight < node1->weight) {
                node1 = min_heap[i];
            } else if (min_heap[i]->weight < node2->weight) {
                node2 = min_heap[i];
            }
        }
        /* Create a new node with the two nodes as children */
        struct node* new_node = create_node(0, node1->weight + node2->weight);
        new_node->left = node1;
        new_node->right = node2;
        /* Add the new node to the heap */
        min_heap[0] = new_node;
        /* Heapify the heap */
        for (int i = 1; i < size; i++) {
            if (min_heap[i]->weight < min_heap[0]->weight) {
                struct node* temp = min_heap[i];
                min_heap[i] = min_heap[0];
                min_heap[0] = temp;
            }
        }
        size--;
    }
    return min_heap[0];
}

int main() {
    /* Example values */
    int values[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(values) / sizeof(values[0]);
    /* Build a Huffman tree from the values */
    struct node* root = build_huffman_tree(values, size);
    /* Print the Huffman code */
    char code[100];
    strcpy(code, "");
    print_huffman_code(root, code);
    /* Free the memory */
    free_node(root);
    return 0;
}