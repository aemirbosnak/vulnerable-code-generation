//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
int check_valid_input(int input);
void generate_encounter();
void engage_in_encounter(int encounter);

// Main function
int main() {
  srand(time(NULL)); // Set random seed
  printf("Welcome to Procedural Space Adventure!\n");
  printf("You are the captain of a spaceship tasked with exploring the vast unknown regions of space.\n");
  printf("During your travels, you may encounter various hazards and obstacles. Be ready!\n\n");

  while (1) { // Loop infinitely until the player decides to quit
    printf("What would you like to do?\n");
    printf("1. Continue exploring\n");
    printf("2. Quit game\n");

    int input;
    scanf("%d", &input);

    if (check_valid_input(input)) { // Check if input is valid
      if (input == 1) {
        generate_encounter(); // Generate an encounter
      } else {
        printf("Thanks for playing Procedural Space Adventure! See you next time.\n");
        break; // Exit the loop
      }
    } else {
      printf("Invalid input. Please try again.\n");
    }
  }

  return 0; // End program
}

// Function to check if input is valid
int check_valid_input(int input) {
  if (input == 1 || input == 2) {
    return 1; // Valid input
  } else {
    return 0; // Invalid input
  }
}

// Function to generate an encounter
void generate_encounter() {
  int encounter = rand() % 3; // Generate a random number between 0 and 2

  printf("You have encountered ");

  switch (encounter) {
    case 0:
      printf("an asteroid field!\n");
      break;
    case 1:
      printf("a hostile alien ship!\n");
      break;
    case 2:
      printf("a black hole!\n");
      break;
  }

  engage_in_encounter(encounter); // Engage in the encounter
}

// Function to engage in an encounter
void engage_in_encounter(int encounter) {
  switch (encounter) {
    case 0:
      printf("You must navigate through the asteroid field without getting hit!\n");
      int hit_chance = rand() % 101; // Generate a random number between 0 and 100
      if (hit_chance < 50) {
        printf("You made it through the asteroid field unscathed!\n");
      } else {
        printf("Your ship has been hit by an asteroid! You've lost 10% of your health.\n");
      }
      break;
    case 1:
      printf("The hostile alien ship is attacking you! You must fight back!\n");
      int attack_chance = rand() % 101; // Generate a random number between 0 and 100
      if (attack_chance < 25) {
        printf("You have defeated the alien ship!\n");
      } else {
        printf("Your ship has been destroyed by the alien ship. Game over.\n");
        exit(0); // Exit the program
      }
      break;
    case 2:
      printf("The black hole is pulling your ship in! You must use your thrusters to escape!\n");
      int escape_chance = rand() % 101; // Generate a random number between 0 and 100
      if (escape_chance < 75) {
        printf("You have successfully escaped the black hole!\n");
      } else {
        printf("Your ship has been sucked into the black hole. Game over.\n");
        exit(0); // Exit the program
      }
      break;
  }
}