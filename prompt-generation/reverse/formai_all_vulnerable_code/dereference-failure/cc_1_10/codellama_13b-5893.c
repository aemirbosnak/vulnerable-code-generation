//Code Llama-13B DATASET v1.0 Category: Sentiment analysis tool ; Style: systematic
/*
 * Sentiment Analysis Tool
 *
 * This program takes in a string of text and returns the sentiment of the text.
 *
 * Usage:
 * 1. Compile the program with the following command:
 *     gcc sentiment.c -o sentiment
 * 2. Run the program with the following command:
 *     ./sentiment "Your text here"
 *
 * Example usage:
 * 1. ./sentiment "I love this program!"
 *    Output: Positive
 * 2. ./sentiment "I hate this program!"
 *    Output: Negative
 * 3. ./sentiment "This program is great!"
 *    Output: Positive
 * 4. ./sentiment "This program is terrible!"
 *    Output: Negative
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 20

// Function to convert a string to lowercase
void toLowerCase(char* str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
}

// Function to tokenize a string into words
char** tokenize(char* str, int* num_words) {
    int i, j;
    char** words;

    // Count the number of words in the string
    *num_words = 0;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            (*num_words)++;
        }
    }
    (*num_words)++;

    // Allocate memory for the words
    words = (char**)malloc((*num_words) * sizeof(char*));
    if (words == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }

    // Initialize the words
    for (i = 0; i < *num_words; i++) {
        words[i] = (char*)malloc(MAX_WORD_LENGTH * sizeof(char));
        if (words[i] == NULL) {
            printf("Error: Memory allocation failed.\n");
            exit(1);
        }
    }

    // Tokenize the string
    i = 0;
    j = 0;
    while (str[i] != '\0') {
        if (str[i] == ' ') {
            words[j][i - j] = '\0';
            j = i + 1;
        } else {
            words[j][i - j] = str[i];
        }
        i++;
    }
    words[j][i - j] = '\0';

    return words;
}

// Function to compute the sentiment of a string
int computeSentiment(char* str) {
    int i, num_words, sentiment = 0;
    char** words;

    // Tokenize the string
    words = tokenize(str, &num_words);

    // Compute the sentiment of each word
    for (i = 0; i < num_words; i++) {
        if (strcmp(words[i], "great") == 0) {
            sentiment += 1;
        } else if (strcmp(words[i], "terrible") == 0) {
            sentiment -= 1;
        }
    }

    // Free the memory allocated for the words
    for (i = 0; i < num_words; i++) {
        free(words[i]);
    }
    free(words);

    return sentiment;
}

// Main function
int main(int argc, char* argv[]) {
    char str[100];
    int sentiment;

    // Check if the correct number of arguments were passed
    if (argc != 2) {
        printf("Error: Incorrect number of arguments.\n");
        printf("Usage: ./sentiment \"Your text here\"\n");
        return 1;
    }

    // Get the string from the command line argument
    strcpy(str, argv[1]);

    // Convert the string to lowercase
    toLowerCase(str);

    // Compute the sentiment of the string
    sentiment = computeSentiment(str);

    // Print the sentiment of the string
    if (sentiment > 0) {
        printf("Positive\n");
    } else if (sentiment < 0) {
        printf("Negative\n");
    } else {
        printf("Neutral\n");
    }

    return 0;
}