//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Initialize game variables
  int player_hp = 100;
  int enemy_hp = 100;
  int player_attack = 0;
  int enemy_attack = 0;
  int player_defense = 0;
  int enemy_defense = 0;
  int round_num = 1;
  int action_num;
  char action;

  // Set seed for random numbers
  srand(time(NULL));

  // Print game introduction
  printf("Welcome to the Land of Adventure!\n");
  printf("In this game, you will face a fierce enemy in battle.\n");
  printf("Your health and attack power are determined by a random roll.\n");
  printf("After each round of combat, you will have a chance to choose your next move.\n");
  printf("Good luck!\n\n");

  // Game loop
  while (player_hp > 0 && enemy_hp > 0) {
    // Print round number and stats
    printf("Round %d\n", round_num);
    printf("Player health: %d\n", player_hp);
    printf("Enemy health: %d\n", enemy_hp);

    // Determine player attack and defense
    player_attack = rand() % 10 + 1;
    player_defense = rand() % 5 + 1;

    // Determine enemy attack and defense
    enemy_attack = rand() % 10 + 1;
    enemy_defense = rand() % 5 + 1;

    // Prompt player to choose an action
    printf("Choose an action:\n");
    printf("1. Attack\n");
    printf("2. Defend\n");
    scanf("%d", &action_num);

    // Player attacks
    if (action_num == 1) {
      printf("You attack the enemy!\n");
      enemy_hp -= player_attack;

      // Enemy defends
      if (enemy_defense > player_attack) {
        printf("The enemy defends your attack!\n");
      }
      // Enemy takes damage
      else {
        printf("You deal %d damage to the enemy!\n", player_attack - enemy_defense);
      }
    }
    // Player defends
    else if (action_num == 2) {
      printf("You defend against the enemy!\n");

      // Enemy attacks
      if (player_defense > enemy_attack) {
        printf("You defend the enemy's attack!\n");
      }
      // Player takes damage
      else {
        printf("The enemy deals %d damage to you!\n", enemy_attack - player_defense);
        player_hp -= enemy_attack - player_defense;
      }
    }
    // Invalid input
    else {
      printf("Invalid input, try again.\n");
      continue;
    }

    // Check for winner
    if (player_hp <= 0) {
      printf("You have been defeated by the enemy. Game over.\n");
      break;
    }
    else if (enemy_hp <= 0) {
      printf("Congratulations! You have defeated the enemy.\n");
      break;
    }

    // Increment round number
    round_num++;
  }

  return 0;
}