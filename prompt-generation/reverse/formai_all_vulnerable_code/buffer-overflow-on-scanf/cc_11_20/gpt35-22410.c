//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {

  srand(time(NULL));
  char name[20];
  int choice;
  int scare_level = 0;
  int room = 0;

  printf("Welcome to the Haunted House Simulator!\n");
  printf("What is your name? ");
  scanf("%s", name);
  printf("Hello, %s! You have entered a haunted house, and your goal is to find your way out.\n", name);
  printf("As you walk through the house, you will encounter different rooms and objects that will increase your scare level.\n");
  printf("Be careful, because if your scare level reaches 100, you will be trapped in the house forever!\n");

  while (scare_level < 100 && room != 4) {
    printf("\nYou are now in room %d.\n", room + 1);

    switch(room) {
      case 0:
        printf("You see a creepy doll on a shelf. What would you like to do?\n");
        printf("1. Ignore it\n2. Pick it up\n");
        scanf("%d", &choice);
        if (choice == 2) {
          scare_level += 20;
          printf("Oh no! The doll was cursed and increased your scare level by 20.\n");
        }
        break;

      case 1:
        printf("You hear a strange noise coming from the basement. What would you like to do?\n");
        printf("1. Ignore it\n2. Investigate\n");
        scanf("%d", &choice);
        if (choice == 2) {
          scare_level += 30;
          printf("You descend down the stairs and see a ghostly figure. You scream and your scare level increases by 30.\n");
        }
        break;

      case 2:
        printf("You come across a hallway with flickering lights. What would you like to do?\n");
        printf("1. Turn back\n2. Continue\n");
        scanf("%d", &choice);
        if (choice == 2) {
          scare_level += 10;
          printf("You bravely walk through the hallway, but the flickering lights increase your scare level by 10.\n");
        } else {
          room--;
        }
        break;

      case 3:
        printf("You enter a room with a painting that seems to be watching you. What would you like to do?\n");
        printf("1. Stare back at the painting\n2. Look away\n");
        scanf("%d", &choice);
        if (choice == 1) {
          scare_level += 50;
          printf("You stare at the painting, but it begins to move and your scare level shoots up by 50.\n");
        }
        break;
    }

    room++;
  }

  if (scare_level >= 100) {
    printf("\nOh no! Your scare level reached 100 and you are now trapped in the haunted house forever!\n");
  } else {
    printf("\nCongratulations, %s! You made it out of the haunted house with a scare level of %d.\n", name, scare_level);
  }

  return 0;
}