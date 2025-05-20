//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20
#define ALIEN_VOCABULARY_SIZE 100
#define ALIEN_WORD_LENGTH 10

typedef struct {
    char english[MAX_WORD_LENGTH];
    char alien[ALIEN_WORD_LENGTH];
} word_t;

void load_vocabulary(word_t vocabulary[], int size) {
    FILE *file = fopen("vocabulary.txt", "r");
    if (file == NULL) {
        printf("Error: Failed to open vocabulary file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s", vocabulary[count].english, vocabulary[count].alien)!= EOF) {
        count++;
    }

    if (count!= size) {
        printf("Error: Vocabulary file contains incorrect number of entries.\n");
        exit(1);
    }

    fclose(file);
}

int main() {
    char input_string[MAX_WORD_LENGTH];
    char output_string[MAX_WORD_LENGTH];
    word_t vocabulary[ALIEN_VOCABULARY_SIZE];

    load_vocabulary(vocabulary, ALIEN_VOCABULARY_SIZE);

    printf("Enter a sentence to translate:\n");
    fgets(input_string, MAX_WORD_LENGTH, stdin);

    int word_count = 0;
    char *token = strtok(input_string, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < ALIEN_VOCABULARY_SIZE; i++) {
            if (strcmp(token, vocabulary[i].english) == 0) {
                strcpy(output_string, vocabulary[i].alien);
                break;
            }
        }

        if (i == ALIEN_VOCABULARY_SIZE) {
            strcpy(output_string, "UNKNOWN");
        }

        printf("%s ", output_string);
        word_count++;

        if (word_count >= MAX_WORDS) {
            printf("Too many words in sentence.\n");
            return 1;
        }

        token = strtok(NULL, " ");
    }

    printf("\n");
    return 0;
}