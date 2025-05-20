//Falcon2-11B DATASET v1.0 Category: Table Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// Define the game table
int table[3][3] = {
  { 1, 2, 3 },
  { 4, 5, 6 },
  { 7, 8, 9 }
};

int main() {
  // Print the game table
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", table[i][j]);
    }
    printf("\n");
  }

  // Play the game
  char player1Choice;
  char player2Choice;
  char player1Score = 0;
  char player2Score = 0;

  while (player1Score < 7 && player2Score < 7) {
    printf("\nPlayer 1, choose a number from 1 to 9: ");
    scanf(" %c", &player1Choice);

    if (player1Choice > 9) {
      printf("Invalid choice, try again.\n");
      continue;
    }

    if (table[0][player1Choice - 1] == 'X') {
      printf("Space already taken, try again.\n");
      continue;
    }

    table[0][player1Choice - 1] = 'X';
    player1Score++;

    printf("Player 2, choose a number from 1 to 9: ");
    scanf(" %c", &player2Choice);

    if (player2Choice > 9) {
      printf("Invalid choice, try again.\n");
      continue;
    }

    if (table[1][player2Choice - 1] == 'X') {
      printf("Space already taken, try again.\n");
      continue;
    }

    table[1][player2Choice - 1] = 'O';
    player2Score++;

    if (player1Score == 7) {
      printf("Player 1 wins!\n");
      break;
    } else if (player2Score == 7) {
      printf("Player 2 wins!\n");
      break;
    }
  }

  if (player1Score == 6 && player2Score == 6) {
    printf("It's a tie!\n");
  }

  return 0;
}