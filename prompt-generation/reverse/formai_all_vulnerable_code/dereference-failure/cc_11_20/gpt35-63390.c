//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SPEED_LIMIT 100
#define TURN_SPEED 10

int main()
{
  int speed = 0;
  int turning = 0;
  int steering = 0;
  int position_x = 0;
  int position_y = 0;
  
  srand(time(NULL));
  
  printf("Welcome to the Remote Control Vehicle Simulation!\n\n");
  printf("Commands:\n");
  printf("  - Change speed: s\n");
  printf("  - Turn left: t l\n");
  printf("  - Turn right: t r\n");
  printf("  - Quit: q\n\n");
  
  while (1) {
    printf("Speed: %d km/h\n", speed);
    printf("Direction: %s\n", turning == -1 ? "Left" : turning == 1 ? "Right" : "Straight");
    printf("Position: (%d, %d)\n\n", position_x, position_y);
    
    char input[10];
    printf("> ");
    fgets(input, 10, stdin);
    
    if (input[0] == 's') {
      int new_speed = atoi(input + 2);
      if (new_speed < 0) {
        printf("Invalid speed: %d\n", new_speed);
      } else if (new_speed > SPEED_LIMIT) {
        printf("Speed limit is %d km/h\n", SPEED_LIMIT);
      } else {
        speed = new_speed;
        printf("Speed changed to %d km/h\n", speed);
      }
    } else if (input[0] == 't') {
      if (input[2] == 'l') {
        turning = -1;
        printf("Vehicle turned left\n");
      } else if (input[2] == 'r') {
        turning = 1;
        printf("Vehicle turned right\n");
      } else {
        turning = 0;
        printf("Vehicle turned straight\n");
      }
    } else if (input[0] == 'q') {
      printf("Exiting Remote Control Vehicle Simulation...\n");
      break;
    } else {
      printf("Invalid command: %s\n", input);
    }
    
    // Randomly update the position of the vehicle
    position_x += speed * turning;
    position_y += rand() % TURN_SPEED - TURN_SPEED / 2;
  }
  
  return 0;
}