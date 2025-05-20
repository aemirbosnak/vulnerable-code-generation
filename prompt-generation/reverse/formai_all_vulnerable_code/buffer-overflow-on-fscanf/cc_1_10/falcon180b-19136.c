//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} WordTranslation;

void loadWords(WordTranslation words[]);
char* translateWord(WordTranslation words[], int numWords, char* word);

int main() {
    WordTranslation words[MAX_WORDS];
    int numWords = 0;

    loadWords(words);

    char input[MAX_WORD_LENGTH];
    while (fgets(input, sizeof(input), stdin)!= NULL) {
        char* token = strtok(input, " ");
        while (token!= NULL) {
            char* translatedToken = translateWord(words, numWords, token);
            printf("%s ", translatedToken);
            token = strtok(NULL, " ");
        }
        printf("\n");
    }

    return 0;
}

void loadWords(WordTranslation words[]) {
    FILE* file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open words file.\n");
        exit(1);
    }

    int numWords = 0;
    while (fscanf(file, "%s %s\n", words[numWords].word, words[numWords].translation)!= EOF) {
        numWords++;
    }

    fclose(file);
}

char* translateWord(WordTranslation words[], int numWords, char* word) {
    for (int i = 0; i < numWords; i++) {
        if (strcmp(word, words[i].word) == 0) {
            return words[i].translation;
        }
    }

    return word;
}