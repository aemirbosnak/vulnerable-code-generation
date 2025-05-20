//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int altitude = 0;
  int speed = 0;
  int direction = 0;
  int batteryLife = 100;
  int userInput;
  int randNum;

  srand(time(NULL)); // Setup random number generator seed

  printf("Welcome to your new drone remote control!\n");

  while (batteryLife > 0) {
    printf("\n=====================================\n");
    printf("Altitude: %d feet\n", altitude);
    printf("Speed: %d mph\n", speed);
    printf("Direction: %d degrees\n", direction);
    printf("Battery Life: %d%%\n", batteryLife);
    printf("\nWhat would you like to do?\n");
    printf("1. Increase altitude\n");
    printf("2. Decrease altitude\n");
    printf("3. Increase speed\n");
    printf("4. Decrease speed\n");
    printf("5. Change direction\n");
    printf("6. Land the drone\n");
    printf("Enter a number: ");

    scanf("%d", &userInput);

    switch (userInput) {
      case 1:
        altitude += 50;
        printf("\nIncreasing altitude...\n");
        break;
      case 2:
        altitude -= 50;
        printf("\nDecreasing altitude...\n");
        break;
      case 3:
        speed += 10;
        printf("\nIncreasing speed...\n");
        break;
      case 4:
        speed -= 10;
        printf("\nDecreasing speed...\n");
        break;
      case 5:
        randNum = rand() % 360; // Generate random number between 0-359
        direction = randNum;
        printf("\nChanging direction to %d degrees...\n", direction);
        break;
      case 6:
        printf("\nLanding the drone...\n");
        return 0;
      default:
        printf("\nInvalid input. Try again.\n");
    }

    // Randomly decrease battery life between 1-5%
    int batteryDrain = rand() % 5 + 1;
    batteryLife -= batteryDrain;

    if (altitude < 0) {
      altitude = 0; // Drone can't fly below ground level
      printf("\nDrone crashed! Altitude was too low.\n");
      return 0;
    }

    if (speed < 0) {
      speed = 0; // Drone can't go negative speed
    }

    if (batteryLife <= 0) {
      printf("\nDrone ran out of battery and crashed!\n");
      return 0;
    }
  }

  return 0;
}