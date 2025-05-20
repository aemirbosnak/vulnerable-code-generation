//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct node {
    char data;
    int freq;
    struct node *left;
    struct node *right;
} Node;

void create_tree(Node *root, char *str, int len) {
    if (len == 0) {
        root->data = '\0';
        root->freq = 1;
        root->left = NULL;
        root->right = NULL;
        return;
    }

    char ch = tolower(str[0]);
    int count = 0;

    Node *temp = root;

    while (temp!= NULL) {
        if (temp->data == ch) {
            temp->freq++;
            temp = temp->right;
        } else {
            temp = temp->left;
        }
    }

    if (temp == NULL) {
        temp = (Node *) malloc(sizeof(Node));
        temp->data = ch;
        temp->freq = 1;
        temp->left = NULL;
        temp->right = NULL;
        root->freq++;
        root->right = temp;
    } else {
        temp->freq++;
    }

    create_tree(temp, str + 1, len - 1);
}

void inorder(Node *root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%c ", root->data);
    inorder(root->right);
}

void preorder(Node *root) {
    if (root == NULL)
        return;

    printf("%c ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%c ", root->data);
}

int main() {
    char str[MAX_SIZE];
    printf("Enter a string: ");
    scanf("%s", str);

    Node *root = (Node *) malloc(sizeof(Node));
    root->data = '\0';
    root->freq = 1;
    root->left = NULL;
    root->right = NULL;

    create_tree(root, str, strlen(str));

    printf("\nInorder traversal: ");
    inorder(root);
    printf("\n\n");

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n\n");

    return 0;
}