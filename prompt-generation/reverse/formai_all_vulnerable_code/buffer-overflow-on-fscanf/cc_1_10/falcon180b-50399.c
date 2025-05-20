//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

typedef struct node {
    WordCount data;
    struct node* left;
    struct node* right;
} Node;

Node* create_node(char* word, int count) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->data.word, word);
    new_node->data.count = count;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert_word(Node* node, char* word, int count) {
    if (node == NULL) {
        node = create_node(word, count);
        return;
    }

    if (strcmp(node->data.word, word) < 0) {
        insert_word(node->right, word, count);
    } else if (strcmp(node->data.word, word) > 0) {
        insert_word(node->left, word, count);
    } else {
        node->data.count += count;
    }
}

void print_tree(Node* node, int space) {
    if (node == NULL) {
        return;
    }

    print_tree(node->right, space + 4);

    for (int i = 0; i < space; i++) {
        printf(" ");
    }

    printf("%s %d\n", node->data.word, node->data.count);

    print_tree(node->left, space + 4);
}

int main() {
    FILE* file = fopen("input.txt", "r");
    char word[MAX_WORD_LENGTH];
    int count = 0;

    Node* root = NULL;

    while (fscanf(file, "%s", word)!= EOF) {
        count = 1;
        while (fscanf(file, "%s", word)!= EOF) {
            insert_word(root, word, count);
            count++;
        }
    }

    print_tree(root, 0);

    return 0;
}