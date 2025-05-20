//FormAI DATASET v1.0 Category: Robot movement control ; Style: complex
#include <stdio.h> 

int main() {

   int speed = 1;
   int distance = 0;

   printf("Welcome to the Robot Movement control program!\n");
   printf("Enter a distance in meters for the robot to move: ");
   scanf("%d", &distance);

   for(int i = 0; i < distance; i++) {
      printf("Moving robot forward at a speed of %d m/s\n", speed);
      sleep(1);
   }

   printf("Robot has reached the destination!\n");

   // Robot Turning Control
   
   char turn_direction;
   int turn_angle;

   printf("Enter a turn direction for the robot (L or R): ");
   scanf(" %c", &turn_direction);

   printf("Enter an angle in degrees for the robot to turn: ");
   scanf("%d", &turn_angle);

   if(turn_direction == 'L') {
      printf("Turning robot left by %d degrees\n", turn_angle);
   } else if(turn_direction == 'R') {
      printf("Turning robot right by %d degrees\n", turn_angle);
   } else {
      printf("Invalid turn direction entered. Exiting program...\n");
      return 0;
   }

   // Robot Gripping Control

   char grip_option;

   printf("Would you like the robot to grip an object (Y or N)? ");
   scanf(" %c", &grip_option);

   if(grip_option == 'Y') {
      printf("Robot is gripping an object!\n");

      // Robot Lifting Control

      int lift_height;
      printf("Enter the height in cm to lift the object: ");
      scanf("%d", &lift_height);
      printf("Lifting object to a height of %d cm\n", lift_height);

      // Move to destination with object

      printf("Moving robot forward at a speed of %d m/s with object\n", speed);
      for(int i = 0; i < distance; i++) {
         sleep(1);
      }

      // Release object

      printf("Releasing object\n");
      printf("Robot has reached the destination with object!\n");

   } else if(grip_option == 'N') {
      printf("Robot is not gripping an object.\n");
   } else {
      printf("Invalid option entered. Exiting program...\n");
      return 0;
   }

   printf("Program complete. Robot control sequence finished.\n");
   return 0;
}