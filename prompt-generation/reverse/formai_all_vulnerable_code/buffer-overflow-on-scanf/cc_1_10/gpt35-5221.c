//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: satisfied
#include <stdio.h>

int main() {
  char user_input;
  int battery = 100; // drone battery
  int altitude = 0; // drone altitude

  printf("Welcome to the C Drone Remote Control Program!\n");

  while (1) {
    printf("\nWhat would you like to do? (type 'h' for help)\n");
    scanf(" %c", &user_input);

    switch (user_input) {
      case 'h':
        printf("----- HELP -----\n");
        printf("'u' - Increase altitude by 10ft.\n");
        printf("'d' - Decrease altitude by 10ft.\n");
        printf("'b' - Check battery percentage.\n");
        printf("'q' - Quit program.\n");
        break;

      case 'u':
        if (altitude + 10 > 100) {
          printf("Maximum altitude reached!\n");
        } else {
          altitude += 10;
          printf("Raising altitude by 10ft. Current altitude is %dft.\n", altitude);
        }
        break;

      case 'd':
        if (altitude - 10 < 0) {
          printf("Drone is on the ground already!\n");
        } else {
          altitude -= 10;
          printf("Lowering altitude by 10ft. Current altitude is %dft.\n", altitude);
        }
        break;

      case 'b':
        printf("Battery is at %d%%.\n", battery);
        break;

      case 'q':
        printf("Program terminated.\n");
        return 0;

      default:
        printf("Invalid input. Type 'h' for help.\n");
        break;

    }
  }
  return 0;
}