//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
  srand(time(NULL)); // Seed random number generator
  printf("Welcome to our space adventure game!\n\n");

  // Initialize player stats
  int health = 100;
  int armor = 50;
  int fuel = 100;

  // Get player name
  printf("What is your name, adventurer? ");
  char player_name[20];
  scanf("%s", player_name);

  // Introduction
  printf("\nWelcome, %s! You are about to embark on a thrilling space adventure.\n\n", player_name);

  // Main game loop
  while (health > 0 && fuel > 0) {
    // Generate random event
    int event = rand() % 3;

    // Handle event based on random number
    if (event == 0) {
      printf("You have discovered a new planet!\n");
      fuel -= 10;
      printf("You used 10 units of fuel.\n");
      printf("Your remaining fuel is %d.\n\n", fuel);
    }
    else if (event == 1) {
      printf("You have encountered an alien ship!\n");
      int alien_health = rand() % 50 + 50;
      int alien_attack = rand() % 20 + 10;
      int player_attack = rand() % 20 + 10;
      printf("You enter combat with the alien ship!\n");
      while (health > 0 && alien_health > 0) {
        // Player attacks alien
        alien_health -= player_attack;
        printf("You attack the alien ship for %d damage.\n", player_attack);
        if (alien_health <= 0) {
          printf("You have defeated the alien ship!\n");
          printf("Your health is %d.\n", health);
          break;
        }
        // Alien attacks player
        health -= alien_attack;
        printf("The alien ship attacks you for %d damage.\n", alien_attack);
        printf("Your health is %d.\n", health);
        if (health <= 0) {
          printf("You have been defeated by the alien ship.\n");
          break;
        }
      }
    }
    else if (event == 2) {
      printf("You have discovered a asteroid field!\n");
      fuel -= 5;
      printf("You used 5 units of fuel.\n");
      armor -= 10;
      printf("Your armor has been damaged in the asteroid field.\n");
      printf("Your remaining armor is %d.\n", armor);
    }

    // Check if game over
    if (health <= 0) {
      printf("Game over! You have been defeated.\n");
      break;
    }
    else if (fuel <= 0) {
      printf("Game over! You have run out of fuel.\n");
      break;
    }

    // Ask player what to do next
    printf("What do you want to do next?\n");
    printf("1. Travel to a new sector.\n");
    printf("2. Upgrade your ship.\n");
    printf("3. Rest and recover.\n");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        // Travel to new sector
        printf("You set a course for a new sector.\n");
        fuel -= 25;
        printf("You used 25 units of fuel.\n");
        printf("Your remaining fuel is %d.\n\n", fuel);
        break;
      case 2:
        // Upgrade ship
        printf("You upgrade your ship.\n");
        armor += 10;
        printf("Your armor has been increased to %d.\n", armor);
        break;
      case 3:
        // Rest and recover
        printf("You rest and recover your health.\n");
        health += 25;
        printf("Your health is now %d.\n", health);
        break;
      default:
        printf("Invalid choice.\n");
    }

    // Check if game over
    if (health <= 0) {
      printf("Game over! You have been defeated.\n");
      break;
    }
    else if (fuel <= 0) {
      printf("Game over! You have run out of fuel.\n");
      break;
    }
  }

  printf("%s, thank you for playing our space adventure game!\n", player_name);
  return 0;
}