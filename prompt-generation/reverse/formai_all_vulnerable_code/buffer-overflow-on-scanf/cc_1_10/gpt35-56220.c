//FormAI DATASET v1.0 Category: Binary search trees ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *create_node(int value) {
  struct node *new_node = (struct node*)malloc(sizeof(struct node));
  new_node->data=value;
  new_node->left=NULL;
  new_node->right=NULL;
  return new_node;
}

struct node *insert_node(struct node *root, int value) {
  if(root==NULL) {
    root=create_node(value);
  } else if(value<root->data) {
    root->left=insert_node(root->left, value);
  } else if(value>root->data) {
    root->right=insert_node(root->right, value);
  }
  return root;
}

void inorder_traversal(struct node *root) {
  if(root) {
    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
  }
}

void preorder_traversal(struct node *root) {
  if(root) {
    printf("%d ", root->data);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
  }
}

void postorder_traversal(struct node *root) {
  if(root) {
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%d ", root->data);
  }
}

int search_node(struct node *root, int value) {
  if(root==NULL || root->data==value) {
    return 1;
  } else if(value<root->data) {
    return search_node(root->left, value);
  } else {
    return search_node(root->right, value);
  }
}

int main() {
  struct node *root=NULL;
  int value, choice;
  do {
    printf("\nArtistic Binary Search Tree Program\n");
    printf("-------------------------\n");
    printf("1. Insert Node\n");
    printf("2. Inorder Traversal\n");
    printf("3. Preorder Traversal\n");
    printf("4. Postorder Traversal\n");
    printf("5. Search Node\n");
    printf("6. Exit\n");
    printf("-------------------------\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
      case 1:
        printf("\nEnter the value you want to insert: ");
        scanf("%d", &value);
        root=insert_node(root, value);
        break;
      case 2:
        printf("\nInorder Traversal: ");
        inorder_traversal(root);
        printf("\n");
        break;
      case 3:
        printf("\nPreorder Traversal: ");
        preorder_traversal(root);
        printf("\n");
        break;
      case 4:
        printf("\nPostorder Traversal: ");
        postorder_traversal(root);
        printf("\n");
        break;
      case 5:
        printf("\nEnter the value you want to search: ");
        scanf("%d", &value);
        if(search_node(root, value)==1) {
          printf("The value %d is present in the tree.\n", value);
        } else {
          printf("The value %d is not present in the tree.\n", value);
        }
        break;
      case 6:
        printf("\nExiting program.\n");
        exit(0);
        break;
      default:
        printf("\nInvalid choice.\n");
        break;
    }
  } while(choice!=6);
}