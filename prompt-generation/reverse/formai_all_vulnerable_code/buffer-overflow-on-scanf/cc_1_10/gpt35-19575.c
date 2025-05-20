//FormAI DATASET v1.0 Category: Binary search trees ; Style: complex
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left, *right;
};

struct node *createNode(int value){
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(struct node **root, int value){
    if(*root == NULL){
        *root = createNode(value);
    }
    else{
        if(value < (*root)->data){
            insert(&((*root)->left), value);
        }
        else{
            insert(&((*root)->right), value);
        }
    }
}

void inorder(struct node *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

struct node *search(struct node *root, int value){
    if(root == NULL || root->data == value){
        return root;
    }
    else if(value < root->data){
        return search(root->left, value);
    }
    else{
        return search(root->right, value);
    }
}

struct node *findMinimum(struct node *root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

struct node *delete(struct node *root, int value){
    if(root == NULL){
        return root;
    }
    else if(value < root->data){
        root->left = delete(root->left, value);
    }
    else if(value > root->data){
        root->right = delete(root->right, value);
    }
    else{
        if(root->left == NULL){
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = findMinimum(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

int main(){
    int choice, value;
    struct node *root = NULL;
    while(1){
        printf("\n1. Insert\n2. Inorder\n3. Search\n4. Delete\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(&root, value);
                break;
            case 2:
                inorder(root);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if(search(root, value) == NULL){
                    printf("Value not found!\n");
                }
                else{
                    printf("Value found!\n");
                }
                break;
            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = delete(root, value);
                printf("Value deleted!\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}