//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Node structure
typedef struct {
    char data;
    int freq;
    struct node* left;
    struct node* right;
} Node;

// Function to create a new node
Node* newNode(char ch) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = ch;
    node->freq = 1;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a node into the tree
Node* insert(Node* root, char ch) {
    if (root == NULL)
        return newNode(ch);

    if (ch < root->data)
        root->left = insert(root->left, ch);
    else if (ch > root->data)
        root->right = insert(root->right, ch);
    else
        root->freq++;

    return root;
}

// Function to print the tree
void printTree(Node* root, char prefix[], int level) {
    if (root == NULL)
        return;

    prefix[level] = '\0';
    printf("%s%c (%d)\n", prefix, root->data, root->freq);

    printTree(root->left, prefix, level + 1);
    printTree(root->right, prefix, level + 1);
}

// Function to build the tree
Node* buildTree(char text[]) {
    Node* root = NULL;
    int i = 0;

    while (text[i]) {
        root = insert(root, tolower(text[i]));
        i++;
    }

    return root;
}

// Function to print the frequency of a character
void printFreq(Node* root, char ch) {
    if (root == NULL)
        return;

    if (root->data == ch)
        printf("%c: %d\n", ch, root->freq);

    printFreq(root->left, ch);
    printFreq(root->right, ch);
}

int main() {
    char text[1000];
    printf("Enter a string: ");
    scanf("%s", text);

    Node* root = buildTree(text);
    printf("Tree:\n");
    printTree(root, "", 0);

    char ch;
    printf("Enter a character: ");
    scanf(" %c", &ch);

    printf("Frequency of '%c':\n", ch);
    printFreq(root, ch);

    return 0;
}