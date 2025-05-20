//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: complex
// This program performs sentiment analysis on text input using a complex approach
#include <stdio.h>
#include <string.h>

// Define the different sentiment scores
#define POSITIVE 1
#define NEGATIVE -1
#define NEUTRAL 0

// Define the different weight values for each sentiment analysis algorithm
#define WEIGHTED_WORDS 1 // Weighted words approach
#define WEIGHTED_PHRASES 2 // Weighted phrases approach
#define MACHINE_LEARNING 3 // Machine learning approach

// Global variables to store number of positive, negative, and neutral words/phrases
int num_positive, num_negative, num_neutral = 0;

// Function to analyze text input using the weighted words approach
int weighted_words(char *input) {
    char positive_words[10][20] = {"love", "like", "amazing", "wonderful", "great", "good", "excellent", "happy", "joyful", "awesome"};
    char negative_words[10][20] = {"hate", "dislike", "awful", "terrible", "horrible", "bad", "poor", "sad", "angry", "disgusting"};
    char *token;
    
    token = strtok(input, " "); // Tokenize the input string
    
    while (token != NULL) {
        for (int i = 0; i < 10; i++) {
            if (strcmp(token, positive_words[i]) == 0) {
                num_positive++;
                break;
            }
            if (strcmp(token, negative_words[i]) == 0) {
                num_negative++;
                break;
            }
        }
        token = strtok(NULL, " "); // Move onto next token
    }
    
    if (num_positive > num_negative) {
        return POSITIVE;
    }
    else if (num_positive < num_negative) {
        return NEGATIVE;
    }
    else {
        return NEUTRAL;
    }
}

// Function to analyze text input using the weighted phrases approach
int weighted_phrases(char *input) {
    char positive_phrases[3][50] = {"I love this", "This is awesome", "I am so happy"};
    char negative_phrases[3][50] = {"I hate this", "This is terrible", "I am so sad"};
    char *pos_ptr, *neg_ptr;
    
    pos_ptr = strstr(input, positive_phrases[0]); // Check for positive phrases
    if (pos_ptr != NULL) {
        num_positive++;
    }
    for (int i = 1; i < 3; i++) {
        pos_ptr = strstr(input, positive_phrases[i]);
        if (pos_ptr != NULL) {
            num_positive++;
            break;
        }
    }
    
    neg_ptr = strstr(input, negative_phrases[0]); // Check for negative phrases
    if (neg_ptr != NULL) {
        num_negative++;
    }
    for (int i = 1; i < 3; i++) {
        neg_ptr = strstr(input, negative_phrases[i]);
        if (neg_ptr != NULL) {
            num_negative++;
            break;
        }
    }
    
    if (num_positive > num_negative) {
        return POSITIVE;
    }
    else if (num_positive < num_negative) {
        return NEGATIVE;
    }
    else {
        return NEUTRAL;
    }
}

// Function to analyze text input using a machine learning approach
int machine_learning(char *input) {
    // Machine learning algorithm goes here
}

// Main program
int main() {
    char input[100];
    int approach, score;
    
    printf("Enter your text: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline from input
    
    printf("Choose the approach to use (1: weighted words; 2: weighted phrases; 3: machine learning): ");
    scanf("%d", &approach);
    
    switch (approach) {
        case WEIGHTED_WORDS:
            score = weighted_words(input);
            break;
        case WEIGHTED_PHRASES:
            score = weighted_phrases(input);
            break;
        case MACHINE_LEARNING:
            score = machine_learning(input);
            break;
        default:
            printf("Invalid approach choice");
            return 1;
    }
    
    switch (score) {
        case POSITIVE:
            printf("Sentiment score: Positive\n");
            break;
        case NEGATIVE:
            printf("Sentiment score: Negative\n");
            break;
        case NEUTRAL:
            printf("Sentiment score: Neutral\n");
            break;
    }
    
    return 0;
}