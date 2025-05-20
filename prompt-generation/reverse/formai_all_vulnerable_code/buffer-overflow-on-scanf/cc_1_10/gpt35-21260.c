//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // Seed random number generator
  
  printf("Welcome to Procedural Space Adventure!\n");

  int distance = rand() % 101; // Generate random distance between 0 and 100
  printf("You are now %d lightyears away from Earth.\n", distance);

  printf("You have a choice of two paths to take: \n");
  printf("1. Enter a nearby wormhole\n");
  printf("2. Keep flying straight towards your destination\n");

  int choice;
  printf("Enter your choice: ");
  scanf("%d", &choice);

  if(choice == 1) {
    printf("You have entered the wormhole.\n");
    int time = rand() % 11 + 5; // Generate random time between 5 and 15
    printf("It will take approximately %d years to exit the other side of the wormhole.\n", time);

    distance -= time; // Subtract time taken to travel through wormhole
    printf("You are now %d lightyears away from Earth.\n", distance);
  } else if(choice == 2) {
    printf("You have chosen to keep flying straight.\n");
    int time = rand() % 11 + 10; // Generate random time between 10 and 20
    printf("It will take approximately %d years to reach your destination.\n", time);

    distance -= time; // Subtract time taken to fly straight
    printf("You are now %d lightyears away from Earth.\n", distance);
  } else {
    printf("Invalid choice, try again.\n");
    return 0; // Exit program if user enters invalid choice
  }

  printf("You have encountered an alien spaceship!\n");
  printf("They are demanding that you surrender your ship and all your valuables.\n");

  int response;
  printf("How do you respond?\n");
  printf("1. Surrender peacefully\n");
  printf("2. Try to escape\n");
  scanf("%d", &response);

  if(response == 1) {
    printf("You surrender peacefully and lose all your valuables.\n");
  } else if(response == 2) {
    int roll = rand() % 6 + 1; // Roll a dice with 6 sides
    if(roll >= 4) {
      printf("You managed to escape!\n");
    } else {
      printf("You were caught and lost all your valuables.\n");
    }
  } else {
    printf("Invalid response, try again.\n");
    return 0; // Exit program if user enters invalid response
  }

  printf("You continue on your journey and finally reach your destination.\n");
  printf("Congratulations, you have completed Procedural Space Adventure!\n");

  return 0;
}