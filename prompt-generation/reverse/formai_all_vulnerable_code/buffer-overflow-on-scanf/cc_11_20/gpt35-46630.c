//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  srand(time(0)); //initialize random number generator with current time

  int health = 100;
  int gold = 0;
  int map[3][3] = {{0,0,0}, {0,0,0}, {0,0,0}}; //initialize map with empty cells
  int x = 1, y = 1; //start at center of map

  printf("Welcome to Adventure Game!\n");
  printf("You have %d health and %d gold.\n", health, gold);

  //main game loop
  while (health > 0)
  {
    printf("You are at (%d, %d).\n", x, y);
    printf("Where do you want to go? (N/S/E/W): ");

    char direction;
    scanf(" %c", &direction); //get user input for direction

    //move in selected direction
    switch (direction)
    {
      case 'N':
        if (x > 0) x--;
        break;
      case 'S':
        if (x < 2) x++;
        break;
      case 'E':
        if (y < 2) y++;
        break;
      case 'W':
        if (y > 0) y--;
        break;
      default:
        printf("Invalid direction.\n");
    }

    int event = map[x][y];

    //determine outcome of event at current location
    switch (event)
    {
      case 0:
        printf("You found nothing.\n");
        break;
      case 1:
        printf("You found a treasure chest!\n");
        int found_gold = rand() % 100 + 1; //generate random gold between 1 and 100
        printf("You found %d gold.\n", found_gold);
        gold += found_gold; //add found gold to total gold
        map[x][y] = 0; //remove treasure from map
        break;
      case 2:
        printf("You encountered a monster!\n");
        int damage = rand() % 20 + 1; //generate random damage between 1 and 20
        health -= damage; //subtract damage from total health
        printf("You took %d damage.\n", damage);
        break;
      default:
        printf("Invalid event.\n");
    }

    printf("You have %d health and %d gold.\n", health, gold);

    //check if player has won or lost
    if (health <= 0)
    {
      printf("You have died. Game over!");
      return 0;
    }

    if (map[0][2] == 1 && map[1][2] == 1 && map[2][2] == 1)
    {
      printf("You have collected all the treasure! You win!");
      return 0;
    }
  }

  return 0;
}