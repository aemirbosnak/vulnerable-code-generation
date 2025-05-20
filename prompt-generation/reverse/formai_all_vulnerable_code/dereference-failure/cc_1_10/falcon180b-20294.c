//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SENTENCE_LENGTH 1000
#define POSITIVE_THRESHOLD 0.05
#define NEGATIVE_THRESHOLD -0.05

typedef struct {
    char *word;
    int count;
} WordFrequency;

int compare_word_frequency(const void *a, const void *b) {
    WordFrequency *freq_a = (WordFrequency *)a;
    WordFrequency *freq_b = (WordFrequency *)b;

    if (freq_a->count > freq_b->count) {
        return -1;
    } else if (freq_a->count < freq_b->count) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char text[MAX_SENTENCE_LENGTH];
    WordFrequency *frequencies = NULL;
    int num_words = 0;

    printf("Enter a sentence: ");
    fgets(text, MAX_SENTENCE_LENGTH, stdin);

    char *token = strtok(text, " ");
    while (token!= NULL) {
        frequencies = realloc(frequencies, sizeof(WordFrequency) * ++num_words);
        frequencies[num_words - 1].word = token;
        frequencies[num_words - 1].count = 1;

        token = strtok(NULL, " ");
    }

    qsort(frequencies, num_words, sizeof(WordFrequency), compare_word_frequency);

    printf("Word frequencies:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", frequencies[i].word, frequencies[i].count);
    }

    free(frequencies);
    return 0;
}