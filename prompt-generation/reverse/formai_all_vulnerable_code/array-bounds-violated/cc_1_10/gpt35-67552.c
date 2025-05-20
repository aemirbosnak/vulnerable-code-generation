//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: dynamic
#include <stdio.h>
#include <string.h>

/* Function to determine sentiment of the given input */
void sentiment_analysis(char input[]) {
    int positive_words_count = 0, negative_words_count = 0;
    char *positive_words[] = { "best", "good", "great", "excellent", "awesome" };
    char *negative_words[] = { "worst", "bad", "awful", "terrible", "horrible" };
    int i, j;
    char *token = strtok(input, ".,!? ");

    while (token != NULL) {
        /* Checking if token is in positive words list */
        for (i = 0; i < 5; i++) {
            if (strcmp(token, positive_words[i]) == 0) {
                positive_words_count++;
            }
        }
        /* Checking if token is in negative words list */
        for (j = 0; j < 5; j++) {
            if (strcmp(token, negative_words[j]) == 0) {
                negative_words_count++;
            }
        }
        token = strtok(NULL, ".,!? ");
    }

    if (positive_words_count > negative_words_count) {
        printf("Sentiment: Positive.");
    }
    else if (positive_words_count < negative_words_count) {
        printf("Sentiment: Negative.");
    }
    else {
        printf("Sentiment: Neutral.");
    }
}

int main() {
    char input[1000];

    printf("Enter a sentence to determine the sentiment: ");
    fgets(input, 1000, stdin);

    /* Removing newline character from the input */
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }

    sentiment_analysis(input);

    return 0;
}