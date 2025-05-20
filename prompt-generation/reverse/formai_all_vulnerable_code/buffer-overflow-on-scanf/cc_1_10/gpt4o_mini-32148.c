//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PLAYERS 5
#define MAX_TEXT_LENGTH 256
#define POSITIVE_WORD_COUNT 5
#define NEGATIVE_WORD_COUNT 5

const char *positive_words[POSITIVE_WORD_COUNT] = { "good", "happy", "joy", "excellent", "love" };
const char *negative_words[NEGATIVE_WORD_COUNT] = { "bad", "sad", "hate", "awful", "terrible" };

void analyze_sentiment(const char *input_text) {
    int positive_count = 0;
    int negative_count = 0;

    char *token = strtok((char *)input_text, " ");
    while (token != NULL) {
        for (int i = 0; i < POSITIVE_WORD_COUNT; i++) {
            if (strcmp(token, positive_words[i]) == 0) {
                positive_count++;
            }
        }
        for (int i = 0; i < NEGATIVE_WORD_COUNT; i++) {
            if (strcmp(token, negative_words[i]) == 0) {
                negative_count++;
            }
        }
        token = strtok(NULL, " ");
    }

    if (positive_count > negative_count) {
        printf("Sentiment Analysis Result: Positive\n");
    } else if (negative_count > positive_count) {
        printf("Sentiment Analysis Result: Negative\n");
    } else {
        printf("Sentiment Analysis Result: Neutral\n");
    }
}

int main() {
    char player_text[MAX_PLAYERS][MAX_TEXT_LENGTH];
    int num_players = 0;

    printf("Welcome to the Multiplayer Sentiment Analysis Tool!\n");
    printf("Enter the number of players (1 to %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);
    getchar(); // Consume newline character

    if (num_players < 1 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players! Exiting...\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < num_players; i++) {
        printf("Player %d, please enter your text: ", i + 1);
        fgets(player_text[i], MAX_TEXT_LENGTH, stdin);
        player_text[i][strcspn(player_text[i], "\n")] = '\0'; // Remove newline character
    }

    printf("\nAnalyzing sentiments for each player...\n");
    for (int i = 0; i < num_players; i++) {
        printf("Analysis for Player %d: \n", i + 1);
        analyze_sentiment(player_text[i]);
    }

    return EXIT_SUCCESS;
}