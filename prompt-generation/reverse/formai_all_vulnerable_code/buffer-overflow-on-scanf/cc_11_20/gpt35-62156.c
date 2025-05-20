//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: safe
#include <stdio.h>

int main() {
   int choice;
   
   printf("Welcome to the text-based adventure game!\n");
   
   printf("You are lost in the woods. Which direction do you want to go?\n");
   printf("1. North\n");
   printf("2. East\n");
   printf("3. South\n");
   printf("4. West\n");
   scanf("%d", &choice);
   
   switch (choice) {
      case 1:
         printf("You reach a river. Do you want to ford it or follow it?\n");
         printf("1. Ford\n");
         printf("2. Follow\n");
         scanf("%d", &choice);
         
         if (choice == 1) {
            printf("You successfully cross the river and find a campsite.\n");
            printf("You set up camp for the night and continue your journey in the morning.\n");
         }
         else if (choice == 2) {
            printf("You follow the river and eventually reach a waterfall.\n");
            printf("You can't continue beyond this point and have to turn back.\n");
         }
         break;
      
      case 2:
         printf("You come across a clearing. Do you want to explore or keep moving?\n");
         printf("1. Explore\n");
         printf("2. Keep moving\n");
         scanf("%d", &choice);
         
         if (choice == 1) {
            printf("You find an abandoned cabin and search it for supplies.\n");
            printf("You find some food and water bottles and continue on your journey.\n");
         }
         else if (choice == 2) {
            printf("You keep moving and eventually find yourself back where you started.\n");
         }
         break;
         
      case 3:
         printf("You come across a fork in the road. Which path do you want to take?\n");
         printf("1. Left\n");
         printf("2. Right\n");
         scanf("%d", &choice);
         
         if (choice == 1) {
            printf("You follow the left path and come across a small village.\n");
            printf("The villagers offer you food and shelter for the night.\n");
            printf("You continue on your journey in the morning, well rested and fed.\n");
         }
         else if (choice == 2) {
            printf("You follow the right path and come across a band of robbers.\n");
            printf("They steal all your belongings and leave you stranded in the woods.\n");
            printf("You have to find your way back to civilization.\n");
         }
         break;
         
      case 4:
         printf("You come across a cave. Do you want to explore it or keep moving?\n");
         printf("1. Explore\n");
         printf("2. Keep moving\n");
         scanf("%d", &choice);
         
         if (choice == 1) {
            printf("You enter the cave and find a treasure chest.\n");
            printf("You open the chest and find a priceless artifact.\n");
            printf("You sell it in the next town and become rich.\n");
         }
         else if (choice == 2) {
            printf("You keep moving and eventually find yourself back where you started.\n");
         }
         break;
         
      default:
         printf("Invalid choice. Please try again.\n");
         main(); // restart the game
         break;
   }
   
   return 0;
}