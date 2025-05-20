//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_LENGTH 256
#define POSITIVE_WORDS "positive.txt"
#define NEGATIVE_WORDS "negative.txt"

typedef struct {
    char word[MAX_LENGTH];
    int count;
} WordCount;

WordCount word_counts[MAX_WORDS];
int total_words = 0;

void load_sentiment_words(const char *filename, int sentiment) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening sentiment file");
        return;
    }

    char word[MAX_LENGTH];
    while (fscanf(file, "%s", word) != EOF) {
        for (int i = 0; word[i]; i++) {
            word[i] = tolower(word[i]);
        }

        int found = 0;
        for (int i = 0; i < total_words; i++) {
            if (strcmp(word_counts[i].word, word) == 0) {
                word_counts[i].count += sentiment;
                found = 1;
                break;
            }
        }

        if (!found && total_words < MAX_WORDS) {
            strcpy(word_counts[total_words].word, word);
            word_counts[total_words].count = sentiment;
            total_words++;
        }
    }
    fclose(file);
}

void analyze_text(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening text file");
        return;
    }

    char line[MAX_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        char *word = strtok(line, " \n");
        while (word != NULL) {
            for (int i = 0; word[i]; i++) {
                word[i] = tolower(word[i]);
            }

            for (int i = 0; i < total_words; i++) {
                if (strcmp(word_counts[i].word, word) == 0) {
                    word_counts[i].count += 1;
                    break;
                }
            }
            word = strtok(NULL, " \n");
        }
    }
    fclose(file);
}

void print_sentiment_analysis() {
    int pos_score = 0, neg_score = 0;
    for (int i = 0; i < total_words; i++) {
        if (word_counts[i].count > 0) {
            pos_score += word_counts[i].count;
        } else if (word_counts[i].count < 0) {
            neg_score += -word_counts[i].count;
        }
    }

    printf("Sentiment Analysis Results:\n");
    printf("Total Positive Words: %d\n", pos_score);
    printf("Total Negative Words: %d\n", neg_score);

    if (pos_score > neg_score) {
        printf("Overall Sentiment: Positive\n");
    } else if (neg_score > pos_score) {
        printf("Overall Sentiment: Negative\n");
    } else {
        printf("Overall Sentiment: Neutral\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <text_file>\n", argv[0]);
        return 1;
    }

    load_sentiment_words(POSITIVE_WORDS, 1);
    load_sentiment_words(NEGATIVE_WORDS, -1);

    analyze_text(argv[1]);

    print_sentiment_analysis();

    return 0;
}