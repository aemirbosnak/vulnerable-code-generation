//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

typedef struct node {
    char word[MAX_WORD_LENGTH];
    int frequency;
    struct node* left;
    struct node* right;
} node;

node* create_node(char* word) {
    node* new_node = (node*) malloc(sizeof(node));
    strcpy(new_node->word, word);
    new_node->frequency = 1;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node* insert_word(node* root, char* word) {
    if (root == NULL) {
        return create_node(word);
    }

    if (strcmp(root->word, word) == 0) {
        root->frequency++;
        return root;
    }

    if (strcmp(root->word, word) < 0) {
        root->right = insert_word(root->right, word);
    } else {
        root->left = insert_word(root->left, word);
    }

    return root;
}

void print_in_order(node* root) {
    if (root == NULL) {
        return;
    }

    print_in_order(root->left);
    printf("%s: %d\n", root->word, root->frequency);
    print_in_order(root->right);
}

void print_frequency(node* root, char* word) {
    if (root == NULL) {
        printf("Word not found\n");
        return;
    }

    if (strcmp(root->word, word) == 0) {
        printf("Frequency of %s: %d\n", word, root->frequency);
        return;
    }

    if (strcmp(root->word, word) < 0) {
        print_frequency(root->right, word);
    } else {
        print_frequency(root->left, word);
    }
}

int main() {
    node* root = NULL;
    char word[MAX_WORD_LENGTH];

    printf("Enter words (type 'done' when finished):\n");

    while (scanf("%s", word) == 1) {
        if (strcmp(word, "done") == 0) {
            break;
        }

        root = insert_word(root, word);
    }

    printf("Words in order:\n");
    print_in_order(root);

    printf("\nEnter a word to get its frequency:\n");
    scanf("%s", word);

    print_frequency(root, word);

    return 0;
}