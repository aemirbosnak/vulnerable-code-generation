//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: visionary
#include<stdio.h>

int main(){
  //Initialization of variables 
  int power = 0, altitude = 0, direction = 0;
  int battery = 100, signal = 100;
  char command;
  
  //Display startup message
  printf("Welcome to Drone Remote Control Program!\n");
  
  //Begin command loop
  while(1){
    //Display status of drone
    printf("Power: %d\n", power);
    printf("Battery: %d%%\n", battery);
    printf("Signal: %d%%\n", signal);
    printf("Altitude: %d meters\n", altitude);
    printf("Direction: %d degrees\n", direction);
    
    //Prompt user for command
    printf("Enter command (F)orward, (B)ackward, (L)eft, (R)ight, (U)p, (D)own, (S)top, or (Q)uit: ");
    scanf(" %c", &command);
    
    //Process command
    switch(command){
      case 'F':
        printf("Moving forward.\n");
        direction = 0;
        break;
      case 'B':
        printf("Moving backward.\n");
        direction = 180;
        break;
      case 'L':
        printf("Moving left.\n");
        direction = 270;
        break;
      case 'R':
        printf("Moving right.\n");
        direction = 90;
        break;
      case 'U':
        printf("Moving up.\n");
        altitude += 10;
        break;
      case 'D':
        printf("Moving down.\n");
        altitude -= 10;
        break;
      case 'S':
        printf("Stopping.\n");
        break;
      case 'Q':
        printf("Exiting program...\n");
        return 0;
      default:
        printf("Invalid command.\n");
    }
    
    //Check if drone is still in range and has sufficient battery
    if(signal < 10){
      printf("Signal lost, returning to base.\n");
      direction = 180;
      altitude = 0;
    }
    if(battery < 10){
      printf("Low battery, returning to base.\n");
      direction = 180;
      altitude = 0;
    }
    
    //Update power, battery, and signal values
    power += 10;
    battery -= 10;
    signal -= 5;
  }
  
  return 0;
}