//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOCABULARY_SIZE 100
#define MAX_SENTENCE_LENGTH 100
#define MAX_WORD_LENGTH 10

// Vocabulary structure
typedef struct {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
} Vocabulary;

// Vocabulary array
Vocabulary vocabulary[MAX_VOCABULARY_SIZE];

// Function to load vocabulary from file
void loadVocabulary(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open vocabulary file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(fp, "%s %s\n", vocabulary[count].english, vocabulary[count].alien) == 2) {
        count++;
        if (count >= MAX_VOCABULARY_SIZE) {
            printf("Error: vocabulary file contains too many entries.\n");
            exit(1);
        }
    }

    fclose(fp);
}

// Function to translate sentence
void translateSentence(char* sentence) {
    char* token = strtok(sentence, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < MAX_VOCABULARY_SIZE; i++) {
            if (strcmp(token, vocabulary[i].english) == 0) {
                printf("%s ", vocabulary[i].alien);
                break;
            }
        }
        if (i == MAX_VOCABULARY_SIZE) {
            printf("unknown ");
        }
        token = strtok(NULL, " ");
    }
    printf("\n");
}

// Main function
int main() {
    loadVocabulary("vocabulary.txt");

    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence to translate: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);
    translateSentence(sentence);

    return 0;
}