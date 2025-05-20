//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int r, c, i, j, k, l;
  char **a = NULL;
  char **b = NULL;

  printf("Enter the number of rows: ");
  scanf("%d", &r);

  printf("Enter the number of columns: ");
  scanf("%d", &c);

  a = (char **)malloc(r * sizeof(char *));
  for (i = 0; i < r; i++)
    a[i] = (char *)malloc(c * sizeof(char));

  b = (char **)malloc(r * sizeof(char *));
  for (i = 0; i < r; i++)
    b[i] = (char *)malloc(c * sizeof(char));

  printf("Enter the image data (separated by spaces): ");
  for (i = 0; i < r; i++)
    for (j = 0; j < c; j++)
      scanf("%c", &a[i][j]);

  for (i = 0; i < r; i++)
    for (j = 0; j < c; j++)
    {
      k = a[i][j] - 32;
      l = k / 4;
      b[i][j] = (k % 4) * 3 + l + 96;
    }

  printf("The ASCII art is:\n");
  for (i = 0; i < r; i++)
    for (j = 0; j < c; j++)
      printf("%c ", b[i][j]);

  for (i = 0; i < r; i++)
    free(a[i]);
  free(a);
  for (i = 0; i < r; i++)
    free(b[i]);
  free(b);

  return 0;
}