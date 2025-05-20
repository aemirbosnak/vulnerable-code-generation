//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: safe
#include <stdio.h>

int main() {
  
  int batteryLevel = 100;
  int distance = 0;
  int altitude = 0;
  int speed = 0;
  
  printf("Welcome to C Drone Remote Control Program!\n");
  printf("\n");
  printf("Please enter the distance you want the drone to travel (in meters): ");
  scanf("%d", &distance);
  
  printf("Please enter the altitude you want the drone to fly (in meters): ");
  scanf("%d", &altitude);
  
  printf("Please enter the speed you want the drone to fly (in meters per second): ");
  scanf("%d", &speed);
  
  printf("\n");
  printf("Drone is now in flight.\n");
  printf("Battery level: %d%%\n", batteryLevel);
  printf("\n");
  
  while (distance > 0 && altitude > 0 && batteryLevel > 0) {
    printf("Distance remaining: %d meters\n", distance);
    printf("Altitude remaining: %d meters\n", altitude);
    printf("Battery level: %d%%\n", batteryLevel);
    
    if (distance >= speed) {
      distance -= speed;
    } else {
      distance = 0;
    }
    
    if (altitude >= speed) {
      altitude -= speed;
    } else {
      altitude = 0;
    }
    
    batteryLevel--;
    printf("\n");
  }
  
  if (batteryLevel <= 0) {
    printf("Drone lost power and crashed.\n");
  } else {
    printf("Destination reached successfully!\n");
  }
  
  return 0;
}