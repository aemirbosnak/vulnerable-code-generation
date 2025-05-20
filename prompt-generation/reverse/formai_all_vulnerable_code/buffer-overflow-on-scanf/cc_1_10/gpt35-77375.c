//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to wait for user input
void pressEnter() {
  printf("\nPress Enter to continue...");
  while(getchar() != '\n');
  getchar();
  system("clear");
}

// function to generate a random number between min and max
int getRandom(int min, int max) {
  return (rand() % (max - min + 1)) + min;
}

// function to simulate a space battle between two ships
void spaceBattle() {
  printf("\nWelcome to the space battle!\n");

  // generate statistics for the player's ship
  int playerShields = getRandom(80, 100);
  int playerLasers = getRandom(20, 30);
  int playerMissiles = getRandom(5, 10);

  // generate statistics for the NPC ship
  int enemyShields = getRandom(60, 80);
  int enemyLasers = getRandom(10, 20);
  int enemyMissiles = getRandom(3, 7);

  // print the ship statistics
  printf("\nYour ship:\n");
  printf("Shields: %d\n", playerShields);
  printf("Laser Cannons: %d\n", playerLasers);
  printf("Missile Launchers: %d\n", playerMissiles);

  printf("\nEnemy ship:\n");
  printf("Shields: %d\n", enemyShields);
  printf("Laser Cannons: %d\n", enemyLasers);
  printf("Missile Launchers: %d\n", enemyMissiles);

  // simulate the battle
  while(playerShields > 0 && enemyShields > 0) {
    // player's turn
    printf("\nYour turn to attack!\n");
    printf("Choose your weapon:\n");
    printf("1. Laser Cannons (2-4 damage)\n");
    printf("2. Missile Launchers (5-7 damage)\n");
    int choice;
    scanf("%d", &choice);

    int damage;
    if(choice == 1) {
      damage = getRandom(2, 4);
      enemyShields -= damage;
      printf("\nYou hit the enemy ship with your laser cannons for %d damage!\n", damage);
    }
    else if(choice == 2) {
      damage = getRandom(5, 7);
      enemyShields -= damage;
      printf("\nYou hit the enemy ship with your missile for %d damage!\n", damage);
    }
    else {
      printf("\nInvalid choice, try again.\n");
      continue;
    }

    if(enemyShields <= 0) {
      printf("\nEnemy ship destroyed! You win!\n");
      return;
    }

    // NPC's turn
    printf("\nEnemy turn to attack!\n");
    int npcChoice = getRandom(1, 2);

    if(npcChoice == 1) {
      damage = getRandom(2, 4);
      playerShields -= damage;
      printf("\nEnemy hit your ship with their laser cannons for %d damage!\n", damage);
    }
    else {
      damage = getRandom(5, 7);
      playerShields -= damage;
      printf("\nEnemy hit your ship with their missile for %d damage!\n", damage);
    }

    if(playerShields <= 0) {
      printf("\nYour ship destroyed! You lose!\n");
      return;
    }
  }
}

int main() {
  srand(time(0)); // seed the random function with the current time

  // print the intro message
  printf("Welcome to the medieval space adventure!\n");
  printf("You are on a mission to save the galaxy from an evil emperor.\n");
  printf("You will encounter many challenges along the way, so be prepared!\n");

  // loop until the game is over
  int gameOver = 0;
  while(!gameOver) {
    // print the main menu
    printf("\nMain Menu:\n");
    printf("1. Start Space Battle\n");
    printf("2. Exit Game\n");
    int choice;
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        spaceBattle();
        break;
      case 2:
        printf("\nThanks for playing the medieval space adventure!\n");
        gameOver = 1;
        break;
      default:
        printf("\nInvalid choice, try again.\n");
    }

    // pause the game until the player presses Enter
    pressEnter();
  }

  return 0;
}