//FormAI DATASET v1.0 Category: Searching algorithm ; Style: brave
#include <stdio.h>

//function for performing binary search algorithm
int binary_search(int array[], int key, int low, int high)
{
   int mid;

   while (low <= high) {
      mid = (low + high) / 2;

      if (key == array[mid]) {
         return mid + 1;
      }
      else if (key < array[mid]) {
         high = mid - 1;
      }
      else {
         low = mid + 1;
      }
   }

   return -1;
}

int main()
{
   int n, key, i;
   printf("\n\n MY UNIQUE BRAVE-STYLE BINARY SEARCH ALGORITHM EXAMPLE PROGRAM \n\n");
   printf("Enter number of elements in array: ");
   scanf("%d", &n);

   int array[n];
   printf("Enter %d integers:\n", n);

   for (i = 0; i < n; i++) {
      scanf("%d", &array[i]);
   }

   printf("Enter the key value to search: ");
   scanf("%d", &key);

   int index = binary_search(array, key, 0, n - 1);

   if (index == -1) {
      printf("Key not found\n");
   }
   else {
      printf("Key found at position: %d\n", index);
   }

   return 0;
}