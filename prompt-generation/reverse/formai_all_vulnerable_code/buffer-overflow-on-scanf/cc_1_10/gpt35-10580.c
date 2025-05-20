//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: introspective
#include <stdio.h>

int main() {
   int x;
   int y;
   printf("Welcome to Drone Remote Control\n");
   printf("Enter distance (in meters) to move forward:\n");
   scanf("%d", &x); //get user input

   printf("Enter distance (in meters) to move sideward:\n");
   scanf("%d", &y); //get user input

   if(x > 0) {
       printf("Moving forward by %d meters\n", x);
   } else if(x < 0) {
       printf("Moving backward by %d meters\n", -x);
   } else {
       printf("No forward/backward movement\n");
   }

   if(y > 0) {
       printf("Moving sideward by %d meters to the right\n", y);
   } else if(y < 0) {
       printf("Moving sideward by %d meters to the left\n", -y);
   } else {
       printf("No sideward movement\n");
   }

   printf("Checking altitude...\n");
   int z = 50; //default altitude
   printf("Current altitude is %d meters\n", z);

   printf("Do you want to change altitude? (y/n)\n");
   char choice;
   scanf(" %c", &choice); //get user input, with a space before %c to clear input buffer

   if(choice == 'y') {
       printf("Enter new altitude (in meters):\n");
       scanf("%d", &z); //get user input
       printf("Ascending to %d meters...\n", z);
   } else {
       printf("Maintaining current altitude\n");
   }

   printf("Taking photo...\n");
   printf("Photo taken and saved\n");

   printf("Returning to base...\n");

   return 0;
}