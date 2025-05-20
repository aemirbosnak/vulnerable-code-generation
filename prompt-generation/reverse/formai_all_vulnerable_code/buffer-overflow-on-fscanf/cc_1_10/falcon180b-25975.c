//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} WordTranslation;

void loadDictionary(WordTranslation* dictionary) {
    FILE* file = fopen("dictionary.txt", "r");
    if (!file) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }

    int wordCount = 0;
    while (fscanf(file, "%s %s\n", dictionary[wordCount].word, dictionary[wordCount].translation) == 2) {
        wordCount++;
    }

    fclose(file);
}

bool isValidWord(const char* word) {
    for (int i = 0; i < strlen(word); i++) {
        if (!isalpha(word[i])) {
            return false;
        }
    }
    return true;
}

bool isTranslationWord(const char* word) {
    for (int i = 0; i < strlen(word); i++) {
        if (!isalpha(word[i]) && word[i]!= '-') {
            return false;
        }
    }
    return true;
}

int main() {
    WordTranslation dictionary[MAX_WORDS];
    loadDictionary(dictionary);

    char input[MAX_WORD_LENGTH];
    while (true) {
        printf("Enter a word to translate: ");
        scanf("%s", input);

        int wordIndex = -1;
        for (int i = 0; i < MAX_WORDS; i++) {
            if (strcmp(dictionary[i].word, input) == 0) {
                wordIndex = i;
                break;
            }
        }

        if (wordIndex == -1) {
            printf("Word not found in dictionary.\n");
        } else {
            printf("Translation: %s\n", dictionary[wordIndex].translation);
        }
    }

    return 0;
}