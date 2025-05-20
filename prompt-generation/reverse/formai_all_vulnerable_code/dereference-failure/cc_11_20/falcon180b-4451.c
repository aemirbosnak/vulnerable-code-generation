//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define DICTIONARY_FILE "dictionary.txt"

typedef struct {
    char *word;
    bool isCorrect;
} Word;

int main(int argc, char **argv) {
    FILE *dictionary;
    char line[MAX_WORD_LENGTH];
    int numWords = 0;
    Word *words = NULL;
    char *input = NULL;
    size_t inputSize = 0;

    dictionary = fopen(DICTIONARY_FILE, "r");
    if (dictionary == NULL) {
        printf("Error opening dictionary file.\n");
        return 1;
    }

    while (fgets(line, MAX_WORD_LENGTH, dictionary)!= NULL) {
        line[strcspn(line, "\n")] = '\0';
        words = realloc(words, sizeof(Word) * ++numWords);
        words[numWords - 1].word = strdup(line);
        words[numWords - 1].isCorrect = true;
    }

    fclose(dictionary);

    input = malloc(MAX_WORD_LENGTH);
    inputSize = 0;

    while (fgets(input + inputSize, MAX_WORD_LENGTH - inputSize, stdin)!= NULL) {
        inputSize += strlen(input + inputSize);
    }

    input[inputSize] = '\0';

    for (int i = 0; i < strlen(input); i++) {
        if (isalpha(input[i])) {
            input[i] = tolower(input[i]);
        }
    }

    for (int i = 0; i < strlen(input); i++) {
        if (i == 0 ||!isalpha(input[i - 1])) {
            bool found = false;
            for (int j = 0; j < numWords; j++) {
                if (strncmp(input + i, words[j].word, strlen(words[j].word)) == 0) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                printf("Possible spelling mistake at position %d.\n", i);
            }
        }
    }

    for (int i = 0; i < numWords; i++) {
        free(words[i].word);
    }
    free(words);
    free(input);

    return 0;
}