//GEMINI-pro DATASET v1.0 Category: Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the player and computer choices
#define ROCK 1
#define PAPER 2
#define SCISSORS 3

// Define the game states
#define WIN 1
#define LOSE 2
#define TIE 3

// Define the game messages
#define ROCK_MSG "A strong and unyielding stone..."
#define PAPER_MSG "A delicate and flowing sheet..."
#define SCISSORS_MSG "A sharp and piercing blade..."
#define WIN_MSG "Your love conquers all!"
#define LOSE_MSG "Your heart has been broken..."
#define TIE_MSG "A gentle embrace of equals..."

// Get a random choice from the computer
int get_computer_choice() {
  srand(time(NULL));
  return rand() % 3 + 1;
}

// Get a choice from the player
int get_player_choice() {
  int choice;
  printf("Choose your weapon, my love:\n");
  printf("1. Rock\n");
  printf("2. Paper\n");
  printf("3. Scissors\n");
  scanf("%d", &choice);
  return choice;
}

// Determine the winner of the game
int get_winner(int player_choice, int computer_choice) {
  if (player_choice == computer_choice) {
    return TIE;
  } else if (player_choice == ROCK && computer_choice == SCISSORS) {
    return WIN;
  } else if (player_choice == PAPER && computer_choice == ROCK) {
    return WIN;
  } else if (player_choice == SCISSORS && computer_choice == PAPER) {
    return WIN;
  } else {
    return LOSE;
  }
}

// Print the game results
void print_results(int player_choice, int computer_choice, int winner) {
  printf("\nYou chose: ");
  switch (player_choice) {
    case ROCK:
      printf(ROCK_MSG);
      break;
    case PAPER:
      printf(PAPER_MSG);
      break;
    case SCISSORS:
      printf(SCISSORS_MSG);
      break;
  }

  printf("\nI chose: ");
  switch (computer_choice) {
    case ROCK:
      printf(ROCK_MSG);
      break;
    case PAPER:
      printf(PAPER_MSG);
      break;
    case SCISSORS:
      printf(SCISSORS_MSG);
      break;
  }

  printf("\n");

  switch (winner) {
    case WIN:
      printf(WIN_MSG);
      break;
    case LOSE:
      printf(LOSE_MSG);
      break;
    case TIE:
      printf(TIE_MSG);
      break;
  }

  printf("\n");
}

// Play the game
int main() {
  int player_choice, computer_choice, winner;

  while (1) {
    player_choice = get_player_choice();
    computer_choice = get_computer_choice();
    winner = get_winner(player_choice, computer_choice);
    print_results(player_choice, computer_choice, winner);

    if (winner == WIN) {
      printf("You have won my heart!\n");
      break;
    } else if (winner == LOSE) {
      printf("My heart is broken... Goodbye.\n");
      break;
    }
  }

  return 0;
}