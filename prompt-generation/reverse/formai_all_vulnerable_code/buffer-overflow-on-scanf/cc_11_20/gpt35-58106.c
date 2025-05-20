//FormAI DATASET v1.0 Category: Smart home light control ; Style: Donald Knuth
#include <stdio.h>
#define LED_ON 1
#define LED_OFF 0

struct Room {
   int light;
};

int main()
{
   printf("Welcome to the Smart Home Light Control program!\n\n");

   struct Room bedroom = { LED_OFF };
   struct Room livingroom = { LED_OFF };
   struct Room kitchen = { LED_OFF };

   char option;

   while(1)
   {
       // Display current status
       printf("Current Status:\n");
       printf("Bedroom: %s\n", bedroom.light == LED_ON ? "ON" : "OFF");
       printf("Living Room: %s\n", livingroom.light == LED_ON ? "ON" : "OFF");
       printf("Kitchen: %s\n", kitchen.light == LED_ON ? "ON" : "OFF");

       // Prompt for action
       printf("\nChoose an action:\n");
       printf("(b) Toggle Bedroom Light\n");
       printf("(l) Toggle Living Room Light\n");
       printf("(k) Toggle Kitchen Light\n");
       printf("(q) Quit\n");

       scanf(" %c", &option);

       // Handle user input
       switch(option)
       {
           case 'b':
               bedroom.light = bedroom.light == LED_ON ? LED_OFF : LED_ON;
               break;

           case 'l':
               livingroom.light = livingroom.light == LED_ON ? LED_OFF : LED_ON;
               break;

           case 'k':
               kitchen.light = kitchen.light == LED_ON ? LED_OFF : LED_ON;
               break;

           case 'q':
               printf("\nGoodbye!\n");
               return 0;

           default:
               printf("\nInvalid option, try again.\n");
               break;
       }
   }

   return 0;
}