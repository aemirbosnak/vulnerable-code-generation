//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

char input_sentence[MAX_SENTENCE_LENGTH];
char *token;
int sentence_length;
int word_count;
WordFrequency *word_frequency_table;

void initialize_word_frequency_table() {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        word_frequency_table[i].word[0] = '\0';
        word_frequency_table[i].count = 0;
    }
}

void add_word_to_frequency_table(char *word) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (strcmp(word, word_frequency_table[i].word) == 0) {
            word_frequency_table[i].count++;
            return;
        }
    }
    strcpy(word_frequency_table[word_count].word, word);
    word_frequency_table[word_count].count = 1;
    word_count++;
}

int main() {
    initialize_word_frequency_table();
    printf("Enter a sentence: ");
    fgets(input_sentence, MAX_SENTENCE_LENGTH, stdin);
    sentence_length = strlen(input_sentence);
    token = strtok(input_sentence, " ");
    while (token!= NULL) {
        if (strlen(token) > MAX_WORD_LENGTH) {
            printf("Error: Word is too long.\n");
            exit(1);
        }
        add_word_to_frequency_table(token);
        token = strtok(NULL, " ");
    }
    return 0;
}