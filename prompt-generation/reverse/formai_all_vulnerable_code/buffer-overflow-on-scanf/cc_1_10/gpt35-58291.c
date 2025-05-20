//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototype
void printMenu();
void explorePlanet(int planetNumber);
void battleAlien(int planetNumber);
void upgradeWeapon();
void showStats();

// Global variables
int currentPlanet = 1;
int currentWeaponLevel = 1;
int numberOfAliensDefeated = 0;

int main() {
  srand(time(NULL)); // Seed the random number generator with the current time

  printf("Welcome to the Procedural Space Adventure!\n\n");
  printMenu();

  int choice;
  do {
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        explorePlanet(currentPlanet);
        break;
      
      case 2:
        battleAlien(currentPlanet);
        break;
      
      case 3:
        upgradeWeapon();
        break;
      
      case 4:
        showStats();
        break;
      
      case 5:
        printf("Thanks for playing!\n\n");
        break;

      default:
        printf("Invalid choice, please try again.\n\n");
        break;
    }

    if (currentPlanet == 10) { // Player has reached the final planet
      printf("Congratulations! You have completed your journey through the galaxy.\n\n");
      break;
    }

    printMenu();
  } while (choice != 5);

  return 0;
}

void printMenu() {
  printf("What would you like to do?\n");
  printf("1) Explore planet %d\n", currentPlanet);
  printf("2) Battle an alien on planet %d\n", currentPlanet);
  printf("3) Upgrade weapon\n");
  printf("4) Show statistics\n");
  printf("5) Quit game\n\n");
}

void explorePlanet(int planetNumber) {
  printf("You explore planet %d and find nothing of interest.\n\n", planetNumber);

  // Roll the dice to determine if an alien encounter occurs
  int diceRoll = rand() % 6 + 1;
  if (diceRoll == 1) {
    printf("Oh no! An alien is attacking you!\n");
    battleAlien(planetNumber);
  }
}

void battleAlien(int planetNumber) {
  int alienHealth = rand() % (10 * planetNumber) + 1; // Alien's health is based on the planet number
  int playerHealth = 100;
  int damageDealt;

  printf("You encounter an alien with %d health.\n", alienHealth);
  printf("You have %d health.\n\n", playerHealth);

  while (alienHealth > 0 && playerHealth > 0) {
    damageDealt = rand() % (10 * currentWeaponLevel) + 1; // Player's damage is based on weapon level
    playerHealth -= rand() % 11 + 1; // Alien's damage is random between 1 and 11
    alienHealth -= damageDealt;

    printf("You deal %d damage to the alien.\n", damageDealt);
    printf("The alien deals %d damage to you.\n", rand() % 11 + 1);

    printf("You have %d health.\n", playerHealth);
    printf("The alien has %d health.\n\n", alienHealth);
  }

  if (playerHealth <= 0) {
    printf("You have been defeated by the alien!\n\n");
    return;
  }

  printf("You have defeated the alien!\n\n");
  numberOfAliensDefeated++;

  // Move the player to the next planet
  currentPlanet++;
}

void upgradeWeapon() {
  int cost = 10 * currentWeaponLevel;

  if (numberOfAliensDefeated < cost) {
    printf("You do not have enough alien defeats to upgrade your weapon. You need %d defeats and you currently have %d.\n\n", cost, numberOfAliensDefeated);
    return;
  }

  currentWeaponLevel++;
  numberOfAliensDefeated -= cost;

  printf("Your weapon has been upgraded to level %d!\n\n", currentWeaponLevel);
}

void showStats() {
  printf("Current planet: %d\n", currentPlanet);
  printf("Current weapon level: %d\n", currentWeaponLevel);
  printf("Number of defeated aliens: %d\n\n", numberOfAliensDefeated);
}