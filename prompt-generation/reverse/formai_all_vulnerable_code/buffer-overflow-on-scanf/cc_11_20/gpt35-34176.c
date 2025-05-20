//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
  int power = 0;
  float pitch = 0.0, roll = 0.0, yaw = 0.0;
  float height = 0.0, speed = 0.0, battery_life = 100.0;
  int mode = 0;
  printf("Welcome to the C Drone Remote Control!\n");
  printf("Press 'p' to power on the drone.\n");
  char c = getchar();
  while(c != 'p'){
    printf("Power off! Press 'p' to power on.\n");
    c = getchar();
  }
  if(c = 'p'){
    power = 1;
    printf("Power on! Enter 'h' to set height, 's' to set speed, 'y' to yaw, 'm' to change mode, or 'q' to quit.\n");
  }
  while(power){
    c = getchar();
    switch(c){
      case 'h':
        printf("Enter desired height in meters: ");
        scanf("%f", &height);
        printf("Height set to %.2f meters.\n", height);
        break;
      case 's':
        printf("Enter desired speed in m/s: ");
        scanf("%f", &speed);
        printf("Speed set to %.2f m/s.\n", speed);
        break;
      case 'y':
        printf("Enter desired yaw increment in degrees: ");
        scanf("%f", &yaw);
        roll += yaw * cos(yaw);
        pitch += yaw * sin(yaw);
        printf("New pitch: %.2f degrees, new roll: %.2f degrees.\n", pitch, roll);
        break;
      case 'm':
        printf("Enter desired mode (1 = manual, 2 = semi-automatic, 3 = fully automatic): ");
        scanf("%d", &mode);
        if(mode == 1){
          printf("Manual mode activated.\n");
        }
        else if(mode == 2){
          printf("Semi-automatic mode activated.\n");
        }
        else if(mode == 3){
          printf("Fully automatic mode activated.\n");
        }
        else{
          printf("Invalid mode! Please choose 1, 2, or 3.\n");
        }
        break;
      case 'q':
        printf("Shutting down drone...\n");
        power = 0;
        break;
      default:
        printf("Invalid command! Press 'h', 's', 'y', 'm', or 'q'.\n");
        break;
    }
    battery_life -= 0.1*fabs(speed) + 0.5*fabs(pitch) + 0.5*fabs(roll) + 0.1*fabs(yaw);
    printf("Battery life remaining: %.2f%%.\n", battery_life);
    if(battery_life < 20.0){
      printf("WARNING: LOW BATTERY LIFE!\n");
    }
  }
  return 0;
}