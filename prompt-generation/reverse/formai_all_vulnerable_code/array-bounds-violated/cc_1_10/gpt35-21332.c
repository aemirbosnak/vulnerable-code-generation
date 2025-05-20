//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to calculate sentiment score
int getSentimentScore(char *sentence) {
    int sentimentScore = 0;

    // List of positive words
    char positiveWords[10][20] = {"happy", "great", "love", "amazing", "awesome", "fantastic", "good", "excellent", "wonderful", "perfect"};

    // List of negative words
    char negativeWords[10][20] = {"sad", "angry", "bad", "terrible", "horrible", "awful", "disgusting", "worst", "cry", "regret"};

    // Tokenizing the sentence into words
    char *token = strtok(sentence, " ");

    // Loop through all words in sentence
    while(token != NULL) {
        // Check if word is positive
        for(int i=0; i<10; i++) {
            if(strcmp(token, positiveWords[i]) == 0) {
                sentimentScore++;
                break;
            }
        }

        // Check if word is negative
        for(int i=0; i<10; i++) {
            if(strcmp(token, negativeWords[i]) == 0) {
                sentimentScore--;
                break;
            }
        }

        // Move to next word
        token = strtok(NULL, " ");
    }

    return sentimentScore;
}

int main() {
    char sentence[100];

    // Getting input sentence from user
    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin);

    // Removing '\n' from end of sentence
    sentence[strlen(sentence) - 1] = '\0';

    // Calculating sentiment score
    int sentimentScore = getSentimentScore(sentence);

    // Displaying sentiment score
    printf("Sentiment Score: %d\n", sentimentScore);

    return 0;
}