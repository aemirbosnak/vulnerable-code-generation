//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Romeo's coordinates
int romeo_x, romeo_y;
// Juliet's coordinates
int juliet_x, juliet_y;

// Both Romeo and Juliet are initially at the origin
void init() {
  romeo_x = 0;
  romeo_y = 0;
  juliet_x = 0;
  juliet_y = 0;
}

// Romeo moves forward by one unit
void romeo_forward() {
  romeo_y++;
}

// Romeo moves backward by one unit
void romeo_backward() {
  romeo_y--;
}

// Romeo moves left by one unit
void romeo_left() {
  romeo_x--;
}

// Romeo moves right by one unit
void romeo_right() {
  romeo_x++;
}

// Juliet moves forward by one unit
void juliet_forward() {
  juliet_y++;
}

// Juliet moves backward by one unit
void juliet_backward() {
  juliet_y--;
}

// Juliet moves left by one unit
void juliet_left() {
  juliet_x--;
}

// Juliet moves right by one unit
void juliet_right() {
  juliet_x++;
}

// Romeo and Juliet crash if they are at the same coordinates
int crash() {
  return romeo_x == juliet_x && romeo_y == juliet_y;
}

// Print the current state of the simulation
void print_state() {
  printf("Romeo: (%d, %d)\n", romeo_x, romeo_y);
  printf("Juliet: (%d, %d)\n", juliet_x, juliet_y);
  if (crash()) {
    printf("Romeo and Juliet have crashed!\n");
  }
}

int main() {
  // Initialize the simulation
  init();

  // Get the user's input
  char input[100];
  while (1) {
    printf("Enter a command (f, b, l, r, q): ");
    scanf("%s", input);

    // Parse the user's input
    if (strcmp(input, "f") == 0) {
      romeo_forward();
    } else if (strcmp(input, "b") == 0) {
      romeo_backward();
    } else if (strcmp(input, "l") == 0) {
      romeo_left();
    } else if (strcmp(input, "r") == 0) {
      romeo_right();
    } else if (strcmp(input, "q") == 0) {
      break;
    } else {
      printf("Invalid command!\n");
    }

    // Check if Romeo and Juliet have crashed
    if (crash()) {
      break;
    }

    // Print the current state of the simulation
    print_state();
  }

  return 0;
}