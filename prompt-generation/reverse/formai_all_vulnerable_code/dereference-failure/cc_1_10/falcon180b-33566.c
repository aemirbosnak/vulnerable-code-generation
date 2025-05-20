//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20
#define ALIEN_VOCABULARY_SIZE 100

typedef struct {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
} Vocabulary;

Vocabulary vocabulary[ALIEN_VOCABULARY_SIZE];
int vocabulary_size = 0;

void load_vocabulary(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening vocabulary file\n");
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, fp)!= NULL) {
        char* english_word = strtok(line, " ");
        char* alien_word = strtok(NULL, " ");

        strcpy(vocabulary[vocabulary_size].english, english_word);
        strcpy(vocabulary[vocabulary_size].alien, alien_word);

        vocabulary_size++;
    }

    fclose(fp);
}

void translate_sentence(char* sentence) {
    int i = 0;
    char word[MAX_WORD_LENGTH];

    while ((word[0] = sentence[i])!= '\0') {
        i++;

        word[i] = '\0';
        int is_english = 1;

        for (int j = 0; j < strlen(word); j++) {
            if (!isalpha(word[j])) {
                is_english = 0;
                break;
            }
        }

        if (is_english) {
            for (int j = 0; j < vocabulary_size; j++) {
                if (strcmp(vocabulary[j].english, word) == 0) {
                    printf("%s ", vocabulary[j].alien);
                    break;
                }
            }
        } else {
            printf("%s ", word);
        }
    }

    printf("\n");
}

int main() {
    load_vocabulary("vocabulary.txt");

    char sentence[MAX_WORDS][MAX_WORD_LENGTH];
    int sentence_length = 0;

    printf("Enter a sentence to translate:\n");
    fgets(sentence[sentence_length], MAX_WORD_LENGTH, stdin);

    while (sentence_length < MAX_WORDS - 1 && sentence[sentence_length][0]!= '\0') {
        sentence_length++;
        printf("Enter another word:\n");
        fgets(sentence[sentence_length], MAX_WORD_LENGTH, stdin);
    }

    sentence[sentence_length][0] = '\0';

    translate_sentence(sentence[0]);

    return 0;
}