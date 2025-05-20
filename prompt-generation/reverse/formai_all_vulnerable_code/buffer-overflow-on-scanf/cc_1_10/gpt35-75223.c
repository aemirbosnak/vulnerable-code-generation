//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function prototypes
int generateAlien();
void generateShip(int *fuel, int *health);
void engageFight(int *fuel, int *health, int *ammo, int alienType);

int main() {
  srand(time(NULL));
  int fuel = 30, health = 100, ammo = 20;
  int choice;
  printf("Welcome to the Medieval Space Adventure!\n");
  printf("You are the captain of a medieval spaceship on a journey to explore the galaxy.\n");
  printf("You have limited fuel and ammo, and your ship's health is crucial.\n");

  while (fuel > 0 && health > 0) {
    printf("\nSelect an option:\n");
    printf("1. Explore the galaxy\n");
    printf("2. Rest and repair your ship\n");
    printf("3. Engage in a fight\n");
    printf("4. Quit\n");

    scanf("%d", &choice);

    switch (choice) {
      case 1:
        generateShip(&fuel, &health);
        break;
      case 2:
        printf("You rest and repair your ship.\n");
        health = 100;
        break;
      case 3:
        engageFight(&fuel, &health, &ammo, generateAlien());
        break;
      case 4:
        printf("You decide to quit your adventure. Better luck next time!\n");
        exit(0);
      default:
        printf("Invalid option. Please select an integer between 1 and 4.\n");
    }
  }

  if (health <= 0) {
    printf("Your spaceship has been destroyed. Game over.\n");
  } else if (fuel <= 0) {
    printf("You have run out of fuel. Game over.\n");
  }

  return 0;
}

int generateAlien() {
  int alienType;
  alienType = rand() % 5 + 1;
  switch (alienType) {
    case 1:
      printf("You have encountered an Orc from a nearby planet. (%d health)\n", rand() % 30 + 10);
      break;
    case 2:
      printf("You have encountered a Dark Knight from a distant galaxy. (%d health)\n", rand() % 50 + 30);
      break;
    case 3:
      printf("You have encountered a Giant Troll from a nearby asteroid belt. (%d health)\n", rand() % 70 + 50);
      break;
    case 4:
      printf("You have encountered a Fire Elemental from a volcanic planet. (%d health)\n", rand() % 40 + 20);
      break;
    case 5:
      printf("You have encountered a Dragon from a remote nebula. (%d health)\n", rand() % 100 + 80);
      break;
  }
  return alienType;
}

void generateShip(int *fuel, int *health) {
  int fuelConsumed = rand() % 10 + 1;
  int damageTaken = rand() % 20 + 1;
  printf("You explore the galaxy and find a spacecraft.\n");
  printf("You spend %d fuel.\n", fuelConsumed);
  printf("Your ship takes %d damage.\n", damageTaken);
  *fuel -= fuelConsumed;
  *health -= damageTaken;

  if (*health <= 0) {
    printf("Your spaceship has been destroyed. Game over.\n");
    exit(0);
  } else if (*fuel <= 0) {
    printf("You have run out of fuel. Game over.\n");
    exit(0);
  }
}

void engageFight(int *fuel, int *health, int *ammo, int alienType) {
  printf("You engage in a fight!\n");
  int alienHealth;
  switch (alienType) {
    case 1:
      alienHealth = rand() % 30 + 10;
      break;
    case 2:
      alienHealth = rand() % 50 + 30;
      break;
    case 3:
      alienHealth = rand() % 70 + 50;
      break;
    case 4:
      alienHealth = rand() % 40 + 20;
      break;
    case 5:
      alienHealth = rand() % 100 + 80;
      break;
  }
  while (alienHealth > 0 && *health > 0 && *ammo > 0) {
    printf("Your spaceship's health: %d\n", *health);
    printf("Your ammo supplies: %d\n", *ammo);
    printf("Alien health: %d\n", alienHealth);
    printf("Select your weapon:\n");
    printf("1. Sword\n");
    printf("2. Bow and Arrow\n");
    printf("3. Laser Gun\n");
    int weaponChoice;
    scanf("%d", &weaponChoice);
    switch (weaponChoice) {
      case 1:
        printf("You swing your sword and deal %d damage to the alien.\n", rand() % 10 + 5);
        alienHealth -= rand() % 10 + 5;
        break;
      case 2:
        if (*ammo > 0) {
          printf("You shoot your arrow and deal %d damage to the alien.\n", rand() % 15 + 10);
          alienHealth -= rand() % 15 + 10;
          (*ammo)--;
        } else {
          printf("You have run out of arrows!\n");
        }
        break;
      case 3:
        if (*ammo > 0) {
          printf("You shoot your laser gun and deal %d damage to the alien.\n", rand() % 20 + 15);
          alienHealth -= rand() % 20 + 15;
          (*ammo)--;
        } else {
          printf("You have run out of ammo for your laser gun!\n");
        }
        break;
      default:
        printf("Invalid weapon. Please select an integer between 1 and 3.\n");
    }

    if (alienHealth > 0) {
      printf("The alien attacks!\n");
      int damageTaken = rand() % 20 + 10;
      printf("Your ship takes %d damage.\n", damageTaken);
      *health -= damageTaken;
      if (*health <= 0) {
        printf("Your spaceship has been destroyed. Game over.\n");
        exit(0);
      }
    }
  }

  if (alienHealth <= 0) {
    printf("You have defeated the alien!\n");
    int fuelGained = rand() % 10 + 1;
    printf("You gain %d fuel.\n", fuelGained);
    *fuel += fuelGained;
  }
}