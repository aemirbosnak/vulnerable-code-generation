//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char *name;
  int health;
  int attack;
  int defense;
} Character;

Character player = {"Sir Reginald Poopington", 100, 5, 2};

void fight(Character *enemy) {
  while (player.health > 0 && enemy->health > 0) {
    int player_damage = rand() % player.attack;
    int enemy_damage = rand() % enemy->attack;
    int player_defense = rand() % player.defense;
    int enemy_defense = rand() % enemy->defense;

    printf("You hit %s for %d damage!\n", enemy->name, player_damage - enemy_defense);
    enemy->health -= player_damage - enemy_defense;
    printf("%s hit you for %d damage!\n", enemy->name, enemy_damage - player_defense);
    player.health -= enemy_damage - player_defense;
  }

  if (player.health <= 0) {
    printf("You died! Better luck next time, champ.\n");
  } else {
    printf("You defeated %s! Hooray for you!\n", enemy->name);
  }
}

int main() {
  srand(time(NULL));
  // Define a bunch of silly enemies
  Character enemies[] = {
    {"Fluffy the Bunny", 15, 1, 0},
    {"Grumpy the Troll", 50, 5, 3},
    {"Stinky the Ogre", 100, 10, 5},
    {"Lord Voldemort", 200, 20, 10},
  };
  int num_enemies = sizeof(enemies) / sizeof(enemies[0]);

  // Welcome the player
  printf("Welcome to the Adventure Game, Sir Reginald Poopington!\n");
  printf("You are a brave knight on a quest to defeat the evil Lord Voldemort.\n");
  printf("Along the way, you will encounter many silly enemies. Good luck!\n");

  // Loop through the enemies and fight them
  for (int i = 0; i < num_enemies; i++) {
    printf("You encounter %s!\n", enemies[i].name);
    fight(&enemies[i]);
  }

  // End the game
  printf("Congratulations! You defeated Lord Voldemort and saved the day!\n");
  printf("Now go take a nap, you silly goose.\n");

  return 0;
}