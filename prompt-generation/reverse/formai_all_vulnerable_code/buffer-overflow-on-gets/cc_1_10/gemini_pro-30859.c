//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Get the user's input
    char *input = (char *)malloc(100);
    printf("Enter a sentence: ");
    gets(input);

    // Tokenize the input into words
    char **words = (char **)malloc(100 * sizeof(char *));
    int num_words = 0;
    char *token = strtok(input, " ");
    while (token != NULL) {
        words[num_words] = token;
        num_words++;
        token = strtok(NULL, " ");
    }

    // Create a dictionary of sentiment scores
    char *sentiment_words[] = {"good", "great", "awesome", "superb", "excellent", "bad", "terrible", "awful", "horrible", "dreadful"};
    int sentiment_scores[] = {1, 2, 3, 4, 5, -1, -2, -3, -4, -5};
    int num_sentiment_words = 10;

    // Calculate the sentiment score of the input
    int sentiment_score = 0;
    for (int i = 0; i < num_words; i++) {
        for (int j = 0; j < num_sentiment_words; j++) {
            if (strcmp(words[i], sentiment_words[j]) == 0) {
                sentiment_score += sentiment_scores[j];
            }
        }
    }

    // Print the sentiment score
    if (sentiment_score > 0) {
        printf("The sentence is positive!\n");
    } else if (sentiment_score < 0) {
        printf("The sentence is negative!\n");
    } else {
        printf("The sentence is neutral!\n");
    }

    // Free the allocated memory
    free(input);
    for (int i = 0; i < num_words; i++) {
        free(words[i]);
    }
    free(words);

    return 0;
}