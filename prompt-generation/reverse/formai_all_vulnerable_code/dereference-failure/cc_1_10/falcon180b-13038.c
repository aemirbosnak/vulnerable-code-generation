//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to tokenize a sentence into words
void tokenize(char* sentence, char** tokens) {
    int count = 0;
    char* token;
    char* temp = strdup(sentence);
    token = strtok(temp, " ");
    while (token!= NULL) {
        tokens[count++] = strdup(token);
        token = strtok(NULL, " ");
    }
}

// Function to calculate the sentiment score of a sentence
int calculate_sentiment_score(char** tokens, int num_tokens) {
    int score = 0;
    for (int i = 0; i < num_tokens; i++) {
        if (strcmp(tokens[i], "happy") == 0) {
            score += 3;
        } else if (strcmp(tokens[i], "sad") == 0) {
            score -= 3;
        } else if (strcmp(tokens[i], "angry") == 0) {
            score -= 4;
        } else if (strcmp(tokens[i], "excited") == 0) {
            score += 2;
        } else if (strcmp(tokens[i], "bored") == 0) {
            score -= 2;
        }
    }
    return score;
}

// Function to print the sentiment analysis results
void print_results(char* sentence, int score) {
    if (score > 0) {
        printf("Positive sentiment detected in the sentence '%s' with a score of %d.\n", sentence, score);
    } else if (score < 0) {
        printf("Negative sentiment detected in the sentence '%s' with a score of %d.\n", sentence, score);
    } else {
        printf("Neutral sentiment detected in the sentence '%s' with a score of %d.\n", sentence, score);
    }
}

int main() {
    char sentence[1000];
    printf("Enter a sentence to analyze its sentiment:\n");
    scanf("%[^\n]", sentence);

    // Tokenize the sentence into words
    char* tokens[100];
    int num_tokens;
    tokenize(sentence, tokens);
    num_tokens = strlen(tokens);

    // Calculate the sentiment score of the sentence
    int score = calculate_sentiment_score(tokens, num_tokens);

    // Print the sentiment analysis results
    print_results(sentence, score);

    return 0;
}