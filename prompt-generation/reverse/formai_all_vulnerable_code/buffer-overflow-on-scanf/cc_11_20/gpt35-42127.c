//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: rigorous
#include <stdio.h>

int main(){

  // Drone initialization
  int battery_level = 100; // Battery level in percent
  int altitude = 0; // Altitude in meters
  int direction = 0; // Direction in degrees
  int speed = 0; // Speed in km/h

  printf("Welcome to the Drone Remote Control program!\n");
  printf("Please select an option from the menu below:\n");
  printf("1. Take off\n");
  printf("2. Land\n");
  printf("3. Increase altitude\n");
  printf("4. Decrease altitude\n");
  printf("5. Change direction\n");
  printf("6. Change speed\n");
  printf("7. Check battery level\n");
  printf("8. Exit\n");

  // Loop until user enters 8 to exit
  int choice = 0;
  while(choice != 8){
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice){
      case 1:
        // Take off
        if(altitude == 0){
          printf("\nDrone is taking off!\n");
          altitude = 1;
        }
        else{
          printf("\nDrone is already in the air!\n");
        }
        break;
      case 2:
        // Land
        if(altitude == 0){
          printf("\nDrone is already on the ground!\n");
        }
        else{
          printf("\nDrone is landing!\n");
          altitude = 0;
        }
        break;
      case 3:
        // Increase altitude
        if(altitude == 0){
          printf("\nDrone must take off first!\n");
        }
        else if(altitude < 100){
          printf("\nEnter altitude increase (in meters): ");
          int increase;
          scanf("%d", &increase);
          altitude += increase;
          if(altitude > 100){
            altitude = 100;
            printf("\nMaximum altitude reached!\n");
          }
          else{
            printf("\nAltitude increased by %d meters\n", increase);
          }
        }
        else{
          printf("\nMaximum altitude reached!\n");
        }
        break;
      case 4:
        // Decrease altitude
        if(altitude == 0){
          printf("\nDrone must take off first!\n");
        }
        else if(altitude > 0){
          printf("\nEnter altitude decrease (in meters): ");
          int decrease;
          scanf("%d", &decrease);
          altitude -= decrease;
          if(altitude < 0){
            altitude = 0;
            printf("\nDrone has landed!\n");
          }
          else{
            printf("\nAltitude decreased by %d meters\n", decrease);
          }
        }
        else{
          printf("\nDrone is already on the ground!\n");
        }
        break;
      case 5:
        // Change direction
        printf("\nEnter new direction (in degrees): ");
        scanf("%d", &direction);
        printf("\nDirection set to %d degrees\n", direction);
        break;
      case 6:
        // Change speed
        printf("\nEnter new speed (in km/h): ");
        scanf("%d", &speed);
        printf("\nSpeed set to %d km/h\n", speed);
        break;
      case 7:
        // Check battery level
        printf("\nBattery level is %d percent\n", battery_level);
        break;
      case 8:
        // Exit
        printf("\nExiting Drone Remote Control program...\n");
        break;
      default:
        printf("\nInvalid choice!\n");
    }
  }

  return 0;
}