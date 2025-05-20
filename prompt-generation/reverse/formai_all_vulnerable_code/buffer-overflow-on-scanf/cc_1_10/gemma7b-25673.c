//Gemma-7B DATASET v1.0 Category: Sorting ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main()
{
  int n, i, j, k, l, m, a[100], b[100], c[100], d[100], e[100];

  printf("Enter the number of elements: ");
  scanf("%d", &n);

  printf("Enter the elements: ");
  for (i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }

  for (i = 0; i < n; i++)
  {
    b[i] = a[i] * 2;
  }

  for (i = 0; i < n; i++)
  {
    c[i] = a[i] + 10;
  }

  for (i = 0; i < n; i++)
  {
    d[i] = a[i] / 2;
  }

  for (i = 0; i < n; i++)
  {
    e[i] = a[i] % 2;
  }

  printf("The original array is: ");
  for (i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }

  printf("\nThe doubled array is: ");
  for (i = 0; i < n; i++)
  {
    printf("%d ", b[i]);
  }

  printf("\nThe array with added 10 is: ");
  for (i = 0; i < n; i++)
  {
    printf("%d ", c[i]);
  }

  printf("\nThe array divided by 2 is: ");
  for (i = 0; i < n; i++)
  {
    printf("%d ", d[i]);
  }

  printf("\nThe array modulus 2 is: ");
  for (i = 0; i < n; i++)
  {
    printf("%d ", e[i]);
  }

  return 0;
}