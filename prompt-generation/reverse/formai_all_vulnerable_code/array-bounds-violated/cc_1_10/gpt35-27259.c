//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_SENTENCE 100

void printSentiment(double score) {
    if (score > 0.5) {
        printf("Wow! That's really positive! Your score is %.2lf\n", score);
    } else if (score > 0.2) {
        printf("This seems positive to me. Your score is %.2lf\n", score);
    } else if (score > -0.2) {
        printf("This sentence is neutral. Your score is %.2lf\n", score);
    } else if (score > -0.5) {
        printf("This seems negative to me. Your score is %.2lf\n", score);
    } else {
        printf("Oh dear, this is really negative. Your score is %.2lf\n", score);
    }
}

double getSentimentScore(char* sentence) {
    double score = 0;
    int countWords = 0;
    int i, j;
    char word[MAX_SENTENCE];
    char* feelings[] = {"amazing", "fantastic", "great", "good", "happy", "love", "positive", "excellent"};
    char* antiFeelings[] = {"awful", "poor", "negative", "horrible", "terrible", "hate", "disgusting", "bad"};

    for (i = 0; sentence[i] != '\0'; i++) {
        if (isspace(sentence[i])) {
            word[j] = '\0';
            j = 0;
            for (int k = 0; k < 8; k++) {
                if (strcmp(word, feelings[k]) == 0)
                    score += 0.3;
                if (strcmp(word, antiFeelings[k]) == 0)
                    score -= 0.3;
            }
            countWords++;
        } else {
            word[j++] = sentence[i];
        }
    }

    word[j] = '\0';
    for (int k = 0; k < 8; k++) {
        if (strcmp(word, feelings[k]) == 0)
            score += 0.3;
        if (strcmp(word, antiFeelings[k]) == 0)
            score -= 0.3;
    }
    countWords++;

    return score / (double) countWords;
}

int main() {
    char sentence[MAX_SENTENCE];

    printf("Welcome to the Retro Sentiment Analysis Tool\n");
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE, stdin);

    sentence[strcspn(sentence, "\n")] = '\0';
    double score = getSentimentScore(sentence);
    printSentiment(score);

    return 0;
}