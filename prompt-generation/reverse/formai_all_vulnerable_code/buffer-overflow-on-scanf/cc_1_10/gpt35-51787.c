//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*function to print out the player's ship status*/
void printStatus(int health, int fuel, int ammo) {
  printf("Current Status:\n");
  printf("Health: %d\n", health);
  printf("Fuel: %d\n", fuel);
  printf("Ammo: %d\n", ammo);
}

/*function to calculate the amount of resources found*/
int calcResource(int baseAmount, int randomness) {
  return (baseAmount + (rand() % randomness)); //return baseAmount plus a random number up to randomness
}

/*function to initiate a battle with space pirates*/
int battle(int health, int ammo) {
  int pirateHealth = 100;
  int pirateAmmo = 50;
  while (health > 0 && pirateHealth > 0) {
    pirateHealth -= ammo;
    if (pirateHealth <= 0) {
      printf("You destroyed the pirate ship!\n");
      return 1;
    }
    health -= pirateAmmo;
    if (health <= 0) {
      printf("Your ship has been destroyed. Game over.\n");
      return 0;
    }
  }
}

int main() {
  printf("Welcome to Space Adventure!\n");

  /*initialize player's resources*/
  int health = 100;
  int fuel = 200;
  int ammo = 50;

  while (1) { //game loop
    printf("What would you like to do? (explore/battle/quit)\n");
    char input[10];
    scanf("%s", input);

    if (strcmp(input, "explore") == 0) {
      printf("Exploring...\n");
      int resource = calcResource(10, 20);
      printf("You found %d fuel and %d ammo.\n", resource, resource/2);
      fuel += resource;
      ammo += resource/2;
      printStatus(health, fuel, ammo);
    }
    else if (strcmp(input, "battle") == 0) {
      printf("Entering battle...\n");
      if (battle(health, ammo)) {
        int resource = calcResource(30, 50);
        printf("You found %d health, %d fuel, and %d ammo from the wreckage.\n", resource, resource*2, resource/2);
        health += resource;
        fuel += resource*2;
        ammo += resource/2;
        printStatus(health, fuel, ammo);
      }
      else {
        printf("Game over.\n");
        break;
      }
    }
    else if (strcmp(input, "quit") == 0) {
      printf("Goodbye!\n");
      break;
    }
    else {
      printf("Invalid input. Try again.\n");
    }
  }

  return 0;
}