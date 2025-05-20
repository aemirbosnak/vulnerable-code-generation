//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void play_game(int current_level);

int main()
{
  play_game(1);

  return 0;
}

void play_game(int current_level)
{
  // Level 1: Simple Text Adventure
  if (current_level == 1)
  {
    printf("You are in a dark room. There is a door to the north and a door to the east.\n");
    printf("Enter 'n' to go north or 'e' to go east: ");
    char input;
    scanf("%c", &input);

    if (input == 'n')
    {
      play_game(2);
    }
    else if (input == 'e')
    {
      printf("You have exited the room.\n");
    }
    else
    {
      printf("Invalid input.\n");
    }
  }

  // Level 2: Interactive Text Adventure
  else if (current_level == 2)
  {
    printf("You are in a castle. There are two guards standing in the hall.\n");
    printf("Enter 'attack' to fight the guards, 'negotiate' to talk to them, or 'flee' to run away: ");
    char input;
    scanf("%c", &input);

    if (input == 'attack')
    {
      printf("You have attacked the guards. They have defeated you.\n");
    }
    else if (input == 'negotiate')
    {
      printf("You have negotiated with the guards. They have let you pass.\n");
      play_game(3);
    }
    else if (input == 'flee')
    {
      printf("You have fled the castle. You have won.\n");
    }
    else
    {
      printf("Invalid input.\n");
    }
  }

  // Level 3: Final Battle
  else if (current_level == 3)
  {
    printf("You have reached the final boss. Prepare for battle!\n");
    // Fight the final boss
  }
}