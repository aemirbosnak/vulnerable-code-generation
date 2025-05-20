//FormAI DATASET v1.0 Category: Smart home automation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main() {
   int bedroomLights, kitchenLights, livingroomLights;
   int bedroomTemp, kitchenTemp, livingroomTemp;

   bedroomLights = 0;
   kitchenLights = 0;
   livingroomLights = 0;

   bedroomTemp = 70;
   kitchenTemp = 68;
   livingroomTemp = 72;

   while (1) {
      // Read user input
      int userInput;
      printf("Enter a number to make a change in the smart home: \n");
      printf("1: Turn on/off bedroom lights\n");
      printf("2: Turn on/off kitchen lights\n");
      printf("3: Turn on/off living room lights\n");
      printf("4: Adjust bedroom temperature\n");
      printf("5: Adjust kitchen temperature\n");
      printf("6: Adjust living room temperature\n");
      printf("0: Exit\n");
      scanf("%d", &userInput);

      switch (userInput) {
         case 1:
            if (bedroomLights == 0) {
               printf("Turning on bedroom lights...\n");
               bedroomLights = 1;
            } else {
               printf("Turning off bedroom lights...\n");
               bedroomLights = 0;
            }
            break;
         case 2:
            if (kitchenLights == 0) {
               printf("Turning on kitchen lights...\n");
               kitchenLights = 1;
            } else {
               printf("Turning off kitchen lights...\n");
               kitchenLights = 0;
            }
            break;
         case 3:
            if (livingroomLights == 0) {
               printf("Turning on living room lights...\n");
               livingroomLights = 1;
            } else {
               printf("Turning off living room lights...\n");
               livingroomLights = 0;
            }
            break;
         case 4:
            printf("Enter the new bedroom temperature... ");
            scanf("%d", &bedroomTemp);
            printf("Setting new bedroom temperature to %d\n", bedroomTemp);
            break;
         case 5:
            printf("Enter the new kitchen temperature... ");
            scanf("%d", &kitchenTemp);
            printf("Setting new kitchen temperature to %d\n", kitchenTemp);
            break;
         case 6:
            printf("Enter the new living room temperature... ");
            scanf("%d", &livingroomTemp);
            printf("Setting new living room temperature to %d\n", livingroomTemp);
            break;
         case 0:
            printf("Exiting...\n");
            exit(0);
         default:
            printf("Invalid input.\nPlease enter a valid number.\n");
            break;
      }
   }
   return 0;
}