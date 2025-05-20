#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int score = 0;
  char name[100];

  printf("Enter your name: ");
  scanf("%s", name);

  printf("Welcome, %s! Let's play a game of text-based adventure.", name);

  // Infinite loop to simulate game gameplay
  while (1) {
    int choice;

    printf("What do you want to do? (1) Travel, (2) Fight, (3) Cast Spell:");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        score++;
        printf("You traveled to a new land. You have gained %d points.", score);
        break;
      case 2:
        score -= 2;
        printf("You fought a monster and lost %d points.", score);
        break;
      case 3:
        score += 3;
        printf("You cast a spell and gained %d points.", score);
        break;
      default:
        printf("Invalid input. Please try again.");
    }

    // Check if the player has won or lost
    if (score > 100) {
      printf("Congratulations, %s! You have won the game!", name);
      break;
    } else if (score < 0) {
      printf("Sorry, %s. You have lost the game.", name);
      break;
    }
  }

  return 0;
}
