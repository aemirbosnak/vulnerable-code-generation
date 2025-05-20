//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CHAR_LIMIT 50

int main() {
  char name[CHAR_LIMIT];
  int age;

  // Get player's name and age
  printf("Welcome to the Haunted House Simulator!\n");
  printf("What is your name?\n");
  fgets(name, CHAR_LIMIT, stdin);
  printf("Nice to meet you, %s! How old are you?\n", name);
  scanf("%d", &age);

  // Check if player is old enough to enter
  if (age < 18) {
    printf("Sorry, %s. You must be at least 18 years old to enter the Haunted House.\n", name);
    return 0;
  }

  // Initialize game variables
  int playerHealth = 100;
  int enemyCount = 0;
  int totalEnemies = 5;
  int enemyHealth = 50;
  int playerAttack = 20;
  int enemyAttack = 10;

  // Set up random number generator
  srand(time(NULL));

  // Play game loop until all enemies defeated or player dies
  while (enemyCount < totalEnemies && playerHealth > 0) {
    // Generate random enemy attack and player attack
    int enemyDamage = rand() % enemyAttack + 1;
    int playerDamage = rand() % playerAttack + 1;

    // Simulate turn-based combat
    playerHealth -= enemyDamage;
    enemyHealth -= playerDamage;

    // Display round results
    printf("\nRound %d\n", enemyCount + 1);
    printf("%s's Health: %d\n", name, playerHealth);
    printf("Enemy Health: %d\n", enemyHealth);
    printf("%s attacks the enemy for %d damage!\n", name, playerDamage);
    printf("The enemy attacks %s for %d damage!\n", name, enemyDamage);

    // Check if enemy defeated or player dead
    if (enemyHealth <= 0) {
      printf("\n%s has defeated the enemy!\n", name);
      enemyHealth = 50;
      enemyCount++;
    } else if (playerHealth <= 0) {
      printf("\nThe enemy has defeated %s! Game Over.\n", name);
    }
  }

  // Check if player won or lost and display ending message
  if (playerHealth > 0) {
    printf("\nCongratulations, %s! You have survived all enemies and conquered the Haunted House!\n", name);
  } else {
    printf("\nBetter luck next time, %s. You were not able to survive all the horrors of the Haunted House.\n", name);
  }

  return 0;
}