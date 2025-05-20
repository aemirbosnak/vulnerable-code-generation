//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate a random direction */
int getDirection() {
  int dir = rand() % 4;
  return dir;
}

int main() {
  /* Seed the random number generator */
  srand(time(NULL));
  
  /* Initialize player's variables */
  int x = 0;
  int y = 0;
  int oxygen = 100;
  int fuel = 100;
  
  /* Starting message */
  printf("Welcome to Introspective Space Adventure!\n");
  printf("Your mission is to explore the galaxy and gather resources.\n");
  printf("You have a limited supply of oxygen and fuel, so be careful!\n\n");
  
  /* Main game loop */
  while (oxygen > 0 && fuel > 0) {
    /* Display player's current status */
    printf("Location: (%d,%d)\n", x, y);
    printf("Oxygen remaining: %d%%\n", oxygen);
    printf("Fuel remaining: %d%%\n", fuel);
    
    /* Ask player for input */
    printf("Which direction do you want to go? (N/S/E/W)\n");
    char choice;
    scanf(" %c", &choice);
    
    /* Move the player and update their status */
    int dir;
    switch (choice) {
      case 'N':
        dir = getDirection();
        if (dir == 0) {
          printf("You encountered an asteroid field and lost 10 fuel!\n");
          fuel -= 10;
        } else {
          printf("You traveled north!\n");
          y++;
        }
        break;
      case 'S':
        dir = getDirection();
        if (dir == 1) {
          printf("You encountered a black hole and lost 50 oxygen!\n");
          oxygen -= 50;
        } else {
          printf("You traveled south!\n");
          y--;
        }
        break;
      case 'E':
        dir = getDirection();
        if (dir == 2) {
          printf("You found a cache of fuel and gained 20 fuel!\n");
          fuel += 20;
        } else {
          printf("You traveled east!\n");
          x--;
        }
        break;
      case 'W':
        dir = getDirection();
        if (dir == 3) {
          printf("You encountered a nebula and lost 25 oxygen!\n");
          oxygen -= 25;
        } else {
          printf("You traveled west!\n");
          x++;
        }
        break;
      default:
        printf("Invalid choice, please try again.\n");
        break;
    }
    
    /* Consume resources every turn */
    oxygen--;
    fuel--;
  }
  
  /* Game over message */
  printf("You have run out of oxygen or fuel!\n");
  printf("Your final location was: (%d,%d)\n", x, y);
  printf("Better luck next time!\n");
  
  return 0;
}