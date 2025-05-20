//Falcon2-11B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: unmistakable
#include <stdio.h>

int main() {
   int forward, reverse, left, right, speed;

   printf("Enter the forward speed (1-10): ");
   scanf("%d", &forward);

   printf("Enter the reverse speed (1-10): ");
   scanf("%d", &reverse);

   printf("Enter the left speed (1-10): ");
   scanf("%d", &left);

   printf("Enter the right speed (1-10): ");
   scanf("%d", &right);

   printf("Enter the speed (1-10): ");
   scanf("%d", &speed);

   while(1) {
      printf("Enter 1 to move forward, 2 to move backward, 3 to turn left, 4 to turn right, 5 to increase speed, 6 to decrease speed, 7 to stop, or any other key to exit: ");
      int choice;
      scanf("%d", &choice);

      switch(choice) {
         case 1:
            printf("Moving forward at %d\n", forward);
            break;
         case 2:
            printf("Moving backward at %d\n", reverse);
            break;
         case 3:
            printf("Turning left at %d\n", left);
            break;
         case 4:
            printf("Turning right at %d\n", right);
            break;
         case 5:
            printf("Increasing speed to %d\n", speed);
            break;
         case 6:
            printf("Decreasing speed to %d\n", speed);
            break;
         case 7:
            printf("Stopping\n");
            break;
         default:
            printf("Exiting\n");
            break;
      }
   }

   return 0;
}