//FormAI DATASET v1.0 Category: Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Function to display the game menu
void displayMenu(){
  printf("\t\t Galactic Adventure\n");
  printf("1. Start game\n");
  printf("2. Instructions\n");
  printf("3. Quit\n");
}

// Function to display the instructions
void displayInstructions(){
  printf("\nWelcome to Galactic Adventure!\n");
  printf("You are a space explorer on a mission to discover new planets and resources.\n");
  printf("As you explore, you will encounter different creatures and obstacles.\n");
  printf("Your choices will affect the outcome of the game, so choose wisely!\n\n");
}

int main(){

  int choice;
  
  // Display the game menu
  do {
    displayMenu();
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Check for user's input
    switch (choice){
      case 1: // Start the game
        printf("Game starting...\n");
        // Code for the game logic goes here
        break;
      case 2: // Display the instructions
        displayInstructions();
        break;
      case 3: // Quit the game
        printf("Thanks for playing Galactic Adventure!\n");
        exit(0);
        break;
      default: // Invalid choice
        printf("Invalid choice. Please try again.\n");
        break;
    }

  } while(choice != 3);

  return 0;
}