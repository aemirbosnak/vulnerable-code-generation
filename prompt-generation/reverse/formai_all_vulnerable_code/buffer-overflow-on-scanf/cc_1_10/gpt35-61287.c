//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int room = 1; // starting room
  int playerHealth = 100; // starting player health
  int ghostHealth = 50; // starting ghost health
  int damage; // damage done by player or ghost
  int playerChoice; // player's choice for next action
  int ghostChoice; // ghost's choice for next action

  srand(time(0)); // seed random number generator with current time

  printf("Welcome to the Haunted House Simulator!\n\n");
  printf("You find yourself in a dark room. You can barely see your own hands in front of your face.\n");
  printf("Suddenly, you hear a creaking noise coming from the other side of the room.\n");
  
  while (room <= 5) { // while player has not reached end of house
    printf("\nYou are in room %d.\n", room);

    // player's turn
    printf("\nWhat would you like to do?\n");
    printf("1. Explore the room.\n");
    printf("2. Stay put and hide.\n");
    printf("3. Attack the ghost.\n");
    scanf("%d", &playerChoice);

    if (playerChoice == 1) { // explore the room
      printf("\nYou search the room but find nothing of interest.\n");
    }
    else if (playerChoice == 2) { // stay put and hide
      printf("\nYou stay put and hide in the corner of the room.\n");
    }
    else if (playerChoice == 3) { // attack the ghost
      damage = rand() % 10 + 1; // random damage between 1 and 10
      
      printf("\nYou attack the ghost and deal %d damage!\n", damage);
      ghostHealth -= damage;

      if (ghostHealth <= 0) { // ghost is defeated
        printf("\nYou have defeated the ghost in this room!\n");
        ghostHealth = 50; // reset ghost health for next room
        room++; // move to next room
        continue; // skip ghost's turn
      }
    }

    // ghost's turn
    ghostChoice = rand() % 3 + 1; // random between 1 and 3

    if (ghostChoice == 1) { // ghost attacks
      damage = rand() % 10 + 1; // random damage between 1 and 10
      
      printf("\nThe ghost attacks you and deals %d damage!\n", damage);
      playerHealth -= damage;

      if (playerHealth <= 0) { // player is defeated
        printf("\nYou have been defeated by the ghost. Game over.\n");
        return 0;
      }
    }
    else if (ghostChoice == 2) { // ghost moves to another room
      printf("\nThe ghost disappears and you hear it creaking in another room.\n");
      room++; // move to next room
    }
    else if (ghostChoice == 3) { // ghost does nothing
      printf("\nThe ghost does nothing.\n");
    }
  }

  printf("\nCongratulations, you have made it through the haunted house!\n");
  return 0;
}