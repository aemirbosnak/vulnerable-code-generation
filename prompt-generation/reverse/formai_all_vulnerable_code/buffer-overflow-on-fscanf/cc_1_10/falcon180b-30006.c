//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

typedef struct node {
    char word[MAX_WORD_LENGTH];
    int count;
    struct node* left;
    struct node* right;
} Node;

Node* createNode(char* word) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->word, word);
    newNode->count = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, char* word) {
    if (root == NULL) {
        return createNode(word);
    }

    if (strcmp(root->word, word) == 0) {
        root->count++;
        return root;
    }

    if (strcmp(root->word, word) < 0) {
        root->right = insert(root->right, word);
    } else {
        root->left = insert(root->left, word);
    }

    return root;
}

void printWords(Node* node, int space) {
    if (node == NULL) {
        return;
    }

    printWords(node->right, space + 4);

    printf("%*s%s (%d)\n", space, "", node->word, node->count);

    printWords(node->left, space + 4);
}

int main() {
    FILE* file = fopen("words.txt", "r");
    char word[MAX_WORD_LENGTH];
    Node* root = NULL;

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fscanf(file, "%s", word)!= EOF) {
        tolower(word);
        root = insert(root, word);
    }

    fclose(file);

    printf("Words in the tree:\n");
    printWords(root, 0);

    return 0;
}