//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

int main() {
  int choice;
  
  printf("Welcome to the Text-Based Adventure Game!\n");
  printf("You find yourself in a dark room with two doors. Do you go through door 1 or door 2?\n");
  
  scanf("%d", &choice);
  
  if (choice == 1) {
    printf("You enter a room filled with treasure! Congratulations!\n");
  } else if (choice == 2) {
    printf("You enter a room filled with monsters! Game over!\n");
    return 0;
  } else {
    printf("Invalid choice. Please try again.\n");
    return 0;
  }
  
  printf("You notice a trap door in the corner of the room. Do you open it?\n");
  printf("1. Yes\n");
  printf("2. No\n");
  
  scanf("%d", &choice);
  
  if (choice == 1) {
    printf("You climb down the trap door and find yourself in a labyrinth. You must find your way out!\n");
    printf("You reach a fork in the path. Do you go left or right?\n");
    
    scanf("%d", &choice);
    
    if (choice == 1) {
      printf("You take the left path and come across a giant spider! Fight or flight?\n");
      printf("1. Fight\n");
      printf("2. Flight\n");
      
      scanf("%d", &choice);
      
      if (choice == 1) {
        printf("You defeated the spider and find a key to unlock the door at the end of the labyrinth!\n");
        printf("You escaped the labyrinth and won the game! Congratulations!\n");
        return 0;
      } else {
        printf("You run away and get lost in the labyrinth. Game over!\n");
        return 0;
      }
    } else if (choice == 2) {
      printf("You take the right path and come across a troll guarding the door at the end of the labyrinth. Fight or bribe?\n");
      printf("1. Fight\n");
      printf("2. Bribe\n");
      
      scanf("%d", &choice);
      
      if (choice == 1) {
        printf("You defeated the troll and unlocked the door at the end of the labyrinth!\n");
        printf("You escaped the labyrinth and won the game! Congratulations!\n");
        return 0;
      } else {
        printf("You bribe the troll with your treasure from the previous room and unlock the door at the end of the labyrinth!\n");
        printf("You escaped the labyrinth and won the game! Congratulations!\n");
        return 0;
      }
    } else {
      printf("Invalid choice. Please try again.\n");
      return 0;
    }
  } else if (choice == 2) {
    printf("You decide not to open the trap door and look for another way out. You find a hidden passage that leads you to the exit!\n");
    printf("You escaped the labyrinth and won the game! Congratulations!\n");
    return 0;
  } else {
    printf("Invalid choice. Please try again.\n");
    return 0;
  }
  
  return 0;
}