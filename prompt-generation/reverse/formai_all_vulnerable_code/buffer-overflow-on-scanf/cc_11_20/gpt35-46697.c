//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: careful
#include <stdio.h>

int main() {
  int up = 0, down = 0, forward = 0, backward = 0, left = 0, right = 0;
  int altitude = 0, speed = 0, battery = 100;

  while(1) {
    printf("Drone Remote Control:\n");
    printf("1. Increase altitude\n");
    printf("2. Decrease altitude\n");
    printf("3. Move forward\n");
    printf("4. Move backward\n");
    printf("5. Move left\n");
    printf("6. Move right\n");
    printf("7. Increase speed\n");
    printf("8. Decrease speed\n");
    printf("9. Check battery\n");
    printf("10. Exit\n");

    int option;
    printf("Select an option: ");
    scanf("%d", &option);

    switch(option) {
      case 1:
        altitude++;
        printf("Altitude increased to %d meters.\n", altitude);
        break;
      case 2:
        altitude--;
        printf("Altitude decreased to %d meters.\n", altitude);
        break;
      case 3:
        forward++;
        printf("Moving forward %d meters.\n", forward);
        break;
      case 4:
        backward++;
        printf("Moving backward %d meters.\n", backward);
        break;
      case 5:
        left++;
        printf("Moving left %d meters.\n", left);
        break;
      case 6:
        right++;
        printf("Moving right %d meters.\n", right);
        break;
      case 7:
        speed++;
        printf("Speed increased to %d km/h.\n", speed);
        break;
      case 8:
        speed--;
        printf("Speed decreased to %d km/h.\n", speed);
        break;
      case 9:
        printf("Battery level: %d%%\n", battery);
        break;
      case 10:
        printf("Exiting drone remote control.\n");
        return 0;
      default:
        printf("Invalid option.\n");
        break;
    }

    if(battery == 0) {
      printf("Drone is out of battery. Landing...\n");
      altitude = 0;
      break;
    }
    else if(altitude == 0) {
      printf("Drone has landed safely.\n");
      break;
    }

    battery--;
  }

  return 0;
}