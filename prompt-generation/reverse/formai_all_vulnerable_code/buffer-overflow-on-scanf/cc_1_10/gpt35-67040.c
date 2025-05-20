//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: interoperable
#include <stdio.h>
#include <string.h>

int main() {
   char player_name[20];
   int player_health = 100, player_gold = 50, player_score = 0;
   int choice;

   printf("Welcome to the Text-Based Adventure Game!\n");
   printf("Please enter your name: ");
   scanf("%s", player_name);
   printf("\n");

   printf("Greetings, %s!\n", player_name);
   printf("Your current health is %d.\n", player_health);
   printf("You have %d gold pieces in your pocket.\n", player_gold);
   printf("\n");

   printf("You find yourself standing in front of a dark and spooky forest.\n");
   printf("What would you like to do?\n");
   printf("1. Enter the forest\n");
   printf("2. Turn back and leave\n");
   scanf("%d", &choice);

   while (choice != 2 && player_health > 0) {
      if (choice == 1) {
         printf("\nYou enter the forest and encounter a scary monster!\n");
         printf("What would you like to do?\n");
         printf("1. Attack the monster\n");
         printf("2. Run away\n");
         scanf("%d", &choice);

         if (choice == 1) {
            int monster_health = 50;
            printf("\nYou start attacking the monster!\n");
            while (player_health > 0 && monster_health > 0) {
               printf("Your current health is %d.\n", player_health);
               printf("The monster's current health is %d.\n", monster_health);
               printf("\n");

               player_health -= 10;
               monster_health -= 10;
            }

            if (player_health <= 0) {
               printf("You died!\n");
               break;
            } else {
               printf("\nCongratulations, you defeated the monster!\n");
               player_gold += 30;
               player_score += 50;
               printf("You found 30 gold pieces on the monster's body!\n");
               printf("Your current score is %d.\n", player_score);
               printf("\n");

               printf("What would you like to do next?\n");
               printf("1. Continue exploring the forest\n");
               printf("2. Exit the forest and return home\n");
               scanf("%d", &choice);
            }
         } else if (choice == 2) {
            printf("\nYou managed to run away successfully!\n");
            printf("\n");

            printf("What would you like to do next?\n");
            printf("1. Continue exploring the forest\n");
            printf("2. Exit the forest and return home\n");
            scanf("%d", &choice);
         }
      } else if (choice == 2) {
         printf("\nYou decided to turn back and leave.\n");
         printf("\n");
         break;
      }
   }

   printf("\nThank you for playing the Text-Based Adventure Game, %s!\n", player_name);
   printf("Your final score is %d.\n", player_score);
   printf("Goodbye!\n");

   return 0;
}