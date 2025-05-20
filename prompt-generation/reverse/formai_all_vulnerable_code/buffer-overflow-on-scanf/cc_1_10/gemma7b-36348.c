//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

void main()
{
  char key;
  int room = 1;
  int inventory[] = {0, 0, 0, 0, 0};

  while (1)
  {
    system("clear");
    switch (room)
    {
      case 1:
        printf("You are in a dark and dusty warehouse.\n");
        printf("There is a boarded-up door to the east and a mysterious object on the floor.\n");
        break;
      case 2:
        printf("You have entered a secret room. The walls are covered in strange symbols.\n");
        printf("There is a door to the north and a hidden compartment in the wall.\n");
        break;
      case 3:
        printf("You have found the hidden compartment. It contains a key and a map.\n");
        break;
    }

    printf("What do you want to do? (h/w/s/i/q): ");
    scanf(" %c", &key);

    switch (key)
    {
      case 'h':
        system("clear");
        printf("You have chosen to look around.\n");
        break;
      case 'w':
        room = 2;
        break;
      case 's':
        system("clear");
        printf("You have chosen to smash the boarded-up door.\n");
        room = 2;
        break;
      case 'i':
        system("clear");
        printf("You have chosen to inspect the mysterious object. It is a key.\n");
        inventory[0] = 1;
        break;
      case 'q':
        exit(0);
    }
  }
}