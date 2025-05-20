//FormAI DATASET v1.0 Category: Spell checking ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_DIC_SIZE 10000

int dictionary_size = 0;
char **dictionary;

void load_dictionary(char *filename) {
    FILE *file;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file '%s'\n", filename);
        exit(1);
    }

    dictionary = malloc(MAX_DIC_SIZE * sizeof(char *));
    char word[MAX_WORD_LENGTH];
    while (fgets(word, MAX_WORD_LENGTH, file) != NULL) {
        word[strlen(word)-1] = '\0'; // remove newline character
        dictionary[dictionary_size] = strdup(word);
        dictionary_size++;
    }

    fclose(file);
}

int check_dictionary(char *word) {
    int i;
    for (i = 0; i < dictionary_size; i++) {
        if (strcmp(word, dictionary[i]) == 0) return 1;
    }
    return 0;
}

int check_spelling(char *text) {
    int i, j, error_count = 0;
    char word[MAX_WORD_LENGTH];

    for (i = 0; i < strlen(text); i++) {
        if (text[i] == ' ' || text[i] == '\n' || text[i] == '\t') {
            word[j] = '\0';
            if (!check_dictionary(word)) {
                printf("'%s' is not in the dictionary!\n", word);
                error_count++;
            }
            j = 0;
        } else {
            word[j] = text[i];
            j++;
        }
    }

    return error_count;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        exit(1);
    }

    load_dictionary(argv[1]);

    FILE *file;
    char text[MAX_WORD_LENGTH];
    file = fopen(argv[2], "r");
    if (file == NULL) {
        printf("Unable to open file '%s'\n", argv[2]);
        exit(1);
    }

    fgets(text, MAX_WORD_LENGTH, file);
    fclose(file);

    printf("Original text: %s\n", text);
    int errors = check_spelling(text);
    if (errors == 0) {
        printf("No spelling errors found\n");
    } else {
        printf("%d spelling error(s) found\n", errors);
    }

    return 0;
}