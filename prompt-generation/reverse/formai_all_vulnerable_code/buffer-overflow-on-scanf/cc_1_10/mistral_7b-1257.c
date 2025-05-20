//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define TABLE_SIZE 256

typedef struct Word {
    char *word;
    int count;
} Word;

bool isAlpha(char c) {
    return (isalpha(c) || isdigit(c) || c == '_');
}

void freeWord(Word *word) {
    free(word->word);
    free(word);
}

Word *createWord(char *word) {
    Word *newWord = (Word *)calloc(1, sizeof(Word));
    newWord->word = strdup(word);
    newWord->count = 1;
    return newWord;
}

void incrementWordCount(Word **table, char *word) {
    int index = 0;
    for (; index < TABLE_SIZE; index++) {
        if (strcmp(table[index]->word, word) == 0) {
            table[index]->count++;
            break;
        }
    }

    if (index == TABLE_SIZE) {
        table[index] = createWord(word);
    }
}

void processLine(char *line, Word **table) {
    char *token = strtok(line, " ");
    while (token != NULL) {
        if (isAlpha(token[0])) {
            for (int i = 0; token[i] != '\0'; i++) {
                token[i] = tolower(token[i]);
            }
            incrementWordCount(table, token);
        }
        token = strtok(NULL, " ");
    }
}

int main() {
    char filename[100];
    FILE *file;
    Word *table[TABLE_SIZE];

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = NULL;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file) != NULL) {
        processLine(line, table);
    }

    fclose(file);

    printf("\nWord frequencies:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] != NULL) {
            printf("%s: %d\n", table[i]->word, table[i]->count);
            freeWord(table[i]);
        }
    }

    return EXIT_SUCCESS;
}