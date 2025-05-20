//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 100
#define MAX_WORDS 50
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int score;
} WordSentiment;

WordSentiment sentiments[] = {
    {"happy", 2},
    {"joy", 2},
    {"great", 2},
    {"good", 1},
    {"okay", 0},
    {"bad", -1},
    {"sad", -2},
    {"awful", -2},
    {"hate", -3},
    {"love", 3}
};

int getSentimentScore(char *sentence) {
    int totalScore = 0;
    char *word;
    word = strtok(sentence, " ");
    
    while (word != NULL) {
        for (int i = 0; i < sizeof(sentiments) / sizeof(sentiments[0]); i++) {
            if (strcasecmp(word, sentiments[i].word) == 0) {
                totalScore += sentiments[i].score;
                break;
            }
        }
        word = strtok(NULL, " ");
    }

    return totalScore;
}

void analyzeSentences(char sentences[MAX_SENTENCES][MAX_WORD_LENGTH], int count) {
    for (int i = 0; i < count; ++i) {
        int score = getSentimentScore(sentences[i]);
        printf("Sentence: \"%s\" - Sentiment Score: %d\n", sentences[i], score);
        if (score > 0) {
            printf("Overall Sentiment: Positive\n");
        } else if (score < 0) {
            printf("Overall Sentiment: Negative\n");
        } else {
            printf("Overall Sentiment: Neutral\n");
        }
        printf("\n");
    }
}

void readSentences(char sentences[MAX_SENTENCES][MAX_WORD_LENGTH], int *count) {
    printf("Enter the number of sentences (max %d): ", MAX_SENTENCES);
    scanf("%d", count);
    getchar(); // Clear the newline character
    
    if (*count > MAX_SENTENCES) {
        printf("Exceeding maximum sentence count. Set to maximum %d.\n", MAX_SENTENCES);
        *count = MAX_SENTENCES;
    }

    for (int i = 0; i < *count; i++) {
        printf("Enter sentence %d: ", i + 1);
        fgets(sentences[i], MAX_WORD_LENGTH, stdin);
        sentences[i][strcspn(sentences[i], "\n")] = '\0'; // Remove newline
    }
}

int main() {
    char sentences[MAX_SENTENCES][MAX_WORD_LENGTH];
    int sentenceCount;

    readSentences(sentences, &sentenceCount);
    analyzeSentences(sentences, sentenceCount);

    return 0;
}