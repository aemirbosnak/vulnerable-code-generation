//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: Alan Turing
#include <stdio.h>

struct node {
  int key;
  struct node *left, *right;
};

struct node* new_node(int data) {
  struct node* temp = (struct node*)malloc(sizeof(struct node));
  temp->key = data;
  temp->left = temp->right = NULL;
  return temp;
}

int find(struct node* root, int key) {
  if (root == NULL)
    return -1;
  if (key == root->key)
    return 1;
  if (key < root->key)
    return find(root->left, key);
  else
    return find(root->right, key);
}

void insert(struct node* root, int key) {
  if (root == NULL)
    root = new_node(key);
  else if (key < root->key)
    insert(root->left, key);
  else
    insert(root->right, key);
}

void inorder(struct node* root) {
  if (root!= NULL) {
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
  }
}

int main() {
  struct node* root = NULL;
  int key, choice;
  
  printf("Binary Search Tree\n");
  printf("1. Insertion\n");
  printf("2. Inorder traversal\n");
  printf("3. Exit\n");
  
  while(1) {
    printf("Enter choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
      case 1:
        printf("Enter key: ");
        scanf("%d", &key);
        insert(root, key);
        break;
      case 2:
        if (root == NULL) {
          printf("Empty tree\n");
        } else {
          inorder(root);
        }
        break;
      case 3:
        return 0;
      default:
        printf("Invalid choice\n");
    }
  }
}