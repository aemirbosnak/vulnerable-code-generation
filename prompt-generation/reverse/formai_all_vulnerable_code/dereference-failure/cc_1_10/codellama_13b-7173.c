//Code Llama-13B DATASET v1.0 Category: Huffman Coding Implementation ; Style: scientific
/* Huffman Coding Implementation Example Program */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for each node in the Huffman tree
struct huffman_node {
  char data;
  int freq;
  struct huffman_node *left;
  struct huffman_node *right;
};

// Define a function to create a new Huffman tree node
struct huffman_node *new_node(char data, int freq) {
  struct huffman_node *node = malloc(sizeof(struct huffman_node));
  node->data = data;
  node->freq = freq;
  node->left = NULL;
  node->right = NULL;
  return node;
}

// Define a function to build the Huffman tree
void build_tree(struct huffman_node *root) {
  struct huffman_node *node1, *node2;
  while (root->left != NULL) {
    node1 = root->left;
    node2 = root->right;
    if (node1->freq < node2->freq) {
      root->left = node2;
      root->right = node1;
    }
    root = root->left;
  }
}

// Define a function to print the Huffman code
void print_code(struct huffman_node *root) {
  if (root == NULL) {
    return;
  }
  if (root->left == NULL) {
    printf("%c ", root->data);
    return;
  }
  printf("(");
  print_code(root->left);
  print_code(root->right);
  printf(")");
}

// Define a function to compress a string using Huffman coding
void compress_string(char *str) {
  struct huffman_node *root = new_node(0, 0);
  int i;
  for (i = 0; i < strlen(str); i++) {
    root->freq++;
  }
  build_tree(root);
  print_code(root);
  printf("\n");
  free(root);
}

int main() {
  char str[] = "hello world";
  compress_string(str);
  return 0;
}