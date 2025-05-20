//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char name[30], choice[15];
  int health = 100, puzzle_solved = 0;
  
  printf("Welcome to the Text-Based Adventure Game!\n");
  printf("What is your name?\n");
  scanf("%s", name);
  printf("Hello %s, let's start our adventure!\n", name);

  while (health > 0 && puzzle_solved < 3) {
    printf("You have %d health.\n", health);
    printf("What would you like to do? (type 'explore' or 'rest'): ");
    scanf("%s", choice);

    if (strcmp(choice, "explore") == 0) {
      printf("You are exploring the dungeon.\n");
      printf("You find a locked door.\n");

      char ans[15];
      printf("To unlock the door, solve the riddle:\n");
      printf("I am an odd number. Take away a letter and I become even. What number am I?\n");
      scanf("%s", ans);

      if (strcmp(ans, "seven") == 0) {
        printf("You have unlocked the door!\n");
        puzzle_solved++;
      } else {
        printf("Incorrect Answer! You lose 20 health.\n");
        health -= 20;
      }

    } else if (strcmp(choice, "rest") == 0) {
      printf("You decide to take a short rest.\n");
      printf("You regain 20 health.\n");
      health += 20;

    } else {
      printf("Invalid command! Please choose 'explore' or 'rest'.\n");
    }
  }

  if (health <= 0) {
    printf("You have died. Game Over!\n");
  } else {
    printf("Congratulations %s, you have solved all the puzzles and escaped the dungeon with %d health remaining!\n", name, health);
  }

  return 0;
}