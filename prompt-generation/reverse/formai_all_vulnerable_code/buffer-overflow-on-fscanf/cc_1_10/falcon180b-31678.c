//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50
#define MIN_WORD_LENGTH 3
#define POSITIVE_THRESHOLD 0.75
#define NEGATIVE_THRESHOLD -0.75

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

struct sentiment_analysis {
    int positive_count;
    int negative_count;
    int neutral_count;
};

void read_words(struct word_count words[], int num_words) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open words file.\n");
        exit(1);
    }

    int i = 0;
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (strlen(word) >= MIN_WORD_LENGTH && strlen(word) <= MAX_WORD_LENGTH) {
            strcpy(words[i].word, word);
            words[i].count = 0;
            i++;
        }
    }

    fclose(file);
}

void analyze_sentiment(struct word_count words[], int num_words, struct sentiment_analysis *result) {
    int i;
    for (i = 0; i < num_words; i++) {
        if (words[i].count > 0) {
            if (words[i].count > POSITIVE_THRESHOLD) {
                result->positive_count++;
            } else if (words[i].count < NEGATIVE_THRESHOLD) {
                result->negative_count++;
            } else {
                result->neutral_count++;
            }
        }
    }
}

void print_results(struct sentiment_analysis result) {
    printf("Positive: %d\n", result.positive_count);
    printf("Negative: %d\n", result.negative_count);
    printf("Neutral: %d\n", result.neutral_count);
}

int main() {
    int num_words = 0;
    struct word_count words[MAX_WORDS];
    read_words(words, &num_words);

    struct sentiment_analysis result;
    analyze_sentiment(words, num_words, &result);

    print_results(result);

    return 0;
}