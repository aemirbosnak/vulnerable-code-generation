//Falcon2-11B DATASET v1.0 Category: Terminal Based Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

int main() {
  int i;
  char c;
  printf("Welcome to the terminal based game!\n");
  
  for (i = 0; i < 100; i++) {
    printf("You are in a dark room. You can go north, south, east, or west.\n");
    printf("Where would you like to go? ");
    scanf("%c", &c);
    switch (c) {
      case 'n':
        printf("You go north and find a treasure chest.\n");
        printf("Would you like to open the chest? (y/n) ");
        scanf("%s", &c);
        if (c == 'y') {
          printf("Inside the chest, you find a key!\n");
        } else {
          printf("You leave the chest closed.\n");
        }
        break;
      case's':
        printf("You go south and find a trapdoor.\n");
        printf("Would you like to open the trapdoor? (y/n) ");
        scanf("%s", &c);
        if (c == 'y') {
          printf("You open the trapdoor and fall into a pit.\n");
        } else {
          printf("You leave the trapdoor closed.\n");
        }
        break;
      case 'e':
        printf("You go east and find a locked door.\n");
        printf("Would you like to try to unlock the door? (y/n) ");
        scanf("%s", &c);
        if (c == 'y') {
          printf("You successfully unlock the door!\n");
        } else {
          printf("You leave the door locked.\n");
        }
        break;
      case 'w':
        printf("You go west and find a dead end.\n");
        printf("Would you like to go back? (y/n) ");
        scanf("%s", &c);
        if (c == 'y') {
          printf("You turn around and go back to the dark room.\n");
        } else {
          printf("You stay at the dead end.\n");
        }
        break;
      default:
        printf("Invalid input.\n");
        break;
    }
  }
  
  return 0;
}