//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void haunted_house(int);

int main()
{
  haunted_house(1);
  return 0;
}

void haunted_house(int num)
{
  int i, j, k, l, r, c, d, e, f, g, h, w, b;
  char ch, s, t, n;

  system("CLS");

  printf("--------------------------------------------------------------------\n");
  printf("Welcome to the Haunted House of Gloom. Prepare for a terrifying experience.\n");
  printf("--------------------------------------------------------------------\n");

  for (i = 0; i < num; i++)
  {
    printf("Enter a number between 1 and 10: ");
    scanf("%d", &r);

    switch (r)
    {
      case 1:
        printf("You have chosen the Hallway of Shadows. Prepare for ghostly encounters.\n");
        break;
      case 2:
        printf("You have chosen the Chamber of Screams. Prepare for a haunting melody.\n");
        break;
      case 3:
        printf("You have chosen the Dining Hall of Despair. Prepare for a chilling meal.\n");
        break;
      case 4:
        printf("You have chosen the Bedroom of Doom. Prepare for a terrifying encounter.\n");
        break;
      case 5:
        printf("You have chosen the Library of Secrets. Prepare for ghostly whispers and bookshelves that move.\n");
        break;
      case 6:
        printf("You have chosen the Theatre of Terror. Prepare for a ghostly performance.\n");
        break;
      case 7:
        printf("You have chosen the Crypt of Darkness. Prepare for a chilling encounter with the dead.\n");
        break;
      case 8:
        printf("You have chosen the Garden of Despair. Prepare for a haunting garden with sinister secrets.\n");
        break;
      case 9:
        printf("You have chosen the Staircase of Shadows. Prepare for a terrifying journey up and down.\n");
        break;
      case 10:
        printf("You have chosen the Master's Quarters. Prepare for a final confrontation with the master of the house.\n");
        break;
    }

    printf("Press any key to continue... ");
    scanf("%c", &ch);
  }

  system("CLS");

  printf("Thank you for visiting the Haunted House of Gloom. We hope you enjoyed your terrifying experience.\n");
  printf("--------------------------------------------------------------------\n");
}