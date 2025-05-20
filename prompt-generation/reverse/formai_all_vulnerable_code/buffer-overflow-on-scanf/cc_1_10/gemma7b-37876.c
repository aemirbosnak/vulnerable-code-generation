//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

void fight(int a, int b) {
  int damage = rand() % (a - b + 1) + b;
  printf("You dealt %d damage to the enemy!\n", damage);
  if (damage > b) {
    printf("The enemy is defeated!\n");
    exit(0);
  } else {
    printf("The enemy has %d health remaining.\n", b - damage);
  }
}

int main() {
  int health = 100;
  int enemyHealth = 100;

  printf("Welcome to the battle!\n");
  printf("You have %d health and the enemy has %d health.\n", health, enemyHealth);

  while (health > 0 && enemyHealth > 0) {
    printf("Enter 'attack' to attack the enemy, 'defend' to defend, or 'special' to use a special move.\n");
    char input;
    scanf(" %c", &input);

    switch (input) {
      case 'a':
        fight(health, enemyHealth);
        break;
      case 'd':
        printf("You blocked the enemy's attack.\n");
        break;
      case 's':
        printf("You used your special move and dealt extra damage to the enemy.\n");
        fight(health, enemyHealth);
        break;
      default:
        printf("Invalid input.\n");
    }
  }

  if (health <= 0) {
    printf("You have been defeated.\n");
  } else if (enemyHealth <= 0) {
    printf("You have won the battle!\n");
  }

  return 0;
}