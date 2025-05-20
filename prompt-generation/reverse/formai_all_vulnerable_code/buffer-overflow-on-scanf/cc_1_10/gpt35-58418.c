//FormAI DATASET v1.0 Category: Smart home light control ; Style: real-life
#include <stdio.h>

int main() {
   int lightState = 0;
   int brightness = 0;
   printf("Welcome to your Smart Home Light Control System!\n");
   while(1) {
      printf("\nCurrent Light State: %d, Current Brightness Level: %d\n", lightState, brightness);
      printf("Please select an action:\n");
      printf("1. Turn on/off the lights\n");
      printf("2. Adjust brightness\n");
      printf("3. Exit program\n");
      int choice;
      scanf("%d", &choice);
      if(choice == 1) {
         if(lightState == 0) {
            lightState = 1;
            printf("Lights turned on!\n");
         }
         else {
            lightState = 0;
            brightness = 0;
            printf("Lights turned off!\n");
         }
      }
      else if(choice == 2) {
         if(lightState == 0) {
            printf("Please turn on the lights first\n");
         }
         else {
            printf("Enter brightness level (0-10): ");
            scanf("%d", &brightness);
            if(brightness < 0 || brightness > 10) {
               printf("Invalid brightness level. Please choose a value between 0 and 10.\n");
               brightness = 0;
            }
            else {
               printf("Brightness adjusted to level %d\n", brightness);
            }
         }
      }
      else if(choice == 3) {
         printf("Exiting program...\n");
         break;
      }
      else {
         printf("Invalid input. Please choose an option from 1-3.\n");
      }
   }
   return 0;
}