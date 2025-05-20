//Code Llama-13B DATASET v1.0 Category: Searching algorithm ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100

typedef struct node {
    char key[MAX_STR_LEN];
    struct node *left;
    struct node *right;
} node_t;

node_t* insert(node_t* root, char* key) {
    if (root == NULL) {
        root = (node_t*)malloc(sizeof(node_t));
        strcpy(root->key, key);
        root->left = NULL;
        root->right = NULL;
        return root;
    }

    if (strcmp(key, root->key) < 0) {
        root->left = insert(root->left, key);
    } else if (strcmp(key, root->key) > 0) {
        root->right = insert(root->right, key);
    } else {
        // key already exists, do nothing
    }

    return root;
}

node_t* search(node_t* root, char* key) {
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

int main() {
    node_t* root = NULL;
    char str[MAX_STR_LEN];

    while (scanf("%s", str) != EOF) {
        root = insert(root, str);
    }

    char search_key[MAX_STR_LEN];
    printf("Enter search key: ");
    scanf("%s", search_key);

    node_t* result = search(root, search_key);
    if (result != NULL) {
        printf("Found %s\n", result->key);
    } else {
        printf("Not found\n");
    }

    return 0;
}