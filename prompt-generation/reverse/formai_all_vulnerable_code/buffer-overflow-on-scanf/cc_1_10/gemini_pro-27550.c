//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Initialize the sentiment dictionary with some common words and their associated sentiments
char *sentimentDictionary[][2] = {
    {"good", "positive"},
    {"bad", "negative"},
    {"great", "positive"},
    {"terrible", "negative"},
    {"amazing", "positive"},
    {"awful", "negative"},
    {"fantastic", "positive"},
    {"horrible", "negative"},
    {"wonderful", "positive"},
    {"terrible", "negative"},
    {"excellent", "positive"},
    {"horrible", "negative"},
    {"superb", "positive"},
    {"awful", "negative"},
    {"brilliant", "positive"},
    {"terrible", "negative"},
    {"outstanding", "positive"},
    {"terrible", "negative"},
    {"magnificent", "positive"},
    {"terrible", "negative"},
    {"marvelous", "positive"},
    {"terrible", "negative"},
    {"splendid", "positive"},
    {"terrible", "negative"},
    {"glorious", "positive"},
    {"terrible", "negative"},
    {"glorious", "positive"}
};

// Get the sentiment of a word by looking it up in the sentiment dictionary
char *getSentiment(char *word) {
    // Convert the word to lowercase for easier comparison
    char *lowerWord = malloc(strlen(word) + 1);
    strcpy(lowerWord, word);
    for (int i = 0; i < strlen(lowerWord); i++) {
        lowerWord[i] = tolower(lowerWord[i]);
    }

    // Iterate over the sentiment dictionary to find the word
    for (int i = 0; i < sizeof(sentimentDictionary) / sizeof(sentimentDictionary[0]); i++) {
        if (strcmp(lowerWord, sentimentDictionary[i][0]) == 0) {
            return sentimentDictionary[i][1];
        }
    }

    // If the word is not found in the dictionary, return "neutral"
    return "neutral";
}

// Analyze the sentiment of a given sentence
int analyzeSentiment(char *sentence) {
    // Tokenize the sentence into an array of words
    char *words[100];
    int numWords = 0;
    char *token = strtok(sentence, " ");
    while (token != NULL) {
        words[numWords++] = token;
        token = strtok(NULL, " ");
    }

    // Calculate the total sentiment score for the sentence
    int sentimentScore = 0;
    for (int i = 0; i < numWords; i++) {
        char *sentiment = getSentiment(words[i]);
        if (strcmp(sentiment, "positive") == 0) {
            sentimentScore++;
        } else if (strcmp(sentiment, "negative") == 0) {
            sentimentScore--;
        }
    }

    // Return the sentiment score for the sentence
    return sentimentScore;
}

// Demonstrate the sentiment analysis tool
int main() {
    // Get a sentence from the user
    char sentence[100];
    printf("Enter a sentence to analyze: ");
    scanf("%s", sentence);

    // Analyze the sentiment of the sentence
    int sentimentScore = analyzeSentiment(sentence);

    // Print the sentiment score for the sentence
    printf("The sentiment score for the sentence is: %d\n", sentimentScore);

    // Determine the overall sentiment of the sentence
    if (sentimentScore > 0) {
        printf("The overall sentiment of the sentence is positive.\n");
    } else if (sentimentScore < 0) {
        printf("The overall sentiment of the sentence is negative.\n");
    } else {
        printf("The overall sentiment of the sentence is neutral.\n");
    }

    return 0;
}