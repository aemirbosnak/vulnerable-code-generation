//Code Llama-13B DATASET v1.0 Category: Table Game ; Style: interoperable
/*
 * A simple table game program that generates a table with random numbers and
 * allows the user to make a bet on the sum of the two random numbers.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TABLE_SIZE 5
#define MAX_BET 100

int main() {
  int table[TABLE_SIZE][TABLE_SIZE];
  int bet, sum;

  srand(time(NULL));

  // Generate a random number for each cell in the table
  for (int i = 0; i < TABLE_SIZE; i++) {
    for (int j = 0; j < TABLE_SIZE; j++) {
      table[i][j] = rand() % 10;
    }
  }

  // Print the table
  printf("Here is your table:\n");
  for (int i = 0; i < TABLE_SIZE; i++) {
    for (int j = 0; j < TABLE_SIZE; j++) {
      printf("%d ", table[i][j]);
    }
    printf("\n");
  }

  // Ask the user to make a bet
  printf("What is your bet? (max %d): ", MAX_BET);
  scanf("%d", &bet);

  // Calculate the sum of the two random numbers
  sum = table[0][0] + table[1][1];

  // Check if the user won
  if (sum == bet) {
    printf("Congratulations! You won %d!\n", bet * 2);
  } else {
    printf("Sorry, you lost. The correct answer was %d.\n", sum);
  }

  return 0;
}