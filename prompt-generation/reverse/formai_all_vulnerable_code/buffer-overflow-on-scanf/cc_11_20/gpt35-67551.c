//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: accurate
#include <stdio.h>

int main() {

   int altitude = 0;
   int battery = 100;
   int pitch = 0;
   int roll = 0;
   int yaw = 0;
   int speed = 0;

   printf("Welcome to the C Drone Remote Control Program!\n\n");

   while(1) {

      printf("Current Status:\n");
      printf("Altitude: %d meters\n", altitude);
      printf("Battery: %d%%\n", battery);
      printf("Pitch: %d degrees\n", pitch);
      printf("Roll: %d degrees\n", roll);
      printf("Yaw: %d degrees\n", yaw);
      printf("Speed: %d m/s\n", speed);

      printf("\nPlease choose an action:\n");
      printf("1. Increase altitude\n");
      printf("2. Decrease altitude\n");
      printf("3. Increase pitch\n");
      printf("4. Decrease pitch\n");
      printf("5. Increase roll\n");
      printf("6. Decrease roll\n");
      printf("7. Increase yaw\n");
      printf("8. Decrease yaw\n");
      printf("9. Increase speed\n");
      printf("10. Decrease speed\n");
      printf("11. Exit program\n");

      int choice;
      scanf("%d", &choice);

      switch(choice) {
         case 1:
            altitude += 10;
            printf("Altitude increased by 10 meters.\n");
            break;
         case 2:
            if(altitude >= 10) {
               altitude -= 10;
               printf("Altitude decreased by 10 meters.\n");
            } else {
               printf("Cannot decrease altitude any further.\n");
            }
            break;
         case 3:
            pitch += 1;
            printf("Pitch increased by 1 degree.\n");
            break;
         case 4:
            pitch -= 1;
            printf("Pitch decreased by 1 degree.\n");
            break;
         case 5:
            roll += 1;
            printf("Roll increased by 1 degree.\n");
            break;
         case 6:
            roll -= 1;
            printf("Roll decreased by 1 degree.\n");
            break;
         case 7:
            yaw += 1;
            printf("Yaw increased by 1 degree.\n");
            break;
         case 8:
            yaw -= 1;
            printf("Yaw decreased by 1 degree.\n");
            break;
         case 9:
            speed += 1;
            printf("Speed increased by 1 m/s.\n");
            break;
         case 10:
            if(speed >= 1) {
               speed -= 1;
               printf("Speed decreased by 1 m/s.\n");
            } else {
               printf("Cannot decrease speed any further.\n");
            }
            break;
         case 11:
            printf("Exiting program...\n");
            return 0;
         default:
            printf("Invalid choice. Please try again.\n");
            break;
      }

      //Simulate battery drain
      battery -= speed;

      //Check for low battery
      if(battery < 10) {
         printf("\nWARNING: Battery is low!\n");
      }
      
      //Check for collision
      if(altitude <= 0) {
         printf("\nERROR: Collision detected!\n");
         printf("Exiting program...\n");
         return 0;
      }
   }
}