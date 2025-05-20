//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to find the sentiment score based on input string
int findSentiment(char *input) {
    int score = 0;
    char *token;

    // array of positive and negative words
    char pos_words[][20] = {"good", "great", "love", "happy", "excited", "wonderful", "fantastic"};
    char neg_words[][20] = {"bad", "poor", "hate", "sad", "angry", "terrible", "awful"};

    token = strtok(input, " ");

    // iterate through each word in the input string
    while (token != NULL) {
        // compare the word with positive and negative words array and update the sentiment score accordingly
        for (int i = 0; i < 7; i++) {
            if (strcmp(pos_words[i], token) == 0) {
                score++;
            } else if (strcmp(neg_words[i], token) == 0) {
                score--;
            }
        }

        token = strtok(NULL, " ");
    }

    return score;
}

int main() {
    char input[100];
    int score;

    printf("Welcome to the Sentiment Analysis Tool!\n");
    printf("Enter the string you want to analyze: ");
    gets(input);

    score = findSentiment(input);

    // positive sentiment score
    if (score > 2) {
        printf("Amazing! The sentiment score is %d. This is a highly positive statement.\n", score);
    } 
    // slightly positive sentiment score
    else if (score > 0) {
        printf("Great! The sentiment score is %d. This is a positive statement.\n", score);
    } 
    // neutral sentiment score
    else if (score == 0) {
        printf("The sentiment score is %d. This is a neutral statement.\n", score);
    } 
    // slightly negative sentiment score
    else if (score < 0 && score >= -2) {
        printf("Hmm. The sentiment score is %d. This is a slightly negative statement.\n", score);
    } 
    // highly negative sentiment score
    else {
        printf("Oh no. The sentiment score is %d. This is a highly negative statement.\n", score);
    }

    return 0;
}