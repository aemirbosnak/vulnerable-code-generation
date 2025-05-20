//Code Llama-13B DATASET v1.0 Category: Haunted House Simulator ; Style: ultraprecise
// Haunted House Simulator
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Declare global variables
int user_input;
int door_status;
int haunted_house_level;
int ghost_count;
int ghost_type;

// Function prototypes
void display_intro();
void display_options();
void display_door();
void display_ghost();
void display_ending();

int main() {
  // Initialize global variables
  user_input = 0;
  door_status = 0;
  haunted_house_level = 1;
  ghost_count = 0;
  ghost_type = 0;

  // Display introduction
  display_intro();

  // Loop until user chooses to quit
  while (user_input != 4) {
    // Display options
    display_options();

    // Get user input
    scanf("%d", &user_input);

    // Check if user chose to enter the house
    if (user_input == 1) {
      // Display door
      display_door();

      // Check if door is locked
      if (door_status == 0) {
        // Display ghost
        display_ghost();

        // Increment ghost count
        ghost_count++;

        // Update ghost type
        ghost_type = rand() % 4 + 1;
      }
    }

    // Check if user chose to quit
    if (user_input == 4) {
      // Display ending
      display_ending();

      // Exit program
      return 0;
    }
  }

  return 0;
}

void display_intro() {
  printf("Welcome to the Haunted House Simulator!\n");
  printf("You are about to enter a haunted house and fight ghosts.\n");
  printf("You have 3 options:\n");
  printf("1. Enter the house\n");
  printf("2. Examine the house\n");
  printf("3. Quit the game\n");
}

void display_options() {
  printf("What would you like to do?\n");
  printf("1. Enter the house\n");
  printf("2. Examine the house\n");
  printf("3. Quit the game\n");
}

void display_door() {
  printf("You approach the door and see that it is locked.\n");
  printf("You need to find a way to unlock it.\n");
  door_status = 1;
}

void display_ghost() {
  printf("As you enter the house, you hear a faint whispering.\n");
  printf("Suddenly, a ghost appears before you!\n");
  printf("It is a %s ghost!\n", ghost_type == 1 ? "blue" : ghost_type == 2 ? "green" : ghost_type == 3 ? "red" : "white");
  printf("You have %d ghosts to defeat!\n", ghost_count);
}

void display_ending() {
  printf("You have defeated all %d ghosts!\n", ghost_count);
  printf("Congratulations, you have won the game!\n");
}