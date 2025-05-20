//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: cheerful
// Welcome to the C Drone Remote Control program!

#include <stdio.h>
#include <stdlib.h>

int main() {

  // Declare variables for user inputs
  int speed = 50;
  int altitude = 100;
  int direction = 0;

  // Cheerful welcome message
  printf("Hello! Welcome to the C Drone Remote Control Program!\n");
  printf("You are now in control of your very own drone!\n");

  // Instructions to the user
  printf("\nPlease enter the drone's speed (in mph): ");
  scanf("%d", &speed);

  printf("\nPlease enter the drone's altitude (in feet): ");
  scanf("%d", &altitude);

  printf("\nPlease enter the drone's direction (in degrees): ");
  scanf("%d", &direction);

  // Display the user's input
  printf("\nYour drone is now flying at %d mph, at an altitude of %d feet, and heading in a direction of %d degrees.\n", speed, altitude, direction);

  // Cheerful words of encouragement
  printf("\nGreat job! You're doing awesome!\n");

  // Instructions on what to do next
  printf("\nTo turn the drone left, enter a negative value for direction.\n");
  printf("To turn the drone right, enter a positive value for direction.\n");

  // Get the user's new direction input
  printf("\nPlease enter the new direction (in degrees): ");
  scanf("%d", &direction);

  // Update the drone's direction
  direction = direction + direction;

  // Display the new direction
  printf("\nYour drone is now heading in a direction of %d degrees.\n", direction);

  // Cheerful words of encouragement
  printf("\nYou're doing a great job at controlling your drone!\n");

  // Instructions on what to do next
  printf("\nIf you want to change your drone's altitude, enter a new value for altitude.\n");

  // Get the user's new altitude input
  printf("\nPlease enter the new altitude (in feet): ");
  scanf("%d", &altitude);

  // Update the drone's altitude
  altitude = altitude + altitude;

  // Display the new altitude
  printf("\nYour drone is now at an altitude of %d feet.\n", altitude);

  // Cheerful words of encouragement
  printf("\nYou are a master drone controller!\n");

  // End of the program
  printf("\nThank you for using the C Drone Remote Control Program! We hope you had fun controlling your drone!\n\n");
  return 0;
}