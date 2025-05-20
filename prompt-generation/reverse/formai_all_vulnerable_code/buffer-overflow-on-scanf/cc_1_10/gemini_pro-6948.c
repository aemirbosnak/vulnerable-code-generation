//GEMINI-pro DATASET v1.0 Category: Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 32
#define MAX_PLAYERS 4
#define MAX_ATTEMPTS 10

typedef struct _Player {
  char name[MAX_NAME_LEN];
  int score;
} Player;

Player players[MAX_PLAYERS];
int num_players;

int main() {
  printf("Welcome to the Word Guessing Game!\n");
  printf("How many players are playing? (1-%d): ", MAX_PLAYERS);
  scanf("%d", &num_players);

  for (int i = 0; i < num_players; i++) {
    printf("Enter player %d's name: ", i + 1);
    scanf("%s", players[i].name);
    players[i].score = 0;
  }

  // Get the word to guess
  char word[MAX_NAME_LEN];
  printf("Enter the word to guess: ");
  scanf("%s", word);

  // Shuffle the word
  int len = strlen(word);
  for (int i = 0; i < len; i++) {
    int j = rand() % len;
    char temp = word[i];
    word[i] = word[j];
    word[j] = temp;
  }

  // Print the shuffled word
  printf("The shuffled word is: %s\n", word);

  // Loop through the players
  int current_player = 0;
  int attempts = 0;
  while (attempts < MAX_ATTEMPTS) {
    // Get the guess from the current player
    char guess[MAX_NAME_LEN];
    printf("%s, guess the word: ", players[current_player].name);
    scanf("%s", guess);

    // Check if the guess is correct
    if (strcmp(guess, word) == 0) {
      // The player guessed the word correctly!
      players[current_player].score++;
      printf("%s guessed the word correctly!\n", players[current_player].name);
      break;
    } else {
      // The player guessed the word incorrectly
      printf("%s guessed the word incorrectly.\n", players[current_player].name);
      attempts++;
    }

    // Move to the next player
    current_player = (current_player + 1) % num_players;
  }

  // Print the scores
  printf("Scores:\n");
  for (int i = 0; i < num_players; i++) {
    printf("%s: %d\n", players[i].name, players[i].score);
  }

  // Find the winner
  int max_score = 0;
  int winner = -1;
  for (int i = 0; i < num_players; i++) {
    if (players[i].score > max_score) {
      max_score = players[i].score;
      winner = i;
    }
  }

  // Print the winner
  if (winner != -1) {
    printf("%s wins!\n", players[winner].name);
  } else {
    printf("No one guessed the word correctly.\n");
  }

  return 0;
}