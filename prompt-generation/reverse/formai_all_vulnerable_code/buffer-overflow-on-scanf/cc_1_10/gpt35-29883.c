//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: shocked
#include <stdio.h>

int main() {
  printf("Welcome to Shocked C Drone Remote Control Program!\n\n");

  int altitude = 0;
  int speed = 0;
  char direction = 'N';

  printf("Enter initial altitude (in meters): ");
  scanf("%d", &altitude);

  printf("Enter initial speed (in km/h): ");
  scanf("%d", &speed);

  printf("Enter initial direction (N, S, E, W): ");
  scanf(" %c", &direction);

  printf("\nCurrent status: Altitude: %dm, Speed: %dkm/h, Direction: %c\n", altitude, speed, direction);

  printf("\n\n***WARNING!*** You are entering a no-fly zone!!!\n"
         "Enter 1 to continue, or 0 to cancel: ");

  int confirm;
  scanf("%d", &confirm);

  if (confirm) {
    printf("\n***ENTERING NO-FLY ZONE!***\n\n");

    printf("Increase altitude by (in meters): ");
    int delta_alt;
    scanf("%d", &delta_alt);
    altitude += delta_alt;
    printf("New altitude: %dm\n", altitude);

    printf("Decrease speed by (in km/h): ");
    int delta_speed;
    scanf("%d", &delta_speed);
    speed -= delta_speed;
    printf("New speed: %dkm/h\n", speed);

    printf("Change direction to (N, S, E, W): ");
    scanf(" %c", &direction);
    printf("New direction: %c\n", direction);

    printf("\n***EXITING NO-FLY ZONE!***\n\n");

    printf("Current status: Altitude: %dm, Speed: %dkm/h, Direction: %c\n", altitude, speed, direction);
  } else {
    printf("\n***CANCELLED!***\n");
  }

  return 0;
}