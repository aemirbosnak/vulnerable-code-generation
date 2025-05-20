//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOCABULARY_SIZE 10000
#define MAX_WORD_LENGTH 20

typedef struct {
    char *english;
    char *alien;
} Vocabulary;

Vocabulary vocabulary[MAX_VOCABULARY_SIZE];
int vocabulary_size = 0;

char *translate_word(char *word) {
    int i;
    for (i = 0; i < vocabulary_size; i++) {
        if (strcmp(word, vocabulary[i].english) == 0) {
            return vocabulary[i].alien;
        }
    }
    return word;
}

char *translate_sentence(char *sentence) {
    char *translated_sentence = malloc(strlen(sentence) + 1);
    char *word = strtok(sentence, " ");
    while (word!= NULL) {
        char *translated_word = translate_word(word);
        strcat(translated_sentence, translated_word);
        strcat(translated_sentence, " ");
        word = strtok(NULL, " ");
    }
    return translated_sentence;
}

int main() {
    int choice;
    while (1) {
        printf("1. Add word\n2. Translate sentence\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                char *english_word;
                char *alien_word;
                printf("Enter English word: ");
                scanf("%s", english_word);
                printf("Enter Alien word: ");
                scanf("%s", alien_word);
                if (vocabulary_size >= MAX_VOCABULARY_SIZE) {
                    printf("Vocabulary is full.\n");
                } else {
                    vocabulary[vocabulary_size].english = strdup(english_word);
                    vocabulary[vocabulary_size].alien = strdup(alien_word);
                    vocabulary_size++;
                }
                break;
            }
            case 2: {
                char *sentence;
                printf("Enter sentence: ");
                scanf("%s", sentence);
                char *translated_sentence = translate_sentence(sentence);
                printf("Translated sentence: %s\n", translated_sentence);
                free(translated_sentence);
                break;
            }
            case 3: {
                exit(0);
            }
            default: {
                printf("Invalid choice.\n");
            }
        }
    }
    return 0;
}