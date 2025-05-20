//FormAI DATASET v1.0 Category: Table Game ; Style: secure
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// Declare function prototypes
void displayInstructions();
int rollDice();
void playGame();

int main() {
  // Display game instructions
  displayInstructions();
  
  // Play the game!
  playGame();

  return 0;
}

// Function to display game instructions
void displayInstructions() {
  printf("Welcome to C Table Game!\n");
  printf("The objective of this game is to roll a pair of dice and guess whether the combined value will be odd or even.\n");
}

// Function to roll the dice
int rollDice() {
  int die1, die2, total;
  
  // Seed the random number generator
  srand(time(NULL));
  
  // Roll the dice
  die1 = rand() % 6 + 1;
  die2 = rand() % 6 + 1;
  
  // Calculate the total value
  total = die1 + die2;
  
  // Display the roll
  printf("You rolled a %d and a %d for a total of %d\n", die1, die2, total);
  
  return total;
}

// Function to play the game
void playGame() {
  int prediction, total;
  bool isOdd;
  
  // Prompt the user to make a prediction
  printf("Enter 1 if you think the total will be odd, and 2 if you think it will be even: ");
  scanf("%d", &prediction);
  
  // Validate the prediction
  if(prediction != 1 && prediction != 2) {
    printf("Invalid prediction!\n");
    return;
  }
  
  // Roll the dice
  total = rollDice();
  
  // Determine if the total is odd or even
  if(total % 2 == 0) {
    printf("The total is even!\n");
    isOdd = false;
  } else {
    printf("The total is odd!\n");
    isOdd = true;
  }
  
  // Compare the prediction to the actual result and display the outcome
  if(prediction == 1 && isOdd || prediction == 2 && !isOdd) {
    printf("Congratulations! You win!\n");
  } else {
    printf("Sorry, you lose. Better luck next time!\n");
  }
}