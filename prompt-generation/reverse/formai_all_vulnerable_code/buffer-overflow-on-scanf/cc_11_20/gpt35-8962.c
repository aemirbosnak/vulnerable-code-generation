//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Surrealist GPS Navigation Simulation */

int main() {

  // Declare variables for navigation
  int current_direction = 0;
  int current_longitude = 0;
  int current_latitude = 0;

  // Declare variables for randomization
  int rand_direction;
  int rand_magnitude;

  // Set seed for randomization
  srand(time(NULL));

  // Display welcome message
  printf("Welcome to Surrealist GPS Navigation Simulation!\n\n");

  // Loop until the user chooses to exit
  while (1) {

    // Display current location
    printf("Current location: %d°N %d°E\n\n", current_latitude, current_longitude);

    // Prompt the user for direction or exit command
    printf("Enter a direction (N/S/E/W) or 'exit' to quit: ");
    char direction[10];
    scanf("%s", direction);

    // Exit if the user chooses to exit
    if (strcmp(direction, "exit") == 0) {
        printf("Goodbye!\n");
        return 0;
    }

    // Convert direction to integer for manipulation
    if (strcmp(direction, "N") == 0) {
      rand_direction = 0;
    } else if (strcmp(direction, "E") == 0) {
      rand_direction = 1;
    } else if (strcmp(direction, "S") == 0) {
      rand_direction = 2;
    } else if (strcmp(direction, "W") == 0) {
      rand_direction = 3;
    } else {
      printf("Invalid direction!\n");
      continue;
    }

    // Generate a random magnitude for the movement
    rand_magnitude = rand() % 11;

    // Determine the new coordinates based on the direction and magnitude
    if (rand_direction == 0) {
      current_latitude += rand_magnitude;
    } else if (rand_direction == 1) {
      current_longitude += rand_magnitude;
    } else if (rand_direction == 2) {
      current_latitude -= rand_magnitude;
    } else if (rand_direction == 3) {
      current_longitude -= rand_magnitude;
    }

    // Determine a random change in direction
    current_direction += rand() % 41 - 20;

    // Correct for invalid direction values
    if (current_direction < 0) {
      current_direction += 360;
    } else if (current_direction > 359) {
      current_direction -= 360;
    }

    // Display the new direction and magnitude of movement
    printf("\nMoving %d° %d units...\n\n", current_direction, rand_magnitude);

    // Pause for dramatic effect
    printf("...\n\n");
    printf("...\n\n");

    // Announce a surreal landmark
    int rand_choice = rand() % 5;
    switch (rand_choice) {
      case 0:
        printf("You pass by a giant paperclip statue.\n");
        break;
      case 1:
        printf("You drive through a field of flying jellyfishes.\n");
        break;
      case 2:
        printf("You see a treehouse built entirely of cheese.\n");
        break;
      case 3:
        printf("You drive across a rainbow bridge.\n");
        break;
      case 4:
        printf("You pass by a surrealist painting come to life.\n");
        break;
    }
    printf("\n");

  }

  return 0;
}