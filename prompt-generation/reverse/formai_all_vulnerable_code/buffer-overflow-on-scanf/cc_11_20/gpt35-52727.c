//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: authentic
#include <stdio.h>

int main() {
  int battery_level = 100; // initial battery level is full
  int altitude = 0; // initial altitude is ground level
  int pitch = 0; // initial pitch is level
  int roll = 0; // initial roll is level

  // welcome message
  printf("Welcome to your C drone remote control!\n");

  while (1) { // infinite loop
    printf("\nCommands available:\n"); // print commands
    printf("1. Increase altitude (+)\n"); 
    printf("2. Decrease altitude (-)\n"); 
    printf("3. Increase pitch forward (/)\n"); 
    printf("4. Decrease pitch backward (\\)\n"); 
    printf("5. Increase roll right (>)\n"); 
    printf("6. Decrease roll left (<)\n");
    printf("7. Check battery level (b)\n");
    printf("8. Quit (q)\n\n");

    // ask user for input
    printf("Enter command: ");
    char input;
    scanf(" %c", &input);

    switch (input) {
      case '+': // increase altitude
        altitude += 10;
        printf("Altitude increased to %d meters.\n", altitude);
        break;

      case '-': // decrease altitude
        if (altitude >= 10) { // check if altitude is at least 10 meters
          altitude -= 10;
          printf("Altitude decreased to %d meters.\n", altitude);
        } else {
          printf("Cannot decrease altitude further.\n");
        }
        break;

      case '/': // increase pitch
        pitch += 10;
        printf("Pitch increased to %d degrees.\n", pitch);
        break;

      case '\\': // decrease pitch
        pitch -= 10;
        printf("Pitch decreased to %d degrees.\n", pitch);
        break;

      case '>': // increase roll
        roll += 10;
        printf("Roll increased to %d degrees.\n", roll);
        break;

      case '<': // decrease roll
        roll -= 10;
        printf("Roll decreased to %d degrees.\n", roll);
        break;

      case 'b': // check battery level
        printf("Battery level is %d%%.\n", battery_level);
        break;

      case 'q': // quit program
        printf("Exiting remote control...\n");
        return 0;

      default: // invalid input
        printf("Invalid command.\n");
        break;
    }

    // decrease battery level by 1% for every command input
    battery_level -= 1;

    // check if battery level is low
    if (battery_level <= 20) {
      printf("Battery level is low! Please land drone immediately.\n");
    }
  }

  return 0;
}