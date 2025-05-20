//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} Word;

void loadWords(Word words[], int numWords) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open words.txt\n");
        exit(1);
    }

    int i = 0;
    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL && i < numWords) {
        char *word = strtok(line, " ");
        char *translation = strtok(NULL, " ");
        if (word == NULL || translation == NULL) {
            printf("Error: Invalid entry in words.txt\n");
            exit(1);
        }
        strcpy(words[i].word, word);
        strcpy(words[i].translation, translation);
        i++;
    }

    fclose(file);
}

int findWord(Word words[], int numWords, char *word) {
    for (int i = 0; i < numWords; i++) {
        if (strcmp(words[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    Word words[MAX_WORDS];
    int numWords = 0;
    loadWords(words, MAX_WORDS);
    numWords = MAX_WORDS;

    char sentence[MAX_WORD_LENGTH];
    printf("Enter a sentence to translate:\n");
    fgets(sentence, MAX_WORD_LENGTH, stdin);

    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        int wordIndex = findWord(words, numWords, token);
        if (wordIndex!= -1) {
            printf("%s -> %s\n", token, words[wordIndex].translation);
        } else {
            printf("%s\n", token);
        }
        token = strtok(NULL, " ");
    }

    return 0;
}