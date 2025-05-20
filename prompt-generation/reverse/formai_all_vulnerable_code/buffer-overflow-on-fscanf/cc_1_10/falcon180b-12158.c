//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

// Structure to store words and their translations
typedef struct {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
} Word;

// Function to load words from a file
void loadWords(Word words[], FILE *file) {
    int count = 0;
    while (fscanf(file, "%s %s", words[count].english, words[count].alien)!= EOF) {
        count++;
    }
}

// Function to save words to a file
void saveWords(Word words[], int count, FILE *file) {
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %s\n", words[i].english, words[i].alien);
    }
}

// Function to translate a sentence
void translateSentence(Word words[], int count, char sentence[]) {
    int length = strlen(sentence);
    char translated[length + 1]; // +1 for null terminator
    translated[0] = '\0';

    int wordStart = 0;
    while (wordStart < length) {
        int wordEnd = wordStart;
        while (isalnum(sentence[wordEnd])) {
            wordEnd++;
        }

        char word[MAX_WORD_LENGTH];
        strncpy(word, sentence + wordStart, wordEnd - wordStart);
        word[wordEnd - wordStart] = '\0';

        for (int i = 0; i < count; i++) {
            if (strcmp(word, words[i].english) == 0) {
                strcat(translated, words[i].alien);
                break;
            }
        }

        wordStart = wordEnd;
    }

    printf("%s\n", translated);
}

int main() {
    Word words[MAX_WORDS];
    int count = 0;

    // Load words from file
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words file.\n");
        return 1;
    }
    loadWords(words, file);
    fclose(file);

    // Translate sentence
    char sentence[] = "Hello world!";
    translateSentence(words, count, sentence);

    return 0;
}