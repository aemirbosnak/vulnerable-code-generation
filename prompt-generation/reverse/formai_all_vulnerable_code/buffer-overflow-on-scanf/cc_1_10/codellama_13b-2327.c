//Code Llama-13B DATASET v1.0 Category: Typing Speed Test ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_INPUT_LEN 256
#define MAX_WORD_LEN 16
#define NUM_WORDS 10

typedef struct {
    char word[MAX_WORD_LEN];
    int time_taken;
} Word;

void shuffle_words(Word words[]) {
    for (int i = 0; i < NUM_WORDS; i++) {
        int random_index = rand() % NUM_WORDS;
        Word temp = words[i];
        words[i] = words[random_index];
        words[random_index] = temp;
    }
}

int main() {
    Word words[NUM_WORDS];
    for (int i = 0; i < NUM_WORDS; i++) {
        char word[MAX_WORD_LEN];
        printf("Enter a word: ");
        scanf("%s", word);
        strcpy(words[i].word, word);
    }

    shuffle_words(words);

    int total_time_taken = 0;
    for (int i = 0; i < NUM_WORDS; i++) {
        char input[MAX_INPUT_LEN];
        printf("Enter the word: ");
        scanf("%s", input);
        if (strcmp(input, words[i].word) == 0) {
            words[i].time_taken = 0;
        } else {
            words[i].time_taken = 100;
        }
        total_time_taken += words[i].time_taken;
    }

    printf("Your time taken: %d\n", total_time_taken);

    return 0;
}