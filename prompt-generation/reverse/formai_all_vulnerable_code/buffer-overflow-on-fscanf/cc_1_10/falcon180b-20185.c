//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20
#define DICTIONARY_FILE "dictionary.txt"

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void loadDictionary(WordFrequency dictionary[MAX_WORDS]) {
    FILE *file = fopen(DICTIONARY_FILE, "r");
    if (file == NULL) {
        printf("Error: Dictionary file not found.\n");
        exit(1);
    }

    int wordCount = 0;
    while (fscanf(file, "%s %d", dictionary[wordCount].word, &dictionary[wordCount].frequency) == 2) {
        wordCount++;
        if (wordCount == MAX_WORDS) {
            printf("Error: Dictionary is too large.\n");
            exit(1);
        }
    }

    fclose(file);
}

void translate(char input[MAX_WORD_LENGTH], WordFrequency dictionary[MAX_WORDS]) {
    int inputLength = strlen(input);
    int bestMatchLength = 0;
    int bestMatchIndex = 0;

    for (int i = 0; i < MAX_WORDS; i++) {
        int matchLength = strlen(dictionary[i].word);
        if (matchLength > inputLength) continue;

        int j;
        for (j = 0; j < matchLength; j++) {
            if (tolower(input[j])!= tolower(dictionary[i].word[j])) break;
        }

        if (j == matchLength) {
            if (matchLength > bestMatchLength) {
                bestMatchLength = matchLength;
                bestMatchIndex = i;
            }
        }
    }

    if (bestMatchLength == 0) {
        printf("No match found.\n");
    } else {
        printf("%s -> %s\n", input, dictionary[bestMatchIndex].word);
    }
}

int main() {
    WordFrequency dictionary[MAX_WORDS];
    loadDictionary(dictionary);

    while (true) {
        printf("Enter a word to translate: ");
        scanf("%s", dictionary[0].word);
        translate(dictionary[0].word, dictionary);
    }

    return 0;
}