//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char *word;
    int frequency;
} WordFrequency;

void init_word_frequency(WordFrequency *wf) {
    wf->word = (char *)malloc(MAX_WORD_LENGTH * sizeof(char));
    wf->frequency = 0;
}

void free_word_frequency(WordFrequency *wf) {
    free(wf->word);
}

void process_word(char *word, WordFrequency *wf) {
    wf->frequency++;
}

void print_word_frequency(WordFrequency *wf) {
    printf("%s: %d\n", wf->word, wf->frequency);
}

int main() {
    char input_text[MAX_WORDS * MAX_WORD_LENGTH];
    int input_length = 0;
    int word_count = 0;
    WordFrequency *word_frequency = (WordFrequency *)malloc(MAX_WORDS * sizeof(WordFrequency));

    printf("Enter the text to analyze: ");
    fgets(input_text, MAX_WORDS * MAX_WORD_LENGTH, stdin);
    input_length = strlen(input_text);

    char *word = (char *)malloc(MAX_WORD_LENGTH * sizeof(char));
    char *delimiter = " ";
    char *token = strtok(input_text, delimiter);

    while (token!= NULL) {
        strcpy(word, token);
        process_word(word, word_frequency);
        token = strtok(NULL, delimiter);
        word_count++;
    }

    printf("Word frequency:\n");
    for (int i = 0; i < word_count; i++) {
        print_word_frequency(word_frequency + i);
    }

    free(input_text);
    free(word);
    free(word_frequency);

    return 0;
}