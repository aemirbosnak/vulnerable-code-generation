//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the sentiment scores for each word
const int SENTIMENT_SCORES[] = {
    // Positive words
    [0] = 1,  // "good"
    [1] = 1,  // "great"
    [2] = 1,  // "excellent"
    [3] = 1,  // "amazing"
    [4] = 1,  // "awesome"

    // Negative words
    [5] = -1, // "bad"
    [6] = -1, // "terrible"
    [7] = -1, // "horrible"
    [8] = -1, // "awful"
    [9] = -1  // "dreadful"
};

// Define the number of words in the sentiment dictionary
const int SENTIMENT_DICTIONARY_SIZE = sizeof(SENTIMENT_SCORES) / sizeof(int);

// Function to calculate the sentiment score of a string
int calculate_sentiment_score(char *string) {
    // Convert the string to lowercase
    char *lowercase_string = strdup(string);
    for (int i = 0; lowercase_string[i]; i++) {
        lowercase_string[i] = tolower(lowercase_string[i]);
    }

    // Split the string into words
    char *words[100];
    int num_words = 0;
    char *word = strtok(lowercase_string, " ");
    while (word != NULL) {
        words[num_words++] = word;
        word = strtok(NULL, " ");
    }

    // Calculate the sentiment score for each word
    int sentiment_score = 0;
    for (int i = 0; i < num_words; i++) {
        int index = binary_search(words[i], SENTIMENT_DICTIONARY_SIZE, SENTIMENT_SCORES);
        if (index != -1) {
            sentiment_score += SENTIMENT_SCORES[index];
        }
    }

    // Free the memory allocated for the lowercase string
    free(lowercase_string);

    // Return the sentiment score
    return sentiment_score;
}

// Function to perform a binary search on an array
int binary_search(char *word, int size, int *array) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int comparison = strcmp(word, array[mid]);

        if (comparison == 0) {
            return mid;
        } else if (comparison < 0) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;
}

// Main function
int main() {
    // Get the input string from the user
    char string[100];
    printf("Enter a string: ");
    scanf("%s", string);

    // Calculate the sentiment score of the string
    int sentiment_score = calculate_sentiment_score(string);

    // Print the sentiment score
    if (sentiment_score > 0) {
        printf("The sentiment score is positive.\n");
    } else if (sentiment_score < 0) {
        printf("The sentiment score is negative.\n");
    } else {
        printf("The sentiment score is neutral.\n");
    }

    return 0;
}