//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: random
#include <stdio.h>
#include <string.h>

int main() {

    // Initialize dictionary of positive and negative words
    char positives[10][20] = {"happy", "love", "excited", "great", "fantastic", "amazing", "delightful", "excellent", "fun", "joyful"};
    char negatives[10][20] = {"sad", "hate", "disappointed", "terrible", "awful", "miserable", "dreadful", "bad", "horrible", "unhappy"};

    // Take user input
    char input[100];
    printf("Enter a sentence to analyze sentiment: ");
    fgets(input, 100, stdin);

    // Remove newline character from input
    int len = strlen(input);
    if (input[len-1] == '\n'){
        input[len-1] = '\0';
    }

    // Split input into separate words
    char *token = strtok(input, " ");
    int pos_count = 0;
    int neg_count = 0;
    while (token != NULL){

        // Check if word is positive or negative
        for (int i = 0; i < 10; i++){
            if (strcmp(token, positives[i]) == 0){
                pos_count++;
                break;
            } else if (strcmp(token, negatives[i]) == 0){
                neg_count++;
                break;
            }
        }
        token = strtok(NULL, " ");
    }

    // Determine overall sentiment of sentence
    char sentiment[20];
    if (pos_count > neg_count){
        strcpy(sentiment, "positive");
    } else if (pos_count < neg_count){
        strcpy(sentiment, "negative");
    } else {
        strcpy(sentiment, "neutral");
    }

    // Output results
    printf("The sentiment of the sentence is %s.\n", sentiment);
    printf("There were %d positive words and %d negative words in the sentence.\n", pos_count, neg_count);

    return 0;
}