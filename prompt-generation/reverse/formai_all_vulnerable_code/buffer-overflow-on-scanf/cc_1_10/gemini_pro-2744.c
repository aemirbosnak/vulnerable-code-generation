//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

// Define the control keys
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
#define QUIT 'q'

// Define the drone's state
typedef enum {
  IDLE,
  FLYING,
  LANDED
} drone_state;

// Define the drone's position
typedef struct {
  int x;
  int y;
  int z;
} drone_position;

// Initialize the drone's state and position
drone_state state = IDLE;
drone_position position = {0, 0, 0};

// Function to get the user's input
char get_input() {
  char input;
  scanf("%c", &input);
  return input;
}

// Function to handle the user's input
void handle_input(char input) {
  switch (input) {
    case UP:
      if (state == IDLE) {
        state = FLYING;
        printf("Drone taking off!\n");
      } else if (state == FLYING) {
        position.z++;
        printf("Drone ascending!\n");
      }
      break;
    case DOWN:
      if (state == FLYING) {
        position.z--;
        printf("Drone descending!\n");
      } else if (state == LANDED) {
        state = IDLE;
        printf("Drone landing!\n");
      }
      break;
    case LEFT:
      if (state == FLYING) {
        position.x--;
        printf("Drone moving left!\n");
      }
      break;
    case RIGHT:
      if (state == FLYING) {
        position.x++;
        printf("Drone moving right!\n");
      }
      break;
    case QUIT:
      exit(0);
      break;
    default:
      printf("Invalid input!\n");
      break;
  }
}

// Function to print the drone's state and position
void print_state() {
  printf("State: %s\n", state == IDLE ? "Idle" : state == FLYING ? "Flying" : "Landed");
  printf("Position: (%d, %d, %d)\n", position.x, position.y, position.z);
}

// Main function
int main() {
  // Set the terminal to non-blocking mode
  struct termios old_term, new_term;
  tcgetattr(0, &old_term);
  new_term = old_term;
  new_term.c_lflag &= ~ICANON;
  new_term.c_lflag &= ~ECHO;
  tcsetattr(0, TCSANOW, &new_term);

  // Main loop
  while (1) {
    // Get the user's input
    char input = get_input();

    // Handle the user's input
    handle_input(input);

    // Print the drone's state and position
    print_state();
  }

  // Reset the terminal to blocking mode
  tcsetattr(0, TCSANOW, &old_term);

  return 0;
}