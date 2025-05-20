//FormAI DATASET v1.0 Category: Temperature monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0));
  
  int temperatures[10];
  
  printf("Welcome to the Temperature Monitor Game!\n");
  printf("You are playing multiplayer. The goal is to guess the correct temperature.\n");
  printf("The program will generate 10 random temperatures between -20 and 40 degrees Celsius.\n");
  printf("The player with the fewest number of guesses to guess all 10 temperatures wins!\n");
  
  int player1_guesses = 0;
  int player2_guesses = 0;
  
  for (int i = 0; i < 10; i++) {
    int temperature = rand() % 61 - 20; // random temperature between -20 and 40 degrees Celsius
    temperatures[i] = temperature;
  }
  
  int player1_correct_guesses = 0;
  int player2_correct_guesses = 0;
  
  while (player1_correct_guesses < 10 && player2_correct_guesses < 10) {
    int player1_guess;
    printf("Player 1, enter your guess: ");
    scanf("%d", &player1_guess);
    player1_guesses++;
    
    int player2_guess;
    printf("Player 2, enter your guess: ");
    scanf("%d", &player2_guess);
    player2_guesses++;
    
    for (int i = 0; i < 10; i++) {
      if (player1_guess == temperatures[i]) {
        printf("Player 1 correctly guessed temperature %d.\n", temperatures[i]);
        player1_correct_guesses++;
      }
      if (player2_guess == temperatures[i]) {
        printf("Player 2 correctly guessed temperature %d.\n", temperatures[i]);
        player2_correct_guesses++;
      }
    }
  }
  
  if (player1_correct_guesses == 10 && player2_correct_guesses == 10) {
    printf("Tie! Both players guessed all 10 temperatures.\n");
  } else if (player1_correct_guesses == 10) {
    printf("Player 1 wins! It took them %d guesses.\n", player1_guesses);
  } else {
    printf("Player 2 wins! It took them %d guesses.\n", player2_guesses);
  }
  
  return 0;
}