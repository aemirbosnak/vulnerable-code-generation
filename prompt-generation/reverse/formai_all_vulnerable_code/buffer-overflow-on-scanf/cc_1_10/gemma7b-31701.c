//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define RADS_PER_DEG 3.14159

void main() {
  int choice;
  float angle;
  char unit_from, unit_to;

  // Create a post-apocalyptic atmosphere
  printf("Welcome to the Ruins of Old New York.\n");
  printf("You have stumbled upon a rusty calculator.\n");

  // Display the available conversion units
  printf("Available units:\n");
  printf("R - Radians\n");
  printf("D - Degrees\n");

  // Get the user's choice
  printf("Enter your choice: ");
  scanf("%d", &choice);

  // Get the angle
  printf("Enter the angle: ");
  scanf("%f", &angle);

  // Get the units
  printf("Enter the unit you are converting from: ");
  scanf(" %c", &unit_from);

  // Get the units you are converting to
  printf("Enter the unit you are converting to: ");
  scanf(" %c", &unit_to);

  // Convert the angle
  float converted_angle;
  switch (choice) {
    case 1:
      converted_angle = angle * RADS_PER_DEG;
      break;
    case 2:
      converted_angle = angle * RADS_PER_DEG;
      break;
  }

  // Display the converted angle
  printf("The converted angle is: %.2f %s.\n", converted_angle, unit_to);

  return;
}