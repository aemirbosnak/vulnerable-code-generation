//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   srand(time(NULL));
   int energy = 100;
   int alienHealth = 100;
   int attackChoice = 0;
   int attackDamage = 0;
   int alienAttackDamage = 0;
   
   printf("Welcome to Procedural Space Adventure!\n");
   printf("You are stranded on the planet Zorgon with only 100 energy points.\n");
   printf("You encounter an alien with 100 health points. Your goal is to defeat the alien before you run out of energy.\n");
   
   while (energy > 0 && alienHealth > 0) {
      printf("You currently have %d energy points. What do you want to do?\n", energy);
      printf("1. Attack the alien with your laser gun.\n");
      printf("2. Attempt to negotiate with the alien.\n");
      printf("3. Run away.\n");
      scanf("%d", &attackChoice);
      
      switch (attackChoice) {
         case 1:
            attackDamage = rand() % 11 + 10;
            alienHealth -= attackDamage;
            printf("You attacked the alien with your laser gun and did %d points of damage!\n", attackDamage);
            break;
         case 2:
            printf("You attempted to negotiate with the alien, but it didn't work.\n");
            break;
         case 3:
            printf("You ran away from the alien!\n");
            energy -= 20;
            break;
         default:
            printf("Invalid input. Please try again.\n");
            break;
      }
      
      if (alienHealth > 0) {
         alienAttackDamage = rand() % 11 + 5;
         energy -= alienAttackDamage;
         printf("The alien attacked you and did %d points of damage!\n", alienAttackDamage);
      }
      
      if (energy <= 0) {
         printf("You ran out of energy and died.\n");
      }
      
      if (alienHealth <= 0) {
         printf("Congratulations! You defeated the alien and survived on Zorgon!\n");
      }
   }
   
   return 0;
}