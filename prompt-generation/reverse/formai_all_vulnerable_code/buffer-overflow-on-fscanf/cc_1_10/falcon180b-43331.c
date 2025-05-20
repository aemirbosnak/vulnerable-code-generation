//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: ultraprecise
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1000

// Struct to hold each word and its translation
typedef struct {
    char english[50];
    char alien[50];
} Word;

// Function to load words from file into array
void loadWords(Word words[]) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s", words[count].english, words[count].alien)!= EOF) {
        count++;
    }

    fclose(file);
}

// Function to save words to file from array
void saveWords(Word words[]) {
    FILE *file = fopen("words.txt", "w");
    if (file == NULL) {
        printf("Error saving words file.\n");
        exit(1);
    }

    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].english[0]!= '\0' && words[i].alien[0]!= '\0') {
            fprintf(file, "%s %s\n", words[i].english, words[i].alien);
        }
    }

    fclose(file);
}

// Function to translate sentence
void translateSentence(char sentence[], Word words[]) {
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        int index = -1;
        for (int i = 0; i < MAX_WORDS; i++) {
            if (strcmp(token, words[i].english) == 0) {
                index = i;
                break;
            }
        }

        if (index!= -1) {
            printf("%s ", words[index].alien);
        } else {
            printf("%s ", token);
        }

        token = strtok(NULL, " ");
    }

    printf("\n");
}

int main() {
    Word words[MAX_WORDS];
    loadWords(words);

    char sentence[1000];
    printf("Enter a sentence to translate:\n");
    fgets(sentence, sizeof(sentence), stdin);

    translateSentence(sentence, words);

    saveWords(words);

    return 0;
}