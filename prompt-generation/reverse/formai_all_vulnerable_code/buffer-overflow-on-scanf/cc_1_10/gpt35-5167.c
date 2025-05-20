//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: funny
#include <stdio.h>

int main() {
   printf("Welcome to the C Remote Control Vehicle Simulator!\n");
   printf("Please select the type of vehicle you would like to control:\n");
   printf("1) Race Car\n");
   printf("2) Monster Truck\n");
   printf("3) Tank\n");

   int choice;
   scanf("%d", &choice);

   if (choice == 1) {
      printf("You've selected the Race Car!\n");
      printf("Please use the following controls to drive:\n");
      printf("w - accelerate\n");
      printf("s - brake\n");
      printf("a - turn left\n");
      printf("d - turn right\n");
   } else if (choice == 2) {
      printf("You've selected the Monster Truck!\n");
      printf("Please use the following controls to drive:\n");
      printf("w - forward\n");
      printf("s - reverse\n");
      printf("a - left turn\n");
      printf("d - right turn\n");
      printf("space bar - jump\n");
   } else if (choice == 3) {
      printf("You've selected the Tank!\n");
      printf("Please use the following controls to drive:\n");
      printf("w - forward\n");
      printf("s - reverse\n");
      printf("a - rotate left\n");
      printf("d - rotate right\n");
      printf("space bar - fire cannon\n");
   } else {
      printf("Invalid choice. Please try again.\n");
      return 1;
   }

   printf("Now let's see if you're a good driver!\n");
   printf("Enter the commands to control the vehicle:\n");

   char command;
   scanf(" %c", &command);

   while (command != 'q') {
      switch (command) {
         case 'w':
            printf("Vehicle is accelerating!\n");
            break;
         case 'a':
            printf("Vehicle is turning left!\n");
            break;
         case 's':
            printf("Vehicle is braking!\n");
            break;
         case 'd':
            printf("Vehicle is turning right!\n");
            break;
         case ' ':
            printf("Vehicle is performing a cool trick!\n");
            break;
         default:
            printf("Invalid command. Please try again.\n");
            break;
      }

      scanf(" %c", &command);
   }

   printf("Thanks for playing! Hope you didn't crash too many times!\n");
   return 0;
}