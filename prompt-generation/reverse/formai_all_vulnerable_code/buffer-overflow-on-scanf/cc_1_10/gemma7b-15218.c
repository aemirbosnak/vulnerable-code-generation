//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_HEALTH 100
#define MAX_MANA 100

typedef struct character {
  char name[20];
  int health, mana, level, experience, inventory[10];
} character;

character hero;

void initialize_character() {
  hero.name[0] = '\0';
  hero.health = MAX_HEALTH;
  hero.mana = MAX_MANA;
  hero.level = 1;
  hero.experience = 0;
  for (int i = 0; i < 10; i++) {
    hero.inventory[i] = 0;
  }
}

void display_inventory() {
  printf("Inventory:\n");
  for (int i = 0; i < 10; i++) {
    if (hero.inventory[i] != 0) {
      printf("%d. %s\n", i + 1, hero.inventory[i]);
    }
  }
}

void attack() {
  printf("Enter the target's number:");
  int target_number;
  scanf("%d", &target_number);

  if (hero.inventory[target_number] != 0) {
    printf("You hit the target with %s.\n", hero.inventory[target_number]);
    hero.experience++;
  } else {
    printf("Target not found.\n");
  }
}

int main() {
  initialize_character();

  while (hero.health > 0) {
    printf("Health: %d, Mana: %d\n", hero.health, hero.mana);
    display_inventory();
    attack();
  }

  printf("Game Over.\n");

  return 0;
}