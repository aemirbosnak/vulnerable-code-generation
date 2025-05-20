//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // seed for random number generator
  int score = 0;
  int health = 100;
  int choice;
  int fuel = 100;
  int planet_count = 0;

  printf("Welcome to Procedural Space Adventure!\n");

  while (health > 0) {
    printf("\nCurrent Score: %d\n", score);
    printf("Current Health: %d\n", health);
    printf("Current Fuel: %d\n", fuel);
    printf("Current Planets Visited: %d\n", planet_count);

    printf("\n1. Fly to a new planet\n");
    printf("2. Refuel spaceship\n");
    printf("3. Upgrade spaceship\n");
    printf("4. Quit\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        if (fuel < 20) {
          printf("\nNot enough fuel to fly to a new planet! Refuel first.\n");
          break;
        }
        printf("\nFlying to a new planet...\n");

        int random_event = rand() % 3;
        switch (random_event) {
          case 0:
            printf("You have found a new planet!\n");
            score += 100;
            planet_count++;
            break;
          case 1:
            printf("You have encountered an alien race!\n");
            int fight_result = rand() % 2;
            if (fight_result == 0) {
              printf("You have defeated the aliens and gained their technology!\n");
              score += 200;
            } else {
              printf("The aliens have defeated you and taken your resources...\n");
              score -= 100;
              health -= 20;
            }
            break;
          case 2:
            printf("You have stumbled upon a black hole...\n");
            health -= 50;
            break;
        }

        fuel -= 20;
        break;

      case 2:
        printf("\nRefueling...\n");
        fuel = 100;
        break;

      case 3:
        printf("\nUpgrading spaceship...\n");
        score -= 100;
        health += 10;
        break;

      case 4:
        printf("\nThanks for playing Procedural Space Adventure!\n");
        exit(0);
        break;

      default:
        printf("\nInvalid choice! Try again.\n");
        break;
    }
  }

  printf("\nGame over! Your final score is %d.\n", score);
  return 0;
}