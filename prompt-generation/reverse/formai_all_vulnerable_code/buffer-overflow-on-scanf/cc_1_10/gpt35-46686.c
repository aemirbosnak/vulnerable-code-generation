//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  printf("*Welcome to the Adventure Game!*");
  
  char name[20];
  printf("\nEnter your name to begin your adventure: ");
  scanf("%s", name);
  
  printf("\nHello, %s! You have been chosen to embark on an epic journey through an enchanted forest. Are you ready to begin? (yes/no)\n", name);
  
  char answer[3];
  scanf("%s", answer);
  if (strcmp(answer, "yes") == 0) {
    printf("\nLet the adventure begin!\n\n");
    srand(time(NULL));
    
    int health = 100;
    int gold = 0;
    
    while (health > 0) {
      int chance = rand() % 3;
      
      if (chance == 0) {
        printf("You stumble upon a treasure chest!\n");
        int loot = rand() % 101;
        printf("You found %d gold.\n", loot);
        gold += loot;
      } else if (chance == 1) {
        printf("You encounter a hostile creature!\n");
        int damage = rand() % 21;
        health -= damage;
        printf("The creature dealt %d damage to you.\n", damage);
        printf("Your health is now %d.\n", health);
      } else {
        printf("You meet a friendly traveler who offers you a trade.\n");
        printf("Do you want to trade? (yes/no)\n");
        char trade[3];
        scanf("%s", trade);
        if (strcmp(trade, "yes") == 0) {
          int offer = rand() % 21;
          printf("The traveler offers you %d gold for an item of your choice. Do you accept? (yes/no)\n", offer);
          char accept[3];
          scanf("%s", accept);
          if (strcmp(accept, "yes") == 0) {
            printf("You gained %d gold!\n", offer);
            gold += offer;
          } else {
            printf("The traveler bids you farewell and continues on their way.\n");
          }
        } else {
          printf("The traveler bids you farewell and continues on their way.\n");
        }
      }
      
      if (health <= 0) {
        printf("You have been defeated!\n");
        printf("SCORE: You collected %d gold during your adventure.\n", gold);
      } else {
        printf("\nWhat would you like to do? (stats/continue)\n");
        char choice[8];
        scanf("%s", choice);
        if (strcmp(choice, "stats") == 0) {
          printf("Your health is %d and you have %d gold.\n", health, gold);
        }
      }
    }
  }
  
  printf("Thanks for playing, %s! Goodbye!\n", name);
  
  return 0;
}