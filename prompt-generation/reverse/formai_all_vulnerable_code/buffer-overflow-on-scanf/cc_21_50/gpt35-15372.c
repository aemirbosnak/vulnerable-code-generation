//FormAI DATASET v1.0 Category: Educational ; Style: medieval
#include <stdio.h>

int main() {
   int gold = 100;
   int swordCost = 25;
   int shieldCost = 20;
   int armourCost = 30;
   int healthPotionCost = 10;
   int sword = 0;
   int shield = 0;
   int armour = 0;
   int healthPotions = 0;
   int numberOfEnemies = 5;
   int enemyHealth = 20;

   printf("Welcome traveler, you currently have %d gold pieces.\n", gold);
   printf("Would you like to purchase any equipment? (Y/N)\n");
   char response;
   scanf("%c", &response);

   while(response == 'Y' || response == 'y') {
      printf("What would you like to purchase?\n");
      printf("1) Sword - %d gold pieces\n", swordCost);
      printf("2) Shield - %d gold pieces\n", shieldCost);
      printf("3) Armour - %d gold pieces\n", armourCost);
      printf("4) Health Potion - %d gold pieces\n", healthPotionCost);
      
      // Choose player equipment
      int choice;
      scanf("%d", &choice);

      switch(choice) {
         case 1:
            if(gold >= swordCost) {
               gold -= swordCost;
               sword++;
               printf("You have purchased a sword for %d gold pieces. You now have %d gold pieces left.\n", swordCost, gold);
            } else {
               printf("You do not have enough gold to purchase a sword.\n");
            }
            break;

         case 2:
            if(gold >= shieldCost) {
               gold -= shieldCost;
               shield++;
               printf("You have purchased a shield for %d gold pieces. You now have %d gold pieces left.\n", shieldCost, gold);
            } else {
               printf("You do not have enough gold to purchase a shield.\n");
            }
            break;

         case 3:
            if(gold >= armourCost) {
               gold -= armourCost;
               armour++;
               printf("You have purchased armour for %d gold pieces. You now have %d gold pieces left.\n", armourCost, gold);
            } else {
               printf("You do not have enough gold to purchase armour.\n");
            }
            break;

         case 4:
            if(gold >= healthPotionCost) {
               gold -= healthPotionCost;
               healthPotions++;
               printf("You have purchased a health potion for %d gold pieces. You now have %d gold pieces left.\n", healthPotionCost, gold);
            } else {
               printf("You do not have enough gold to purchase a health potion.\n");
            }
            break;

         default:
            printf("Invalid choice.\n");
            break;
      }

      printf("Would you like to purchase anything else? (Y/N)\n");
      scanf(" %c", &response);
   }

   // Fight the enemies
   printf("You encountered %d enemies! Get ready for battle!\n", numberOfEnemies);

   for(int i = 1; i <= numberOfEnemies; i++) {
      int enemy = i;
      printf("Enemy %d has approached you.\n", enemy);

      while(enemyHealth > 0) {
         int playerAttack = 5;

         // Calculate player damage
         if(sword > 0) {
            playerAttack += 5;
         }

         int enemyDamage = playerAttack;

         // Calculate enemy damage
         if(shield > 0) {
            enemyDamage -= 2;
         }

         if(armour > 0) {
            enemyDamage -= 3;
         }

         if(healthPotions > 0) {
            printf("You have %d health potions. Would you like to use one? (Y/N)\n", healthPotions);
            char potionResponse;
            scanf(" %c", &potionResponse);

            if(potionResponse == 'Y' || potionResponse == 'y') {
               enemyDamage -= 3;
               healthPotions--;
               printf("You have used a health potion. You now have %d health potions left.\n", healthPotions);
            }
         }

         enemyHealth -= enemyDamage;
         printf("You did %d damage to the enemy. The enemy has %d health left.\n", playerAttack, enemyHealth);

         // Check if enemy is defeated
         if(enemyHealth <= 0) {
            printf("You have defeated enemy %d!\n", enemy);
            enemy++;
            enemyHealth = 20;
         } else {
            printf("The enemy did %d damage to you. You have %d health left.\n", enemyDamage, gold);
         }

         // Check if player is defeated
         if(gold <= 0) {
            printf("You have been defeated by enemy %d. Game over!\n", enemy);
            return 0;
         }
      }
   }

   printf("Congratulations! You have defeated all the enemies and completed the game!\n");

   return 0;
}