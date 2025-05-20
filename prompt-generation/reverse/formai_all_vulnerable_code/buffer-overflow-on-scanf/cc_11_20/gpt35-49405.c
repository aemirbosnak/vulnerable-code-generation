//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Cyberpunk
#include <stdio.h>

int main() {
   int droneSpeed = 0;
   int droneAltitude = 0;
   int droneDirection = 0;
   char userInput;

   printf("Welcome to the Cyberpunk Drone Remote Control Interface!\n");
   printf("Commands:\n");
   printf("w = increase speed\n");
   printf("s = decrease speed\n");
   printf("a = turn left\n");
   printf("d = turn right\n");
   printf("q = decrease altitude\n");
   printf("e = increase altitude\n");
   printf("x = exit program\n");

   while (1) {
      printf("\nCurrent speed: %d\nCurrent altitude: %d\nCurrent direction: %d degrees\n", droneSpeed, droneAltitude, droneDirection);

      printf("Enter command: ");
      scanf(" %c", &userInput);

      switch (userInput) {
         case 'w':
            droneSpeed += 10;
            break;
         case 's':
            droneSpeed -= 10;
            break;
         case 'a':
            droneDirection -= 30;
            break;
         case 'd':
            droneDirection += 30;
            break;
         case 'q':
            droneAltitude -= 10;
            break;
         case 'e':
            droneAltitude += 10;
            break;
         case 'x':
            printf("Exiting program...\n");
            return 0;
         default:
            printf("Invalid command, please try again.\n");
            break;
      }

      if (droneSpeed < 0) {
         printf("Warning! Drone speed is negative.\n");
         droneSpeed = 0;
      }

      if (droneAltitude < 0) {
         printf("Warning! Drone altitude is negative.\n");
         droneAltitude = 0;
      }

      droneDirection %= 360;

      printf("Drone executing command %c...\n", userInput);
   }

   return 0;
}