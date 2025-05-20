//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void introspective_space_adventure(void) {
  // Declare variables
  char name[20];
  int age;
  float wealth;
  char ship_name[50];

  // Get user input
  printf("What is your name?\n");
  scanf("%s", name);

  printf("How old are you?\n");
  scanf("%d", &age);

  printf("How much wealth do you have?\n");
  scanf("%f", &wealth);

  // Construct ship name
  sprintf(ship_name, "The %s", name);

  // Print welcome message
  printf("Welcome aboard, %s. You are %d years old and have a wealth of $%.2f. Your ship is the %s.\n", name, age, wealth, ship_name);

  // Begin adventure
  printf("Please choose an adventure:\n");
  printf("1. Travel to the Galactic Core\n");
  printf("2. Battle a space pirate\n");
  printf("3. Explore the asteroid belt\n");

  // Get user choice
  int choice;
  scanf("%d", &choice);

  // Execute adventure
  switch (choice) {
    case 1:
      printf("You traveled to the Galactic Core, where you found a priceless relic.\n");
      break;
    case 2:
      printf("You battled a space pirate and won.\n");
      break;
    case 3:
      printf("You explored the asteroid belt and discovered a new route.\n");
      break;
    default:
      printf("Invalid choice.\n");
  }

  // End adventure
  printf("Thank you for your journey, %s. May the stars be with you.\n", name);
}

int main() {
  introspective_space_adventure();
  return 0;
}