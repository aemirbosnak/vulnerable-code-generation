//Code Llama-13B DATASET v1.0 Category: Huffman Coding Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 256

typedef struct node {
  char value;
  int weight;
  struct node *left;
  struct node *right;
} node_t;

node_t* build_tree(int weights[], int n) {
  node_t *root = NULL;
  for (int i = 0; i < n; i++) {
    node_t *node = malloc(sizeof(node_t));
    node->value = weights[i];
    node->weight = weights[i];
    node->left = NULL;
    node->right = NULL;
    if (root == NULL) {
      root = node;
    } else {
      node_t *curr = root;
      while (curr != NULL) {
        if (node->weight < curr->weight) {
          if (curr->left == NULL) {
            curr->left = node;
            break;
          } else {
            curr = curr->left;
          }
        } else {
          if (curr->right == NULL) {
            curr->right = node;
            break;
          } else {
            curr = curr->right;
          }
        }
      }
    }
  }
  return root;
}

void encode(node_t *root, char *input, char *output) {
  int i = 0;
  while (input[i] != '\0') {
    node_t *curr = root;
    while (curr->left != NULL || curr->right != NULL) {
      if (curr->left != NULL && curr->left->value == input[i]) {
        curr = curr->left;
      } else if (curr->right != NULL && curr->right->value == input[i]) {
        curr = curr->right;
      } else {
        break;
      }
    }
    if (curr->value == input[i]) {
      output[i] = '0';
    } else {
      output[i] = '1';
    }
    i++;
  }
  output[i] = '\0';
}

int main() {
  int weights[MAX_CHARS];
  char input[MAX_CHARS];
  char output[MAX_CHARS];
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &weights[i]);
  }
  scanf("%s", input);
  node_t *root = build_tree(weights, n);
  encode(root, input, output);
  printf("%s\n", output);
  return 0;
}