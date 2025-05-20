//FormAI DATASET v1.0 Category: Table Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate random number between min and max
int generateRandomNumber(int min, int max) {
  int num = (rand() % (max - min + 1)) + min;
  return num;
}

// function to check if number is already in the array
int isInArray(int arr[], int size, int num) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == num) {
      return 1;
    }
  }
  return 0;
}

int main() {
  srand(time(0)); // seed for random number generator
  int numRows, numCols;
  printf("Enter the number of rows (<= 10): ");
  scanf("%d", &numRows);
  printf("Enter the number of columns (<= 10): ");
  scanf("%d", &numCols);
  if (numRows > 10 || numCols > 10) {
    printf("Invalid input. Rows and columns should be less than or equal to 10.\n");
    return 0;
  }
  int numCells = numRows * numCols;
  int cells[numCells];
  for (int i = 0; i < numCells; i++) {
    cells[i] = i + 1;
  }
  int randNums[numCells/2]; // array to store random numbers
  int randIndex = 0; // index of randNums array
  int cellIndex; // index of cell that contains random number
  int randNum;
  while (randIndex < numCells/2) {
    randNum = generateRandomNumber(1, numCells); // generate random number
    if (!isInArray(randNums, randIndex, randNum)) { // check if number is not already in array
      randNums[randIndex] = randNum;
      randIndex++;
    }
  }
  int gameBoard[numRows][numCols];
  int index = 0; // index of randNums array
  // loop to fill game board with random numbers
  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j < numCols; j++) {
      if (index < numCells/2) { // first half of game board
        cellIndex = generateRandomNumber(0, numCells-1);
        while (isInArray(cells, numCells, cellIndex)) { // check if cell is not already used
          cellIndex = generateRandomNumber(0, numCells-1);
        }
        cells[index] = cellIndex;
        gameBoard[i][j] = randNums[index];
        gameBoard[numRows-1-i][numCols-1-j] = randNums[index];
        index++;
      } else { // second half of game board
        gameBoard[i][j] = 0;
        gameBoard[numRows-1-i][numCols-1-j] = 0;
      }
    }
  }
  int row1, col1, row2, col2;
  int numTries = 0;
  printf("\nGAME BOARD:\n");
  // loop to print game board
  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j < numCols; j++) {
      printf("%d ", gameBoard[i][j]);
    }
    printf("\n");
  }
  do { // loop to play game
    numTries++;
    printf("\nEnter the coordinates of first cell (row col): ");
    scanf("%d %d", &row1, &col1);
    printf("Enter the coordinates of second cell (row col): ");
    scanf("%d %d", &row2, &col2);
    if (gameBoard[row1-1][col1-1] == gameBoard[numRows-row2][numCols-col2]) {
      gameBoard[row1-1][col1-1] = -1;
      gameBoard[numRows-row2][numCols-col2] = -1;
      printf("\nMatch found! Number %d removed from board.\n", gameBoard[row1-1][col1-1]);
    } else {
      printf("\nNo match found. Try again.\n");
    }
    // loop to print updated game board
    printf("\nGAME BOARD:\n");
    for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < numCols; j++) {
        if (gameBoard[i][j] == -1) {
          printf("  ");
        } else {
          printf("%d ", gameBoard[i][j]);
        }
      }
      printf("\n");
    }
  } while (numTries != numCells/2);
  printf("\nCongratulations! You have won the game in %d tries.\n", numTries);
  return 0;
}