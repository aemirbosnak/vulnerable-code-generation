//Gemma-7B DATASET v1.0 Category: Audio processing ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

void main()
{
  int n = 0;
  scanf("%d", &n);

  if (n < 0)
  {
    printf("Error: n must be non-negative.\n");
    return;
  }

  int *a = malloc(n * sizeof(int));
  if (a == NULL)
  {
    printf("Error: memory allocation failed.\n");
    return;
  }

  printf("Enter %d integers:\n", n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }

  int m = 0;
  scanf("%d", &m);

  if (m < 0)
  {
    printf("Error: m must be non-negative.\n");
    return;
  }

  int *b = malloc(m * sizeof(int));
  if (b == NULL)
  {
    printf("Error: memory allocation failed.\n");
    return;
  }

  printf("Enter %d integers:\n", m);
  for (int i = 0; i < m; i++)
  {
    scanf("%d", &b[i]);
  }

  int k = 0;
  scanf("%d", &k);

  if (k < 0)
  {
    printf("Error: k must be non-negative.\n");
    return;
  }

  int *c = malloc(k * sizeof(int));
  if (c == NULL)
  {
    printf("Error: memory allocation failed.\n");
    return;
  }

  printf("Enter %d integers:\n", k);
  for (int i = 0; i < k; i++)
  {
    scanf("%d", &c[i]);
  }

  int result = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      for (int l = 0; l < k; l++)
      {
        if (a[i] == b[j] && b[j] == c[l])
        {
          result++;
        }
      }
    }
  }

  printf("Number of triples found: %d\n", result);
  free(a);
  free(b);
  free(c);
}