//Gemma-7B DATASET v1.0 Category: Data recovery tool ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void crack_the_code(char **arr, int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i != j)
      {
        char tmp = arr[i][j];
        arr[i][j] = arr[j][i];
        arr[j][i] = tmp;
      }
    }
  }
  return;
}

int main()
{
  char **arr = NULL;
  int n = 0;

  printf("Enter the number of rows: ");
  scanf("%d", &n);

  arr = (char **)malloc(n * sizeof(char *));
  for (int i = 0; i < n; i++)
  {
    arr[i] = (char *)malloc(n * sizeof(char));
  }

  printf("Enter the data: ");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      scanf("%c", &arr[i][j]);
    }
  }

  crack_the_code(arr, n);

  printf("The recovered data is: ");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%c ", arr[i][j]);
    }
    printf("\n");
  }

  free(arr);

  return 0;
}