//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char c;
    struct Node *left, *right;
} Node;

Node* createNode(char c) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->c = c;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int charIsAlpha(char c) {
    return isalpha(c) || isdigit(c);
}

void mirror(Node *node) {
    if (node == NULL)
        return;

    Node *temp = node->left;
    node->left = node->right;
    node->right = temp;

    mirror(node->left);
    mirror(node->right);
}

int isPalindromeHelper(const char *str, Node *root, int len) {
    if (len == 0)
        return 1;

    if (root == NULL) {
        root = createNode(str[0]);
        root->left = root->right = NULL;
    }

    if (charIsAlpha(str[len - 1])) {
        if (root->c != tolower(str[len - 1]))
            return 0;

        Node *newNode = createNode(str[len - 1]);
        newNode->left = root->left;
        newNode->right = root;
        root->left = newNode;

        len--;
        return isPalindromeHelper(str, root->right, len);
    } else {
        len--;
        return isPalindromeHelper(str, root, len);
    }
}

int main() {
    char str[101];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0';

    Node *root = NULL;
    int len = strlen(str);

    if (isPalindromeHelper(str, root, len) == 1)
        printf("The given string is a palindrome.\n");
    else
        printf("The given string is not a palindrome.\n");

    mirror(root);
    free(root);

    return 0;
}