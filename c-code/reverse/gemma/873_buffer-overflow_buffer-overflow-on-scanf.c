#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  char command;
  int state = 0; // 0 = unarmed, 1 = armed, 2 = flying
  int altitude = 0;
  int speed = 0;
  int heading = 0;
  int battery = 100;

  printf("Enter command (arm, fly, land, status, exit): ");
  scanf("%c", &command);

  switch (command) {
    case 'a':
      if (state == 0) {
        state = 1;
        printf("Drone armed.\n");
      } else {
        printf("Drone already armed.\n");
      }
      break;
    case 'f':
      if (state == 1) {
        altitude++;
        printf("Drone flying at altitude %d.\n", altitude);
      } else {
        printf("Drone not armed.\n");
      }
      break;
    case 'l':
      if (state == 1) {
        state = 0;
        printf("Drone landed.\n");
      } else {
        printf("Drone not armed.\n");
      }
      break;
    case 's':
      printf("Current status:\n"
             "State: %s\n"
             "Altitude: %d\n"
             "Speed: %d\n"
             "Heading: %d\n"
             "Battery: %d%%",
             state == 1 ? "Armed" : "Unarmed", altitude, speed, heading, battery);
      break;
    case 'e':
      printf("Exiting.\n");
      break;
    default:
      printf("Invalid command.\n");
  }

  return 0;
}
