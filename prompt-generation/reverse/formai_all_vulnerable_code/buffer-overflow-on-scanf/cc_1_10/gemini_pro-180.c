//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct node {
  int frequency;
  char character;
  struct node *left;
  struct node *right;
} node;

node *create_node(int frequency, char character) {
  node *new_node = (node *)malloc(sizeof(node));
  new_node->frequency = frequency;
  new_node->character = character;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

node *insert_node(node *root, node *new_node) {
  if (root == NULL) {
    root = new_node;
  } else if (new_node->frequency < root->frequency) {
    root->left = insert_node(root->left, new_node);
  } else {
    root->right = insert_node(root->right, new_node);
  }
  return root;
}

void print_tree(node *root, int depth) {
  if (root == NULL) {
    return;
  }
  for (int i = 0; i < depth; i++) {
    printf(" ");
  }
  printf("%d %c\n", root->frequency, root->character);
  print_tree(root->left, depth + 1);
  print_tree(root->right, depth + 1);
}

node *build_tree(char *string) {
  int frequencies[256] = {0};
  for (int i = 0; i < strlen(string); i++) {
    frequencies[string[i]]++;
  }

  node *root = NULL;
  for (int i = 0; i < 256; i++) {
    if (frequencies[i] > 0) {
      node *new_node = create_node(frequencies[i], i);
      root = insert_node(root, new_node);
    }
  }

  return root;
}

void encode(node *root, char *string, char *encoded_string, int index) {
  if (root == NULL) {
    return;
  }
  if (root->left == NULL && root->right == NULL) {
    encoded_string[index] = '\0';
    return;
  }
  if (root->left != NULL) {
    encoded_string[index] = '0';
    encode(root->left, string, encoded_string, index + 1);
  }
  if (root->right != NULL) {
    encoded_string[index] = '1';
    encode(root->right, string, encoded_string, index + 1);
  }
}

void decode(node *root, char *encoded_string, int index) {
  if (root == NULL) {
    return;
  }
  if (root->left == NULL && root->right == NULL) {
    printf("%c", root->character);
    return;
  }
  if (encoded_string[index] == '0') {
    decode(root->left, encoded_string, index + 1);
  }
  if (encoded_string[index] == '1') {
    decode(root->right, encoded_string, index + 1);
  }
}

int main() {
  char string[1000];
  printf("Enter a string: ");
  scanf("%s", string);

  node *root = build_tree(string);

  char encoded_string[1000];
  encode(root, string, encoded_string, 0);
  printf("Encoded string: %s\n", encoded_string);

  decode(root, encoded_string, 0);
  printf("\nDecoded string: %s\n", string);

  return 0;
}