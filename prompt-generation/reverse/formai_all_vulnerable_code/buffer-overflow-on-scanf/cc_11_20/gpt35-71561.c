//FormAI DATASET v1.0 Category: Smart home light control ; Style: inquisitive
#include <stdio.h>

int main() {
   int lightStatus = 0;
   int userInput;
   char response;

   printf("Welcome to Smart Home Light Control!\n");
   printf("Lights are currently turned off. Would you like to turn them on? (y/n)\n");
   scanf("%c", &response);

   if(response == 'y' || response == 'Y') {
      lightStatus = 1;
      printf("Lights have been turned on.\n");
   } else if(response == 'n' || response == 'N') {
      printf("Okay, lights will remain turned off.\n");
   } else {
      printf("Invalid input. Please enter 'y' or 'n'.\n");
   }

   while(1) {
      printf("What would you like to do next?\n");
      printf("1. Turn lights on\n");
      printf("2. Turn lights off\n");
      printf("3. Check light status\n");
      printf("4. Exit\n");

       scanf("%d", &userInput);

       if(userInput == 1) {
          if(lightStatus == 1) {
             printf("Lights are already turned on.\n");
          } else {
             lightStatus = 1;
             printf("Lights have been turned on.\n");
          }
       } else if(userInput == 2) {
             if(lightStatus == 0) {
                printf("Lights are already turned off.\n");
             } else {
                lightStatus = 0;
                printf("Lights have been turned off.\n");
             }
       } else if(userInput == 3) {
          if(lightStatus == 1) {
             printf("Lights are currently turned on.\n");
          } else {
             printf("Lights are currently turned off.\n");
          }
       } else if(userInput == 4) {
             break;
       } else {
          printf("Invalid input. Please try again.\n");
       }
   }

   printf("Thank you for using Smart Home Light Control!\n");

   return 0;
}