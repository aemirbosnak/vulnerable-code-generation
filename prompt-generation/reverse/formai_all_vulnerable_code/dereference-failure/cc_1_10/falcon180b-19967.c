//Falcon-180B DATASET v1.0 Category: Recursive ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 1000
#define MAX_WORD_SIZE 50

typedef struct {
    char *word;
    int count;
    struct node *next;
} node;

node *head = NULL;

node *create_node(char *word, int count) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->word = (char *)malloc(MAX_WORD_SIZE * sizeof(char));
    strcpy(new_node->word, word);
    new_node->count = count;
    new_node->next = NULL;
    return new_node;
}

void add_word(char *word) {
    node *current = head;
    int found = 0;
    while (current!= NULL &&!found) {
        if (strcmp(current->word, word) == 0) {
            current->count++;
            found = 1;
        } else {
            current = current->next;
        }
    }
    if (!found) {
        node *new_node = create_node(word, 1);
        new_node->next = head;
        head = new_node;
    }
}

void print_word_counts(node *current) {
    while (current!= NULL) {
        printf("%s: %d\n", current->word, current->count);
        current = current->next;
    }
}

int main() {
    srand(time(NULL));
    char *words[] = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "kiwi", "lemon", "mango", "nectarine", "orange", "pear", "quince", "raspberry", "strawberry", "tangerine", "watermelon", "xylophone", "yellow", "zebra"};
    int i;
    for (i = 0; i < 26; i++) {
        add_word(words[i]);
    }
    node *current = head;
    while (current!= NULL) {
        printf("%s: %d\n", current->word, current->count);
        current = current->next;
    }
    return 0;
}