//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

typedef struct node {
    char word[MAX_WORD_LENGTH + 1];
    struct node *next;
} node;

node *head = NULL;

void insert_word(char *word) {
    node *new_node = malloc(sizeof(node));
    strcpy(new_node->word, word);
    new_node->next = head;
    head = new_node;
}

int load_dictionary(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return -1;
    }

    char line[MAX_WORD_LENGTH + 1];
    while (fgets(line, MAX_WORD_LENGTH + 1, fp)) {
        line[strlen(line) - 1] = '\0';  // remove newline character
        insert_word(line);
    }

    fclose(fp);
    return 0;
}

int check_word(char *word) {
    node *current = head;
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

void spell_check(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return;
    }

    char line[1024];
    int line_number = 1;
    while (fgets(line, 1024, fp)) {
        char *word = strtok(line, " .,;:!?\n\t");
        while (word != NULL) {
            word = tolower(word);
            if (!check_word(word)) {
                printf("Line %d: Misspelled word: %s\n", line_number, word);
            }
            word = strtok(NULL, " .,;:!?\n\t");
        }
        line_number++;
    }

    fclose(fp);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <dictionary file> <text file>\n", argv[0]);
        return 1;
    }

    if (load_dictionary(argv[1]) != 0) {
        printf("Error loading dictionary file.\n");
        return 1;
    }

    spell_check(argv[2]);

    return 0;
}