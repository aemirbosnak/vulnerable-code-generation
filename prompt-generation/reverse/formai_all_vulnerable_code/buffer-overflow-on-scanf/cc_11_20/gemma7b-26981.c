//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int x = 0, y = 0, z = 0, i = 0, j = 0, k = 0, l = 0, m = 0, n = 0;
  char c;

  printf("Enter 'a' to begin, any other key to quit:\n");
  scanf("%c", &c);

  if (c == 'a')
  {
    printf("Beginning...\n");

    for (i = 0; i < 5; i++)
    {
      for (j = 0; j < 5; j++)
      {
        printf("Cell (%d, %d) is empty.\n", i, j);
      }
    }

    printf("Please choose a cell (e.g. 2,3):\n");
    scanf("%d %d", &x, &y);

    if (x >= 0 && x < 5 && y >= 0 && y < 5)
    {
      printf("You have chosen cell (%d, %d).", x, y);

      for (k = 0; k < 5; k++)
      {
        for (l = 0; l < 5; l++)
        {
          if (k == x && l == y)
          {
            printf("Cell (%d, %d) is your choice.\n", k, l);
          }
          else
          {
            printf("Cell (%d, %d) is empty.\n", k, l);
          }
        }
      }
    }
    else
    {
      printf("Invalid input. Please try again.\n");
    }
  }

  return 0;
}