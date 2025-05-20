//Code Llama-13B DATASET v1.0 Category: Spam Detection System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WORD_LEN 100
#define MAX_SENTENCE_LEN 1000

typedef struct {
    char *word;
    int count;
} WordCount;

typedef struct {
    WordCount *word_counts;
    int num_words;
} WordFrequency;

WordFrequency *get_word_frequency(char *sentence) {
    WordFrequency *word_freq = malloc(sizeof(WordFrequency));
    word_freq->num_words = 0;
    word_freq->word_counts = NULL;

    char *word = strtok(sentence, " ");
    while (word != NULL) {
        word_freq->num_words++;
        word_freq->word_counts = realloc(word_freq->word_counts, word_freq->num_words * sizeof(WordCount));
        word_freq->word_counts[word_freq->num_words - 1].word = word;
        word_freq->word_counts[word_freq->num_words - 1].count = 1;
        word = strtok(NULL, " ");
    }

    return word_freq;
}

void free_word_frequency(WordFrequency *word_freq) {
    free(word_freq->word_counts);
    free(word_freq);
}

double calculate_spam_score(WordFrequency *word_freq) {
    double score = 0.0;
    for (int i = 0; i < word_freq->num_words; i++) {
        score += word_freq->word_counts[i].count * log(word_freq->word_counts[i].count);
    }
    return score;
}

void print_spam_score(double spam_score) {
    printf("Spam score: %f\n", spam_score);
}

int main() {
    char sentence[MAX_SENTENCE_LEN];
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LEN, stdin);

    WordFrequency *word_freq = get_word_frequency(sentence);
    double spam_score = calculate_spam_score(word_freq);
    print_spam_score(spam_score);

    free_word_frequency(word_freq);
    return 0;
}