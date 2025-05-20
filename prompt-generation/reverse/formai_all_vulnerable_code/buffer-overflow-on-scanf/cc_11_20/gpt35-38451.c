//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int choice;
   int playerHealth = 100;
   int enemyHealth = 100;
   int playerAmmo = 6;
   int enemyAmmo = 6;
   srand(time(NULL));

   printf("Welcome to the Cyberpunk Adventure Game!\n");

   while (playerHealth > 0 && enemyHealth > 0) {
      printf("\nYour health: %d, Enemy health: %d\n\n", playerHealth, enemyHealth);
      
      //prompt user for action
      printf("1. Attack\n");
      printf("2. Reload\n");
      printf("3. Run away\n\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch (choice) {
         case 1: //attack
            printf("\nYou fire your weapon at the enemy.\n");
            if (rand() % 2 == 0) { //50% chance enemy is hit
               printf("You hit the enemy!\n");
               enemyHealth -= 15; //reduce enemy health by 15
            }
            else {
               printf("You missed the enemy.\n");
            }

            printf("The enemy fires back at you.\n");
            if (rand() % 2 == 0) { //50% chance player is hit
               printf("The enemy hit you!\n");
               playerHealth -= 20; //reduce player health by 10
            }
            else {
               printf("The enemy missed you.\n");
            }

            playerAmmo--; //decrement player's ammo by 1
            enemyAmmo--; //decrement enemy's ammo by 1

            break;

         case 2: //reload
            printf("\nYou reload your weapon.\n");
            playerAmmo = 6; //player's ammo is restored to full
            printf("The enemy also reloads their weapon.\n");
            enemyAmmo = 6; //enemy's ammo is restored to full
            break;

         case 3: //run away
            printf("\nYou run away from the battle!\n");
            printf("You lose 20 health points for cowardice!\n");
            playerHealth -= 20; //reduce player's health by 20
            enemyHealth = 0; //set enemy's health to 0 to end the game
            break;

         default: //invalid choice
            printf("Invalid choice, try again.\n");
            break;
      }

      if (playerAmmo == 0 && enemyAmmo == 0) { //if both run out of ammo
         printf("\nYou and the enemy are both out of ammo!\n");
         printf("The fight ends in a draw!\n");
         playerHealth = 0; //set player health to 0 to end the game
      }
   }

   if (playerHealth <= 0) { //player loses
      printf("\nYour health reaches 0. GAME OVER!\n");
   }
   else { //player wins
      printf("\nYou defeated the enemy and emerged victorious! Congratulations!\n");
   }

   return 0;
}