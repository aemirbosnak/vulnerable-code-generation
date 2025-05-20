//Code Llama-13B DATASET v1.0 Category: Huffman Coding Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 256
#define MAX_TREE_HEIGHT 10

typedef struct Node {
  char value;
  int weight;
  struct Node *left;
  struct Node *right;
} Node;

Node* build_tree(int weights[], int size) {
  Node* nodes[MAX_CHARS];
  Node* tree[MAX_TREE_HEIGHT];

  // Initialize the nodes
  for (int i = 0; i < size; i++) {
    nodes[i] = malloc(sizeof(Node));
    nodes[i]->value = i;
    nodes[i]->weight = weights[i];
    nodes[i]->left = NULL;
    nodes[i]->right = NULL;
  }

  // Build the tree
  for (int i = 0; i < size; i++) {
    Node* node = nodes[i];
    if (node->weight == 0) {
      continue;
    }

    int j = i + 1;
    while (j < size && weights[j] == 0) {
      j++;
    }

    if (j < size) {
      Node* other = nodes[j];
      node->weight += other->weight;
      node->left = other;
      node->right = NULL;
      other->left = NULL;
      other->right = NULL;
    }
  }

  return nodes[0];
}

void huffman_encode(Node* root, char* text, char* encoded) {
  int i = 0;
  int j = 0;

  while (text[i] != '\0') {
    Node* node = root;
    while (node->left != NULL) {
      if (text[i] == node->value) {
        node = node->left;
      } else {
        node = node->right;
      }
    }

    if (node->value == text[i]) {
      encoded[j] = '1';
    } else {
      encoded[j] = '0';
    }

    i++;
    j++;
  }

  encoded[j] = '\0';
}

int main() {
  char text[] = "This is an example of Huffman coding";
  int weights[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  Node* root = build_tree(weights, sizeof(weights) / sizeof(int));

  char encoded[1024];
  huffman_encode(root, text, encoded);

  printf("Encoded text: %s\n", encoded);

  return 0;
}