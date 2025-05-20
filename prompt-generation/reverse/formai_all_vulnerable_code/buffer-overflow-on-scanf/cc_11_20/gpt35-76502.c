//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];
    int positive_count = 0, negative_count = 0, neutral_count = 0;
    float sentiment_score = 0.0;

    printf("Welcome to the shape-shifting sentiment analysis tool!\n");
    printf("Please enter your text: ");
    scanf("%[^\n]", input);

    // convert input to lowercase
    for (int i = 0; input[i]; i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            input[i] = input[i] - 'A' + 'a';
        }
    }

    // split input into individual words
    char *word = strtok(input, " ");
    while (word != NULL) {
        // check for positive or negative words
        if (strcmp(word, "good") == 0 || strcmp(word, "great") == 0 || strcmp(word, "awesome") == 0) {
            positive_count++;
            sentiment_score += 0.5;
        }
        else if (strcmp(word, "bad") == 0 || strcmp(word, "terrible") == 0 || strcmp(word, "awful") == 0) {
            negative_count++;
            sentiment_score -= 0.5;
        }
        else {
            neutral_count++;
        }
        // move on to next word
        word = strtok(NULL, " ");
    }

    // determine overall sentiment
    if (sentiment_score > 0) {
        printf("\nThis text has a positive sentiment!\n");
    }
    else if (sentiment_score < 0) {
        printf("\nThis text has a negative sentiment.\n");
    }
    else {
        printf("\nThis text has a neutral sentiment.\n");
    }

    // display statistics
    printf("\nPositive words: %d\n", positive_count);
    printf("Negative words: %d\n", negative_count);
    printf("Neutral words: %d\n", neutral_count);

    return 0;
}