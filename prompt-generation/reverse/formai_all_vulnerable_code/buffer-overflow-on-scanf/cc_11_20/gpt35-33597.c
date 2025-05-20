//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: satisfied
#include <stdio.h>

int main() {
   int n, i, j, k;
   printf("Enter the number of elements in the array: ");
   scanf("%d", &n);

   int arr[n], total = 0, temp, min;
   printf("Enter the elements of the array:\n");
   for (i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
      total += arr[i];
   }

   int subset[n];
   for (i = 0; i < n; i++) {
      subset[i] = 0;
   }

   min = total;
   for (i = 0; i < n; i++) {
      for (j = i; j < n; j++) {
         temp = 0;
         for (k = i; k <= j; k++) {
            temp += arr[k];
         }
         if (total - (2 * temp) < min) {
            min = total - (2 * temp);
            for (k = 0; k < n; k++) {
               if (k >= i && k <= j) {
                  subset[k] = 1;
               } else {
                  subset[k] = 0;
               }
            }
         }
      }
   }

   printf("The minimum absolute difference of subsets is %d.\n", min);
   printf("Subset 1: { ");
   for (i = 0; i < n; i++) {
      if (subset[i] == 1) {
         printf("%d ", arr[i]);
      }
   }
   printf("}\n");
   printf("Subset 2: { ");
   for (i = 0; i < n; i++) {
      if (subset[i] == 0) {
         printf("%d ", arr[i]);
      }
   }
   printf("}\n");

   return 0;
}