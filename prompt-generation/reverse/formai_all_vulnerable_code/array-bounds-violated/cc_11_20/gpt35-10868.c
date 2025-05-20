//FormAI DATASET v1.0 Category: Table Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Welcome to the SlapJack game
  printf("Welcome to the SlapJack game! This game is all about luck and reflexes.\n");
  
  // Define the deck of cards
  char cards[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K'};
  int n_cards = sizeof(cards)/sizeof(cards[0]);

  // Shuffle the deck of cards using the Fisher-Yates algorithm
  for (int i = n_cards-1; i > 0; i--) {
    int j = rand() % (i+1);
    char temp = cards[i];
    cards[i] = cards[j];
    cards[j] = temp;
  }

  // Display the deck of cards
  printf("Here is the shuffled deck of cards:\n");
  for (int i = 0; i < n_cards; i++) {
    printf("%c ", cards[i]);
  }
  printf("\n");

  // Deal the cards to the players (two players for this game)
  char player1_card, player2_card;
  int player1_points = 0, player2_points = 0;
  int n_turns = 10; // the game will last for 10 turns
  printf("Are you ready to play? Let's start!\n");

  for (int turn = 1; turn <= n_turns; turn++) {
    printf("Turn %d: \n", turn);
    player1_card = cards[2*turn-2];
    player2_card = cards[2*turn-1];
    printf("Player 1: %c\n", player1_card);
    printf("Player 2: %c\n", player2_card);
    if (player1_card == 'J') {
      player1_points += 10;
      printf("Player 1 got a bonus of 10 points!\n");
    }
    if (player2_card == 'J') {
      player2_points += 10;
      printf("Player 2 got a bonus of 10 points!\n");
    }
    if (player1_card == 'A' && player2_card == 'K') {
      player1_points += 20;
      printf("Player 1 got a bonus of 20 points!\n");
    }
    if (player2_card == 'A' && player1_card == 'K') {
      player2_points += 20;
      printf("Player 2 got a bonus of 20 points!\n");
    }
    if (player1_card == player2_card) {
      printf("It's a tie! Both players slap the deck!\n");
    }
    else if (player1_card > player2_card) {
      player1_points++;
      printf("Player 1 wins this round!\n");
    }
    else {
      player2_points++;
      printf("Player 2 wins this round!\n");
    }
    printf("Current score: Player 1 - %d, Player 2 - %d\n", player1_points, player2_points);
  }

  // Final score and winner
  printf("Game over! Final score: Player 1 - %d, Player 2 - %d\n", player1_points, player2_points);
  if (player1_points == player2_points) {
    printf("It's a tie! Nobody wins.\n");
  }
  else if (player1_points > player2_points) {
    printf("Player 1 wins the game! Congratulations!\n");
  }
  else {
    printf("Player 2 wins the game! Congratulations!\n");
  }

  return 0;
}