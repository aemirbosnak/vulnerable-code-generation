//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct node {
    char word[MAX_WORD_LENGTH];
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

Node* insert_word(Node* root, char* word) {
    if (root == NULL) {
        return create_node(word);
    }

    if (strcmp(root->word, word) == 0) {
        root->count++;
        return root;
    }

    if (strcmp(root->word, word) < 0) {
        root->right = insert_word(root->right, word);
    } else {
        root->left = insert_word(root->left, word);
    }

    return root;
}

void print_words(Node* root, char* prefix) {
    if (root == NULL) {
        return;
    }

    printf("%s%s (%d)\n", prefix, root->word, root->count);

    print_words(root->left, (char*)malloc(sizeof(char) * (strlen(prefix) + 2)));
    print_words(root->right, (char*)malloc(sizeof(char) * (strlen(prefix) + 2)));

    free(prefix);
}

int main() {
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int num_words = 0;
    char input[MAX_WORD_LENGTH];

    Node* root = NULL;

    while (num_words < MAX_WORDS) {
        printf("Enter a word: ");
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        strcpy(words[num_words], input);
        num_words++;

        root = insert_word(root, input);
    }

    printf("Words in the tree:\n");
    print_words(root, "");

    return 0;
}