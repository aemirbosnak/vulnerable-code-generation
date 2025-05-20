//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *word;
    int score;
} Sentiment;

#define SENTIMENT_SIZE 100

Sentiment sentiments[SENTIMENT_SIZE];

int load_sentiments(char *filename) {
    FILE *fp;
    int i;

    if ((fp = fopen(filename, "r")) == NULL) {
        perror("fopen");
        return -1;
    }

    for (i = 0; i < SENTIMENT_SIZE; i++) {
        if (fscanf(fp, "%s %d", sentiments[i].word, &sentiments[i].score) != 2) {
            break;
        }
    }

    fclose(fp);

    return i;
}

int analyze_sentiment(char *text) {
    int score;
    int i;

    score = 0;

    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            text[i] = tolower(text[i]);

            for (int j = 0; j < SENTIMENT_SIZE; j++) {
                if (strcmp(text + i, sentiments[j].word) == 0) {
                    score += sentiments[j].score;
                    break;
                }
            }
        }
    }

    return score;
}

int main() {
    char text[1024];
    int score;

    if (load_sentiments("sentiments.txt") < 0) {
        return -1;
    }

    printf("Enter text to analyze: ");
    gets(text);

    score = analyze_sentiment(text);

    if (score > 0) {
        printf("Positive sentiment\n");
    } else if (score < 0) {
        printf("Negative sentiment\n");
    } else {
        printf("Neutral sentiment\n");
    }

    return 0;
}