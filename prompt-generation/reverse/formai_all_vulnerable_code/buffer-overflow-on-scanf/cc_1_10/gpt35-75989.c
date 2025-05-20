//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct SpaceShip {
  int x;
  int y;
  int shield;
};

struct Enemy {
  int x;
  int y;
  int health;
};

void moveSpaceship(struct SpaceShip *ship, char direction) {
  switch(direction) {
    case 'W':
      ship->y--;
      break;
    case 'A':
      ship->x--;
      break;
    case 'S':
      ship->y++;
      break;
    case 'D':
      ship->x++;
      break;
    default:
      printf("Invalid direction.\n");
      break;
  }
}

void updateEnemy(struct SpaceShip *ship, struct Enemy *enemy) {
  int x_diff = abs(ship->x - enemy->x);
  int y_diff = abs(ship->y - enemy->y);

  if (x_diff <= 2 && y_diff <= 2) {
    enemy->health -= rand() % (ship->shield + 1);
    printf("Enemy health: %d\n", enemy->health);
  }
}

int main() {
  srand(time(0));

  struct SpaceShip ship = {0, 0, 5};
  struct Enemy enemy = {10, 10, 20};

  printf("Welcome to the Space Adventure game!\n");
  printf("You are in control of a spaceship and your mission is to defeat the enemy ship.\n");
  printf("To move your spaceship, use W (up), A (left), S (down), and D (right).\n");
  printf("Your spaceship has a shield, which reduces incoming damage by a random value between 0 and the shield value.\n");
  printf("Are you ready? Let's go!\n");

  while (enemy.health > 0) {
    char direction;
    printf("Your location: (%d, %d)\n", ship.x, ship.y);
    printf("Enter a direction (W, A, S, or D): ");
    scanf(" %c", &direction);
    moveSpaceship(&ship, direction);
    printf("Your new location: (%d, %d)\n", ship.x, ship.y);
    updateEnemy(&ship, &enemy);
  }

  printf("Congratulations! You defeated the enemy ship.\n");

  return 0;
}