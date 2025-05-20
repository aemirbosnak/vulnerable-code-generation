//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the haunted house
#define ROOMS 10
#define MIN_SCARES 1
#define MAX_SCARES 5

// Define the player
#define HEALTH 100
#define STAMINA 100

// Define the game state
#define GAME_OVER 0
#define PLAYING 1
#define WON 2

// Define the scares
#define SCREAM 0
#define JUMP_SCARE 1
#define GHOST 2
#define DEMON 3
#define ZOMBIE 4

// Define the player's actions
#define RUN 0
#define HIDE 1
#define FIGHT 2

// Define the game loop
void game_loop();

// Define the main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Start the game loop
  game_loop();

  return 0;
}

// Define the game loop
void game_loop() {
  // Initialize the game state
  int game_state = PLAYING;

  // Initialize the player's health and stamina
  int health = HEALTH;
  int stamina = STAMINA;

  // Initialize the haunted house
  int rooms[ROOMS];
  for (int i = 0; i < ROOMS; i++) {
    rooms[i] = 0;
  }

  // Main game loop
  while (game_state == PLAYING) {
    // Get the player's input
    int action = 0;
    printf("What do you want to do? (0: Run, 1: Hide, 2: Fight)\n");
    scanf("%d", &action);

    // Handle the player's input
    switch (action) {
      case RUN:
        // Run away from the scares
        stamina -= 10;
        if (stamina <= 0) {
          health -= 10;
          stamina = 100;
        }
        break;
      case HIDE:
        // Hide from the scares
        stamina -= 5;
        if (stamina <= 0) {
          health -= 10;
          stamina = 100;
        }
        break;
      case FIGHT:
        // Fight the scares
        health -= 10;
        break;
      default:
        // Invalid input
        printf("Invalid input\n");
        break;
    }

    // Check if the player has won
    if (health <= 0) {
      game_state = GAME_OVER;
      printf("You have died. Game over.\n");
    } else if (stamina <= 0) {
      game_state = GAME_OVER;
      printf("You have run out of stamina. Game over.\n");
    } else if (rooms[ROOMS - 1] == 1) {
      game_state = WON;
      printf("You have escaped the haunted house. You win!\n");
    }

    // Generate a scare
    int scare = rand() % 5;

    // Handle the scare
    switch (scare) {
      case SCREAM:
        // The player hears a scream
        printf("You hear a scream.\n");
        health -= 10;
        break;
      case JUMP_SCARE:
        // The player is jump-scared
        printf("You are jump-scared.\n");
        health -= 20;
        break;
      case GHOST:
        // The player sees a ghost
        printf("You see a ghost.\n");
        health -= 30;
        break;
      case DEMON:
        // The player is attacked by a demon
        printf("You are attacked by a demon.\n");
        health -= 40;
        break;
      case ZOMBIE:
        // The player is attacked by a zombie
        printf("You are attacked by a zombie.\n");
        health -= 50;
        break;
    }

    // Update the haunted house
    for (int i = 0; i < ROOMS; i++) {
      if (rooms[i] == 0) {
        if (rand() % 100 < 20) {
          rooms[i] = 1;
        }
      }
    }

    // Print the game state
    printf("Health: %d\nStamina: %d\nRoom: %d\n", health, stamina, rooms[ROOMS - 1]);
  }
}