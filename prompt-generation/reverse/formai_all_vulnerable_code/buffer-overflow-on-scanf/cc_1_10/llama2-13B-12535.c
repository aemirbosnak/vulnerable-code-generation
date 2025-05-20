//LLAMA2-13B DATASET v1.0 Category: Word Count Tool ; Style: complex
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WORD_COUNT_MAX 100000
#define WORD_COUNT_INC 1000

struct word_count {
    int count;
    char *word;
};

void init_word_count(struct word_count *word_counts, int max_words) {
    int i;
    for (i = 0; i < max_words; i++) {
        word_counts[i].count = 0;
        word_counts[i].word = NULL;
    }
}

void add_word(struct word_count *word_counts, char *word) {
    int i;
    for (i = 0; i < WORD_COUNT_MAX; i++) {
        if (word_counts[i].count < WORD_COUNT_INC) {
            if (strcmp(word, word_counts[i].word) == 0) {
                word_counts[i].count++;
                return;
            }
        }
    }
    // If we reach here, the word is not in the list, so add it
    word_counts[i].count = 1;
    word_counts[i].word = word;
}

void print_word_counts(struct word_count *word_counts, int max_words) {
    int i;
    for (i = 0; i < max_words; i++) {
        if (word_counts[i].count > 0) {
            printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
        }
    }
}

int main() {
    int num_words;
    char *words[10];
    struct word_count word_counts[10];

    // Read input from the user
    printf("Enter up to 10 words: ");
    scanf("%s", words);
    num_words = strlen(words);

    // Initialize word count array
    init_word_count(word_counts, num_words);

    // Add words to the word count array
    int i;
    for (i = 0; i < num_words; i++) {
        add_word(word_counts, words[i]);
    }

    // Print the word counts
    print_word_counts(word_counts, num_words);

    return 0;
}