//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
  int num_wheels = 4;
  float steering_angle = 0.0; 
  int max_speed = 50;
  int current_speed = 0;
  int throttle_position = 0;
  float acceleration_rate = 3.5; 
  float brake_rate = 5.0;
  srand(time(NULL)); 
  int random_num; 

  printf("Welcome to the Remote Control Vehicle Simulation\n");

  while(1) {
    printf("\nCommand Options:\n");
    printf("1. Increase Speed\n");
    printf("2. Decrease Speed\n");
    printf("3. Turn Steering Wheel\n");
    printf("4. Exit Simulation\n");
    printf("Enter your command selection: ");
    int selection; 
    scanf("%d", &selection); 

    switch(selection) {
      case 1: 
        printf("\nIncreasing Speed...\n");
        throttle_position += 10;
        current_speed = acceleration_rate * throttle_position;
        if(current_speed > max_speed) {
          current_speed = max_speed;
          throttle_position = max_speed/acceleration_rate;
          printf("Maximum speed reached!\n");
        }
        printf("Current Speed: %d\n", current_speed);
        break;

      case 2: 
        printf("\nDecreasing Speed...\n");
        throttle_position -= 10;
        if(throttle_position < 0) {
          throttle_position = 0;
          current_speed = 0;
          printf("Vehicle has come to a complete stop.\n");
        }
        else {
          current_speed = acceleration_rate * throttle_position;
          printf("Current Speed: %d\n", current_speed);
        }
        break;

      case 3:
        printf("\nTurning Steering Wheel...\n");
        random_num = rand()%11 + (-5);
        steering_angle += random_num;
        if(steering_angle > 180) {
          steering_angle = fmod(steering_angle, 180);
          printf("Turning around full circle.\n");
        }
        else if(steering_angle < -180) {
          steering_angle = fmod(steering_angle, -180);
          printf("Turning around full circle.\n");
        }
        printf("Steering angle: %.1f degrees\n", steering_angle);
        break;

      case 4: 
        printf("\nExiting Remote Control Vehicle Simulation. Thank you for using this program!\n");
        exit(0);

      default: 
        printf("\nInvalid command selection. Please try again.\n");
    }
  }

  return 0;
}