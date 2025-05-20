//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
int randomNumber(int min, int max);
int playGame(int health, int ammo, int fuel);

int main() {
  srand(time(NULL)); // Seed random number generator

  printf("Welcome to Procedural Space Adventure!\n");
  printf("You are the captain of a space ship on a mission to explore the universe.\n");

  int health = 100;
  int ammo = 10;
  int fuel = 100;

  int result = playGame(health, ammo, fuel);

  printf("\n\nGAME OVER\n");
  printf("Final Score: %d\n", result);

  return 0;
}

// Generate a random number between a min and max value
int randomNumber(int min, int max) {
  return (rand() % (max - min + 1)) + min;
}

// Recursive function representing a single turn of gameplay
int playGame(int health, int ammo, int fuel) {
  // Check if player is out of resources
  if (health <= 0 || ammo <= 0 || fuel <= 0) {
    printf("You have run out of resources and lost the game...\n");
    return 0;
  }

  // Print current status
  printf("\nCurrent Status:\n");
  printf("Health: %d\n", health);
  printf("Ammo: %d\n", ammo);
  printf("Fuel: %d\n\n", fuel);

  // Ask player for their action
  printf("What would you like to do?\n");
  printf("1. Explore a planet\n");
  printf("2. Battle an alien race\n");
  printf("3. Travel to a new star system\n");
  printf("Please enter your choice (1-3): ");

  int choice;
  scanf("%d", &choice);

  // Perform action based on player's choice
  if (choice == 1) {
    printf("\nExploring planet...\n");

    // Generate random events
    int event = randomNumber(1, 3);
    switch (event) {
      case 1:
        printf("You have discovered a cache of resources!\n");
        health += 20;
        ammo += 5;
        fuel += 20;
        break;
      case 2:
        printf("You encounter a hostile alien creature!\n");
        health -= 25;
        ammo -= 5;
        break;
      case 3:
        printf("You find nothing of interest...\n");
        fuel -= 10;
        break;
    }
  } else if (choice == 2) {
    printf("\nFighting an alien race...\n");

    // Generate random events
    int event = randomNumber(1, 3);
    switch (event) {
      case 1:
        printf("Enemy destroyed!\n");
        health += 10;
        ammo -= 5;
        fuel -= 5;
        break;
      case 2:
        printf("Enemy heavily damages your ship!\n");
        health -= 50;
        ammo -= 10;
        fuel -= 10;
        break;
      case 3:
        printf("Enemy retreats!\n");
        fuel -= 5;
        break;
    }
  } else if (choice == 3) {
    printf("\nTravelling to new star system...\n");

    // Generate random events
    int event = randomNumber(1, 3);
    switch (event) {
      case 1:
        printf("You arrive safely at the new star system!\n");
        health += 10;
        ammo -= 5;
        fuel -= 20;
        break;
      case 2:
        printf("Your ship encounters a malfunction!\n");
        health -= 25;
        ammo -= 5;
        fuel -= 20;
        break;
      case 3:
        printf("Your ship encounters a wormhole and is transported to an unknown location!\n");
        health -= 10;
        ammo -= 5;
        fuel = 0;
        break;
    }
  } else {
    // Handle invalid input
    printf("\nInvalid input, please try again.\n");
    return playGame(health, ammo, fuel);
  }

  // Recursively call playGame() again for the next turn
  return playGame(health, ammo, fuel);
}