//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

// Struct to hold word and its translation
typedef struct {
    char english[MAX_WORD_LEN];
    char alien[MAX_WORD_LEN];
} WordTranslation;

// Function to load words from file into array of structs
void loadWords(WordTranslation words[], FILE *fp) {
    int count = 0;
    while (fscanf(fp, "%s %s\n", words[count].english, words[count].alien)!= EOF) {
        count++;
    }
}

// Function to save words to file from array of structs
void saveWords(WordTranslation words[], int numWords, FILE *fp) {
    for (int i = 0; i < numWords; i++) {
        fprintf(fp, "%s %s\n", words[i].english, words[i].alien);
    }
}

// Function to translate sentence using loaded words
void translateSentence(char sentence[], WordTranslation words[], int numWords) {
    int len = strlen(sentence);
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        int found = 0;
        for (int i = 0; i < numWords; i++) {
            if (strcmp(token, words[i].english) == 0) {
                printf("%s ", words[i].alien);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("%s ", token);
        }
        token = strtok(NULL, " ");
    }
    printf("\n");
}

// Main function
int main() {
    WordTranslation words[MAX_WORDS];
    FILE *fp;

    // Load words from file
    fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open words file.\n");
        exit(1);
    }
    loadWords(words, fp);
    fclose(fp);

    // Translate sentence
    char sentence[] = "Hello world, how are you?";
    translateSentence(sentence, words, sizeof(words)/sizeof(WordTranslation));

    return 0;
}