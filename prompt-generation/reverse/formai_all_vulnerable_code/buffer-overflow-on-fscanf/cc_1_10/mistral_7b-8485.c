//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 50
#define DICTIONARY_SIZE 10000

typedef struct {
    char word[WORD_LENGTH];
    int is_valid;
} Word;

Word dictionary[DICTIONARY_SIZE];

void load_dictionary() {
    FILE *fp = fopen("dictionary.txt", "r");
    int i = 0;

    if (fp == NULL) {
        printf("Error: Could not open dictionary file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s", dictionary[i].word) != EOF) {
        i++;
    }

    fclose(fp);

    for (i = 0; i < DICTIONARY_SIZE; i++) {
        dictionary[i].is_valid = 1;
    }
}

int check_word(char *word) {
    int i;

    for (i = 0; i < DICTIONARY_SIZE; i++) {
        if (strcmp(word, dictionary[i].word) == 0) {
            return dictionary[i].is_valid;
        }
    }

    return 0;
}

void process_line(char *line) {
    char *token = strtok(line, " ");
    int i = 0;

    while (token != NULL) {
        if (check_word(token) == 1) {
            printf("%s is a valid word.\n", token);
        } else {
            printf("%s is not a valid word.\n", token);
            strcpy(dictionary[i].word, token);
            dictionary[i].is_valid = -1;
            i++;
        }

        token = strtok(NULL, " ");
    }
}

int main(int argc, char *argv[]) {
    char line[100];

    if (argc != 2) {
        printf("Usage: %s < text_file > output_file >\n", argv[0]);
        return 1;
    }

    load_dictionary();

    FILE *input = fopen(argv[1], "r");
    FILE *output = stdout;

    if (input == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), input) != NULL) {
        process_line(line);
    }

    fclose(input);

    if (argc > 3) {
        output = fopen(argv[2], "w");
    }

    for (int i = 0; i < DICTIONARY_SIZE && dictionary[i].is_valid == -1; i++) {
        fprintf(output, "%s\n", dictionary[i].word);
    }

    fclose(output);

    return 0;
}