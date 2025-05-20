//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: satisfied
#include <stdio.h>

int main()
{
  printf("Welcome to Procedural Space Adventure!\n");

  char name[20];
  printf("What's your name, adventurer? ");
  scanf("%s", name);
  printf("\n");

  printf("Ah, %s! What a fine name for a space adventurer.\n\n", name);

  printf("As you set out on your journey through the galaxy, you come across a mysterious planet.\n");
  printf("You descend through the atmosphere and land on the surface, ready to explore...\n\n");

  printf("As you explore the planet, you encounter a hostile alien race!\n");
  printf("Quickly, you pull out your trusty laser pistol and engage in a fierce battle...\n\n");

  int alien_health = 50;
  int your_health = 100;
  int round = 1;

  while(alien_health > 0 && your_health > 0)
  {
    printf("Round %d:\n", round);
    printf("\t%s's health: %d\n", name, your_health);
    printf("\tAlien health: %d\n\n", alien_health);

    printf("\t%s, what do you do? [1] Shoot [2] Dodge [3] Rest\n", name);
    int choice;
    scanf("%d", &choice);

    switch(choice)
    {
      case 1:
        printf("\tYou shoot the alien with your laser pistol! -10 health\n");
        printf("\tThe alien attacks you! -5 health\n");
        your_health -= 5;
        alien_health -= 10;
        break;
      case 2:
        printf("\tYou try to dodge the alien's attack!\n");
        printf("\tThe alien attacks you! -10 health\n");
        your_health -= 10;
        break;
      case 3:
        printf("\tYou take a moment to rest and catch your breath. +5 health\n");
        printf("\tThe alien attacks you! -5 health\n");
        your_health += 5;
        your_health -= 5;
        break;
      default:
        printf("\tThat's not a valid choice!\n");
        printf("\tThe alien attacks you! -5 health\n");
        your_health -= 5;
    }

    round++;
  }

  if(alien_health <= 0)
  {
    printf("\nYou defeated the alien! Congratulations!\n");
  }
  else
  {
    printf("\nYou were defeated by the alien. Game over.\n");
  }

  return 0;
}