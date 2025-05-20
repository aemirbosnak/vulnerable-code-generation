//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  // initialize variables
  int battery_life = 100;
  int drone_altitude = 0;
  int drone_distance = 0;
  int drone_speed = 0;
  int drone_direction = 0;
  char user_input;

  // generate random starting coordinates for the drone
  srand(time(NULL));
  int x = rand() % 1001;
  int y = rand() % 1001;

  // greet user and give starting coordinates
  printf("Welcome to the C Drone Remote Control Program!\n");
  printf("Your drone is currently located at (%d, %d)\n", x, y);

  // loop through program until user chooses to exit
  while (1) {
    // prompt user for input
    printf("\nEnter W/A/S/D to move the drone in different directions\n");
    printf("Enter F to increase the drone speed or B to decrease it\n");
    printf("Enter U to increase the drone altitude or D to decrease it\n");
    printf("Enter E to exit the program\n");
    scanf(" %c", &user_input);

    // handle user input
    if (user_input == 'W') {
      y += 10;
      drone_distance += 10;
      drone_direction = 1;
      printf("Drone moved North\n");
    } else if (user_input == 'A') {
      x -= 10;
      drone_distance += 10;
      drone_direction = 2;
      printf("Drone moved West\n");
    } else if (user_input == 'S') {
      y -= 10;
      drone_distance += 10;
      drone_direction = 3;
      printf("Drone moved South\n");
    } else if (user_input == 'D') {
      x += 10;
      drone_distance += 10;
      drone_direction = 4;
      printf("Drone moved East\n");
    } else if (user_input == 'F') {
      drone_speed += 10;
      printf("Drone speed increased to %d mph\n", drone_speed);
    } else if (user_input == 'B') {
      drone_speed -= 10;
      printf("Drone speed decreased to %d mph\n", drone_speed);
    } else if (user_input == 'U') {
      drone_altitude += 10;
      printf("Drone altitude increased to %d ft\n", drone_altitude);
    } else if (user_input == 'D') {
      drone_altitude -= 10;
      printf("Drone altitude decreased to %d ft\n", drone_altitude);
    } else if (user_input == 'E') {
      printf("Exiting the program...\n");
      break;
    } else {
      printf("Invalid input. Please try again.\n");
    }

    // check battery life status
    battery_life -= 1;
    if (battery_life < 20) {
      printf("WARNING: Low battery. Please recharge the drone.\n");
    }

    // print current drone stats
    printf("Current Drone Stats:\n");
    printf("Location: (%d, %d)\n", x, y);
    printf("Distance Traveled: %d ft\n", drone_distance);
    printf("Direction: ");
    switch (drone_direction) {
      case 1:
        printf("North\n");
        break;
      case 2:
        printf("West\n");
        break;
      case 3:
        printf("South\n");
        break;
      case 4:
        printf("East\n");
        break;
      default:
        printf("Unknown\n");
        break;
    }
    printf("Altitude: %d ft\n", drone_altitude);
    printf("Speed: %d mph\n", drone_speed);
    printf("Battery Life: %d%%\n", battery_life);
  }

  // end program
  return 0;
}