//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Dennis Ritchie
#include <stdio.h>

#define MAX_DISTANCE 500 // in meters

int main() {
  int altitude = 0;
  int distance_from_base = 0;
  int battery_level = 100;
  
  printf("Welcome to the C Drone Remote Control Program!\n");
  
  // Loop until battery dies
  while (battery_level > 0) {
    // Get user input
    printf("Enter altitude (in meters): ");
    scanf("%d", &altitude);
    
    printf("Enter distance from base (in meters): ");
    scanf("%d", &distance_from_base);
    
    // Check if drone is within acceptable range
    if (altitude <= MAX_DISTANCE && distance_from_base <= MAX_DISTANCE) {
      printf("Drone is within range.\n");
      
      // Update battery level
      battery_level = battery_level - 10;
      
      // Check battery level
      if (battery_level < 20) {
        printf("Battery level is low: %d%%.\n", battery_level);
      }
    } else {
      printf("Drone is out of range.\n");
      // Land drone
      altitude = 0;
      // Update battery level
      battery_level = battery_level - 20;
    }
    
    // Check battery level
    if (battery_level < 10) {
      printf("Battery level is critically low: %d%%.\n", battery_level);
      break;
    }
  }
  
  printf("Battery is dead. Drone is landing automatically.\n");

  return 0;
}