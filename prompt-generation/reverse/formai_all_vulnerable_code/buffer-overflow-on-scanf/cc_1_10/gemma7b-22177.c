//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Define the variables
  int number_of_players = 2;
  int player_1_health = 100;
  int player_2_health = 100;
  int current_turn = 1;
  int game_over = 0;

  // Initialize the game
  printf("Welcome to the mathematical adventure game!\n");
  printf("There are %d players.\n", number_of_players);
  printf("Each player has %d health points.\n", player_1_health);
  printf("It is player %d's turn.\n", current_turn);

  // Loop until the game is over
  while (!game_over) {
    // Get the player's input
    int input = 0;
    printf("Enter your move: ");
    scanf("%d", &input);

    // Check if the input is valid
    if (input < 1 || input > 5) {
      printf("Invalid input. Please try again.\n");
    } else {
      // Calculate the damage
      int damage = 0;
      switch (input) {
        case 1:
          damage = 10;
          break;
        case 2:
          damage = 15;
          break;
        case 3:
          damage = 20;
          break;
        case 4:
          damage = 25;
          break;
        case 5:
          damage = 30;
          break;
      }

      // Subtract the damage from the player's health
      player_1_health -= damage;

      // Check if the player is still alive
      if (player_1_health <= 0) {
        printf("Player %d is dead. Game over.\n", current_turn);
        game_over = 1;
      } else {
        // Print the damage and the player's health
        printf("You dealt %d damage to player %d.\n", damage, current_turn);
        printf("Player %d has %d health points left.\n", current_turn, player_1_health);
      }
    }

    // Switch to the next turn
    current_turn++;
  }

  // Final message
  printf("Thank you for playing! See you next time.\n");

  return 0;
}