//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: beginner-friendly
// C Remote Control Vehicle Simulation Program
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0));
  int battery = 100, fuel = 100, distance = 0;
  char command;
  
  printf("*** Remote Control Vehicle Simulation ***\n");
  printf("Battery: %d%%\nFuel: %d%%\nDistance: %d km\n\n", battery, fuel, distance);
  
  while (battery > 0 && fuel > 0) {
    printf("Enter command (F-forward, L-turn left, R-turn right, B-backward, E-exit): ");
    scanf(" %c", &command);
    
    switch (command) {
      case 'F':
        distance += rand() % 10 + 1;
        battery -= rand() % 5 + 1;
        fuel -= rand() % 3 + 1;
        printf("Moving forward...distance now %d km\n", distance);
        break;
        
      case 'L':
        printf("Turning left...distance still %d km\n", distance);
        break;
        
      case 'R':
        printf("Turning right...distance still %d km\n", distance);
        break;
        
      case 'B':
        distance -= rand() % 10 + 1;
        battery -= rand() % 5 + 1;
        fuel -= rand() % 3 + 1;
        printf("Moving backward...distance now %d km\n", distance);
        break;
        
      case 'E':
        printf("Exiting simulation...\n");
        exit(0);
        
      default:
        printf("Invalid command. Distance still %d km\n", distance);
        break;
    }
    
    printf("Battery: %d%%\nFuel: %d%%\nDistance: %d km\n\n", battery, fuel, distance);
  }
  
  if (battery <= 0) {
    printf("Battery level too low. Game over.\n");
  }
  
  if (fuel <= 0) {
    printf("Fuel tank empty. Game over.\n");
  }
  
  return 0;
}