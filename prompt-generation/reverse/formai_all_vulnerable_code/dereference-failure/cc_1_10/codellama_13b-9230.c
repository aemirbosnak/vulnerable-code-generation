//Code Llama-13B DATASET v1.0 Category: Huffman Coding Implementation ; Style: Linus Torvalds
// Linus Torvalds Huffman Coding Implementation
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 256

// Huffman Tree Node
typedef struct node {
  unsigned char c;
  int freq;
  struct node *left, *right;
} Node;

// Create a new node
Node* new_node(unsigned char c, int freq, Node *left, Node *right) {
  Node *node = malloc(sizeof(Node));
  node->c = c;
  node->freq = freq;
  node->left = left;
  node->right = right;
  return node;
}

// Create a new tree
Node* create_tree(unsigned char *chars, int freqs[], int n) {
  Node *root = NULL;
  while (n > 1) {
    int min1 = -1, min2 = -1;
    for (int i = 0; i < n; i++) {
      if (freqs[i] > 0 && (min1 == -1 || freqs[i] < freqs[min1])) {
        min1 = i;
      }
    }
    for (int i = 0; i < n; i++) {
      if (freqs[i] > 0 && i != min1 && (min2 == -1 || freqs[i] < freqs[min2])) {
        min2 = i;
      }
    }
    if (min1 == -1 || min2 == -1) {
      break;
    }
    freqs[min1] = freqs[min2] = 0;
    Node *node = new_node(chars[min1], freqs[min1] + freqs[min2], root, root);
    root = node;
    n--;
  }
  return root;
}

// Encode a string
void encode(Node *root, unsigned char *str, int n) {
  int i = 0;
  while (i < n) {
    Node *node = root;
    while (node->left || node->right) {
      if (node->left && str[i] < node->left->c) {
        node = node->left;
      } else if (node->right && str[i] >= node->right->c) {
        node = node->right;
      } else {
        break;
      }
    }
    printf("%c", node->c);
    i++;
  }
}

// Decode a string
void decode(Node *root, unsigned char *str, int n) {
  int i = 0;
  while (i < n) {
    Node *node = root;
    while (node->left || node->right) {
      if (node->left && str[i] < node->left->c) {
        node = node->left;
      } else if (node->right && str[i] >= node->right->c) {
        node = node->right;
      } else {
        break;
      }
    }
    printf("%c", node->c);
    i++;
  }
}

int main() {
  // Test string
  unsigned char *str = "Hello, World!";
  int n = strlen(str);

  // Calculate frequencies
  int freqs[MAX_CHARS] = {0};
  for (int i = 0; i < n; i++) {
    freqs[str[i]]++;
  }

  // Create a Huffman tree
  Node *root = create_tree(str, freqs, n);

  // Encode the string
  encode(root, str, n);

  // Decode the encoded string
  decode(root, str, n);

  return 0;
}