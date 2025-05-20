//FormAI DATASET v1.0 Category: Smart home light control ; Style: excited
#include <stdio.h>

int main () {
   char roomName[20];
   int lightIntensity;

   printf("Enter the name of the room: ");
   scanf("%s", roomName);

   printf("Enter the current light intensity in the room (1-10): ");
   scanf("%d", &lightIntensity);

   if (lightIntensity < 1 || lightIntensity > 10){
       printf("Invalid input. Light intensity should be between 1 and 10.");
   }
   else {
       printf("The current light intensity in the %s room is %d.\n", roomName, lightIntensity);
       printf("What would you like to do?\n");
       printf("1. Turn the lights on\n");
       printf("2. Turn the lights off\n");
       printf("3. Adjust the light intensity\n");

       int choice;
       scanf("%d", &choice);

       switch (choice) {
           case 1:
               printf("Turning on the lights in the %s room.\n", roomName);
               break;
           case 2:
               printf("Turning off the lights in the %s room.\n", roomName);
               break;
           case 3:
               printf("Enter the new intensity level for the lights (1-10): ");
               int newIntensity;
               scanf("%d", &newIntensity);

               if (newIntensity < 1 || newIntensity > 10){
                   printf("Invalid input. Light intensity should be between 1 and 10.");
               }
               else {
                   printf("Adjusting the light intensity in the %s room from %d to %d.\n", roomName, lightIntensity, newIntensity);
               }
               break;
           default:
               printf("Invalid choice. Please select an option between 1 and 3.\n");
               break;
       }
   }
   return 0;
}