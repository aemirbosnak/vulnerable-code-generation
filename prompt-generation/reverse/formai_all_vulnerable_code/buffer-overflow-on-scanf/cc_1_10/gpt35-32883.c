//FormAI DATASET v1.0 Category: Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  // Prompt user for their name
  char name[20];
  printf("Welcome brave adventurer! What is your name?\n");
  printf("Name: ");
  fgets(name, 20, stdin);

  // Declare variables for player stats
  int health = 100;
  int strength = 10;
  int gold = 0;

  // Generate random number to determine enemy's strength
  srand(time(NULL));
  int enemy_strength = rand() % 10 + 1;

  // Set flag for player status (alive or dead)
  int alive = 1;

  // Game loop
  while (alive) {

    // Display player stats
    printf("\n%s's Stats:\n", name);
    printf("Health: %d\n", health);
    printf("Strength: %d\n", strength);
    printf("Gold: %d\n", gold);

    // Prompt user for action
    printf("\nWhat would you like to do?\n");
    printf("1. Fight an enemy\n");
    printf("2. Go on a quest\n");
    printf("3. Exit game\n");
    printf("Action: ");

    int choice;
    scanf("%d", &choice);

    switch(choice) {
      // Fight an enemy
      case 1:
        printf("\nYou encounter an enemy!\n");
        printf("Enemy Strength: %d\n", enemy_strength);

        // Determine outcome of battle based on player and enemy strength
        if (strength >= enemy_strength) {
          printf("You defeat the enemy and gain 10 gold.\n");
          gold += 10;
        }
        else {
          printf("You are defeated and lose 20 health.\n");
          health -= 20;
          if (health <= 0) {
            alive = 0;
            printf("You have died. Game over.\n");
          }
        }
        break;

      // Go on a quest
      case 2:
        printf("\nYou embark on a quest and find a treasure chest!\n");
        printf("Do you want to open it? (1 for Yes, 0 for No)\n");
        int open_choice;
        scanf("%d", &open_choice);

        if (open_choice == 1) {
          printf("You found 50 gold!\n");
          gold += 50;
        }
        else {
          printf("You decide not to open the chest.\n");
        }
        break;

      // Exit game
      case 3:
        alive = 0;
        printf("\nThanks for playing!\n");
        break;

      // Invalid input
      default:
        printf("\nInvalid choice. Try again.\n");
        break;
    } 
  }

  return 0;
}