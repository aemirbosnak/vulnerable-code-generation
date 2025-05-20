//Code Llama-13B DATASET v1.0 Category: Data structures visualization ; Style: grateful
/*
 * Unique C Data Structures Visualization Example Program in a Grateful Style
 *
 * This program uses a combination of linked lists and binary trees to
 * visualize different data structures.
 */

#include <stdio.h>
#include <stdlib.h>

// Linked List Structure
struct node {
  int data;
  struct node *next;
};

// Binary Tree Structure
struct tree {
  int data;
  struct tree *left;
  struct tree *right;
};

// Linked List Functions
void print_list(struct node *head) {
  struct node *curr = head;
  while (curr != NULL) {
    printf("%d ", curr->data);
    curr = curr->next;
  }
  printf("\n");
}

void add_list(struct node **head, int data) {
  struct node *new_node = malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = *head;
  *head = new_node;
}

void remove_list(struct node **head, int data) {
  struct node *curr = *head;
  struct node *prev = NULL;
  while (curr != NULL && curr->data != data) {
    prev = curr;
    curr = curr->next;
  }
  if (curr != NULL) {
    if (prev == NULL) {
      *head = curr->next;
    } else {
      prev->next = curr->next;
    }
    free(curr);
  }
}

// Binary Tree Functions
void print_tree(struct tree *root) {
  if (root == NULL) {
    printf("Empty tree\n");
    return;
  }
  printf("%d ", root->data);
  print_tree(root->left);
  print_tree(root->right);
}

void add_tree(struct tree **root, int data) {
  if (*root == NULL) {
    *root = malloc(sizeof(struct tree));
    (*root)->data = data;
    (*root)->left = NULL;
    (*root)->right = NULL;
  } else {
    struct tree *curr = *root;
    while (curr != NULL) {
      if (data < curr->data) {
        if (curr->left == NULL) {
          curr->left = malloc(sizeof(struct tree));
          curr->left->data = data;
          curr->left->left = NULL;
          curr->left->right = NULL;
          break;
        } else {
          curr = curr->left;
        }
      } else {
        if (curr->right == NULL) {
          curr->right = malloc(sizeof(struct tree));
          curr->right->data = data;
          curr->right->left = NULL;
          curr->right->right = NULL;
          break;
        } else {
          curr = curr->right;
        }
      }
    }
  }
}

void remove_tree(struct tree **root, int data) {
  if (*root == NULL) {
    return;
  }
  if ((*root)->data == data) {
    struct tree *temp = *root;
    if ((*root)->left == NULL && (*root)->right == NULL) {
      *root = NULL;
    } else if ((*root)->left != NULL) {
      *root = (*root)->left;
    } else {
      *root = (*root)->right;
    }
    free(temp);
  } else {
    remove_tree(&((*root)->left), data);
    remove_tree(&((*root)->right), data);
  }
}

int main() {
  struct node *head = NULL;
  struct tree *root = NULL;

  // Linked List Operations
  add_list(&head, 1);
  add_list(&head, 2);
  add_list(&head, 3);
  print_list(head);
  remove_list(&head, 2);
  print_list(head);

  // Binary Tree Operations
  add_tree(&root, 1);
  add_tree(&root, 2);
  add_tree(&root, 3);
  print_tree(root);
  remove_tree(&root, 2);
  print_tree(root);

  return 0;
}