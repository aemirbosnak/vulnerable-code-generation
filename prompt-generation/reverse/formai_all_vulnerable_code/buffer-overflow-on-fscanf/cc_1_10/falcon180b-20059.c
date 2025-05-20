//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SENTENCE_LENGTH 100
#define NUM_SENTIMENTS 3
#define NUM_WORDS_PER_SENTIMENT 5

struct sentiment_word {
    char word[10];
    int frequency;
};

struct sentiment {
    char name[10];
    struct sentiment_word words[NUM_WORDS_PER_SENTIMENT];
};

int main() {
    FILE *input_file;
    char sentence[MAX_SENTENCE_LENGTH];
    int num_sentences = 0;
    int num_words = 0;
    int total_sentiment_counts[NUM_SENTIMENTS] = {0};

    struct sentiment sentiments[NUM_SENTIMENTS] = {{"Happy", {"love", "joy", "smile", "laugh", "fun"}}};

    input_file = fopen("input.txt", "r");

    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    while (fscanf(input_file, "%s", sentence)!= EOF) {
        num_sentences++;
        num_words += strlen(sentence);

        int i;
        for (i = 0; i < NUM_SENTIMENTS; i++) {
            int j;
            for (j = 0; j < NUM_WORDS_PER_SENTIMENT; j++) {
                int k;
                for (k = 0; k < strlen(sentence); k++) {
                    if (tolower(sentence[k]) == tolower(sentiments[i].words[j].word[k])) {
                        total_sentiment_counts[i]++;
                    }
                }
            }
        }
    }

    fclose(input_file);

    printf("Number of sentences: %d\n", num_sentences);
    printf("Number of words: %d\n", num_words);

    int max_sentiment_count = 0;
    int max_sentiment_index = -1;

    for (int i = 0; i < NUM_SENTIMENTS; i++) {
        if (total_sentiment_counts[i] > max_sentiment_count) {
            max_sentiment_count = total_sentiment_counts[i];
            max_sentiment_index = i;
        }
    }

    printf("Dominant sentiment: %s\n", sentiments[max_sentiment_index].name);

    return 0;
}