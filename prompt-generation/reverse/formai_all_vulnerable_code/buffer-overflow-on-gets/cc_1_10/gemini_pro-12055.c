//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1000

// Define a struct to represent a word and its sentiment score
typedef struct {
    char* word;
    int score;
} WordScore;

// Create an array of common positive words and their sentiment scores
WordScore positiveWords[] = {
    {"amazing", 5},
    {"awesome", 5},
    {"brilliant", 4},
    {"cool", 3},
    {"excellent", 4},
    {"fantastic", 5},
    {"great", 4},
    {"incredible", 5},
    {"lovely", 3},
    {"marvelous", 5},
    {"nice", 2},
    {"perfect", 5},
    {"splendid", 4},
    {"superb", 5},
    {"wonderful", 5}
};

// Create an array of common negative words and their sentiment scores
WordScore negativeWords[] = {
    {"awful", -5},
    {"bad", -4},
    {"dreadful", -5},
    {"terrible", -5},
    {"horrible", -5}
};

// Function to calculate the sentiment score of a string
int calculateSentiment(char* str) {
    // Convert the string to lowercase
    for (int i = 0; i < strlen(str); i++) {
        str[i] = tolower(str[i]);
    }

    // Initialize the sentiment score to 0
    int score = 0;

    // Tokenize the string into words
    char* token = strtok(str, " ");
    while (token != NULL) {
        // Check if the word is a positive word
        for (int i = 0; i < sizeof(positiveWords) / sizeof(WordScore); i++) {
            if (strcmp(token, positiveWords[i].word) == 0) {
                score += positiveWords[i].score;
                break;
            }
        }

        // Check if the word is a negative word
        for (int i = 0; i < sizeof(negativeWords) / sizeof(WordScore); i++) {
            if (strcmp(token, negativeWords[i].word) == 0) {
                score += negativeWords[i].score;
                break;
            }
        }

        // Get the next token
        token = strtok(NULL, " ");
    }

    // Return the sentiment score
    return score;
}

// Main function
int main() {
    // Get the input string from the user
    char str[MAX_STR_LEN];
    printf("Enter a string: ");
    gets(str);

    // Calculate the sentiment score of the string
    int score = calculateSentiment(str);

    // Print the sentiment score
    printf("The sentiment score of the string is: %d\n", score);

    return 0;
}