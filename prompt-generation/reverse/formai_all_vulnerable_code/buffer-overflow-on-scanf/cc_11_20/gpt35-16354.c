//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

int main(){

  int battery = 100;
  int altitude = 0;
  int pitch = 0;
  int roll = 0;
  int yaw = 0;
  int command;

  printf("Welcome to the Drone Remote Control Program!\n");
  printf("Your drone's initial battery level is 100%\n");

  do {
    printf("\nPlease enter a command:\n");
    printf("1. Increase altitude\n");
    printf("2. Decrease altitude\n");
    printf("3. Turn left\n");
    printf("4. Turn right\n");
    printf("5. Move forward\n");
    printf("6. Move backward\n");
    printf("7. Check battery level\n");
    printf("8. Exit program\n\n");

    scanf("%d", &command);

    switch(command){
      case 1:
        if(altitude < 20){
          altitude += 5;
          printf("Altitude increased to %d meters\n", altitude);
        }else{
          printf("Maximum altitude reached\n");
        }
        break;

      case 2:
        if(altitude > 0){
          altitude -= 5;
          printf("Altitude decreased to %d meters\n", altitude);
        }else{
          printf("Minimum altitude reached\n");
        }
        break;

      case 3:
        if(roll > -45){
          roll -= 5;
          printf("Drone turned left to %d degrees\n", roll);
        }else{
          printf("Maximum left turn reached\n");
        }
        break;

      case 4:
        if(roll < 45){
          roll += 5;
          printf("Drone turned right to %d degrees\n", roll);
        }else{
          printf("Maximum right turn reached\n");
        }
        break;

      case 5:
        if(pitch < 20){
          pitch += 5;
          printf("Drone moved forward %d meters\n", pitch);
        }else{
          printf("Maximum forward movement reached\n");
        }
        break;

      case 6:
        if(pitch > -20){
          pitch -= 5;
          printf("Drone moved backward %d meters\n", pitch);
        }else{
          printf("Maximum backward movement reached\n");
        }
        break;

      case 7:
        printf("Your drone's current battery level is %d%%\n", battery);
        break;

      case 8:
        printf("Exiting program...\n");
        break;

      default:
        printf("Invalid command entered\n");
        break;
    }

    battery -= 1;
    printf("Battery level decreased to %d%%\n", battery);

  } while(command != 8);

  return 0;
}