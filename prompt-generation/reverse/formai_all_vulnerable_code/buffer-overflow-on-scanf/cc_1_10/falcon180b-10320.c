//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 100

typedef struct node {
    char word[MAX_WORD_LEN];
    int count;
    struct node *left;
    struct node *right;
} Node;

Node *create_node(char *word) {
    Node *node = (Node *) malloc(sizeof(Node));
    strcpy(node->word, word);
    node->count = 1;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node *insert_word(Node *root, char *word) {
    if (root == NULL) {
        return create_node(word);
    }

    if (strcmp(root->word, word) == 0) {
        root->count++;
        return root;
    }

    if (strcmp(root->word, word) > 0) {
        root->left = insert_word(root->left, word);
    } else {
        root->right = insert_word(root->right, word);
    }

    return root;
}

void print_words(Node *root, int min_count) {
    if (root == NULL) {
        return;
    }

    if (root->count >= min_count) {
        printf("%s %d\n", root->word, root->count);
    }

    print_words(root->left, min_count);
    print_words(root->right, min_count);
}

int main() {
    char input[MAX_WORD_LEN];
    int min_count;

    printf("Enter minimum word count: ");
    scanf("%d", &min_count);

    Node *root = NULL;

    while (1) {
        printf("Enter word (or type 'exit' to quit): ");
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        root = insert_word(root, input);
    }

    printf("Words with count >= %d:\n", min_count);
    print_words(root, min_count);

    return 0;
}