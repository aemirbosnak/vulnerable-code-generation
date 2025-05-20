//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: Cryptic
#include <stdlib.h>
#include <time.h>

int main()
{
  int w, h, n, i, j, k, l, r, c, **a, **b;
  w = h = n = 10;
  a = (int *)malloc(w * h * sizeof(int));
  b = (int *)malloc(w * h * sizeof(int));
  srand(time(NULL));

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      a[i][j] = rand() % 2;
    }
  }

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      b[i][j] = 0;
    }
  }

  for (k = 0; k < 10; k++)
  {
    for (l = 0; l < n; l++)
    {
      for (r = 0; r < n; r++)
      {
        c = a[l][r] & b[l][r];
        if (c)
        {
          b[l][r] = 1;
        }
      }
    }
  }

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      if (b[i][j] == 1)
      {
        printf("%d ", b[i][j]);
      }
    }
  }

  free(a);
  free(b);

  return 0;
}