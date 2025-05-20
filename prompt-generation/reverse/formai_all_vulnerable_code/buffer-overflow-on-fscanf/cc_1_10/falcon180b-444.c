//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 20

// Structure to hold word and its translation
typedef struct {
    char word[MAX_WORD_LEN];
    char translation[MAX_WORD_LEN];
} WordTranslation;

// Function to load translations from file
bool loadTranslations(const char* filename, WordTranslation translations[MAX_WORDS]) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open translation file.\n");
        return false;
    }

    int numTranslations = 0;
    while (fscanf(file, "%s %s\n", translations[numTranslations].word, translations[numTranslations].translation) == 2) {
        numTranslations++;
        if (numTranslations >= MAX_WORDS) {
            printf("Error: Too many translations in file.\n");
            fclose(file);
            return false;
        }
    }

    fclose(file);
    return true;
}

// Function to translate sentence using loaded translations
void translateSentence(const char* sentence, const WordTranslation translations[MAX_WORDS]) {
    char* words[MAX_WORDS];
    int numWords = 0;

    // Split sentence into words
    char* word = strtok(sentence, " ");
    while (word!= NULL && numWords < MAX_WORDS) {
        words[numWords] = word;
        numWords++;
        word = strtok(NULL, " ");
    }

    // Translate each word
    for (int i = 0; i < numWords; i++) {
        bool foundTranslation = false;
        for (int j = 0; j < MAX_WORDS; j++) {
            if (strcmp(words[i], translations[j].word) == 0) {
                printf("%s -> %s\n", words[i], translations[j].translation);
                foundTranslation = true;
                break;
            }
        }

        if (!foundTranslation) {
            printf("%s -> (No translation found)\n", words[i]);
        }
    }
}

int main() {
    WordTranslation translations[MAX_WORDS];
    if (!loadTranslations("translations.txt", translations)) {
        return 1;
    }

    char sentence[1000];
    printf("Enter a sentence to translate: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Remove newline character from input
    sentence[strcspn(sentence, "\n")] = '\0';

    translateSentence(sentence, translations);

    return 0;
}