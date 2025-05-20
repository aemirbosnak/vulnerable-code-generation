//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the drone's commands
#define UP "Ascend, my winged steed!"
#define DOWN "Descend, like a majestic eagle!"
#define LEFT "Turn left, like a graceful ballerina!"
#define RIGHT "Turn right, like a whirling dervish!"
#define FORWARD "Soar forward, like a majestic eagle!"
#define BACKWARD "Retreat, like a wise old owl!"
#define TAKEOFF "Rise, oh mighty bird!"
#define LAND "Rest, weary traveler!"

// Define the drone's responses
#define UNDERSTOOD "Affirmative, pilot!"
#define NOT_UNDERSTOOD "Huh? I must have a glitch in my circuits."
#define JOKING "Ha ha, very funny, human!"
#define ERROR "Oops, I seem to have crashed... Drat!"
#define BYE "Farewell, human! May your flights be filled with joy!"

// Define the user's commands
#define QUIT "Enough for today, I'm going to watch cat videos instead."
#define HELP "Help me, I'm lost in this sea of commands!"

// Define the drone's personality
#define DRONE_NAME "Zephyr"
#define DRONE_PERSONALITY "quirky"

// Function to generate a random response from the drone
char *generate_response() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate a random number between 0 and 5
  int response_index = rand() % 6;

  // Return the corresponding response
  switch (response_index) {
    case 0:
      return UNDERSTOOD;
    case 1:
      return NOT_UNDERSTOOD;
    case 2:
      return JOKING;
    case 3:
      return ERROR;
    case 4:
      return BYE;
    case 5:
      return HELP;
    default:
      return NOT_UNDERSTOOD;
  }
}

// Function to print the drone's response
void print_response(char *response) {
  printf("%s: %s\n", DRONE_NAME, response);
}

// Function to handle the user's input
void handle_input(char *input) {
  // Convert the input to uppercase
  for (int i = 0; input[i] != '\0'; i++) {
    input[i] = toupper(input[i]);
  }

  // Compare the input to the drone's commands
  if (strcmp(input, UP) == 0) {
    print_response(UNDERSTOOD);
  } else if (strcmp(input, DOWN) == 0) {
    print_response(UNDERSTOOD);
  } else if (strcmp(input, LEFT) == 0) {
    print_response(UNDERSTOOD);
  } else if (strcmp(input, RIGHT) == 0) {
    print_response(UNDERSTOOD);
  } else if (strcmp(input, FORWARD) == 0) {
    print_response(UNDERSTOOD);
  } else if (strcmp(input, BACKWARD) == 0) {
    print_response(UNDERSTOOD);
  } else if (strcmp(input, TAKEOFF) == 0) {
    print_response(UNDERSTOOD);
  } else if (strcmp(input, LAND) == 0) {
    print_response(UNDERSTOOD);
  } else if (strcmp(input, QUIT) == 0) {
    print_response(BYE);
    exit(0);
  } else if (strcmp(input, HELP) == 0) {
    print_response(HELP);
  } else {
    print_response(NOT_UNDERSTOOD);
  }
}

// Main function
int main() {
  // Print the drone's introduction
  printf("Greetings, human! I am %s, your trusty drone.\n", DRONE_NAME);

  // Repeat until the user quits
  while (1) {
    // Get the user's input
    char input[100];
    printf("Enter a command, human: ");
    scanf("%s", input);

    // Handle the user's input
    handle_input(input);
  }

  return 0;
}