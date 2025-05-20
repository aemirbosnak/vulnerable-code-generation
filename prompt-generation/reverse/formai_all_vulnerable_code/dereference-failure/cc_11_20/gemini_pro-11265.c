//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *text;
    int sentiment;
} Review;

Review *reviews;
int num_reviews;

int main() {
    reviews = malloc(sizeof(Review) * 10);
    num_reviews = 0;

    // Read in the reviews from a file
    FILE *fp = fopen("reviews.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    while (1) {
        char line[1024];
        if (fgets(line, sizeof(line), fp) == NULL) {
            break;
        }

        // Parse the line and store the review
        char *text = strtok(line, "\t");
        int sentiment = atoi(strtok(NULL, "\t"));

        reviews[num_reviews].text = strdup(text);
        reviews[num_reviews].sentiment = sentiment;
        num_reviews++;
    }

    fclose(fp);

    // Perform sentiment analysis on the reviews
    for (int i = 0; i < num_reviews; i++) {
        Review review = reviews[i];

        // Split the review text into words
        char **words = malloc(sizeof(char *) * 10);
        int num_words = 0;

        char *word = strtok(review.text, " ");
        while (word != NULL) {
            words[num_words++] = strdup(word);
            word = strtok(NULL, " ");
        }

        // Count the number of positive and negative words in the review
        int positive = 0;
        int negative = 0;

        for (int j = 0; j < num_words; j++) {
            char *word = words[j];

            if (strcmp(word, "good") == 0 || strcmp(word, "great") == 0 || strcmp(word, "excellent") == 0) {
                positive++;
            } else if (strcmp(word, "bad") == 0 || strcmp(word, "terrible") == 0) {
                negative++;
            }
        }

        // Determine the sentiment of the review
        int sentiment;
        if (positive > negative) {
            sentiment = 1;
        } else if (negative > positive) {
            sentiment = -1;
        } else {
            sentiment = 0;
        }

        // Print the review and its sentiment
        printf("%s\t%d\n", review.text, sentiment);
    }

    // Free the allocated memory
    for (int i = 0; i < num_reviews; i++) {
        free(reviews[i].text);
    }
    free(reviews);

    return EXIT_SUCCESS;
}