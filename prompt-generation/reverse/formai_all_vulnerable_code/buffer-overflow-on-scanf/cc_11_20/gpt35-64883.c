//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  char playerName[50];
  int playerHealth = 100;
  int playerGold = 0;
  int weaponDamage = 10;
  
  printf("Welcome to the Text-Based Adventure Game!\n");
  printf("What is your name, adventurer? ");
  scanf("%s", playerName);
  
  printf("\nGreetings, %s! Your adventure begins now.\n", playerName);
  
  srand(time(NULL));
  
  while (playerHealth > 0) {
    int randomEncounter = rand() % 3;
    
    switch(randomEncounter) {
      case 0:
        printf("\nYou encountered a hungry wolf!\n");
        int wolfHealth = 50;
        
        while (wolfHealth > 0) {
          int playerAttack = rand() % weaponDamage + 1;
          int wolfAttack = rand() % 5 + 1;
          
          printf("You dealt %d damage to the wolf!\n", playerAttack);
          wolfHealth -= playerAttack;
          
          if (wolfHealth <= 0) {
            printf("You defeated the wolf!\n");
            playerGold += 20;
            break;
          }
          
          printf("The wolf dealt %d damage to you!\n", wolfAttack);
          playerHealth -= wolfAttack;
          
          if (playerHealth <= 0) {
            printf("You are dead.\n");
            break;
          }
          
          printf("\nYour health is now %d.\n", playerHealth);
          printf("The wolf's health is now %d.\n", wolfHealth);
        }
        
        break;
        
      case 1:
        printf("\nYou stumbled upon a hidden treasure chest!\n");
        printf("You gained 50 gold!\n");
        playerGold += 50;
        break;
        
      case 2:
        printf("\nYou found a mysterious old man!\n");
        printf("For 10 gold, the old man will increase your weapon damage by 5.\n");
        printf("Do you want to pay the old man?\n");
        
        char choice[3];
        scanf("%s", choice);
        
        if (choice[0] == 'y' || choice[0] == 'Y') {
          if (playerGold >= 10) {
            printf("Your weapon damage has increased by 5!\n");
            playerGold -= 10;
            weaponDamage += 5;
          } else {
            printf("You don't have enough gold!\n");
          }
        } else {
          printf("The old man cackles and disappears into the shadows.\n");
        }
        
        break;
    }
    
    if (playerHealth <= 0) {
      break;
    }
    
    printf("\nYou have %d gold.\n", playerGold);
    printf("Your health is %d.\n", playerHealth);
    printf("Your weapon damage is %d.\n", weaponDamage);
    
    printf("\nWhat do you want to do?\n");
    printf("1. Continue your adventure.\n");
    printf("2. Quit the game.\n");
    
    int choice;
    scanf("%d", &choice);
    
    if (choice == 2) {
      break;
    } else {
      printf("\nYour adventure continues!\n");
    }
  }
  
  printf("\nThank you for playing the Text-Based Adventure Game!\n");
  
  return 0;
}