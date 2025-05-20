//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

void loadDictionary(char* filename, Word* dictionary) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error loading dictionary file\n");
        exit(1);
    }

    int numWords = 0;
    while (fscanf(file, "%s", dictionary[numWords].word)!= EOF) {
        numWords++;
    }

    fclose(file);
}

void generateSentence(Word* dictionary, int numWords, char* sentence) {
    strcpy(sentence, "");

    for (int i = 0; i < numWords; i++) {
        int wordIndex = rand() % numWords;
        strcat(sentence, dictionary[wordIndex].word);
        strcat(sentence, " ");
    }

    sentence[strlen(sentence) - 1] = '\0';
}

int main() {
    Word dictionary[MAX_WORDS];
    loadDictionary("dictionary.txt", dictionary);

    int numWords = rand() % 5 + 5;
    char sentence[100];

    generateSentence(dictionary, numWords, sentence);

    printf("Cat: %s\n", sentence);

    return 0;
}