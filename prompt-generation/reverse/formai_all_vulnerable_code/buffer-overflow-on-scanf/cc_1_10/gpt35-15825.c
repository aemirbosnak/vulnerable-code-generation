//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: intelligent
#include <stdio.h>

int main() {
  char name[20];
  int health = 100;
  int coins = 0;
  int damage = 0;
  int choice;

  printf("Welcome to The Adventure Game!\n");
  printf("What is your name, adventurer?\n");
  scanf("%s", name);

  printf("Hello, %s! Your journey starts here.\n", name);
  printf("You have %d health and %d coins.\n", health, coins);

  printf("\nYou are walking through a forest when a goblin suddenly appears!\n");
  printf("The goblin is level 1 and has 10 health points.\n");

  while (health > 0) {
    printf("\nWhat do you want to do? Choose a number:\n");
    printf("1. Fight the goblin\n");
    printf("2. Run away\n");

    scanf("%d", &choice);

    if (choice == 1) {
      printf("\nYou attack the goblin!\n");
      damage = 20;
      health -= damage;
      printf("You dealt %d damage. The goblin has %d health left.\n", damage, health);

      if (health <= 0) {
        printf("You were defeated by the goblin! Game over.\n");
        return 0;
      }

      printf("The goblin attacks you!\n");
      damage = 5;
      health -= damage;
      printf("The goblin dealt %d damage. You have %d health left.\n", damage, health);

    } else if (choice == 2) {
      printf("\nYou run away from the goblin. Coward.\n");
      return 0;
    } else {
      printf("\nInvalid choice. Choose again.\n");
    }
  }

  return 0;
}