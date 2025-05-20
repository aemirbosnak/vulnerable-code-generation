//Falcon-180B DATASET v1.0 Category: Text processing ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTENCE_LENGTH 1000
#define MAX_NUM_WORDS 1000

typedef struct {
    char *word;
    int count;
} WordFrequency;

void process_sentence(char *sentence, WordFrequency *word_frequencies, int num_words) {
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(token, word_frequencies[i].word) == 0) {
                word_frequencies[i].count++;
                break;
            }
        }
        if (i == num_words) {
            if (num_words >= MAX_NUM_WORDS) {
                printf("Error: too many unique words.\n");
                exit(1);
            }
            word_frequencies[num_words].word = strdup(token);
            word_frequencies[num_words].count = 1;
            num_words++;
        }
        token = strtok(NULL, " ");
    }
}

void print_word_frequencies(WordFrequency *word_frequencies, int num_words) {
    printf("Word frequencies:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_frequencies[i].word, word_frequencies[i].count);
    }
}

int main() {
    char input_text[MAX_SENTENCE_LENGTH];
    printf("Enter some text:\n");
    fgets(input_text, MAX_SENTENCE_LENGTH, stdin);
    int num_words = 0;
    WordFrequency *word_frequencies = malloc(sizeof(WordFrequency) * MAX_NUM_WORDS);
    char *token = strtok(input_text, " ");
    while (token!= NULL) {
        if (num_words >= MAX_NUM_WORDS) {
            printf("Error: too many words in input text.\n");
            exit(1);
        }
        if (strlen(token) > MAX_WORD_LENGTH) {
            printf("Error: word '%s' is too long.\n", token);
            exit(1);
        }
        word_frequencies[num_words].word = strdup(token);
        word_frequencies[num_words].count = 1;
        num_words++;
        token = strtok(NULL, " ");
    }
    process_sentence(input_text, word_frequencies, num_words);
    print_word_frequencies(word_frequencies, num_words);
    free(word_frequencies);
    return 0;
}