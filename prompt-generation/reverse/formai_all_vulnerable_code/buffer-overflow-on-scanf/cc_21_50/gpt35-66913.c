//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: rigorous
#include <stdio.h>

int main() {
   int option, speed = 0;
   char direction = 'N';

   printf("Welcome to Remote Control Vehicle Simulation\n");
   printf("--------------------------------------------\n");

   while (1) {
       printf("\n");
       printf("What would you like to do?\n");
       printf("1. Move forward\n");
       printf("2. Move backward\n");
       printf("3. Turn left\n");
       printf("4. Turn right\n");
       printf("5. Change speed\n");
       printf("6. Quit\n");

       scanf("%d", &option);
       printf("\n");

       switch (option) {
           case 1:
               if (direction == 'N') {
                   printf("Vehicle moves North.\n");
               } else if (direction == 'E') {
                   printf("Vehicle moves East.\n");
               } else if (direction == 'S') {
                   printf("Vehicle moves South.\n");
               } else {
                   printf("Vehicle moves West.\n");
               }
               break;

           case 2:
               if (direction == 'N') {
                   printf("Vehicle moves South.\n");
               } else if (direction == 'E') {
                   printf("Vehicle moves West.\n");
               } else if (direction == 'S') {
                   printf("Vehicle moves North.\n");
               } else {
                   printf("Vehicle moves East.\n");
               }
               break;
           
           case 3:
               if (direction == 'N') {
                   printf("Vehicle turns West.\n");
                   direction = 'W';
               } else if (direction == 'E') {
                   printf("Vehicle turns North.\n");
                   direction = 'N';
               } else if (direction == 'S') {
                   printf("Vehicle turns East.\n");
                   direction = 'E';
               } else {
                   printf("Vehicle turns South.\n");
                   direction = 'S';
               }
               break;

           case 4:
               if (direction == 'N') {
                   printf("Vehicle turns East.\n");
                   direction = 'E';
               } else if (direction == 'E') {
                   printf("Vehicle turns South.\n");
                   direction = 'S';
               } else if (direction == 'S') {
                   printf("Vehicle turns West.\n");
                   direction = 'W';
               } else {
                   printf("Vehicle turns North.\n");
                   direction = 'N';
               }
               break;

           case 5:
               printf("Enter speed (0-10): ");
               scanf("%d", &speed);
               if (speed > 10) {
                   printf("Invalid speed. Setting speed to 10.\n");
                   speed = 10;
               } else if (speed < 0) {
                   printf("Invalid speed. Setting speed to 0.\n");
                   speed = 0;
               } else {
                   printf("Speed set to %d.\n", speed);
               }
               break;

           case 6:
               printf("Goodbye!\n");
               return 0;

           default:
               printf("Invalid option.\n");
       }
   }
}