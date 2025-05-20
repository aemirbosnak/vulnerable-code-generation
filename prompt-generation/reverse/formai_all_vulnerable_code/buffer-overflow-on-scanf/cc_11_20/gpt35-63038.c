//FormAI DATASET v1.0 Category: Smart home light control ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   srand(time(NULL)); // initialize random seed

   int light1 = rand() % 2; // generate random binary value for light1
   int light2 = rand() % 2; // generate random binary value for light2

   if (light1 == 0 && light2 == 0) {
      printf("The lights are currently off.\n");
   } else if (light1 == 0 && light2 == 1) {
      printf("Light 2 is currently on, but Light 1 is off.\n");
   } else if (light1 == 1 && light2 == 0) {
      printf("Light 1 is currently on, but Light 2 is off.\n");
   } else {
      printf("Both lights are currently on.\n");
   }

   printf("Would you like to turn a light on or off? (1 for on, 0 for off)\n");

   int choice = -1;
   scanf("%d", &choice);

   if (choice == 1) {
      printf("Which light? (1 or 2)\n");
      int light_choice = -1;
      scanf("%d", &light_choice);

      if (light_choice == 1) {
         printf("Light 1 is now on.\n");
         light1 = 1;
      } else if (light_choice == 2) {
         printf("Light 2 is now on.\n");
         light2 = 1;
      } else {
         printf("Invalid choice.\n");
      }
   } else if (choice == 0) {
      printf("Which light? (1 or 2)\n");
      int light_choice = -1;
      scanf("%d", &light_choice);

      if (light_choice == 1) {
         printf("Light 1 is now off.\n");
         light1 = 0;
      } else if (light_choice == 2) {
         printf("Light 2 is now off.\n");
         light2 = 0;
      } else {
         printf("Invalid choice.\n");
      }
   } else {
      printf("Invalid choice.\n");
   }

   if (light1 == 0 && light2 == 0) {
      printf("The lights are now off.\n");
   } else if (light1 == 0 && light2 == 1) {
      printf("Light 2 is currently on, but Light 1 is off.\n");
   } else if (light1 == 1 && light2 == 0) {
      printf("Light 1 is currently on, but Light 2 is off.\n");
   } else {
      printf("Both lights are currently on.\n");
   }

   return 0;
}