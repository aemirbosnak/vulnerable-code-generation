//Gemma-7B DATASET v1.0 Category: Drone Remote Control ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  system("clear");
  printf("Welcome to the Future of Flight, Commander. Prepare for an epic journey.\n");

  // Connect to the Drone
  printf("Connecting to your Quantum Drone... Please wait...");
  sleep(2);
  printf("Connection Established. You are now in control.\n");

  // Main Menu
  printf("Enter '1' to Fly Forward, '2' to Fly Backward, '3' to Fly Left, '4' to Fly Right, '5' to Hover:");
  char input;
  scanf("%c", &input);

  // Execute Command
  switch (input)
  {
    case '1':
      printf("Accelerating forward... Prepare for a cosmic blast!\n");
      sleep(1);
      printf("You are flying forward.\n");
      break;
    case '2':
      printf("Reversing course... Prepare for a reverse rampage!\n");
      sleep(1);
      printf("You are flying backward.\n");
      break;
    case '3':
      printf("Turning left... Prepare for a cosmic dance.\n");
      sleep(1);
      printf("You are flying left.\n");
      break;
    case '4':
      printf("Turning right... Prepare for a gravitational flip.\n");
      sleep(1);
      printf("You are flying right.\n");
      break;
    case '5':
      printf("Hovering... Prepare for a cosmic snooze.\n");
      sleep(1);
      printf("You are hovering.\n");
      break;
    default:
      printf("Invalid input. Please try again.\n");
  }

  // Disconnect from the Drone
  printf("Disconnecting from your Quantum Drone... Thank you for flying with us.\n");
  sleep(1);
  system("clear");

  return 0;
}