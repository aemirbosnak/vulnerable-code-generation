//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main(){
  int batteryPercentage = 100;
  int altitude = 0;
  int x = 0, y = 0;
  char instruction; 
  printf("Welcome to the C Drone Remote Control Program!\n");
  printf("Battery percentage: %d\n", batteryPercentage);

  while (1){
 
    printf("Enter instruction (f, b, l, r, u, d): ");
    scanf(" %c", &instruction);
 
    switch (instruction){
      case 'f':
        y--;
        break;
      case 'b':
        y++;
        break;
      case 'l':
        x--;
        break;
      case 'r':
        x++;
        break;
      case 'u':
        altitude++;
        break;
      case 'd':
        altitude--;
        break;
      default:
        printf("Invalid instruction.\n");
        continue;
    }
 
    if (altitude > 10 || altitude < 0){
      printf("WARNING: Max altitude reached.\n");
      altitude = 10;
    }
 
    if (batteryPercentage <= 20){
      printf("WARNING: Low battery. Returning to home base.\n");
      continue;
    } else {
      batteryPercentage--;
      printf("Battery percentage: %d\n", batteryPercentage);
    }
 
    if (x < -10 || x > 10 || y < -10 || y > 10){
      printf("WARNING: Out of range. Returning to home base.\n");
      x = 0;
      y = 0;
      continue;
    }
 
    printf("Altitude: %d\n", altitude);
    printf("Position: (%d,%d)\n", x, y);
  }
 
  return EXIT_SUCCESS;
}