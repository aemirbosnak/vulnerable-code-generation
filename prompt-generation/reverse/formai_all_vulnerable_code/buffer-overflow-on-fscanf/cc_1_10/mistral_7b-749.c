//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 50

typedef struct {
    char word[WORD_LENGTH];
    int is_valid;
} word_t;

word_t dictionary[MAX_WORDS];

void load_dictionary(const char *filename) {
    FILE *fp = fopen(filename, "r");
    int i = 0;
    char word[WORD_LENGTH];

    if (fp == NULL) {
        perror("Error opening dictionary file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(fp, "%s", word) != EOF) {
        strcpy(dictionary[i].word, word);
        dictionary[i].is_valid = 1;
        i++;
    }

    fclose(fp);
}

int is_valid_word(const char *word) {
    int i;

    for (i = 0; i < MAX_WORDS; i++) {
        if (strcmp(dictionary[i].word, word) == 0 && dictionary[i].is_valid) {
            return 1;
        }
    }

    return 0;
}

int main() {
    char line[1024];
    char *token;
    int i, num_errors = 0;

    load_dictionary("dictionary.txt");

    printf("Enter a line to check for spelling errors:\n");
    fgets(line, sizeof(line), stdin);
    line[strlen(line) - 1] = '\0'; // remove newline character

    token = strtok(line, " ");

    while (token != NULL) {
        int is_valid = is_valid_word(token);

        if (!is_valid) {
            printf("Error: %s is not a valid word.\n", token);
            num_errors++;
        }

        token = strtok(NULL, " ");
    }

    if (num_errors > 0) {
        printf("%d error(s) found.\n", num_errors);
    } else {
        printf("No errors found.\n");
    }

    return EXIT_SUCCESS;
}