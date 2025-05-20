//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0)); // Seed for random number generation
  int player_health = 100;
  int monster_health = 100;
  int damage_dealt, damage_taken;
  char choice;

  printf("*** Welcome to the Text-Based Adventure Game ***\n");
  printf("You are lost in a dark forest filled with monsters.\n");
  printf("Your goal is to defeat the monster and find your way out of the forest.\n");
  printf("You have 100 health points.\n\n");

  while (player_health > 0 && monster_health > 0) {
    printf("Your health: %d\n", player_health);
    printf("Monster health: %d\n", monster_health);
    printf("What will you do?\n");
    printf("1. Attack.\n");
    printf("2. Heal.\n");
    printf("3. Run.\n");
    scanf(" %c", &choice);

    switch (choice) {
      case '1':
        damage_dealt = rand() % 20 + 1; // Player attacks
        printf("You deal %d damage to the monster.\n", damage_dealt);
        monster_health -= damage_dealt;
        damage_taken = rand() % 15 + 1; // Monster attacks
        printf("The monster deals %d damage to you.\n", damage_taken);
        player_health -= damage_taken;
        break;
      case '2':
        player_health += 20; // Player heals
        printf("You heal yourself and regain 20 health points.\n");
        damage_taken = rand() % 15 + 1; // Monster attacks
        printf("The monster deals %d damage to you.\n", damage_taken);
        player_health -= damage_taken;
        break;
      case '3':
        printf("You run away from the monster.\n");
        return 0;
      default:
        printf("Invalid choice. Please choose again.\n");
        break;
    }
  }

  if (player_health <= 0) { // Player loses
    printf("Your health: %d\n", player_health);
    printf("Monster health: %d\n", monster_health);
    printf("You have been defeated by the monster. Game over.\n");
  } else { // Player wins
    printf("Your health: %d\n", player_health);
    printf("Monster health: %d\n", monster_health);
    printf("Congratulations! You have defeated the monster and found your way out of the forest.\n");
  }

  return 0;
}