//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

int main()
{
  int n, m, t, i, j, k, x, y;
  int **a = NULL;

  n = m = 0;
  t = time(NULL);
  srand(t);

  printf("Enter the number of iterations: ");
  scanf("%d", &t);

  a = malloc(n * m * sizeof(int));
  if (a == NULL)
  {
    printf("Memory allocation error.\n");
    exit(1);
  }

  for (k = 0; k < t; k++)
  {
    printf("Iteration %d:\n", k);

    for (i = 0; i < MAX; i++)
    {
      for (j = 0; j < MAX; j++)
      {
        x = rand() % MAX;
        y = rand() % MAX;

        if (a[x][y] == 0)
        {
          a[x][y] = 1;
          printf("Percolation at (%d, %d)\n", x, y);
        }
      }
    }

    printf("\n");
  }

  free(a);
  return 0;
}