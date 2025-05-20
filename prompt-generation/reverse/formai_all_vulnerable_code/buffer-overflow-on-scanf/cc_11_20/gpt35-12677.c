//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

int main() {

  //Configurable variables
  int maxAltitude = 50;
  int maxSpeed = 30;
  int maxRotation = 90;

  //Initialization
  int altitude = 0;
  int speed = 0;
  int rotation = 0;

  //Main control loop
  while(1) {

    printf("Enter altitude (0-%d): ", maxAltitude);
    scanf("%d", &altitude);

    if(altitude < 0 || altitude > maxAltitude) {
      printf("Invalid altitude!\n");
      continue;
    }

    printf("Enter speed (0-%d): ", maxSpeed);
    scanf("%d", &speed);

    if(speed < 0 || speed > maxSpeed) {
      printf("Invalid speed!\n");
      continue;
    }

    printf("Enter rotation (-%d-%d): ", maxRotation, maxRotation);
    scanf("%d", &rotation);

    if(rotation < -maxRotation || rotation > maxRotation) {
      printf("Invalid rotation!\n");
      continue;
    }

    //Execute drone commands
    printf("Executing drone commands...\n");
    
    //Code snippet for altitude control
    if(altitude > 0) {
      //Move up
      printf("Moving up %d meters...\n", altitude);
    } else if(altitude < 0) {
      //Move down
      printf("Moving down %d meters...\n", -altitude);
    }
    
    //Code snippet for speed control
    if(speed > 0) {
      //Move forward
      printf("Moving forward %d meters per second...\n", speed);
    } else if(speed < 0) {
      //Move backward
      printf("Moving backward %d meters per second...\n", -speed);
    }
    
    //Code snippet for rotation control
    if(rotation > 0) {
      //Turn right
      printf("Turning right %d degrees...\n", rotation);
    } else if(rotation < 0) {
      //Turn left
      printf("Turning left %d degrees...\n", -rotation);
    }

    printf("Drone commands executed.\n\n");
  }

  return 0;
}