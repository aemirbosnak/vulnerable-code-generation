//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the map of London
#define MAP_WIDTH 10
#define MAP_HEIGHT 10
char map[MAP_WIDTH][MAP_HEIGHT] = {
  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
  {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
  {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
  {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
  {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
  {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
  {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
  {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
  {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

// Define the player's position
int player_x = 1;
int player_y = 1;

// Define the destination
int destination_x = 8;
int destination_y = 8;

// Define the list of commands
char commands[] = "NESWLRQ";

// Define the Sherlock Holmes quotes
char quotes[][100] = {
  "Elementary, my dear Watson.",
  "It is a capital mistake to theorize before one has data.",
  "I have no data yet. It is a capital mistake to theorize before one has data.",
  "When you have eliminated the impossible, whatever remains, however improbable, must be the truth.",
  "I never guess. It is a capital mistake to theorize before one has data."
};

// Print the map with the player's position
void print_map() {
  for (int i = 0; i < MAP_HEIGHT; i++) {
    for (int j = 0; j < MAP_WIDTH; j++) {
      if (i == player_y && j == player_x) {
        printf("X"); // Player's position
      } else {
        printf("%c", map[i][j]);
      }
    }
    printf("\n");
  }
}

// Get a random Sherlock Holmes quote
char* get_quote() {
  return quotes[rand() % 5];
}

// Main program
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Print the welcome message
  printf("Welcome to the Sherlock Holmes GPS Navigation Simulation!\n");
  printf("Your destination is 221B Baker Street.\n");

  // Print the map
  print_map();

  // Get the user's input
  char input[100];
  while (1) {
    printf("Enter a command (NESWLRQ): ");
    scanf("%s", input);

    // Check if the command is valid
    if (strchr(commands, input[0]) == NULL) {
      printf("Invalid command.\n");
      continue;
    }

    // Move the player
    switch (input[0]) {
      case 'N':
        if (player_y > 0) {
          player_y--;
        }
        break;
      case 'E':
        if (player_x < MAP_WIDTH - 1) {
          player_x++;
        }
        break;
      case 'S':
        if (player_y < MAP_HEIGHT - 1) {
          player_y++;
        }
        break;
      case 'W':
        if (player_x > 0) {
          player_x--;
        }
        break;
      case 'L':
        player_x = 1;
        player_y = 1;
        break;
      case 'R':
        player_x = 8;
        player_y = 8;
        break;
      case 'Q':
        exit(0);
    }

    // Print the map
    print_map();

    // Check if the player has reached the destination
    if (player_x == destination_x && player_y == destination_y) {
      printf("You have reached your destination!\n");
      printf("%s", get_quote());
      break;
    }
  }

  return 0;
}