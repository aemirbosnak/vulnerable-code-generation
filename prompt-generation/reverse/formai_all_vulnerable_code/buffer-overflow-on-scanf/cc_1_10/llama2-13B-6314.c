//LLAMA2-13B DATASET v1.0 Category: Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to print a crazy message
void printCrazyMessage(void) {
  printf("WELCOME TO THE MOST EPIC C PROGRAM EVER!!!\n");
  printf("I AM A C PROGRAM, AND I AM HERE TO ROCK YOUR WORLD!!!\n");
  printf("I CAN DO ALL KINDS OF AMAZING THINGS, LIKE PRINTING CRAZY MESSAGES AND DOING CALCULATIONS!!!\n");
  printf("SO, GET READY TO BE AMAZED BY MY AWESOME POWERS!!!\n");
}

// Function to print a boring message
void printBoringMessage(void) {
  printf("Hello, this is a boring message.\n");
}

int main() {
  // Call the crazy message function
  printCrazyMessage();

  // Call the boring message function
  printBoringMessage();

  // Do some calculations
  int x = 5;
  int y = 10;
  int z = x + y;
  printf("The result of x + y is: %d\n", z);

  // Play a game of rock, paper, scissors
  int choice;
  int computerChoice;
  do {
    printf("Choose rock, paper, or scissors: ");
    scanf("%d", &choice);
    computerChoice = rand() % 3;
    if (choice == computerChoice) {
      printf("We have a tie!\n");
    } else if (choice == 1 && computerChoice == 2) {
      printf("You won! I chose rock, and you chose paper.\n");
    } else if (choice == 2 && computerChoice == 1) {
      printf("I won! I chose rock, and you chose scissors.\n");
    } else {
      printf("I won! I chose %d, and you chose %d.\n", computerChoice, choice);
    }
  } while (1);

  return 0;
}