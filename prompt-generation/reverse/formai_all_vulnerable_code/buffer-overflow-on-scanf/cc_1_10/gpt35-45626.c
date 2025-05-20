//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: random
#include <stdio.h>

int main() {
   int choice;
   printf("Welcome to the Text-Based Adventure Game!\n\n");
   printf("You are lost in a forest. You see two paths ahead of you:\n");
   printf("1. A dark path leading deeper into the forest.\n");
   printf("2. A well-lit path leading out of the forest.\n");
   printf("Which path do you choose? (1/2): ");
   scanf("%d", &choice);
   
   if (choice == 1) {
      printf("\nYou start walking down the dark path. Soon, you hear strange noises coming from the bushes.\n");
      printf("Do you:\n");
      printf("1. Investigate the noises.\n");
      printf("2. Keep walking.\n");
      printf("What do you do? (1/2): ");
      scanf("%d", &choice);
      
      if (choice == 1) {
         printf("\nYou investigate the noises and come face to face with a group of angry wolves.\n");
         printf("You try to run, but they are too fast. You get attacked and lose the game.\n");
      }
      else if (choice == 2) {
         printf("\nYou keep walking and soon reach a clearing where you see a small cabin.\n");
         printf("Do you:\n");
         printf("1. Approach the cabin.\n");
         printf("2. Keep walking.\n");
         printf("What do you do? (1/2): ");
         scanf("%d", &choice);
         
         if (choice == 1) {
            printf("\nYou approach the cabin and knock on the door. An old man opens the door and invites you in.\n");
            printf("He tells you that he is a hermit and has been living in the forest for many years.\n");
            printf("He offers you food and shelter for the night. You accept and spend a peaceful night.\n");
            printf("In the morning, he gives you a map showing the way out of the forest.\n");
            printf("You win the game!\n");
         }
         else if (choice == 2) {
            printf("\nYou keep walking and soon lose your way. You get lost in the forest and lose the game.\n");
         }
         else {
            printf("\nInvalid choice. You lose the game.\n");
         }
      }
      else {
         printf("\nInvalid choice. You lose the game.\n");
      }
   }
   else if (choice == 2) {
      printf("\nYou start walking down the well-lit path. Soon, you see a river blocking your path.\n");
      printf("Do you:\n");
      printf("1. Swim across the river.\n");
      printf("2. Follow the river to see if there is a bridge.\n");
      printf("What do you do? (1/2): ");
      scanf("%d", &choice);
      
      if (choice == 1) {
         printf("\nYou start swimming but soon get exhausted. You drown in the river and lose the game.\n");
      }
      else if (choice == 2) {
         printf("\nYou follow the river and soon find a bridge. You cross it and keep walking.\n");
         printf("After a while, you reach a small village where you ask for directions.\n");
         printf("You learn that you are only a few miles away from civilization.\n");
         printf("You win the game!\n");
      }
      else {
         printf("\nInvalid choice. You lose the game.\n");
      }
   }
   else {
      printf("\nInvalid choice. You lose the game.\n");
   }
   
   return 0;
}