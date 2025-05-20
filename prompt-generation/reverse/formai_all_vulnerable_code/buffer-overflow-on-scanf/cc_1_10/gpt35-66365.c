//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: real-life
#include <stdio.h>
int main()
{
   int battery_life = 100; //initialize the battery life of the drone
   
   /* Take user inputs for drone controls */
   int user_input = 0;
   int direction = 0;
   int altitude = 0;
   int speed = 0;
   printf("Welcome to the C Drone Remote Control!\n");
   
   while (battery_life > 0)
   {
      printf("\n-- Drone Status --\nBattery Life: %d\nDirection: %d\nAltitude: %d\nSpeed: %d\n\n", battery_life, direction, altitude, speed);

      printf("-- Drone Controls --\n");
      printf("1 - Change Direction\n");
      printf("2 - Change Altitude\n");
      printf("3 - Change Speed\n");
      printf("4 - Display Drone Status\n");
      printf("5 - Exit Drone Remote Control\n");
      printf("Choose an option (1/2/3/4/5): ");
      scanf("%d", &user_input);

      switch (user_input)
      {
         case 1:
            printf("\nEnter new direction (in degrees): ");
            scanf("%d", &direction);
            break;

         case 2:
            printf("\nEnter new altitude (in meters): ");
            scanf("%d", &altitude);
            break;

         case 3:
            printf("\nEnter new speed (in km/h): ");
            scanf("%d", &speed);
            break;

         case 4:
            printf("\n-- Drone Status --\nBattery Life: %d\nDirection: %d\nAltitude: %d\nSpeed: %d\n", battery_life, direction, altitude, speed);
            break;

         case 5:
            printf("\nExiting Drone Remote Control...\n");
            return 0;

         default:
            printf("\nInvalid input! Try again.\n");
      }

      //decrease battery life with each move
      battery_life--;
   }

   printf("\nDrone's battery life is too low, please recharge it for further use.\n");
   return 0;
}