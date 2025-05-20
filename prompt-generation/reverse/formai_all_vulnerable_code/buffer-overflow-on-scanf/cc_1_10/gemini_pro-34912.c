//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of players and the maximum length of a message
#define MAX_PLAYERS 10
#define MAX_MESSAGE_LENGTH 100

// Define the sentiment analysis function
int sentiment_analysis(char *message) {
  // Initialize the sentiment score
  int sentiment_score = 0;

  // Loop through the message and update the sentiment score
  for (int i = 0; i < strlen(message); i++) {
    if (message[i] == ':') {
      sentiment_score++;
    } else if (message[i] == ')') {
      sentiment_score++;
    } else if (message[i] == '(') {
      sentiment_score--;
    } else if (message[i] == ':(') {
      sentiment_score--;
    }
  }

  // Return the sentiment score
  return sentiment_score;
}

// Define the main function
int main() {
  // Initialize the game state
  char players[MAX_PLAYERS][MAX_MESSAGE_LENGTH];
  int sentiments[MAX_PLAYERS];

  // Get the number of players
  int num_players;
  printf("Enter the number of players: ");
  scanf("%d", &num_players);

  // Get the messages from the players
  for (int i = 0; i < num_players; i++) {
    printf("Enter player %d's message: ", i + 1);
    scanf("%s", players[i]);
  }

  // Analyze the sentiments of the messages
  for (int i = 0; i < num_players; i++) {
    sentiments[i] = sentiment_analysis(players[i]);
  }

  // Print the results
  for (int i = 0; i < num_players; i++) {
    printf("Player %d's sentiment score: %d\n", i + 1, sentiments[i]);
  }

  // Return 0 to indicate success
  return 0;
}