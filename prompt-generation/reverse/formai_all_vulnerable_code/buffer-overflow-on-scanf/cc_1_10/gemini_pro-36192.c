//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of players
#define MAX_PLAYERS 4

// Define the maximum size of a message
#define MAX_MESSAGE_SIZE 100

// Define the sentiment analysis function
int sentiment_analysis(char *message) {
  // Initialize the sentiment score
  int sentiment_score = 0;

  // Iterate over the message
  for (int i = 0; i < strlen(message); i++) {
    // Check if the character is a positive sentiment word
    if (strcmp(&message[i], "good") == 0 || strcmp(&message[i], "great") == 0 || strcmp(&message[i], "awesome") == 0) {
      // Increase the sentiment score
      sentiment_score++;
    }
    // Check if the character is a negative sentiment word
    else if (strcmp(&message[i], "bad") == 0 || strcmp(&message[i], "terrible") == 0 || strcmp(&message[i], "awful") == 0) {
      // Decrease the sentiment score
      sentiment_score--;
    }
  }

  // Return the sentiment score
  return sentiment_score;
}

// Define the main function
int main() {
  // Initialize the players
  char players[MAX_PLAYERS][MAX_MESSAGE_SIZE];

  // Get the messages from the players
  for (int i = 0; i < MAX_PLAYERS; i++) {
    printf("Player %d: ", i + 1);
    scanf("%s", players[i]);
  }

  // Analyze the sentiment of the messages
  int sentiment_scores[MAX_PLAYERS];
  for (int i = 0; i < MAX_PLAYERS; i++) {
    sentiment_scores[i] = sentiment_analysis(players[i]);
  }

  // Determine the winner
  int winning_player = 0;
  int highest_sentiment_score = sentiment_scores[0];
  for (int i = 1; i < MAX_PLAYERS; i++) {
    if (sentiment_scores[i] > highest_sentiment_score) {
      winning_player = i;
      highest_sentiment_score = sentiment_scores[i];
    }
  }

  // Print the winner
  printf("The winner is Player %d with a sentiment score of %d\n", winning_player + 1, highest_sentiment_score);

  return 0;
}