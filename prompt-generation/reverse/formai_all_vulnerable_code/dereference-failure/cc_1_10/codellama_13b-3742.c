//Code Llama-13B DATASET v1.0 Category: Sentiment analysis tool ; Style: detailed
/*
 * C Sentiment Analysis Tool
 *
 * This program takes a text file as input and analyzes the sentiment of the text
 * using a simple sentiment analysis algorithm.
 */

#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Define a structure to represent a sentiment score
typedef struct {
    float positive;
    float negative;
    float neutral;
} sentiment_score;

// Define a function to calculate the sentiment score of a text
sentiment_score calculate_sentiment(char *text) {
    sentiment_score score = {0, 0, 0};

    // Loop through each word in the text
    while (*text != '\0') {
        // Check if the word is a positive word
        if (strcmp(text, "good") == 0 || strcmp(text, "great") == 0 || strcmp(text, "awesome") == 0) {
            score.positive++;
        }
        // Check if the word is a negative word
        else if (strcmp(text, "bad") == 0 || strcmp(text, "terrible") == 0 || strcmp(text, "awful") == 0) {
            score.negative++;
        }
        // Check if the word is a neutral word
        else if (strcmp(text, "neutral") == 0 || strcmp(text, "normal") == 0 || strcmp(text, "average") == 0) {
            score.neutral++;
        }

        // Move to the next word
        text = strchr(text, ' ') + 1;
    }

    return score;
}

// Define a function to print the sentiment score
void print_sentiment_score(sentiment_score score) {
    printf("Positive: %.2f\n", score.positive);
    printf("Negative: %.2f\n", score.negative);
    printf("Neutral: %.2f\n", score.neutral);
}

// Define the main function
int main(int argc, char *argv[]) {
    // Check if the user has provided a text file as input
    if (argc != 2) {
        printf("Usage: %s <text_file>\n", argv[0]);
        return 1;
    }

    // Open the text file
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", argv[1]);
        return 1;
    }

    // Read the text from the file
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        // Calculate the sentiment score of the line
        sentiment_score score = calculate_sentiment(line);

        // Print the sentiment score
        print_sentiment_score(score);
    }

    // Close the file
    fclose(fp);

    return 0;
}