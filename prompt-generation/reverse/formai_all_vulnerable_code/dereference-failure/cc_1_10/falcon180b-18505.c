//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_VOCABULARY_SIZE 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

typedef struct {
    WordFrequency *vocabulary;
    int vocabulary_size;
} Vocabulary;

void initialize_vocabulary(Vocabulary *vocabulary) {
    vocabulary->vocabulary = (WordFrequency *)malloc(MAX_VOCABULARY_SIZE * sizeof(WordFrequency));
    vocabulary->vocabulary_size = 0;
}

void add_word(Vocabulary *vocabulary, char *word) {
    if (vocabulary->vocabulary_size >= MAX_VOCABULARY_SIZE) {
        printf("Error: Vocabulary is full.\n");
        return;
    }

    WordFrequency *new_word = (WordFrequency *)malloc(sizeof(WordFrequency));
    strcpy(new_word->word, word);
    new_word->frequency = 1;

    vocabulary->vocabulary[vocabulary->vocabulary_size++] = *new_word;
}

int main() {
    FILE *input_file;
    char input_buffer[MAX_WORD_LENGTH];
    Vocabulary vocabulary;

    initialize_vocabulary(&vocabulary);

    input_file = fopen("input.txt", "r");

    if (input_file == NULL) {
        printf("Error: Input file not found.\n");
        return 1;
    }

    while (fscanf(input_file, "%s", input_buffer)!= EOF) {
        if (strlen(input_buffer) > MAX_WORD_LENGTH) {
            printf("Error: Word is too long.\n");
            continue;
        }

        input_buffer[strcspn(input_buffer, ",.?!;:\"'")] = '\0';

        if (isalpha(input_buffer[0])) {
            add_word(&vocabulary, input_buffer);
        }
    }

    fclose(input_file);

    printf("Vocabulary:\n");
    for (int i = 0; i < vocabulary.vocabulary_size; i++) {
        printf("%s %d\n", vocabulary.vocabulary[i].word, vocabulary.vocabulary[i].frequency);
    }

    return 0;
}