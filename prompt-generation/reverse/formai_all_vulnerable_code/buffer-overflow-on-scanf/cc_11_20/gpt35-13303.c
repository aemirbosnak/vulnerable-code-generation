//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int fuel = 100;
  int distance = 0;
  int oxygen = 100;
  int enemyHealth = 100;
  int playerHealth = 100;
  int randomEnemyAttack;
  int playerAttack;
  int playerEscapeChance;
  
  srand(time(NULL));
  
  printf("Welcome to the Space Adventure Game!\n");
  printf("Your mission is to travel 20000 miles away from Earth in your spaceship.\n");
  printf("You have 100 units of fuel, 100 units of oxygen, and a laser gun.\n");
  
  while (distance < 20000) {
    printf("\n");
    printf("Current distance from Earth: %d miles\n", distance);
    printf("Fuel left: %d units\n", fuel);
    printf("Oxygen left: %d units\n", oxygen);
    printf("Your health: %d\n", playerHealth);
    printf("Enemy health: %d\n", enemyHealth);
    
    printf("\n");
    printf("Select an action:\n");
    printf("1. Travel 1000 miles\n");
    printf("2. Refill fuel (cost 10 units of oxygen)\n");
    printf("3. Refill oxygen (cost 10 units of fuel)\n");
    printf("4. Fight enemy\n");
    printf("5. Try to escape from enemy\n");
    
    int choice;
    scanf("%d", &choice);
    
    switch (choice) {
      case 1:
        if (fuel >= 10 && oxygen >= 10) {
          fuel -= 10;
          oxygen -= 10;
          distance += 1000;
          printf("You have traveled 1000 miles.\n");
        } else {
          printf("Not enough resources to travel.\n");
        }
        break;
      case 2:
        if (oxygen >= 10) {
          fuel += 10;
          oxygen -= 10;
          printf("Fuel refilled by 10 units.\n");
        } else {
          printf("Not enough oxygen to refill fuel.\n");
        }
        break;
      case 3:
        if (fuel >= 10) {
          oxygen += 10;
          fuel -= 10;
          printf("Oxygen refilled by 10 units.\n");
        } else {
          printf("Not enough fuel to refill oxygen.\n");
        }
        break;
      case 4:
        if (enemyHealth > 0) {
          randomEnemyAttack = rand() % 20 + 1;
          playerHealth -= randomEnemyAttack;
          printf("Enemy attacked you with %d damage.\n", randomEnemyAttack);
          if (playerHealth <= 0) {
            printf("You have died.\n");
            return 0;
          }
          playerAttack = rand() % 20 + 1;
          enemyHealth -= playerAttack;
          printf("You attacked enemy with %d damage.\n", playerAttack);
          if (enemyHealth <= 0) {
            printf("Enemy has been defeated. Continue your journey.\n");
            break;
          }
        } else {
          printf("There is no enemy to fight.\n");
        }
        break;
      case 5:
        playerEscapeChance = rand() % 2;
        if (playerEscapeChance == 1) {
          printf("You have successfully escaped from the enemy.\n");
          break;
        } else {
          randomEnemyAttack = rand() % 20 + 1;
          playerHealth -= randomEnemyAttack;
          printf("Enemy attacked you with %d damage.\n", randomEnemyAttack);
          if (playerHealth <= 0) {
            printf("You have died.\n");
            return 0;
          }
        }
        break;
      default:
        printf("Invalid choice.\n");
        break;
    }
    
    if (distance >= 20000) {
      printf("Congratulations! You have successfully completed your mission.\n");
      return 0;
    }
    
    if (distance >= 1000) {
      printf("You have reached a new planet. Refill your resources.\n");
      fuel = 100;
      oxygen = 100;
      playerHealth = 100;
      enemyHealth = 100;
    }
  }
  
  return 0;
}