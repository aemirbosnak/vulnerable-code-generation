//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int score;
} WordScore;

WordScore positiveWords[MAX_WORDS] = {
    {"good", 1}, {"happy", 1}, {"great", 1}, {"excellent", 1}, {"love", 1},
    {"fantastic", 1}, {"amazing", 1}, {"wonderful", 1}, {"joy", 1}, {"success", 1}
};

WordScore negativeWords[MAX_WORDS] = {
    {"bad", -1}, {"sad", -1}, {"terrible", -1}, {"hate", -1}, {"awful", -1},
    {"horrible", -1}, {"disappointing", -1}, {"worst", -1}, {"angry", -1}, {"failure", -1}
};

int analyzeSentiment(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        return 0;
    }

    char word[MAX_WORD_LENGTH];
    int totalScore = 0;

    while (fscanf(file, "%s", word) != EOF) {
        for (int i = 0; i < sizeof(positiveWords) / sizeof(WordScore); i++) {
            if (strcasecmp(word, positiveWords[i].word) == 0) {
                totalScore += positiveWords[i].score;
                break;
            }
        }
        for (int i = 0; i < sizeof(negativeWords) / sizeof(WordScore); i++) {
            if (strcasecmp(word, negativeWords[i].word) == 0) {
                totalScore += negativeWords[i].score;
                break;
            }
        }
    }

    fclose(file);
    return totalScore;
}

void displaySentiment(int score) {
    if (score > 0) {
        printf("Overall sentiment: Positive (Score: %d)\n", score);
    } else if (score < 0) {
        printf("Overall sentiment: Negative (Score: %d)\n", score);
    } else {
        printf("Overall sentiment: Neutral (Score: %d)\n", score);
    }
}

int main() {
    char filename[MAX_WORD_LENGTH];
    
    printf("Welcome to the Sentiment Analysis Tool!\n");
    printf("Please enter the name of the text file you wish to analyze: ");
    
    scanf("%s", filename);
    int sentimentScore = analyzeSentiment(filename);
    displaySentiment(sentimentScore);
    
    return 0;
}