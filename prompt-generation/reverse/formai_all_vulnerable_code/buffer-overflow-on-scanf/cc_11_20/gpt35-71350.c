//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Generating random values in a range
int rand_range(int min, int max)
{
   return rand() % (max - min + 1) + min;
}

// Main Function
int main()
{
   // Variables
   int x = 0, y = 0, direction = 0;
   int maxX = 10, maxY = 10;
   char move;

   printf("\nWelcome to Remote Control Vehicle Simulation!\n");
   printf("\n================= Main Menu ==================\n");
   printf(" Use 'w' to move forward\n Use 'a' to turn left\n Use 'd' to turn right\n Use 'q' to quit\n");
   printf("===============================================\n");

   // Setting random seed
   srand(time(0));

   // Loop until user quits
   while (move != 'q')
   {
      // Display current position and direction
      printf("\nCurrent Position: (%d, %d) Direction: ", x, y);
      switch (direction % 4)
      {
         case 0:
             printf("East\n");
             break;
         case 1:
             printf("North\n");
             break;
         case 2:
             printf("West\n");
             break;
         case 3:
             printf("South\n");
             break;
      }

      // Ask for user input
      printf("Enter command: ");
      scanf("%c", &move);

      // Process user input
      switch (move)
      {
         case 'w':
             // Move forward
             if (direction % 4 == 0 && x < maxX)
             {
                 x++;
             }
             else if (direction % 4 == 1 && y < maxY)
             {
                 y++;
             }
             else if (direction % 4 == 2 && x > 0)
             {
                 x--;
             }
             else if (direction % 4 == 3 && y > 0)
             {
                 y--;
             }
             else
             {
                 printf("You cannot go that way!\n");
             }
             break;
         case 'a':
             // Turn left
             direction--;
             if (direction < 0)
             {
                 direction = 3;
             }
             break;
         case 'd':
             // Turn right
             direction++;
             if (direction > 3)
             {
                 direction = 0;
             }
             break;
         case 'q':
             // Quit
             printf("\nGoodbye!\n");
             break;
         default:
             // Invalid input
             printf("Invalid command! Use 'w', 'a', 'd', or 'q'.\n");
             break;
      }

      // Add random obstacle
      if (rand_range(1, 10) == 1)
      {
         printf("\nObstacle at (%d, %d)!\n", rand_range(0, maxX), rand_range(0, maxY));
      }
   }

   return 0;
}