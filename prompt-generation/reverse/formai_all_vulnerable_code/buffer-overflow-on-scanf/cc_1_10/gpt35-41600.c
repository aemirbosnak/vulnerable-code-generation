//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Variables to store user input and game state
  int choice, gameState = 1;

  // Seed random number generator
  srand(time(NULL));

  // Haunted house simulator loop
  while (gameState == 1) {
    printf("\nWelcome to the Haunted House Simulator!\n");
    printf("You are standing at the entrance of a spooky mansion, what do you want to do?\n");
    printf("1. Enter the mansion\n");
    printf("2. Leave the area\n");
    printf("Your choice: ");

    // Get user choice
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("\nYou cautiously enter the mansion...\n");
        break;
      case 2:
        printf("\nYou're too scared to enter the mansion. You quickly leave the area.\n");
        gameState = 0;
        break;
      default:
        printf("\nInvalid choice. Please try again.\n");
        break;
    }

    // Random event generator
    int eventChance = rand() % 101;

    if (eventChance > 50) {
      printf("\nSuddenly, you hear a loud noise coming from the second floor.\n");
      printf("What do you want to do?\n");
      printf("1. Investigate the noise\n");
      printf("2. Ignore the noise\n");
      printf("Your choice: ");

      // Get user choice
      scanf("%d", &choice);

      switch (choice) {
        case 1:
          printf("\nYou approach the stairs and climb up to the second floor...\n");
          break;
        case 2:
          printf("\nYou decide to ignore the noise and explore the ground floor.\n");
          break;
        default:
          printf("\nInvalid choice. Please try again.\n");
          break;
      }

      // Random encounter generator
      int enemyChance = rand() % 101;

      if (enemyChance > 75) {
        printf("\nYou encounter a ghostly apparition!\n");
        printf("What do you want to do?\n");
        printf("1. Run away!\n");
        printf("2. Confront the ghost\n");
        printf("Your choice: ");

        // Get user choice
        scanf("%d", &choice);

        switch (choice) {
          case 1:
            printf("\nYou run as fast as you can back to the entrance and escape the mansion.\n");
            printf("Congratulations! You survived the Haunted House Simulator.\n");
            gameState = 0;
            break;
          case 2:
            printf("\nYou prepare to confront the ghostly apparition...\n");
            printf("The ghostly apparition disappears without a trace.\n");
            break;
          default:
            printf("\nInvalid choice. Please try again.\n");
            break;
        }
      }
    }
  }

  // End of program
  printf("\nThank you for playing the Haunted House Simulator!\n");
  return 0;
}