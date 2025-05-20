//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int health = 100;
int strength = 10;

void startGame();
void displayStats();
void battle(int enemyHealth, int enemyStrength);
void win();
void lose();

int main() {
  startGame();
  return 0;
}

void startGame() {
  printf("Welcome to the adventure game!\n");
  printf("You are in a dark forest with only a sword as your weapon.\n");
  printf("You see a path leading to two directions. \n");

  char direction[20];
  printf("Which direction will you choose? (left/right): ");
  scanf("%s", direction);

  if (strcmp(direction, "left") == 0) {
    printf("You have chosen left.\n");
    displayStats();

    printf("You encounter an enemy with a health of 50 and a strength of 5.\n");
    battle(50, 5);
    win();
  } else {
    printf("You have chosen right.\n");
    displayStats();

    printf("You encounter an enemy with a health of 70 and a strength of 8.\n");
    battle(70, 8);
    win();
  }
}

void displayStats() {
  printf("Your health is %d.\n", health);
  printf("Your strength is %d.\n", strength);
}

void battle(int enemyHealth, int enemyStrength) {
  srand(time(NULL));

  while (health > 0 && enemyHealth > 0) {
    int attack = rand() % strength;
    printf("You attack the enemy with a strength of %d.\n", attack);
    enemyHealth -= attack;

    if (enemyHealth <= 0) {
      printf("You have defeated the enemy! \n"); 
      return;
    }

    int enemyAttack = rand() % enemyStrength;
    printf("The enemy attacks you with a strength of %d.\n", enemyAttack);
    health -= enemyAttack;

    if (health <= 0) {
      lose();
    }
  }
}

void win() {
  printf("Congratulations, you have won the game!\n");
  printf("Thank you for playing the adventure game.");
  exit(0);
}

void lose() {
  printf("Game over. You lost all your health.\n");
  printf("Thank you for playing the adventure game.");
  exit(0);
}