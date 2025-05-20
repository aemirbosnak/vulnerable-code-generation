//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} Word;

void loadWords(Word words[]) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words file.\n");
        exit(1);
    }

    int numWords = 0;
    while (fscanf(file, "%s %s", words[numWords].word, words[numWords].translation)!= EOF) {
        numWords++;
    }

    fclose(file);
}

int main() {
    Word words[MAX_WORDS];
    loadWords(words);

    char input[MAX_WORD_LENGTH];
    printf("Enter a sentence in alien language:\n");
    fgets(input, MAX_WORD_LENGTH, stdin);

    char output[MAX_WORD_LENGTH];
    int outputIndex = 0;

    char *wordStart = strtok(input, " ");
    while (wordStart!= NULL) {
        int i;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(wordStart, words[i].word) == 0) {
                strcpy(output + outputIndex, words[i].translation);
                outputIndex += strlen(words[i].translation) + 1;
                break;
            }
        }

        if (i == MAX_WORDS) {
            printf("Unknown word: %s\n", wordStart);
        }

        wordStart = strtok(NULL, " ");
    }

    printf("Translation: %s\n", output);

    return 0;
}