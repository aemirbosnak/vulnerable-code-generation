//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 100

typedef struct node {
    char word[MAX_WORD_LEN];
    int count;
    struct node* left;
    struct node* right;
} Node;

Node* create_node(char* word) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->word, word);
    new_node->count = 1;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node* insert_node(Node* root, char* word) {
    if (root == NULL) {
        return create_node(word);
    }

    if (strcmp(root->word, word) == 0) {
        root->count++;
    } else if (strcmp(root->word, word) < 0) {
        root->right = insert_node(root->right, word);
    } else {
        root->left = insert_node(root->left, word);
    }

    return root;
}

void print_in_order(Node* root) {
    if (root == NULL) {
        return;
    }

    print_in_order(root->left);
    printf("%s: %d\n", root->word, root->count);
    print_in_order(root->right);
}

int main() {
    char input[MAX_WORD_LEN];
    Node* root = NULL;

    while (1) {
        printf("Enter a word (or type 'exit' to quit): ");
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        root = insert_node(root, input);
    }

    printf("Words in order:\n");
    print_in_order(root);

    return 0;
}