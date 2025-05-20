//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 100

typedef struct node {
    char word[MAX_WORD_LENGTH];
    int count;
    struct node *left;
    struct node *right;
} Node;

Node *create_node(char *word) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    strcpy(new_node->word, word);
    new_node->count = 1;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node *insert_word(Node *root, char *word) {
    if (root == NULL) {
        root = create_node(word);
    } else if (strcmp(root->word, word) == 0) {
        root->count++;
    } else if (strcmp(root->word, word) < 0) {
        root->right = insert_word(root->right, word);
    } else {
        root->left = insert_word(root->left, word);
    }
    return root;
}

void print_in_order(Node *root) {
    if (root!= NULL) {
        print_in_order(root->left);
        printf("%s: %d\n", root->word, root->count);
        print_in_order(root->right);
    }
}

int main() {
    FILE *file = fopen("words.txt", "r");
    char word[MAX_WORD_LENGTH];
    Node *root = NULL;

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    while (fscanf(file, "%s", word)!= EOF) {
        root = insert_word(root, word);
    }

    fclose(file);

    printf("Words in alphabetical order:\n");
    print_in_order(root);

    return 0;
}