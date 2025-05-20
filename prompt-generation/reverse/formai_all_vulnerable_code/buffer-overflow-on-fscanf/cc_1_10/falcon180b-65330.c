//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_SENTENCE_LENGTH 1000
#define NUM_SENTIMENTS 6
#define SENTIMENT_FILE "sentiments.txt"

typedef struct {
    char *word;
    int score;
} SentimentWord;

SentimentWord sentiments[NUM_SENTIMENTS][100];

void loadSentiments() {
    FILE *file = fopen(SENTIMENT_FILE, "r");

    if (file == NULL) {
        printf("Error loading sentiment file.\n");
        exit(1);
    }

    int sentimentIndex = 0;

    while (fscanf(file, "%s %d\n", sentiments[sentimentIndex][0].word, &sentiments[sentimentIndex][0].score)!= EOF) {
        sentimentIndex++;
    }

    fclose(file);
}

int analyzeSentiment(char *sentence) {
    int totalScore = 0;

    char *word = strtok(sentence, " ");

    while (word!= NULL) {
        int i;
        for (i = 0; i < NUM_SENTIMENTS; i++) {
            int j;
            for (j = 0; j < 100 && sentiments[i][j].word!= NULL; j++) {
                if (strcmp(word, sentiments[i][j].word) == 0) {
                    totalScore += sentiments[i][j].score;
                    break;
                }
            }
        }

        word = strtok(NULL, " ");
    }

    return totalScore;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <sentence>\n", argv[0]);
        exit(1);
    }

    loadSentiments();

    char *sentence = argv[1];
    int length = strlen(sentence);

    if (length > MAX_SENTENCE_LENGTH) {
        printf("Sentence is too long.\n");
        exit(1);
    }

    int score = analyzeSentiment(sentence);

    if (score > 0) {
        printf("Positive sentiment.\n");
    } else if (score < 0) {
        printf("Negative sentiment.\n");
    } else {
        printf("Neutral sentiment.\n");
    }

    return 0;
}