//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   int fuel = 100;
   int laser = 50;
   int shield = 100;
   int distance = 0;
   
   printf("Space Adventure Begins");
   printf("\n-----------------------\n\n");
   
   printf("Welcome to your first mission. You are the captain of this spaceship and must navigate through the galaxy to reach your destination planet.\n\n");
   
   printf("Press ENTER to continue...");
   getchar();
   
   printf("You begin your journey with a full fuel tank and a charged laser. Be careful, there may be space pirates lurking around. Make sure to keep an eye on your shield too.\n\n");
   
   while (distance < 500) {
      int choice;
      printf("You have travelled %d light years. What would you like to do next?\n", distance);
      printf("1. Travel forward 50 light years\n");
      printf("2. Refuel at the nearest station (costs 20 fuel)\n");
      printf("3. Trade with other spacecraft for supplies (costs 30 fuel and 10 laser)\n");
      printf("4. Attack the next enemy spacecraft (uses 40 laser and 30 shield)\n");
      printf("5. Quit the game\n\n");
      
      printf("Enter your choice (1-5): ");
      scanf("%d", &choice);
      
      switch (choice) {
         case 1:
            if (fuel >= 50) {
               fuel -= 50;
               laser -= 5;
               shield -= 5;
               distance += 50;
               printf("\nYou have travelled 50 light years forward. Current fuel: %d, Current laser: %d, Current shield: %d\n\n", fuel, laser, shield);
            } else {
               printf("\nYou don't have enough fuel to travel. Choose a different option.\n\n");
            }
            break;
            
         case 2:
            if (fuel >= 20) {
               fuel -= 20;
               printf("\nYou have refuelled your tank. Current fuel: %d\n\n", fuel);
            } else {
               printf("\nYou don't have enough fuel to refuel. Choose a different option.\n\n");
            }
            break;
            
         case 3:
            if (fuel >= 30 && laser >= 10) {
               fuel -= 30;
               laser -= 10;
               printf("\nYou have traded with other spacecraft. Current fuel: %d, Current laser: %d\n\n", fuel, laser);
            } else {
               printf("\nYou don't have enough fuel and laser to trade. Choose a different option.\n\n");
            }
            break;
            
         case 4:
            if (laser >= 40 && shield >= 30) {
               laser -= 40;
               shield -= 30;
               printf("\nYou have successfully attacked the enemy spacecraft. Current laser: %d, Current shield: %d\n\n", laser, shield);
            } else {
               printf("\nYou don't have enough laser and shield to attack. Choose a different option.\n\n");
            }
            break;
            
         case 5:
            printf("\nThanks for playing!\n");
            exit(0);
            
         default:
            printf("\nInvalid choice. Choose a number between 1-5.\n\n");
            break;
      }
      
      if (distance == 500) {
         printf("Congratulations, you have travelled 500 light years and have successfully reached your destination planet!");
         printf("\nPress ENTER to continue...");
         getchar();
      }
   }
   
   return 0;
}