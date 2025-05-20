//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
   int n, i, j, k, max, min, range;
   int *array, *temp;
   double start_time, end_time;

   printf("Enter the number of elements: ");
   scanf("%d", &n);

   array = (int *)malloc(n * sizeof(int));

   printf("Enter the elements: ");
   for(i = 0; i < n; i++) {
      scanf("%d", &array[i]);
   }

   max = array[0];
   min = array[0];
   for(i = 0; i < n; i++) {
      if(array[i] > max) {
         max = array[i];
      }
      if(array[i] < min) {
         min = array[i];
      }
   }

   range = max - min + 1;
   temp = (int *)malloc(range * sizeof(int));
   for(i = 0; i < range; i++) {
      temp[i] = 0;
   }

   for(i = 0; i < n; i++) {
      temp[array[i] - min]++;
   }

   for(i = 1; i < range; i++) {
      temp[i] += temp[i - 1];
   }

   start_time = clock();
   for(i = n - 1; i >= 0; i--) {
      array[temp[array[i] - min] - 1] = array[i];
      temp[array[i] - min]--;
   }
   end_time = clock();

   printf("Sorted array: ");
   for(i = 0; i < n; i++) {
      printf("%d ", array[i]);
   }

   printf("\nTime taken: %f seconds\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

   return 0;
}