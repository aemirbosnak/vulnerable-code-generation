//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to tokenize a sentence
void tokenize(char* sentence, char* tokens[]) {
    int i = 0;
    char* token = strtok(sentence, " ");
    while (token!= NULL) {
        tokens[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    tokens[i] = NULL;
}

// Function to calculate the sentiment score of a sentence
int calculateSentimentScore(char* sentence) {
    int score = 0;
    char* tokens[100];
    tokenize(sentence, tokens);

    // Loop through each token and check if it is a positive or negative word
    for (int i = 0; tokens[i]!= NULL; i++) {
        char* word = tokens[i];
        if (strcmp(word, "happy") == 0 || strcmp(word, "joy") == 0 || strcmp(word, "love") == 0) {
            score++;
        } else if (strcmp(word, "sad") == 0 || strcmp(word, "anger") == 0 || strcmp(word, "hate") == 0) {
            score--;
        }
    }

    return score;
}

int main() {
    char sentence[100];

    // Get user input
    printf("Enter a sentence: ");
    scanf("%s", sentence);

    // Calculate the sentiment score
    int score = calculateSentimentScore(sentence);

    // Print the sentiment analysis result
    if (score > 0) {
        printf("The sentence is positive.\n");
    } else if (score < 0) {
        printf("The sentence is negative.\n");
    } else {
        printf("The sentence is neutral.\n");
    }

    return 0;
}