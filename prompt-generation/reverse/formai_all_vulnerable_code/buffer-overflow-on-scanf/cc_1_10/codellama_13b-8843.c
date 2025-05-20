//Code Llama-13B DATASET v1.0 Category: Binary search trees ; Style: retro
// Binary search tree example program in a retro style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  char *key;
  struct node *left;
  struct node *right;
} node_t;

node_t *create_node(char *key) {
  node_t *node = malloc(sizeof(node_t));
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  return node;
}

node_t *insert(node_t *root, char *key) {
  if (root == NULL) {
    return create_node(key);
  }
  if (strcmp(key, root->key) < 0) {
    root->left = insert(root->left, key);
  } else {
    root->right = insert(root->right, key);
  }
  return root;
}

node_t *search(node_t *root, char *key) {
  if (root == NULL) {
    return NULL;
  }
  if (strcmp(key, root->key) == 0) {
    return root;
  } else if (strcmp(key, root->key) < 0) {
    return search(root->left, key);
  } else {
    return search(root->right, key);
  }
}

node_t *min_value_node(node_t *node) {
  node_t *current = node;
  while (current->left != NULL) {
    current = current->left;
  }
  return current;
}

node_t *delete(node_t *root, char *key) {
  if (root == NULL) {
    return root;
  }
  if (strcmp(key, root->key) < 0) {
    root->left = delete(root->left, key);
  } else if (strcmp(key, root->key) > 0) {
    root->right = delete(root->right, key);
  } else {
    if (root->left == NULL) {
      node_t *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      node_t *temp = root->left;
      free(root);
      return temp;
    }
    node_t *temp = min_value_node(root->right);
    root->key = temp->key;
    root->right = delete(root->right, temp->key);
  }
  return root;
}

int main() {
  node_t *root = NULL;
  root = insert(root, "C");
  root = insert(root, "C++");
  root = insert(root, "Java");
  root = insert(root, "Python");
  root = insert(root, "JavaScript");
  root = insert(root, "PHP");
  root = insert(root, "Ruby");
  root = insert(root, "Swift");
  root = insert(root, "Go");

  printf("Search for key: ");
  char key[10];
  scanf("%s", key);
  node_t *result = search(root, key);
  if (result != NULL) {
    printf("Found key: %s\n", result->key);
  } else {
    printf("Key not found\n");
  }

  printf("Delete key: ");
  scanf("%s", key);
  delete(root, key);

  printf("Search for key: ");
  scanf("%s", key);
  result = search(root, key);
  if (result != NULL) {
    printf("Found key: %s\n", result->key);
  } else {
    printf("Key not found\n");
  }

  return 0;
}