//LLAMA2-13B DATASET v1.0 Category: Table Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_GUESS 5
#define MIN_GUESS 1

// Global variables
int players[MAX_PLAYERS];
int guesses[MAX_PLAYERS][MAX_GUESS];
int current_player = 0;
int game_over = 0;

// Function prototypes
void player_turn();
void check_guess();
void print_score();

int main() {
  // Initialize players and guesses
  for (int i = 0; i < MAX_PLAYERS; i++) {
    players[i] = 0;
    for (int j = 0; j < MAX_GUESS; j++) {
      guesses[i][j] = 0;
    }
  }

  // Start the game!
  player_turn();

  // Game loop
  while (!game_over) {
    player_turn();
  }

  // Print final score
  print_score();

  return 0;
}

// Player turn function
void player_turn() {
  // Print current player's name
  printf("It's %s's turn! \n", players[current_player]);

  // Ask player for guess
  printf("Guess a number between 1 and 10: ");
  int guess = getchar() - '0';

  // Check if guess is valid
  if (guess < 1 || guess > 10) {
    printf("Oops, that's not a valid guess! Try again.\n");
    return;
  }

  // Update guesses array
  guesses[current_player][guess]++;

  // Check if guess is correct
  if (guesses[current_player][guess] == 2) {
    // Print correct guess message
    printf("Woohoo! %s, you got it right! \n", players[current_player]);

    // Update score
    players[current_player]++;

    // Check if game is over
    game_over = check_game_over();

    // Update current player
    current_player++;
    current_player %= MAX_PLAYERS;

    // Print next player's name
    printf("It's %s's turn! \n", players[current_player]);
  } else {
    // Print incorrect guess message
    printf("Oops, that's not the correct answer. Try again.\n");
  }
}

// Check if game is over
int check_game_over() {
  int count = 0;
  for (int i = 0; i < MAX_PLAYERS; i++) {
    if (players[i] == 10) {
      count++;
    }
  }

  return count == MAX_PLAYERS;
}

// Print final score
void print_score() {
  printf("Final score: \n");

  for (int i = 0; i < MAX_PLAYERS; i++) {
    printf("%d ", players[i]);
  }

  printf("\n");
}