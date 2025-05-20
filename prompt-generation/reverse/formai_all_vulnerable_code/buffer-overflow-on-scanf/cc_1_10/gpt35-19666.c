//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int health = 100;
int inventory[3] = {0, 0, 0};
int current_room = 1;
char direction;

void clear_screen() {
  printf("\033[2J\033[1;1H");
}

void print_room() {
  clear_screen();
  printf("You are in room %d.\n", current_room);

  switch(current_room) {
    case 1:
      printf("There is a door to the north.\n");
      break;

    case 2:
      printf("There is a door to the south and a key on the table.\n");
      break;

    case 3:
      printf("There is a door to the east and a potion on the shelf.\n");
      break;

    case 4:
      printf("There is a door to the west and a monster in the room!\n");
      break;
  }

  printf("Your health is %d and you have:\n", health);
  printf("- %d gold coins\n", inventory[0]);
  printf("- %d keys\n", inventory[1]);
  printf("- %d potions\n", inventory[2]);
}

void game_over() {
  clear_screen();
  printf("Oh no! You died! Game over!\n");
  exit(0);
}

void win_game() {
  clear_screen();
  printf("Congratulations! You have escaped the dungeon and won the game!\n");
  exit(0);
}

void check_health() {
  if (health <= 0) {
    game_over();
  }
}

void check_inventory() {
  int gold_coins = inventory[0];
  int keys = inventory[1];
  int potions = inventory[2];

  if (gold_coins >= 10 && keys >= 2 && potions >= 1) {
    win_game();
  }
}

void handle_input() {
  printf("Which way would you like to go? (n, s, e, w)\n");
  scanf(" %c", &direction);

  switch(direction) {
    case 'n':
      if (current_room == 1) {
        current_room = 2;
      }
      else {
        printf("There is no door in that direction.\n");
      }
      break;

    case 's':
      if (current_room == 2) {
        current_room = 1;
      }
      else {
        printf("There is no door in that direction.\n");
      }
      break;

    case 'e':
      if (current_room == 2) {
        inventory[1] = 1;
        current_room = 3;
      }
      else {
        printf("There is no door in that direction.\n");
      }
      break;

    case 'w':
      if (current_room == 3) {
        inventory[2] = 1;
        current_room = 4;
      }
      else {
        printf("There is no door in that direction.\n");
      }
      break;

    default:
      printf("Invalid direction.\n");
  }
}

void attack_monster() {
  int damage = rand() % 10 + 1;
  int monster_health = rand() % 10 + 1;

  if (damage > monster_health) {
    printf("You defeated the monster!\n");
    inventory[0] = inventory[0] + 5;
  }
  else {
    printf("The monster damaged you!\n");
    health = health - monster_health;
    check_health();
  }
}

void handle_monster() {
  char choice;
  printf("A monster has appeared! (a to attack, r to run)\n");
  scanf(" %c", &choice);

  switch(choice) {
    case 'a':
      attack_monster();
      break;

    case 'r':
      current_room = 3;
      printf("You ran away from the monster.\n");
      break;

    default:
      printf("Invalid choice.\n");
      handle_monster();
  }
}

int main() {
  while (1) {
    print_room();

    if (current_room == 4) {
      handle_monster();
    }
    else {
      handle_input();
    }

    health = health - 5;
    check_health();
    check_inventory();
  }

  return 0;
}