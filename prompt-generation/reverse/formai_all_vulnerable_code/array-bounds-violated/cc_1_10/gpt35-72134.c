//FormAI DATASET v1.0 Category: Table Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate a random number between 1 and 10
int randNum() {
  srand(time(0));
  return (rand() % 10) + 1;
}

// function to display the table
void displayTable(int table[10][10]) {
  printf("   ");
  for (int i = 1; i <= 10; i++) {
    printf("%3d", i);
  }
  printf("\n");
  
  for (int i = 0; i < 10; i++) {
    printf("%3d", i+1);
    for (int j = 0; j < 10; j++) {
      printf("%3d", table[i][j]);
    }
    printf("\n");
  }
}

int main() {
  printf("Welcome to the C Table Game!\n");
  printf("In this game, you will try to guess the hidden number in the table.\n");
  
  int table[10][10];
  
  // fill the table with random numbers
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      table[i][j] = randNum();
    }
  }
  
  // display the table
  printf("Here is the table:\n");
  displayTable(table);
  
  int guess = 0, row, col;
  int attempts = 0;
  
  while (guess != table[row][col]) {
    attempts++;
    printf("Attempt #%d\n", attempts);
    
    // get user input for row and column
    printf("Enter a row number (1-10): ");
    scanf("%d", &row);
    
    printf("Enter a column number (1-10): ");
    scanf("%d", &col);
    
    guess = table[row-1][col-1];
    
    if (guess < table[row-1][col-1]) {
      printf("The hidden number is less than %d.\n", guess);
    } else if (guess > table[row-1][col-1]) {
      printf("The hidden number is greater than %d.\n", guess);
    } else {
      printf("Congratulations! You found the hidden number in %d attempts.\n", attempts);
    }
  }
  
  return 0;
}