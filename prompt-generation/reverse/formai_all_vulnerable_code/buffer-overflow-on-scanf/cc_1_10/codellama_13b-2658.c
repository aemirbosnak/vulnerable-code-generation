//Code Llama-13B DATASET v1.0 Category: Text-Based Adventure Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_LENGTH 256
#define MAX_COMMANDS 10

// Global variables
char input[MAX_INPUT_LENGTH];
char commands[MAX_COMMANDS][MAX_INPUT_LENGTH];
int num_commands = 0;

// Function prototypes
void print_welcome_message();
void print_prompt();
void parse_input();
void execute_command();

int main() {
  // Initialize the game
  print_welcome_message();
  print_prompt();

  // Main game loop
  while (1) {
    // Get input from the player
    scanf("%s", input);
    parse_input();

    // Execute the command
    execute_command();

    // Print the prompt again
    print_prompt();
  }

  return 0;
}

void print_welcome_message() {
  printf("Welcome to the Text-Based Adventure Game!\n");
}

void print_prompt() {
  printf("> ");
}

void parse_input() {
  // Split the input into individual commands
  char *token = strtok(input, " ");
  while (token != NULL) {
    strcpy(commands[num_commands], token);
    num_commands++;
    token = strtok(NULL, " ");
  }
}

void execute_command() {
  // Check if the command is valid
  if (strcmp(commands[0], "go") == 0) {
    // Check the direction
    if (strcmp(commands[1], "north") == 0) {
      // Move north
      printf("You go north.\n");
    } else if (strcmp(commands[1], "south") == 0) {
      // Move south
      printf("You go south.\n");
    } else if (strcmp(commands[1], "east") == 0) {
      // Move east
      printf("You go east.\n");
    } else if (strcmp(commands[1], "west") == 0) {
      // Move west
      printf("You go west.\n");
    } else {
      // Invalid direction
      printf("Invalid direction.\n");
    }
  } else if (strcmp(commands[0], "pick") == 0) {
    // Check the item
    if (strcmp(commands[1], "key") == 0) {
      // Pick the key
      printf("You pick the key.\n");
    } else if (strcmp(commands[1], "treasure") == 0) {
      // Pick the treasure
      printf("You pick the treasure.\n");
    } else {
      // Invalid item
      printf("Invalid item.\n");
    }
  } else if (strcmp(commands[0], "use") == 0) {
    // Check the item
    if (strcmp(commands[1], "key") == 0) {
      // Use the key
      printf("You use the key.\n");
    } else {
      // Invalid item
      printf("Invalid item.\n");
    }
  } else {
    // Invalid command
    printf("Invalid command.\n");
  }
}