//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Sherlock Holmes
#include <stdio.h>

int main() {
   int batteryLife = 100;
   int speed = 0;
   int direction = 0;
   char option;
   
   printf("\nWelcome to the Remote Control Vehicle Simulation!\n");
   
   do {
       printf("\n[B] Start the engine\n");
       printf("[+] Increase speed\n");
       printf("[-] Decrease speed\n");
       printf("[<] Turn left\n");
       printf("[>] Turn right\n");
       printf("[Q] Quit\n");
       printf("\nCurrent speed: %d\n", speed);
       printf("Current direction: %d degrees\n", direction);
       printf("Battery life: %d%%\n", batteryLife);
       
       printf("\nPlease enter your option: ");
       scanf(" %c", &option);
       
       switch (option) {
           case 'B':
               printf("\nEngine started!\n");
               speed = 10;
               break;
           case '+':
               if (speed < 100) {
                   speed += 10;
                   batteryLife -= 2;
               }
               break;
           case '-':
               if (speed > 0) {
                   speed -= 10;
                   batteryLife -= 2;
               }
               break;
           case '<':
               if (direction >= 0) {
                   direction -= 15;
               } else {
                   direction = 345;
               }
               batteryLife--;
               break;
           case '>':
               if (direction <= 345) {
                   direction += 15;
               } else {
                   direction = 0;
               }
               batteryLife--;
               break;
           case 'Q':
               printf("\nExiting simulation...Goodbye!\n");
               break;
           default:
               printf("\nInvalid option. Please try again.\n");
               break;
       }
   } while (option != 'Q');
   
   return 0;
}