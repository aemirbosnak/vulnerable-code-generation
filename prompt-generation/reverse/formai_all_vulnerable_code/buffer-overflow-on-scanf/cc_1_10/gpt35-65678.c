//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function prototypes
void printIntro();
void gameLoop();

int main()
{
  printIntro();
  gameLoop();
  return 0;
}

void printIntro(){
  printf("Welcome to the adventure game!\n");
}

void gameLoop(){
  char input[100];
  while (1) {
    printf("Enter a command: ");
    scanf("%s", input);
    if (strcmp(input, "quit") == 0)
    {
      printf("Thanks for playing!\n");
      break;
    }
    else if (strcmp(input, "look") == 0)
    {
      printf("You are in a dimly lit room with a door to the east.\n");
    }
    else if (strcmp(input, "go") == 0)
    {
      printf("Where would you like to go?\n");
      scanf("%s", input);
      if (strcmp(input, "east") == 0)
      {
        printf("You go east and enter another room.\n");
      }
      else
      {
        printf("You can't go there.\n");
      }
    }
    else
    {
      printf("Invalid command.\n");
    }
  }
}