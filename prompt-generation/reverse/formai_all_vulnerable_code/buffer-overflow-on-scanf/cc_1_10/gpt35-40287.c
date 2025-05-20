//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: creative
#include <stdio.h>

int main()
{
  int battery = 100;
  int altitude = 0;
  int speed = 0;
  char direction;

  printf("Welcome to C Drone Remote Control!\n");

  while (battery > 0) // loop until battery is drained
  {
    printf("Battery: %d%%\n", battery);
    printf("Altitude: %d meters\n", altitude);
    printf("Speed: %d km/h\n", speed);

    printf("Enter direction (up/down/left/right): ");
    scanf(" %c", &direction); // read user input

    switch (direction)
    {
      case 'u':
        altitude += 10; // increase altitude by 10 meters
        speed += 5; // increase speed by 5 km/h
        break;
      case 'd':
        altitude -= 10; // decrease altitude by 10 meters
        if (altitude < 0) {
          altitude = 0; // prevent drone from crashing
        }
        speed += 5; // increase speed by 5 km/h
        break;
      case 'l':
        speed -= 5; // decrease speed by 5 km/h
        if (speed < 0) {
          speed = 0; // prevent drone from going negative speed
        }
        break;
      case 'r':
        speed += 5; // increase speed by 5 km/h
        break;
      default:
        printf("Invalid direction. Try again.\n");
        continue; // do not deduct battery when input is invalid
    }

    battery -= 5; // deduct 5% battery for each move
  }

  printf("Battery drained. Land immediately!\n");

  return 0;
}