//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool is_verb;
} Word;

int main() {
    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    FILE *output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        return 1;
    }

    int num_words = 0;
    Word words[MAX_WORDS];

    char line[MAX_WORD_LENGTH];
    while (fgets(line, sizeof(line), input_file)!= NULL) {
        char *token = strtok(line, " ");
        while (token!= NULL) {
            if (num_words >= MAX_WORDS) {
                printf("Error: Too many words in input file.\n");
                return 1;
            }

            strcpy(words[num_words].word, token);
            words[num_words].is_verb = false;

            num_words++;

            token = strtok(NULL, " ");
        }
    }

    fclose(input_file);

    for (int i = 0; i < num_words; i++) {
        bool is_verb = false;

        if (strlen(words[i].word) > 2 && words[i].word[strlen(words[i].word) - 2] == 'e' && isalpha(words[i].word[strlen(words[i].word) - 1])) {
            is_verb = true;
        }

        if (is_verb) {
            words[i].is_verb = true;
        }
    }

    for (int i = 0; i < num_words; i++) {
        if (words[i].is_verb) {
            fprintf(output_file, "%s\n", words[i].word);
        }
    }

    fclose(output_file);

    return 0;
}