//FormAI DATASET v1.0 Category: Smart home automation ; Style: imaginative
#include <stdio.h>

int main() {

   char usr_in;
   int lights = 0;
   int doors_locked = 1;
   int heating = 0;
   printf("Hello, welcome to the Smart Home Automation System!\n");

   while(1) {
      printf("\nPlease choose an option:\n");
      printf("L - Lights\n");
      printf("D - Doors\n");
      printf("H - Heating\n");
      printf("Q - Quit\n");

      scanf(" %c", &usr_in);

      switch(usr_in) {

         case 'L' :
            printf("\n\n");
            printf("Please choose an option:\n");
            printf("1 - Turn lights on\n");
            printf("0 - Turn lights off\n");

            scanf(" %d", &lights);

            if (lights == 1) {
               printf("\nLights are on!\n");
            } else {
               printf("\nLights are off!\n");
            }
            break;

         case 'D' :
            printf("\n\n");
            printf("Please choose an option:\n");
            printf("1 - Lock doors\n");
            printf("0 - Unlock doors\n");

            scanf(" %d", &doors_locked);

            if (doors_locked == 1) {
               printf("\nDoors are locked!\n");
            } else {
               printf("\nDoors are unlocked!\n");
            }
            break;

         case 'H' :
            printf("\n\n");
            printf("Please choose an option:\n");
            printf("1 - Turn heating on\n");
            printf("0 - Turn heating off\n");

            scanf(" %d", &heating);

            if (heating == 1) {
               printf("\nHeating is on!\n");
            } else {
               printf("\nHeating is off!\n");
            }
            break;

         case 'Q' :
            printf("\nGoodbye!\n");
            return 0;
         
         default :
            printf("\nInvalid input. Please try again.\n");
      }
   }

   return 0;
}