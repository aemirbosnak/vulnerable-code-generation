//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
void travel();
void fight();
void upgrade();
void rest();
void game_over();

// global variables
int ship_health = 100;
int armor = 50;
int weapon = 50;
int credits = 100;
int fuel = 100;
int sector = 1;

int main() {
  srand(time(0)); // seed random number generator

  printf("Welcome to Procedural Space Adventure!\n");

  // game loop
  while (ship_health > 0) {
    printf("\nCurrent Sector: %d\n", sector);
    printf("Ship Health: %d\n", ship_health);
    printf("Armor: %d\n", armor);
    printf("Weapon: %d\n", weapon);
    printf("Credits: %d\n", credits);
    printf("Fuel: %d\n", fuel);

    // prompt for action
    int choice;
    printf("\nWhat would you like to do?\n");
    printf("1. Travel to a new sector\n");
    printf("2. Fight enemy ships\n");
    printf("3. Upgrade your ship\n");
    printf("4. Rest and repair your ship\n");
    printf("5. Quit\n");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        travel();
        break;

      case 2:
        fight();
        break;

      case 3:
        upgrade();
        break;

      case 4:
        rest(); 
        break;

      case 5:
        game_over();
        break;

      default:
        printf("Invalid choice. Try again.\n");
    }
  }
  
  return 0;
}

// function to travel to a new sector
void travel() {
  int sector_chance = rand() % 10; // 10% chance of new sector
  int fuel_used = rand() % 20 + 10; // fuel use between 10-30

  if (fuel_used > fuel) {
    printf("Not enough fuel to travel to new sector!\n");
    return;
  }

  fuel -= fuel_used;

  if (sector_chance == 0) {
    printf("Discovered new sector!\n");
    sector++;
    credits += 50;
  }
  else {
    printf("Nothing eventful happened while traveling.\n");
  }
}

// function to fight enemy ships
void fight() {
  int enemy_strength = rand() % 100 + 1; // enemy strength between 1-100
  int damage_taken = enemy_strength - armor;

  if (damage_taken < 0) { // ensure damage taken is at least 1
    damage_taken = 1;
  }

  printf("Encountered enemy ship with strength %d.\n", enemy_strength);
  printf("Taking %d damage from enemy.\n", damage_taken);

  ship_health -= damage_taken;

  // check if player is dead
  if (ship_health <= 0) {
    printf("Your ship has been destroyed. Game over.\n");
    return;
  }

  printf("Destroyed enemy ship! Gained 25 credits.\n");
  credits += 25;
}

// function to upgrade ship
void upgrade() {
  // prompt for upgrade type
  int upgrade_choice;
  printf("\nWhat would you like to upgrade?\n");
  printf("1. Armor\n");
  printf("2. Weapon\n");
  scanf("%d", &upgrade_choice);

  // prompt for upgrade amount
  int upgrade_amount;
  printf("How much would you like to upgrade? (1-50)\n");
  scanf("%d", &upgrade_amount);

  if (upgrade_amount < 1 || upgrade_amount > 50) {
    printf("Invalid upgrade amount. Try again.\n");
    return;
  }

  // check if player has enough credits
  if (upgrade_amount * 2 > credits) {
    printf("Not enough credits to upgrade. Try again.\n");
    return;
  }

  credits -= upgrade_amount * 2;

  // apply upgrade
  switch (upgrade_choice) {
    case 1:
      armor += upgrade_amount;
      printf("Armor upgraded by %d points.\n", upgrade_amount);
      break;

    case 2:
      weapon += upgrade_amount;
      printf("Weapon upgraded by %d points.\n", upgrade_amount);
      break;

    default:
      printf("Invalid upgrade choice. Try again.\n");
  }
}

// function to rest and repair ship
void rest() {
  if (ship_health == 100) {
    printf("Ship health already at max. Nothing to repair.\n");
    return;
  }

  int repair_cost = 100 - ship_health;

  // check if player has enough credits
  if (repair_cost > credits) {
    printf("Not enough credits to repair ship. Try again.\n");
    return;
  }

  credits -= repair_cost;
  ship_health = 100;

  printf("Ship repaired to full health for %d credits.\n", repair_cost);
}

// function to end game
void game_over() {
  printf("Thanks for playing Procedural Space Adventure!\n");
  exit(0);
}