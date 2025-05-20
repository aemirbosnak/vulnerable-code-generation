//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
void intro();
void forest();
void cave();
void castle();
void ending();

int main()
{
  // set seed for random number generator
  srand(time(NULL));

  intro(); // initialize game

  return 0;
}

// function definitions

void intro()
{
  printf("Welcome to the Adventure Game!\n");
  printf("You find yourself in a dark forest...\n");
  printf("What do you want to do?\n");

  int choice = 0;
  printf("\n1. Walk deeper into the forest\n");
  printf("2. Look for a way out\n");
  printf("3. Stay where you are\n");
  scanf("%d", &choice);

  switch(choice)
  {
    case 1:
      forest();
      break;
    case 2:
      printf("You search for a while and find a path leading out of the forest.\n");
      printf("You follow the path and eventually reach a cave.\n");
      cave();
      break;
    case 3:
      printf("You sit down and wait...\n");
      printf("Nothing happens.\n");
      intro(); // restart intro
      break;
    default:
      printf("Invalid input, please try again.\n");
      intro(); // restart intro
      break;
  }
}

void forest()
{
  printf("You walk deeper into the forest...\n");

  // determine if there's an encounter
  int encounter = rand() % 3; // 0, 1, or 2

  if(encounter == 0)
  {
    printf("You encounter a troll!\n");
    printf("What do you want to do?\n");

    int choice = 0;
    printf("\n1. Fight the troll\n");
    printf("2. Run away\n");
    scanf("%d", &choice);

    if(choice == 1)
    {
      printf("You fight the troll and win!\n");
      printf("You continue walking and eventually reach a castle.\n");
      castle();
    }
    else if(choice == 2)
    {
      printf("You run away from the troll and eventually reach a cave.\n");
      cave();
    }
    else
    {
      printf("Invalid input, please try again.\n");
      forest();
    }
  }
  else
  {
    printf("You continue walking and eventually reach a castle.\n");
    castle();
  }
}

void cave()
{
  printf("You enter the cave...\n");

  // determine if there's an encounter
  int encounter = rand() % 3; // 0, 1, or 2

  if(encounter == 0)
  {
    printf("You encounter a dragon!\n");
    printf("What do you want to do?\n");

    int choice = 0;
    printf("\n1. Fight the dragon\n");
    printf("2. Run away\n");
    scanf("%d", &choice);

    if(choice == 1)
    {
      printf("You fight the dragon and win!\n");
      printf("You continue exploring the cave and eventually find a way out.\n");
      printf("You follow the path and eventually reach a castle.\n");
      castle();
    }
    else if(choice == 2)
    {
      printf("You run away from the dragon and eventually reach a forest.\n");
      forest();
    }
    else
    {
      printf("Invalid input, please try again.\n");
      cave();
    }
  }
  else
  {
    printf("You continue exploring the cave and eventually find a way out.\n");
    printf("You follow the path and eventually reach a castle.\n");
    castle();
  }
}

void castle()
{
  printf("You arrive at the castle...\n");

  // determine if there's an encounter
  int encounter = rand() % 3; // 0, 1, or 2

  if(encounter == 0)
  {
    printf("You encounter a knight!\n");
    printf("What do you want to do?\n");

    int choice = 0;
    printf("\n1. Fight the knight\n");
    printf("2. Talk to the knight\n");
    scanf("%d", &choice);

    if(choice == 1)
    {
      printf("You fight the knight and win!\n");
      ending();
    }
    else if(choice == 2)
    {
      printf("You talk to the knight and he agrees to let you pass.\n");
      ending();
    }
    else
    {
      printf("Invalid input, please try again.\n");
      castle();
    }
  }
  else
  {
    printf("You explore the castle and eventually find the way out.\n");
    printf("You follow the path and eventually reach the end of your adventure!\n");
    ending();
  }
}

void ending()
{
  printf("Congratulations, you have successfully completed the Adventure Game!\n");
}