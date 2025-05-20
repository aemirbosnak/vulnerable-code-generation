//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: energetic
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void displayIntro() {
  printf("Welcome to the thrilling adventure game!\n");
  printf("Your mission is to explore the mysterious castle of Dracula and retrieve the treasure hidden inside!\n");
  printf("Be careful, Dracula is known to be a powerful vampire who doesn't take kindly to intruders.\n");
}

int main() {
  displayIntro();
  
  // Initialize game variables
  bool isGameOver = false;
  bool hasTreasure = false;
  int choice;
  
  // Game loop
  while (!isGameOver) {
    printf("\nWhat do you want to do?\n");
    printf("1. Go left\n");
    printf("2. Go right\n");
    printf("3. Go straight\n");
    printf("4. Quit\n");
    
    // Get user choice
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
      case 1:
        printf("You encounter a group of bats and get scared. You run back to the entrance!\n");
        break;
      case 2:
        printf("You find yourself in a dark hallway. You can barely see anything. Do you want to go left or go right?\n");
        printf("1. Go left.\n");
        printf("2. Go right.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
          printf("You trip on some stones and make a loud noise. Dracula hears you and sends his minions to attack you! Game over.\n");
          isGameOver = true;
        }
        else if (choice == 2) {
          printf("You find a torch and light it up. You can now see your way around. Keep going straight ahead.\n");
        }
        else {
          printf("Invalid choice!\n");
        }
        break;
      case 3:
        printf("You find yourself in a large room. You can hear the sound of dripping water coming from the corner. Do you want to investigate or leave the room?\n");
        printf("1. Investigate.\n");
        printf("2. Leave the room.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
          printf("You find the treasure! Congratulations! You win!\n");
          hasTreasure = true;
          isGameOver = true;
        }
        else if (choice == 2) {
          printf("You leave the room but feel like you missed something important.\n");
        }
        else {
          printf("Invalid choice\n");
        }
        break;
      case 4:
        printf("You quit the game. Thanks for playing!\n");
        isGameOver = true;
        break;
      default:
        printf("Invalid choice!\n");
        break;
    }
  }
  
  return 0;
}