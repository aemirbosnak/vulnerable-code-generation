//Gemma-7B DATASET v1.0 Category: Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main() {
  int choice, score = 0, lives = 5;
  char name[20];

  printf("Welcome to the fantastical realm of Quibble Manor.\n");
  printf("Please enter your name: ");
  scanf("%s", name);

  printf("Greetings, %s, prepare for a journey of epic proportions.\n", name);

  while (lives > 0) {
    printf("You have %d lives remaining.\n", lives);

    printf("What would you like to do? (1) Fight the evil dragon, (2) Cast a spell, (3) Search for treasures:\n");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        // Fight the dragon
        printf("You bravely fought the dragon and slayed it.\n");
        score++;
        break;
      case 2:
        // Cast a spell
        printf("You cast a spell and summoned a flock of fiery phoenixes.\n");
        score++;
        break;
      case 3:
        // Search for treasures
        printf("You searched for treasures and found a hidden diamond. \n");
        score++;
        break;
      default:
        printf("Invalid choice. Please try again.\n");
    }

    // Check if the player has won or lost
    if (score >= 3) {
      printf("Congratulations, %s, you have won the game! You are now a hero of Quibble Manor.\n", name);
      break;
    } else if (lives == 0) {
      printf("Sorry, %s, your journey has ended. You have run out of lives.\n", name);
      break;
    }
  }

  return 0;
}