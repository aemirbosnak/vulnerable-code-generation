//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 20
#define MAX_SENTENCES 1000
#define MAX_WORDS 5000

typedef struct {
    char *word;
    int count;
} WordCount;

typedef struct {
    WordCount *word_counts;
    int num_words;
} Sentiment;

Sentiment *initialize_sentiment() {
    Sentiment *sentiment = (Sentiment *)malloc(sizeof(Sentiment));
    sentiment->word_counts = (WordCount *)malloc(MAX_WORDS * sizeof(WordCount));
    sentiment->num_words = 0;
    return sentiment;
}

void add_word(Sentiment *sentiment, char *word) {
    int i;
    for (i = 0; i < sentiment->num_words; i++) {
        if (strcmp(sentiment->word_counts[i].word, word) == 0) {
            sentiment->word_counts[i].count++;
            return;
        }
    }
    if (sentiment->num_words >= MAX_WORDS) {
        printf("Error: Maximum number of words exceeded.\n");
        exit(1);
    }
    sentiment->word_counts[sentiment->num_words].word = strdup(word);
    sentiment->word_counts[sentiment->num_words].count = 1;
    sentiment->num_words++;
}

void print_word_counts(Sentiment *sentiment) {
    int i;
    for (i = 0; i < sentiment->num_words; i++) {
        printf("%s: %d\n", sentiment->word_counts[i].word, sentiment->word_counts[i].count);
    }
}

int main() {
    char input[MAX_SENTENCES][MAX_WORD_LENGTH];
    int num_sentences = 0;

    Sentiment *sentiment = initialize_sentiment();

    char *word;
    while (fgets(input[num_sentences], MAX_WORD_LENGTH, stdin)!= NULL) {
        word = strtok(input[num_sentences], " ");
        while (word!= NULL) {
            add_word(sentiment, word);
            word = strtok(NULL, " ");
        }
        num_sentences++;
    }

    print_word_counts(sentiment);

    return 0;
}