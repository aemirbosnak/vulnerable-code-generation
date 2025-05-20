//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 50
#define DICTIONARY_SIZE 5000

typedef struct {
    char word[WORD_LENGTH];
} Word;

void load_dictionary(Word dictionary[DICTIONARY_SIZE]) {
    FILE *fp;
    int i = 0;

    fp = fopen("dictionary.txt", "r");

    if (fp == NULL) {
        printf("Error: Could not open dictionary file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s", dictionary[i].word) != EOF) {
        i++;
    }

    fclose(fp);
}

int check_word(char *word, Word dictionary[DICTIONARY_SIZE]) {
    int i;

    for (i = 0; i < DICTIONARY_SIZE; i++) {
        if (strcasecmp(word, dictionary[i].word) == 0) {
            return 1;
        }
    }

    return 0;
}

void process_line(char line[1024], Word dictionary[DICTIONARY_SIZE]) {
    char word[WORD_LENGTH];
    char *token;
    int i, found;

    token = strtok(line, " .,\n");

    while (token != NULL) {
        strcpy(word, token);

        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }

        found = check_word(word, dictionary);

        if (!found) {
            printf("Error: %s is not a valid word.\n", word);
        }

        token = strtok(NULL, " .,\n");
    }
}

int main(int argc, char *argv[]) {
    Word dictionary[DICTIONARY_SIZE];
    char line[1024];

    if (argc != 2) {
        printf("Usage: %s <text_file>\n", argv[0]);
        return 1;
    }

    load_dictionary(dictionary);

    FILE *fp;

    fp = fopen(argv[1], "r");

    if (fp == NULL) {
        printf("Error: Could not open text file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        process_line(line, dictionary);
    }

    fclose(fp);

    printf("Spelling check completed.\n");

    return 0;
}