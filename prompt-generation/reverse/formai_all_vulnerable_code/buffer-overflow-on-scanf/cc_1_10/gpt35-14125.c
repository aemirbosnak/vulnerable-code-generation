//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  char player_name[30];
  int player_health = 100;
  int enemy_health = 75;
  int player_attack;
  int enemy_attack;
  int dice_roll;
  int potion_count = 3;
  
  printf("Welcome, traveler! What is your name?\n");
  scanf("%s", player_name);
  printf("Greetings, %s! Your journey begins...\n\n", player_name);
  
  while (player_health > 0 && enemy_health > 0) {
    printf("Your health: %d | Enemy health: %d\n", player_health, enemy_health);
    printf("What would you like to do? (1) Attack (2) Drink potion\n");
    int choice;
    scanf("%d", &choice);
    
    switch (choice) {
      case 1:
        printf("Roll the dice to see how much damage you do!\n");
        printf("Press enter to roll...\n\n");
        getchar();
        getchar();
        srand(time(NULL));
        dice_roll = rand() % 6 + 1;
        player_attack = dice_roll * 10;
        printf("You rolled a %d! You did %d damage!\n", dice_roll, player_attack);
        enemy_health -= player_attack;
        break;
        
      case 2:
        if (potion_count > 0) {
          printf("You drank a potion! You gained 25 health!\n");
          player_health += 25;
          potion_count--;
        } else {
          printf("You don't have any potions left!\n");
        }
        break;
        
      default:
        printf("I'm sorry, I didn't understand that.\n");
    }
    
    if (enemy_health <= 0) {
      printf("Congratulations, you defeated the enemy!\n");
      break;
    }
    
    printf("The enemy attacks!\n");
    srand(time(NULL));
    dice_roll = rand() % 6 + 1;
    enemy_attack = dice_roll * 8;
    printf("The enemy rolled a %d! You took %d damage!\n", dice_roll, enemy_attack);
    player_health -= enemy_attack;
    
    if (player_health <= 0) {
      printf("Game over! You have been defeated.\n");
      break;
    }
  }
  
  printf("Thanks for playing!\n");
  return 0;
}