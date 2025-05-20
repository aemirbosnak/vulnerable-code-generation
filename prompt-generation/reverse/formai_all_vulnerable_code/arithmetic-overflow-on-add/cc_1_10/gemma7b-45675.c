//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int n, m, i, j, k, l, t, x, y, z;
  char a[100], b[100], c[100], d[100], e[100], f[100];

  scanf("%d", &n);
  scanf("%d", &m);

  for (i = 0; i < n; i++)
  {
    scanf("%s", a);
  }

  for (i = 0; i < m; i++)
  {
    scanf("%s", b);
  }

  for (i = 0; i < n + m; i++)
  {
    c[i] = '\0';
  }

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < m; j++)
    {
      scanf("%d", &x);
      scanf("%d", &y);
      scanf("%d", &z);

      k = x + y + z;
      l = k % 3;

      c[k] = 'a' + l;
    }
  }

  for (i = 0; i < n + m; i++)
  {
    printf("%c ", c[i]);
  }

  printf("\n");

  return 0;
}