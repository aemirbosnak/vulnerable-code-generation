//FormAI DATASET v1.0 Category: Spell checking ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1000
#define DICTIONARY_FILE "dictionary.txt"

char *dictionary_words[MAX_WORD_LENGTH];
int num_dictionary_words = 0;

void load_dictionary(char *file_name) {
    FILE *file = fopen(file_name, "r");

    if (file == NULL) {
        fprintf(stderr, "Could not open dictionary file '%s'\n", file_name);
        exit(1);
    }

    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        line[strlen(line) - 1] = '\0'; // Remove newline character
        dictionary_words[num_dictionary_words] = strdup(line);
        num_dictionary_words++;
    }

    fclose(file);
}

int is_word_in_dictionary(char *word) {
    for (int i = 0; i < num_dictionary_words; i++) {
        if (strcmp(dictionary_words[i], word) == 0) {
            return 1;
        }
    }
    return 0;
}

void check_spelling(char *input_file_name, char *output_file_name) {
    FILE *input_file = fopen(input_file_name, "r");
    FILE *output_file = fopen(output_file_name, "w");

    if (input_file == NULL) {
        fprintf(stderr, "Could not open input file '%s'\n", input_file_name);
        exit(1);
    }

    if (output_file == NULL) {
        fprintf(stderr, "Could not open output file '%s'\n", output_file_name);
        exit(1);
    }

    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL) {
        char *word = NULL;

        for (int i = 0; i < strlen(line); i++) {
            if (isalpha(line[i])) {
                if (word == NULL) {
                    word = &line[i];
                }
            } else {
                if (word != NULL) {
                    int word_length = &line[i] - word;
                    char buffer[MAX_WORD_LENGTH];
                    strncpy(buffer, word, word_length);
                    buffer[word_length] = '\0';

                    if (!is_word_in_dictionary(buffer)) {
                        fprintf(output_file, "%s ", buffer);
                    } else {
                        fprintf(output_file, "%s ", word);
                    }

                    word = NULL;
                } else {
                    fprintf(output_file, "%c", line[i]);
                }
            }
        }

        if (word != NULL) {
            if (!is_word_in_dictionary(word)) {
                fprintf(output_file, "%s", word);
            } else {
                fprintf(output_file, "%s", word);
            }
        }

        fprintf(output_file, "\n");
    }

    fclose(input_file);
    fclose(output_file);
}

int main(int argc, char *argv[]) {
    load_dictionary(DICTIONARY_FILE);

    if (argc != 3) {
        fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
        exit(1);
    }

    check_spelling(argv[1], argv[2]);

    return 0;
}