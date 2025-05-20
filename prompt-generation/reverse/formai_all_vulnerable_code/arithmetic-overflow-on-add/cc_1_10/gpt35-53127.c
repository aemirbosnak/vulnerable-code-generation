//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// function prototypes
void wait();
int generateRandomNumber(int min, int max);
void displayIntro();
void chooseDifficultyLevel(int *alienHealth, int *playerHealth, char *difficultyLevel);
void alienAttack(int alienHealth, int *playerHealth);
void playerAttack(int playerHealth, int *alienHealth);
void displayEnding(int playerHealth);

int main() {
  srand(time(0));

  int alienHealth;
  int playerHealth;
  char difficultyLevel;

  displayIntro();

  // player chooses difficulty level
  chooseDifficultyLevel(&alienHealth, &playerHealth, &difficultyLevel);

  // game loop
  while (alienHealth > 0 && playerHealth > 0) {
    printf("\n");

    // alien attacks
    alienAttack(alienHealth, &playerHealth);
    if (playerHealth <= 0) {
      break;
    }

    // player attacks
    playerAttack(playerHealth, &alienHealth);
    if (alienHealth <= 0) {
      break;
    }
  }

  displayEnding(playerHealth);
  return 0;
}

// function to wait for 1 second
void wait() {
  int ms = 1000;
  clock_t start_time = clock();
  while (clock() < start_time + ms);
}

// function to generate a random number between min and max
int generateRandomNumber(int min, int max) {
  return (rand() % (max - min + 1)) + min;
}

// function to display the introduction
void displayIntro() {
  printf("Welcome to Procedural Space Adventure!\n");
  printf("You are the captain of a spaceship exploring the galaxy,\n");
  printf("but you have encountered a hostile alien ship.\n");
  printf("\n");
  wait();
}

// function to choose difficulty level
void chooseDifficultyLevel(int *alienHealth, int *playerHealth, char *difficultyLevel) {
  printf("Choose your difficulty level:\n");
  printf("a) Easy (Alien has 50 health, you have 100 health)\n");
  printf("b) Medium (Alien has 75 health, you have 75 health)\n");
  printf("c) Hard (Alien has 100 health, you have 50 health)\n");
  printf("Enter your choice (a/b/c): ");

  scanf(" %c", difficultyLevel);

  switch (*difficultyLevel) {
    case 'a':
      *alienHealth = 50;
      *playerHealth = 100;
      break;
    case 'b':
      *alienHealth = 75;
      *playerHealth = 75;
      break;
    case 'c':
      *alienHealth = 100;
      *playerHealth = 50;
      break;
    default:
      *alienHealth = 75;
      *playerHealth = 75;
      break;
  }

  printf("\n");
  printf("You have chosen difficulty level %c.\n", *difficultyLevel);
  printf("The alien has %d health.\n", *alienHealth);
  printf("You have %d health.\n", *playerHealth);
  printf("\n");
}

// function for alien to attack player
void alienAttack(int alienHealth, int *playerHealth) {
  int damage = generateRandomNumber(1, 10);
  *playerHealth -= damage;

  printf("The alien attacks you and does %d damage.\n", damage);
  printf("You have %d health left.\n", *playerHealth);

  wait();
}

// function for player to attack alien
void playerAttack(int playerHealth, int *alienHealth) {
  int damage = generateRandomNumber(5, 20);
  *alienHealth -= damage;
  printf("You attack the alien and do %d damage.\n", damage);
  printf("The alien has %d health left.\n", *alienHealth);

  wait();
}

// function to display the ending
void displayEnding(int playerHealth) {
  if (playerHealth <= 0) {
    printf("You have been defeated by the alien ship. Game over.\n");
  } else {
    printf("Congratulations! You have defeated the alien ship.\n");
  }
}