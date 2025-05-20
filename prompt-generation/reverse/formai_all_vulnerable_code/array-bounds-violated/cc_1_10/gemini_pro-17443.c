//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 20

typedef struct node {
    char word[MAX_WORD_LEN];
    struct node *next;
} node_t;

node_t *dictionary[26];

void insert_word(char *word) {
    int index = word[0] - 'a';
    node_t *new_node = malloc(sizeof(node_t));
    strcpy(new_node->word, word);
    new_node->next = dictionary[index];
    dictionary[index] = new_node;
}

int load_dictionary(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return -1;
    }

    char word[MAX_WORD_LEN];
    while (fscanf(fp, "%s", word) != EOF) {
        insert_word(word);
    }

    fclose(fp);
    return 0;
}

int check_spelling(char *word) {
    int index = word[0] - 'a';
    node_t *node = dictionary[index];

    while (node != NULL) {
        if (strcmp(node->word, word) == 0) {
            return 1;
        }
        node = node->next;
    }

    return 0;
}

int main(void) {
    if (load_dictionary("dictionary.txt") != 0) {
        printf("Error loading dictionary.\n");
        return 1;
    }

    char word[MAX_WORD_LEN];
    printf("Enter a word to check spelling: ");
    scanf("%s", word);

    if (check_spelling(word)) {
        printf("Yay! The word '%s' is spelled correctly.\n", word);
    } else {
        printf("Oops! The word '%s' is spelled incorrectly.\n", word);
    }

    return 0;
}