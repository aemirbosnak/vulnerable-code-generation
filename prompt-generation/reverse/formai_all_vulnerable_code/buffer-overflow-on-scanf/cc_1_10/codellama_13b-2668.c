//Code Llama-13B DATASET v1.0 Category: Intrusion detection system ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define THRESHOLD 5

struct Node {
  char value[MAX_LENGTH];
  struct Node* left;
  struct Node* right;
};

void add(struct Node* root, char* value) {
  if (root == NULL) {
    root = malloc(sizeof(struct Node));
    strcpy(root->value, value);
    root->left = NULL;
    root->right = NULL;
  } else if (strcmp(value, root->value) < 0) {
    add(root->left, value);
  } else if (strcmp(value, root->value) > 0) {
    add(root->right, value);
  }
}

void print(struct Node* root) {
  if (root != NULL) {
    print(root->left);
    printf("%s\n", root->value);
    print(root->right);
  }
}

int count(struct Node* root) {
  if (root == NULL) {
    return 0;
  }
  int leftCount = count(root->left);
  int rightCount = count(root->right);
  return leftCount + rightCount + 1;
}

int main() {
  struct Node* root = NULL;
  char value[MAX_LENGTH];

  while (1) {
    scanf("%s", value);
    if (strcmp(value, "end") == 0) {
      break;
    }
    add(root, value);
  }

  print(root);
  printf("Count: %d\n", count(root));

  return 0;
}