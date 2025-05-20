//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct node {
    char data;
    int freq;
    struct node* left;
    struct node* right;
};

struct node* create_node(char data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    new_node->data = data;
    new_node->freq = 1;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct node* insert_node(struct node* root, char data) {
    if (root == NULL) {
        return create_node(data);
    }
    if (root->data == data) {
        root->freq++;
        return root;
    }
    if (data < root->data) {
        root->left = insert_node(root->left, data);
    }
    else {
        root->right = insert_node(root->right, data);
    }
    return root;
}

int search_node(struct node* root, char data) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == data) {
        return root->freq;
    }
    if (data < root->data) {
        return search_node(root->left, data);
    }
    else {
        return search_node(root->right, data);
    }
}

int main() {
    char text[MAX_SIZE];
    printf("Enter the text: ");
    scanf("%s", text);
    int len = strlen(text);
    struct node* root = NULL;
    for (int i = 0; i < len; i++) {
        root = insert_node(root, text[i]);
    }
    char search_char;
    printf("Enter the character to search: ");
    scanf("%c", &search_char);
    int freq = search_node(root, search_char);
    if (freq == 0) {
        printf("Character not found\n");
    }
    else {
        printf("Frequency of %c is %d\n", search_char, freq);
    }
    return 0;
}