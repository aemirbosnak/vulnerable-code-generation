//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ENEMY_NUMBER 5

typedef struct Enemy {
  int health;
  int attack_power;
  char name[20];
} Enemy;

Enemy enemies[MAX_ENEMY_NUMBER];

void initialize_enemies() {
  for (int i = 0; i < MAX_ENEMY_NUMBER; i++) {
    enemies[i].health = rand() % 100 + 1;
    enemies[i].attack_power = rand() % 20 + 1;
    sprintf(enemies[i].name, "Enemy %d", i + 1);
  }
}

void battle(Enemy* enemy) {
  printf("You are battling %s.\n", enemy->name);
  printf("Health: %d, Attack Power: %d\n", enemy->health, enemy->attack_power);

  int your_choice = 0;
  printf("Enter 1 to attack, 2 to defend, 3 to flee: ");
  scanf("%d", &your_choice);

  switch (your_choice) {
    case 1:
      enemy->health -= rand() % enemy->attack_power;
      printf("You attacked %s. They have %d health left.\n", enemy->name, enemy->health);
      break;
    case 2:
      printf("You defended against %s's attack.\n", enemy->name);
      break;
    case 3:
      printf("You fled from battle.\n");
      break;
    default:
      printf("Invalid input.\n");
  }

  if (enemy->health <= 0) {
    printf("You defeated %s!\n", enemy->name);
  } else if (enemy->health > 0) {
    battle(enemy);
  }
}

int main() {
  initialize_enemies();

  for (int i = 0; i < MAX_ENEMY_NUMBER; i++) {
    battle(&enemies[i]);
  }

  return 0;
}