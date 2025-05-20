//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define MAX_LIVES 3

typedef struct Character {
  char name[20];
  int health;
  int strength;
  int agility;
  int intelligence;
} Character;

Character hero;

void initializeHero() {
  hero.name[0] = '\0';
  hero.health = MAX_LIVES;
  hero.strength = 5;
  hero.agility = 6;
  hero.intelligence = 4;
}

int main() {
  initializeHero();

  printf("Welcome, %s, to the realm of Theia!\n", hero.name);

  // Game Loop
  while (hero.health > 0) {
    // Display available actions
    printf("What would you like to do? (attack, defend, cast spell, inventory)\n");

    char action;
    scanf(" %c", &action);

    switch (action) {
      case 'a':
        // Attack
        printf("You attacked your enemy!\n");
        break;
      case 'd':
        // Defend
        printf("You defended against your enemy's attack.\n");
        break;
      case 'c':
        // Cast Spell
        printf("You cast a spell on your enemy.\n");
        break;
      case 'i':
        // Inventory
        printf("Your inventory:\n");
        break;
      default:
        printf("Invalid action.\n");
    }

    // Check if the hero is still alive
    if (hero.health <= 0) {
      printf("Game over, %s. You have perished in the realm of Theia.\n", hero.name);
    }
  }

  return 0;
}