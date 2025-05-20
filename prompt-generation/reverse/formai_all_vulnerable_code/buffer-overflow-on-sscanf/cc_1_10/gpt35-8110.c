//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: protected
//Sentiment Analysis Tool in C

#include <stdio.h>
#include <string.h>

int main() {
    char input[1000], test[1000];
    int positive = 0, negative = 0, neutral = 0;

    //List of positive and negative words
    char positiveWords[5][50] = {"happy", "good", "great", "excellent", "love"};
    char negativeWords[5][50] = {"sad", "bad", "terrible", "awful", "hate"};

    printf("Enter your text for sentiment analysis: ");
    fgets(input, 1000, stdin);

    //Convert text to lowercase
    for (int i = 0; i < strlen(input); i++) {
        input[i] = tolower(input[i]);
    }

    //Tokenize input text
    char delimiters[] = " \n";
    char *retptr;
    retptr = strtok(input, delimiters);

    while (retptr != NULL) {
        sscanf(retptr, "%s", test);

        //Count positive, negative and neutral words
        for (int i = 0; i < 5; i++) {
            if (strcmp(test, positiveWords[i]) == 0) {
                positive++;
            } else if (strcmp(test, negativeWords[i]) == 0) {
                negative++;
            } else {
                neutral++;
            }
        }
        retptr = strtok(NULL, delimiters);
    }

    //Calculate sentiment score
    int sentimentScore = positive - negative;

    printf("\nSentiment analysis results:\n");
    printf("Positive words: %d\n", positive);
    printf("Negative words: %d\n", negative);
    printf("Neutral words: %d\n", neutral);

    if (sentimentScore > 0) {
        printf("\nSentiment score: %d (Positive)\n", sentimentScore);
    } else if (sentimentScore < 0) {
        printf("\nSentiment score: %d (Negative)\n", sentimentScore);
    } else {
        printf("\nSentiment score: %d (Neutral)\n", sentimentScore);
    }

    return 0;
}