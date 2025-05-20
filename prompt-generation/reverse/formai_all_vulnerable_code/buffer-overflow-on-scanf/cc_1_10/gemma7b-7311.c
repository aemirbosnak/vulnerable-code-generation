//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
  srand(time(NULL));
  int choice, ghost_number = 1, haunt_number = 0, is_haunted = 0;
  char answer;

  // Create a haunted house
  struct haunted_house {
    char name[20];
    int ghosts;
    int hauntings;
  } haunted_houses[] = {
    {"The Bleeding Manor", 5, 10},
    {"The Whispering Hall", 3, 8},
    {"The Haunted Tower", 7, 12}
  };

  // Initialize the haunted house
  haunt_number = haunted_houses[0].hauntings;
  is_haunted = 1;

  // Welcome the user
  printf("Welcome to the haunted house simulator!\n");

  // Loop until the user chooses to leave
  while (1) {
    // Display the haunted house options
    printf("Please choose a haunted house:\n");
    for (int i = 0; i < 3; i++) {
      printf("%d. %s\n", i + 1, haunted_houses[i].name);
    }

    // Get the user's choice
    scanf("%d", &choice);

    // Check if the user's choice is valid
    if (choice < 1 || choice > 3) {
      printf("Invalid choice.\n");
      continue;
    }

    // Enter the haunted house
    printf("You have chosen %s.\n", haunted_houses[choice - 1].name);

    // Simulate the haunted house experience
    switch (haunt_number) {
      case 5:
        printf("The Bleeding Manor is a terrifying place. You hear voices whispering in your ear and see blood dripping from the ceiling.\n");
        break;
      case 3:
        printf("The Whispering Hall is a haunted by a ghostly figure. You hear footsteps echoing through the halls and feel cold hands brushing against you.\n");
        break;
      case 7:
        printf("The Haunted Tower is a dangerous place. You hear screams and see ghostly figures roaming the halls.\n");
        break;
    }

    // Ask the user if they want to continue
    printf("Do you want to continue? (Y/N) ");
    scanf(" %c", &answer);

    // Check if the user wants to continue
    if (answer != 'Y') {
      break;
    }
  }

  // Thank the user for visiting
  printf("Thank you for visiting the haunted house simulator!\n");

  return;
}