//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: invasive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

char *dictionary[MAX_WORDS];
int dictionary_size = 0;

void load_dictionary(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening dictionary file");
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, sizeof(line), fp)) {
        line[strlen(line) - 1] = '\0'; // Remove newline character
        dictionary[dictionary_size++] = strdup(line);
    }

    fclose(fp);
}

int check_spelling(const char *word) {
    for (int i = 0; i < dictionary_size; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

int main() {
    load_dictionary("dictionary.txt");

    char input[MAX_WORD_LENGTH];
    while (1) {
        printf("Enter a word to check (or quit to exit): ");
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) {
            break;
        }

        int is_correct = check_spelling(input);
        if (is_correct) {
            printf("%s is spelled correctly.\n", input);
        } else {
            printf("%s is spelled incorrectly.\n", input);
        }
    }

    return 0;
}