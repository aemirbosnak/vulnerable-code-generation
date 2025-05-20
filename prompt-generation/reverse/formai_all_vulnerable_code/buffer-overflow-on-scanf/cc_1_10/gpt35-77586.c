//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLUMNS 5

void displayBoard(int board[ROWS][COLUMNS], int playerScore, int computerScore);
void generateNumbers(int board[ROWS][COLUMNS], int usedNumbers[]);
int checkNumber(int usedNumbers[], int number);


int main() {
   int board[ROWS][COLUMNS];
   srand(time(0)); // to generate random numbers 
   int usedNumbers[ROWS * COLUMNS] = {0}; // to keep track of already generated numbers
   int playerScore = 0;
   int computerScore = 0;

   generateNumbers(board, usedNumbers); // initialize the board with numbers

   while (playerScore < 5 && computerScore < 5) {
      int playerNumber;
      printf("Enter a number between 1 and 25: ");
      scanf("%d", &playerNumber);

      if (checkNumber(usedNumbers, playerNumber)) { // check if the number is valid or not
         printf("Number already used! Try again.\n");
         continue; // ask the player to enter again
      }

      usedNumbers[playerNumber - 1] = 1; // mark the number as used
      displayBoard(board, ++playerScore, computerScore);

      // simulate the computer's turn
      int computerNumber = (rand() % (ROWS * COLUMNS)) + 1;
      while (checkNumber(usedNumbers, computerNumber)) { // generate a new number if the number is already used
         computerNumber = (rand() % (ROWS * COLUMNS)) + 1;
      }

      usedNumbers[computerNumber - 1] = 1; // mark the number as used
      displayBoard(board, playerScore, ++computerScore);

   }

   if (playerScore == 5) {
      printf("You won!\n");
   } else {
      printf("Computer won!\n");
   }

   return 0;
}

// displays the current state of the board
void displayBoard(int board[ROWS][COLUMNS], int playerScore, int computerScore) {
   printf("\n\n\n\n\n\n\n\n\n\n\n");
   printf("==========================\n");
   printf("Player Score: %d\tComputer Score: %d\n\n", playerScore, computerScore);
   printf("       B   I   N   G   O\n");
   for (int i = 0; i < ROWS; i++) {
      printf("   ----------------------\n");
      for (int j = 0; j < COLUMNS; j++) {
         if (board[i][j] == 0) {
            printf("   |   ");
         } else if (board[i][j] < 10) {
            printf("   | %d ", board[i][j]);
         } else {
            printf("   | %d", board[i][j]);
         }
      }
      printf("   |\n");
   }
   printf("   ----------------------\n\n\n");
}

// generates the numbers for the board
void generateNumbers(int board[ROWS][COLUMNS], int usedNumbers[]) {
   for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLUMNS; j++) {
         int number = (j * ROWS) + i + 1;
         while (checkNumber(usedNumbers, number)) { // generate a new number if the number is already used
            number = (rand() % (ROWS * COLUMNS)) + 1;
         }
         board[i][j] = number;
         usedNumbers[number - 1] = 1; // mark the number as used
      }
   }
}

// checks if the number has been used already
int checkNumber(int usedNumbers[], int number) {
   if (usedNumbers[number - 1] == 1) {
      return 1;
   } else {
      return 0;
   }
}