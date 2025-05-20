//FormAI DATASET v1.0 Category: Table Game ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  
  // Initializing variables
  int gameBoard[3][3], row, col, count = 0, player = 1, choice;
  
  // Filling game board with zeros
  for (row = 0; row < 3; row++) {
    for (col = 0; col < 3; col++) {
      gameBoard[row][col] = 0;
    }
  }
  
  // Printing initial game board
  printf("Welcome to the C Table Game!\n");
  printf("Player 1 = X and Player 2 = O\n");
  printf("-----------------------------\n");
  printf("|       |       |       |\n");
  printf("|   %d   |   %d   |   %d   |\n", gameBoard[0][0], gameBoard[0][1], gameBoard[0][2]);
  printf("|       |       |       |\n");
  printf("|---------------------------|\n");
  printf("|       |       |       |\n");
  printf("|   %d   |   %d   |   %d   |\n", gameBoard[1][0], gameBoard[1][1], gameBoard[1][2]);
  printf("|       |       |       |\n");
  printf("|---------------------------|\n");
  printf("|       |       |       |\n");
  printf("|   %d   |   %d   |   %d   |\n", gameBoard[2][0], gameBoard[2][1], gameBoard[2][2]);
  printf("|       |       |       |\n");
  printf("-----------------------------\n\n");
  
  // Game loop
  while (count < 9) {
    printf("Player %d's turn to move: ", player);
    scanf("%d", &choice);
    
    // Check if user input is valid
    while (choice < 1 || choice > 9 || gameBoard[(choice-1)/3][(choice-1)%3] != 0) {
      printf("Please enter a valid move: ");
      scanf("%d", &choice);
    }
    
    // Update game board with player's move
    gameBoard[(choice-1)/3][(choice-1)%3] = player;
    
    // Print updated game board
    printf("-----------------------------\n");
    printf("|       |       |       |\n");
    printf("|   %c   |   %c   |   %c   |\n", gameBoard[0][0] == 1 ? 'X' : (gameBoard[0][0] == 2 ? 'O' : ' '), gameBoard[0][1] == 1 ? 'X' : (gameBoard[0][1] == 2 ? 'O' : ' '), gameBoard[0][2] == 1 ? 'X' : (gameBoard[0][2] == 2 ? 'O' : ' '));
    printf("|       |       |       |\n");
    printf("|---------------------------|\n");
    printf("|       |       |       |\n");
    printf("|   %c   |   %c   |   %c   |\n", gameBoard[1][0] == 1 ? 'X' : (gameBoard[1][0] == 2 ? 'O' : ' '), gameBoard[1][1] == 1 ? 'X' : (gameBoard[1][1] == 2 ? 'O' : ' '), gameBoard[1][2] == 1 ? 'X' : (gameBoard[1][2] == 2 ? 'O' : ' '));
    printf("|       |       |       |\n");
    printf("|---------------------------|\n");
    printf("|       |       |       |\n");
    printf("|   %c   |   %c   |   %c   |\n", gameBoard[2][0] == 1 ? 'X' : (gameBoard[2][0] == 2 ? 'O' : ' '), gameBoard[2][1] == 1 ? 'X' : (gameBoard[2][1] == 2 ? 'O' : ' '), gameBoard[2][2] == 1 ? 'X' : (gameBoard[2][2] == 2 ? 'O' : ' '));
    printf("|       |       |       |\n");
    printf("-----------------------------\n\n");
    
    // Check if player has won
    if ((gameBoard[0][0] == player && gameBoard[0][1] == player && gameBoard[0][2] == player) ||
        (gameBoard[1][0] == player && gameBoard[1][1] == player && gameBoard[1][2] == player) ||
        (gameBoard[2][0] == player && gameBoard[2][1] == player && gameBoard[2][2] == player) ||
        (gameBoard[0][0] == player && gameBoard[1][0] == player && gameBoard[2][0] == player) ||
        (gameBoard[0][1] == player && gameBoard[1][1] == player && gameBoard[2][1] == player) ||
        (gameBoard[0][2] == player && gameBoard[1][2] == player && gameBoard[2][2] == player) ||
        (gameBoard[0][0] == player && gameBoard[1][1] == player && gameBoard[2][2] == player) ||
        (gameBoard[0][2] == player && gameBoard[1][1] == player && gameBoard[2][0] == player)) {
      printf("Player %d wins!\n", player);
      return 0;
    }
    
    // Switch to other player's turn and increment move counter
    player = (player == 1) ? 2 : 1;
    count++;
  }
  
  // If no one has won and the game board is full, it's a tie
  printf("It's a tie!\n");
  return 0;
}