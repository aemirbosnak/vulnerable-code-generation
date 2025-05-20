//FormAI DATASET v1.0 Category: Smart home automation ; Style: Dennis Ritchie
#include <stdio.h>

#define LIGHT_OFF 0
#define LIGHT_ON 1

#define AC_OFF 0
#define AC_ON 1

int main() {
   int light_status = LIGHT_OFF;
   int ac_status = AC_OFF;

   printf("Welcome to My Smart Home Automation\n");

   while(1) {
      printf("\n Please select an Option: \n");
      printf("Option 1: Turn on/off the Lights\n");
      printf("Option 2: Turn on/off the AC\n");
      printf("Option 3: Exit automation system\n");

      int option;
      scanf("%d", &option);

      switch(option) {
         case 1: {
            if (light_status == LIGHT_OFF) {
               printf("Lights are ON\n");
               light_status = LIGHT_ON;
            } 
            else {
               printf("Lights are OFF\n");
               light_status = LIGHT_OFF;
            }
            break;
         }
         case 2: {
            if (ac_status == AC_OFF) {
               printf("AC is ON\n");
               ac_status = AC_ON;
            } 
            else {
               printf("AC is OFF\n");
               ac_status = AC_OFF;
            }
            break;
         }
         case 3: {
            printf("Exiting Smart Home Automation...\n");
            return 0;
         }
         default: {
            printf("Sorry, Invalid option!\n");
         }
      }
   }
   return 0;
}