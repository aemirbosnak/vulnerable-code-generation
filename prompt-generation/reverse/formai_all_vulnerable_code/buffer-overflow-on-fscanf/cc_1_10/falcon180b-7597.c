//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 1000
#define NUM_SENTIMENTS 6
#define SENTIMENT_FILE "sentiments.txt"

typedef struct {
    char *sentiment;
    int count;
} Sentiment;

Sentiment sentiments[NUM_SENTIMENTS];
char input_buffer[MAX_SENTENCE_LENGTH];

void load_sentiments() {
    FILE *fp = fopen(SENTIMENT_FILE, "r");
    if (fp == NULL) {
        printf("Error: could not open %s\n", SENTIMENT_FILE);
        exit(1);
    }

    for (int i = 0; i < NUM_SENTIMENTS; i++) {
        char sentiment_buffer[MAX_SENTENCE_LENGTH];
        if (fscanf(fp, "%s\n", sentiment_buffer)!= 1) {
            printf("Error: invalid sentiment in %s\n", SENTIMENT_FILE);
            exit(1);
        }
        sentiments[i].sentiment = strdup(sentiment_buffer);
        sentiments[i].count = 0;
    }

    fclose(fp);
}

void analyze_sentiment(char *sentence) {
    int max_count = 0;
    int max_index = -1;

    for (int i = 0; i < NUM_SENTIMENTS; i++) {
        int count = 0;
        char *token = strtok(sentence, " ");
        while (token!= NULL) {
            if (strcmp(token, sentiments[i].sentiment) == 0) {
                count++;
            }
            token = strtok(NULL, " ");
        }
        if (count > max_count) {
            max_count = count;
            max_index = i;
        }
    }

    if (max_count > 0) {
        printf("Sentiment: %s\n", sentiments[max_index].sentiment);
    } else {
        printf("Sentiment: neutral\n");
    }
}

int main() {
    load_sentiments();

    while (1) {
        printf("Enter a sentence: ");
        fgets(input_buffer, MAX_SENTENCE_LENGTH, stdin);
        input_buffer[strcspn(input_buffer, "\n")] = '\0';

        analyze_sentiment(input_buffer);
    }

    return 0;
}