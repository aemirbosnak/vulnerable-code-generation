//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} Word;

int main() {
    int numWords;
    Word words[MAX_WORDS];
    char input[MAX_WORD_LENGTH];
    char output[MAX_WORD_LENGTH];
    char *token;

    // Load dictionary
    FILE *dictFile = fopen("dictionary.txt", "r");
    if (dictFile == NULL) {
        printf("Error: could not load dictionary file.\n");
        return 1;
    }

    int wordCount = 0;
    while (fscanf(dictFile, "%s %s", words[wordCount].word, words[wordCount].translation) == 2) {
        wordCount++;
        if (wordCount >= MAX_WORDS) {
            break;
        }
    }
    fclose(dictFile);

    // Get input
    printf("Enter a sentence to translate:\n");
    fgets(input, MAX_WORD_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';

    // Tokenize input
    token = strtok(input, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(token, words[i].word) == 0) {
                strcpy(output, words[i].translation);
                break;
            }
        }
        if (i == numWords) {
            strcpy(output, "unknown");
        }
        printf("%s ", output);
        token = strtok(NULL, " ");
    }

    return 0;
}