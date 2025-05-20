//FormAI DATASET v1.0 Category: Data structures visualization ; Style: romantic
#include<stdio.h>
#include<stdlib.h>

typedef struct _node {
  int data;
  struct _node* left;
  struct _node* right;
} node;

void insert_knight(node** p, int x);
void print_knight(node* p, int level);
void delete_knight(node** p, int x);

int main() {
  node* root = NULL;
  int choice, val;
  do {
    printf("\n1. Add a number to the knight's squad\n2. Remove a number from the knight's squad\n3. Visualize the knight's squad\n4. Quit\nEnter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        printf("\nEnter a number to add to the knight's squad: ");
        scanf("%d", &val);
        insert_knight(&root, val);
        break;
      case 2:
        printf("\nEnter a number to remove from the knight's squad: ");
        scanf("%d", &val);
        delete_knight(&root, val);
        break;
      case 3:
        printf("\nThe knight's squad: \n");
        print_knight(root, 0);
        break;
      case 4:
        printf("\nFarewell my love, until we meet again!");
        break;
      default:
        printf("\nThat is not a valid option, my dearest. Please try again.\n");
        break;
    }
  } while (choice != 4);
  return 0;
}

void insert_knight(node** p, int x) {
  if (*p == NULL) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = x;
    new_node->left = NULL;
    new_node->right = NULL;
    *p = new_node;
  }
  else if (x < (*p)->data) {
    insert_knight(&((*p)->left), x);
  }
  else if (x > (*p)->data) {
    insert_knight(&((*p)->right), x);
  }
  else {
    printf("\nThe knight's squad already contains the number you are trying to add, my love.");
  }
}

void print_knight(node* p, int level) {
  if (p == NULL) {
    return;
  }
  else {
    print_knight(p->right, level + 1);
    printf("\n");
    for (int i = 0; i < level; i++) {
      printf("    ");
    }
    printf("%d", p->data);
    print_knight(p->left, level + 1);
  }
}

void delete_knight(node** p, int x) {
  if (*p == NULL) {
    printf("\nThe knight's squad does not contain the number you are trying to remove, my dear.");
  }
  else if (x < (*p)->data) {
    delete_knight(&((*p)->left), x);
  }
  else if (x > (*p)->data) {
    delete_knight(&((*p)->right), x);
  }
  else {
    node* temp;
    if ((*p)->left == NULL) {
      temp = *p;
      *p = (*p)->right;
      free(temp);
    }
    else if ((*p)->right == NULL) {
      temp = *p;
      *p = (*p)->left;
      free(temp);
    }
    else {
      temp = (*p)->right;
      while (temp->left != NULL) {
        temp = temp->left;
      }
      (*p)->data = temp->data;
      delete_knight(&((*p)->right), temp->data);
    }
  }
}