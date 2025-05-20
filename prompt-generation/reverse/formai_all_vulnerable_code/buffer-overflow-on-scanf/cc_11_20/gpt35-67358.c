//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main() {
  int choice;
  int altitude = 0;
  int speed = 0;
  int direction = 0;
  int battery_life = 100;
  
  printf("Welcome to the Shape-Shifting Drone Remote Control Program!\n");
  printf("Please select an option:\n");
  printf("1. Take off\n");
  printf("2. Fly up\n");
  printf("3. Fly down\n");
  printf("4. Move forward\n");
  printf("5. Move backward\n");
  printf("6. Turn left\n");
  printf("7. Turn right\n");
  printf("8. Land\n");
  
  do {
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
      case 1:
        printf("Taking off...\n");
        altitude = 10;
        speed = 25;
        direction = 0;
        printf("Altitude: %d meters\n", altitude);
        printf("Speed: %d kph\n", speed);
        printf("Direction: %d degrees\n", direction);
        break;
      case 2:
        printf("Flying up...\n");
        altitude += 5;
        speed += 5;
        printf("Altitude: %d meters\n", altitude);
        printf("Speed: %d kph\n", speed);
        printf("Direction: %d degrees\n", direction);
        break;
      case 3:
        printf("Flying down...\n");
        altitude -= 5;
        speed -= 5;
        printf("Altitude: %d meters\n", altitude);
        printf("Speed: %d kph\n", speed);
        printf("Direction: %d degrees\n", direction);
        break;
      case 4:
        printf("Moving forward...\n");
        speed += 10;
        printf("Altitude: %d meters\n", altitude);
        printf("Speed: %d kph\n", speed);
        printf("Direction: %d degrees\n", direction);
        break;
      case 5:
        printf("Moving backward...\n");
        speed -= 10;
        printf("Altitude: %d meters\n", altitude);
        printf("Speed: %d kph\n", speed);
        printf("Direction: %d degrees\n", direction);
        break;
      case 6:
        printf("Turning left...\n");
        if (direction <= 20) {
          direction += 340;
        } else {
          direction -= 20;
        }
        printf("Altitude: %d meters\n", altitude);
        printf("Speed: %d kph\n", speed);
        printf("Direction: %d degrees\n", direction);
        break;
      case 7:
        printf("Turning right...\n");
        if (direction >= 340) {
          direction -= 340;
        } else {
          direction += 20;
        }
        printf("Altitude: %d meters\n", altitude);
        printf("Speed: %d kph\n", speed);
        printf("Direction: %d degrees\n", direction);
        break;        
      case 8:
        printf("Landing...\n");
        altitude = 0;
        speed = 0;
        direction = 0;
        printf("Altitude: %d meters\n", altitude);
        printf("Speed: %d kph\n", speed);
        printf("Direction: %d degrees\n", direction);
        break;
      default:
        printf("Invalid choice!\n");
        break;
    }
    
    if (altitude > 50) {
      printf("Warning: High altitude!\n");
    }
    
    if (battery_life < 20) {
      printf("Warning: Low battery life!\n");
    }
    
    battery_life -= 1;
    
  } while (choice != 8 && battery_life > 0);
  
  printf("Battery life: %d%%\n", battery_life);

  return 0;
}