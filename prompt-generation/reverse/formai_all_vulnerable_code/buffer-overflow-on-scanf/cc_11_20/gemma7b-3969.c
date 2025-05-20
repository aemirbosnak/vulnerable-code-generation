//Gemma-7B DATASET v1.0 Category: Math exercise ; Style: visionary
#include <stdio.h>

int main()
{
  int n, m, i, j, k, l, a[100], b[100], c[100], d[100], e[100], f[100], g[100], h[100], i1, i2, i3, i4, i5, i6, i7, i8, i9, i10;
  scanf("%d %d", &n, &m);

  for (i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }

  for (i = 0; i < m; i++)
  {
    scanf("%d", &b[i]);
  }

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < m; j++)
    {
      c[i] = a[i] + b[j];
    }
  }

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < m; j++)
    {
      d[i] = c[i] - b[j];
    }
  }

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < m; j++)
    {
      e[i] = d[i] * b[j];
    }
  }

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < m; j++)
    {
      f[i] = e[i] / b[j];
    }
  }

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < m; j++)
    {
      g[i] = f[i] % b[j];
    }
  }

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < m; j++)
    {
      h[i] = g[i] + 1;
    }
  }

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < m; j++)
    {
      printf("%d ", h[i]);
    }
  }

  printf("\n");

  return 0;
}