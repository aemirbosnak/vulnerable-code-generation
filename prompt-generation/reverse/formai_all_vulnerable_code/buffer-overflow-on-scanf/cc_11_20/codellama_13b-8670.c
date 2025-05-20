//Code Llama-13B DATASET v1.0 Category: Text-Based Adventure Game ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
  char choice;
  char direction;

  printf("Welcome to the C Text-Based Adventure Game!\n");
  printf("You are a brave adventurer on a quest to find the legendary Sword of Light.\n");
  printf("You are standing in a dark forest, surrounded by tall trees that block out most of the sunlight.\n");
  printf("You can see a path to the east and a path to the west.\n");

  while (1) {
    printf("What would you like to do?\n");
    printf("(E)ast, (W)est, or (Q)uit? ");
    scanf("%c", &choice);

    if (choice == 'E' || choice == 'e') {
      printf("You head east, and the forest becomes even darker and more foreboding.\n");
      printf("You stumble upon a clearing, and in the center is a large stone statue of a dragon.\n");
      printf("The dragon is guarding a chest, and it's not happy to see you.\n");
      printf("Do you (1) fight the dragon or (2) try to sneak past it? ");
      scanf("%c", &direction);

      if (direction == '1' || direction == 'f') {
        printf("You draw your sword and prepare to fight the dragon.\n");
        printf("The dragon breathes fire, and you dodge and weave to avoid the flames.\n");
        printf("You manage to land a few blows, but the dragon is too powerful and defeats you.\n");
        printf("You have died in the forest. Better luck next time.\n");
        return 0;
      } else if (direction == '2' || direction == 's') {
        printf("You try to sneak past the dragon, but it notices you and attacks.\n");
        printf("You manage to dodge its claws and make it into the clearing.\n");
        printf("You open the chest and find the Sword of Light.\n");
        printf("You have found the Sword of Light. You have won the game.\n");
        return 0;
      } else {
        printf("Invalid choice. Try again.\n");
      }
    } else if (choice == 'W' || choice == 'w') {
      printf("You head west, and the forest becomes more open and sunlit.\n");
      printf("You come across a group of friendly elves who offer to guide you to the Sword of Light.\n");
      printf("Do you (1) follow the elves or (2) explore the forest on your own? ");
      scanf("%c", &direction);

      if (direction == '1' || direction == 'f') {
        printf("You follow the elves, and they lead you to a hidden cave deep in the forest.\n");
        printf("You enter the cave and find the Sword of Light. You have found the Sword of Light. You have won the game.\n");
        return 0;
      } else if (direction == '2' || direction == 's') {
        printf("You decide to explore the forest on your own, and you come across a group of hostile goblins.\n");
        printf("They attack you and you must defend yourself. You defeat the goblins and continue your journey.\n");
        printf("You come across a hidden cave, and you enter it to find the Sword of Light.\n");
        printf("You find the Sword of Light. You have found the Sword of Light. You have won the game.\n");
        return 0;
      } else {
        printf("Invalid choice. Try again.\n");
      }
    } else if (choice == 'Q' || choice == 'q') {
      printf("You have decided to quit the game. Better luck next time.\n");
      return 0;
    } else {
      printf("Invalid choice. Try again.\n");
    }
  }

  return 0;
}