//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>

int main() {
  int battery_percentage = 100;
  int drone_speed = 0;
  int drone_rotation = 0;
  int drone_elevation = 0;

  printf("Welcome to the C Drone Remote Control!\n\n");
  
  while(1) {
    printf("Enter command (s = speed, r = rotation, e = elevation, b = battery check, q = quit):\n");
    char command;
    scanf("%c", &command);
    
    switch(command) {
      case 's':
        printf("Enter new speed (0-100): ");
        int new_speed;
        scanf("%d", &new_speed);

        if(new_speed < 0 || new_speed > 100) {
          printf("Invalid speed, please enter a number between 0 and 100.\n");
        }
        else {
          drone_speed = new_speed;
          printf("Drone speed set to %d.\n", drone_speed);
        }

        break;
      case 'r':
        printf("Enter new rotation (-180 to 180 degrees): ");
        int new_rotation;
        scanf("%d", &new_rotation);

        if(new_rotation < -180 || new_rotation > 180) {
          printf("Invalid rotation, please enter a number between -180 and 180.\n");
        }
        else {
          drone_rotation = new_rotation;
          printf("Drone rotation set to %d degrees.\n", drone_rotation);
        }

        break;
      case 'e':
        printf("Enter new elevation (0-100 meters): ");
        int new_elevation;
        scanf("%d", &new_elevation);

        if(new_elevation < 0 || new_elevation > 100) {
          printf("Invalid elevation, please enter a number betwen 0 and 100.\n");
        }
        else {
          drone_elevation = new_elevation;
          printf("Drone elevation set to %d meters.\n", drone_elevation);
        }

        break;
      case 'b':
        printf("Battery percentage: %d\n", battery_percentage);
        break;
      case 'q':
        printf("Shutting down C Drone Remote Control.\n");
        exit(0);
      default:
        printf("Invalid command.\n");
        break;
    }

    // Consume the \n character from the input buffer
    while(getchar() != '\n');
  }

  return 0;
}