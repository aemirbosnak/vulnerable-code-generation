//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  printf("Welcome to the Cyberpunk Search Algorithm!\n");
  printf("Enter the number of elements to be searched: ");
  int n;
  scanf("%d", &n);

  int arr[n];
  srand(time(0));

  printf("Enter the range of the elements (min-max): ");
  int min, max;
  scanf("%d %d", &min, &max);

  printf("Enter the element to be searched: ");
  int search;
  scanf("%d", &search);

  printf("Generating random numbers...\n");
  for (int i = 0; i < n; i++)
  {
    arr[i] = (rand() % (max - min + 1)) + min;
  }
  printf("Generated array: { ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("}\n");

  // Cyberpunk Searching Algorithm
  printf("Initiating Cyberpunk Search Algorithm...\n");

  int found = 0, index = -1;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == search)
    {
      found = 1;
      index = i;
      break;
    }

    if (arr[i] > search)
    {
      break;
    }
  }

  if (found)
  {
    printf("Element %d found at index %d\n", search, index);
  }
  else
  {
    printf("Element not found.\n");
  }

  return 0;
}