//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: satisfied
#include<stdio.h>

int main(){
  int throttle = 0, roll = 0, pitch = 0, yaw = 0;
  printf("Welcome to C Drone Remote Control program!\n\n");
  printf("To fly the drone, please follow the instructions:\n\n");
  
  while(1){
    printf("Enter throttle value (0-100): ");
    scanf("%d", &throttle);
    if(throttle < 0 || throttle > 100){
      printf("Error: Throttle value should be between 0 and 100.\n");
      continue;
    }
    printf("Enter roll value (-90 to 90): ");
    scanf("%d", &roll);
    if(roll < -90 || roll > 90){
      printf("Error: Roll value should be between -90 and 90.\n");
      continue;
    }
    printf("Enter pitch value (-90 to 90): ");
    scanf("%d", &pitch);
    if(pitch < -90 || pitch > 90){
      printf("Error: Pitch value should be between -90 and 90.\n");
      continue;
    }
    printf("Enter yaw value (-180 to 180): ");
    scanf("%d", &yaw);
    if(yaw < -180 || yaw > 180){
      printf("Error: Yaw value should be between -180 and 180.\n");
      continue;
    }
    
    // Code to send the throttle, roll, pitch, and yaw values to the drone's remote control
    printf("Sending throttle value %d, roll value %d, pitch value %d, yaw value %d to the drone's remote control.\n", throttle, roll, pitch, yaw);
    
    // Code to wait for the drone's response (to ensure the values were received)
    printf("Waiting for confirmation from the drone's remote control...\n");
    // Code to receive the confirmation from the drone's remote control
    
    char another;
    printf("Do you want to fly again? (y/n): ");
    scanf(" %c", &another);
    if(another != 'y' && another != 'Y'){
      break;
    }
    printf("\n");
  }
  printf("Thank you for using C Drone Remote Control program!\n");
  return 0;
}