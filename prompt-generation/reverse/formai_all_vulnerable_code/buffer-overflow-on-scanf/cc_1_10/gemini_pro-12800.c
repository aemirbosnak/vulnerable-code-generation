//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: mind-bending
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct Node {
  int data;
  struct Node *left;
  struct Node *right;
} Node;

Node *create_node(int data) {
  Node *node = malloc(sizeof(Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

Node *insert_node(Node *root, int data) {
  if (root == NULL) {
    return create_node(data);
  } else if (data < root->data) {
    root->left = insert_node(root->left, data);
  } else {
    root->right = insert_node(root->right, data);
  }
  return root;
}

void print_inorder(Node *root) {
  if (root == NULL) {
    return;
  }
  print_inorder(root->left);
  printf("%d ", root->data);
  print_inorder(root->right);
}

void print_preorder(Node *root) {
  if (root == NULL) {
    return;
  }
  printf("%d ", root->data);
  print_preorder(root->left);
  print_preorder(root->right);
}

void print_postorder(Node *root) {
  if (root == NULL) {
    return;
  }
  print_postorder(root->left);
  print_postorder(root->right);
  printf("%d ", root->data);
}

Node *search_node(Node *root, int data) {
  if (root == NULL) {
    return NULL;
  }
  if (root->data == data) {
    return root;
  } else if (data < root->data) {
    return search_node(root->left, data);
  } else {
    return search_node(root->right, data);
  }
}

Node *find_min_node(Node *root) {
  if (root == NULL) {
    return NULL;
  }
  while (root->left != NULL) {
    root = root->left;
  }
  return root;
}

Node *find_max_node(Node *root) {
  if (root == NULL) {
    return NULL;
  }
  while (root->right != NULL) {
    root = root->right;
  }
  return root;
}

Node *delete_node(Node *root, int data) {
  if (root == NULL) {
    return NULL;
  }
  if (data < root->data) {
    root->left = delete_node(root->left, data);
  } else if (data > root->data) {
    root->right = delete_node(root->right, data);
  } else {
    if (root->left == NULL) {
      Node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      Node *temp = root->left;
      free(root);
      return temp;
    } else {
      Node *temp = find_min_node(root->right);
      root->data = temp->data;
      root->right = delete_node(root->right, temp->data);
    }
  }
  return root;
}

int main() {
  Node *root = NULL;
  int n;
  printf("Enter the number of elements to insert: ");
  scanf("%d", &n);
  printf("Enter the elements to insert: ");
  for (int i = 0; i < n; i++) {
    int data;
    scanf("%d", &data);
    root = insert_node(root, data);
  }
  printf("Inorder traversal: ");
  print_inorder(root);
  printf("\nPreorder traversal: ");
  print_preorder(root);
  printf("\nPostorder traversal: ");
  print_postorder(root);
  int search_data;
  printf("\nEnter the element to search: ");
  scanf("%d", &search_data);
  Node *found_node = search_node(root, search_data);
  if (found_node == NULL) {
    printf("Element not found\n");
  } else {
    printf("Element found: %d\n", found_node->data);
  }
  int min_data;
  printf("\nEnter the minimum element to find: ");
  scanf("%d", &min_data);
  Node *min_node = find_min_node(root);
  if (min_node == NULL) {
    printf("Minimum element not found\n");
  } else {
    printf("Minimum element: %d\n", min_node->data);
  }
  int max_data;
  printf("\nEnter the maximum element to find: ");
  scanf("%d", &max_data);
  Node *max_node = find_max_node(root);
  if (max_node == NULL) {
    printf("Maximum element not found\n");
  } else {
    printf("Maximum element: %d\n", max_node->data);
  }
  int delete_data;
  printf("\nEnter the element to delete: ");
  scanf("%d", &delete_data);
  root = delete_node(root, delete_data);
  printf("Inorder traversal after deletion: ");
  print_inorder(root);
  return 0;
}