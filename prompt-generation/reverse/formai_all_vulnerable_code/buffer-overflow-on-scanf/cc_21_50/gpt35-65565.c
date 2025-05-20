//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main() {
  int battery_life = 100;
  int speed = 0;
  int altitude = 0;
  int pitch = 0;
  int roll = 0;

  printf("Welcome to the C Drone Remote Control Program!\n");

  printf("Battery:%d%% Speed:%d Altitude:%d Pitch:%d Roll:%d\n", battery_life, speed, altitude, pitch, roll);

  while(1) {
    printf("Enter a command (fly, land, forward, backward, left, right, up, down, stop): ");
    char command[10];
    scanf("%s", command);

    if(strcmp(command, "fly") == 0) {
      if(altitude == 0) {
        printf("The drone is taking off!\n");
        altitude = 10;
      }
      else {
        printf("The drone is already flying!\n");
      }
    }

    else if(strcmp(command, "land") == 0) {
      printf("The drone is landing.\n");
      altitude = 0;
    }

    else if(strcmp(command, "forward") == 0) {
      if(altitude > 0 && speed < 10) {
        speed++;
        printf("The drone is moving forward. Speed:%d\n", speed);
      }
      else {
        printf("Cannot move forward at this altitude or speed.\n");
      }
    }

    else if(strcmp(command, "backward") == 0) {
      if(altitude > 0 && speed > 0) {
        speed--;
        printf("The drone is moving backward. Speed:%d\n", speed);
      }
      else {
        printf("Cannot move backward at this altitude or speed.\n");
      }
    }

    else if(strcmp(command, "left") == 0) {
      if(altitude > 0 && roll > -10) {
        roll--;
        printf("The drone is moving left. Roll:%d\n", roll);
      }
      else {
        printf("Cannot move left at this altitude or roll.\n");
      }
    }

    else if(strcmp(command, "right") == 0) {
      if(altitude > 0 && roll < 10) {
        roll++;
        printf("The drone is moving right. Roll:%d\n", roll);
      }
      else {
        printf("Cannot move right at this altitude or roll.\n");
      }
    }

    else if(strcmp(command, "up") == 0) {
      if(altitude < 50 && pitch < 10) {
        altitude++;
        pitch++;
        printf("The drone is moving up. Altitude:%d Pitch:%d\n", altitude, pitch);
      }
      else {
        printf("Cannot move up any higher.\n");
      }
    }

    else if(strcmp(command, "down") == 0) {
      if(altitude > 0) {
        altitude--;
        pitch--;
        printf("The drone is moving down. Altitude:%d Pitch:%d\n", altitude, pitch);
      }
      else {
        printf("Cannot move down any further.\n");
      }
    }

    else if(strcmp(command, "stop") == 0) {
      speed = 0;
      roll = 0;
      pitch = 0;
      printf("The drone has stopped.\n");
    }

    else {
      printf("Invalid command. Please enter a valid command.\n");
    }

    if(altitude > 0) {
      battery_life--;
    }

    printf("Battery:%d%% Speed:%d Altitude:%d Pitch:%d Roll:%d\n", battery_life, speed, altitude, pitch, roll);

    if(battery_life == 0) {
      printf("Battery empty. The drone has crashed.\n");
      break;
    }
  }

  printf("Goodbye!\n");

  return 0;
}