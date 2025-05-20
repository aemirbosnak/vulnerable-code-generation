//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Ken Thompson
#include <stdio.h>

int main() {

  int altitude, direction, speed, batteryLevel;
  char command;

  //Initializing the values for the drone
  altitude = 0;
  direction = 0;
  speed = 0;
  batteryLevel = 100;

  printf("Welcome to the Drone Remote Control System\n");
  printf("Enter commands to operate the drone:\n");

  while(1) {
    printf("\nType in a command (U=up,D=down,L=left,R=right,S=speed,B=battery,Q=quit): ");
    scanf(" %c",&command); //Taking user input 

    switch(command) {
      case 'U': //increase altitude
        altitude++;
        printf("Altitude increased to %d\n",altitude);
        break;

      case 'D': //decrease altitude
        altitude--;
        printf("Altitude decreased to %d\n",altitude);
        break;

      case 'L': //change direction to left
        direction--;
        printf("Direction changed to %d\n",direction);
        break;

      case 'R': //change direction to right
        direction++;
        printf("Direction changed to %d\n",direction);
        break;

      case 'S': //increase speed
        speed++;
        printf("Speed increased to %d\n",speed);
        break;

      case 'B': //check battery level
        printf("Battery level is %d percent\n",batteryLevel);
        break;

      case 'Q': //quit the program
        printf("Exiting program...\n");
        return 0;

      default: //invalid command
        printf("Invalid command\n");
        break;
    }
  }
  return 0;
}