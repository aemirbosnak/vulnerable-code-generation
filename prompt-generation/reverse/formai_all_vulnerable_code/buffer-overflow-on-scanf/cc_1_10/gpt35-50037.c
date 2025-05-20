//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: real-life
#include <stdio.h>

int main() {
  int distance = 0;
  int speed = 0;
  int batteryLife = 100;
  int signalStrength = 100;
  int currentDirection = 0;
  char command;
  
  printf("Welcome to the Remote Control Vehicle Simulation\n");
  printf("Here are the available commands:\n");
  printf("w: move forward\n");
  printf("a: turn left\n");
  printf("d: turn right\n");
  printf("s: move backward\n");
  printf("x: stop\n");
  
  while (batteryLife > 0 && signalStrength > 0) {
    printf("\nDistance: %d m    Speed: %d km/h    Battery: %d%%    Signal: %d%%    Direction: %d degrees\n\n", distance, speed, batteryLife, signalStrength, currentDirection);
    printf("Enter command: ");
    scanf(" %c", &command);

    switch(command) {
      case 'w' :
        printf("Moving forward...\n");
        distance += 10;
        batteryLife -= 5;
        speed = 20;
        break;
        
      case 'a' :
        printf("Turning left...\n");
        currentDirection -= 30;
        break;
        
      case 'd' :
        printf("Turning right...\n");
        currentDirection += 30;
        break;
        
      case 's' :
        printf("Moving backward...\n");
        distance -= 10;
        batteryLife -= 5;
        speed = -20;
        break;
        
      case 'x' :
        printf("Stopping...\n");
        speed = 0;
        break;
        
      default :
        printf("Invalid command. Please try again.\n");
        break;
    }
    
    signalStrength -= 2;
    
    if (signalStrength == 0) {
      printf("\nSignal lost. Game over.\n");
      break;
    }
    
    if (batteryLife == 0) {
      printf("\nOut of battery. Game over.\n");
      break;
    }
    
  }
  
  printf("\nGame over. You traveled a total distance of %d meters with a maximum speed of %d km/h.\n", distance, speed);
  
  return 0;
}