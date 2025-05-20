//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: rigorous
#include <stdio.h>
#include <string.h>

int main() {
   char name[20];
   int choice;
   
   printf("Welcome to the Text-Based Adventure Game!\n");
   printf("Please enter your name: ");
   scanf("%s", name);
   
   printf("\nHello %s, are you ready to play? (Enter 1 to begin or 2 to quit): ", name);
   scanf("%d", &choice);
   
   if (choice == 1) {
      printf("\nYou wake up on a deserted island with no memory of how you got there.\n");
      printf("You see a forest in the distance and a beach to your right.\n");
      printf("What would you like to do?\n");
      printf("Enter 1 to explore the forest or 2 to head to the beach: ");
      scanf("%d", &choice);

      if (choice == 1) {
          printf("\nYou make your way through the dense forest and stumble upon a waterfall.\n");
          printf("Do you want to swim in the waterfall? (Enter 1 for yes or 2 for no): ");
          scanf("%d", &choice);
          
          if (choice == 1) {
             printf("\nYou swim in the waterfall and find a hidden cave behind the waterfall.\n");
             printf("You enter the cave and find a treasure chest filled with gold and jewels!\n");
             printf("You have won the game! Congratulations %s!\n", name);
          } else {
             printf("\nYou chose not to swim in the waterfall and keep exploring the forest.\n");
             printf("You soon come across a tribe of cannibals and they capture you.\n");
             printf("You did not win the game. Better luck next time %s.\n", name);
          }
            
      } else {
          printf("\nYou make your way to the beach and find a boat.\n");
          printf("Do you want to try and sail the boat? (Enter 1 for yes or 2 for no): ");
          scanf("%d", &choice);
          
          if (choice == 1) {
             printf("\nYou sail the boat but get caught in a hurricane and shipwrecked again.\n");
             printf("You did not win the game. Better luck next time %s.\n", name);
          } else {
             printf("\nYou chose not to sail the boat and keep exploring the beach.\n");
             printf("You soon come across a group of survivors who help you escape the island.\n");
             printf("You have won the game! Congratulations %s!\n", name);
          }
      }
   } else {
      printf("\nYou have quit the game. Goodbye %s.\n", name);
   }
   
   return 0;
}