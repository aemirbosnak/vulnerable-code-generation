//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: peaceful
#include <stdio.h>

int main() {
   int flyButton;
   int landButton;
   int forwardButton;
   int backwardButton;
   int leftButton;
   int rightButton;
   int upButton;
   int downButton;
   
   flyButton = 1;
   landButton = 0;
   forwardButton = 5;
   backwardButton = 6;
   leftButton = 9;
   rightButton = 10;
   upButton = 13;
   downButton = 14;
   
   printf("Welcome to Peaceful C Drone Remote Control!\n");
   
   while(1) {
      printf("Please select an option:\n");
      printf("1 = Fly, 0 = Land, 5 = Forward, 6 = Backward\n");
      printf("9 = Left, 10 = Right, 13 = Up, 14 = Down\n");
      
      int choice;
      scanf("%d", &choice);
      
      switch(choice) {
         case 1:
            printf("Drone is flying.\n");
            break;
         case 0:
            printf("Drone is landing.\n");
            break;
         case 5:
            printf("Drone is moving forward.\n");
            break;
         case 6:
            printf("Drone is moving backward.\n");
            break;
         case 9:
            printf("Drone is moving left.\n");
            break;
         case 10:
            printf("Drone is moving right.\n");
            break;
         case 13:
            printf("Drone is moving up.\n");
            break;
         case 14:
            printf("Drone is moving down.\n");
            break;
         default:
            printf("Invalid choice! Please try again.\n");
            break;
      }
   }
   
   return 0;
}