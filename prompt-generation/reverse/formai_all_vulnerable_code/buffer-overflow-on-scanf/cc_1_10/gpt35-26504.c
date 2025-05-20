//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Dennis Ritchie
#include <stdio.h>

void bucketSort(float arr[], int n) {
   int i, j;
   float temp;
   int cnt[n];

   for(i = 0; i < n; i++) {
      cnt[i] = 0;
   }

   for(i = 0; i < n; i++) {
      cnt[(int)arr[i]]++;
   }

   for(i = 1; i < n; i++) {
      cnt[i] += cnt[i-1];
   }

   float b[n];
   for(i = n-1; i >= 0; i--) {
      b[--cnt[(int)arr[i]]] = arr[i];
   }

   for(i = 0; i < n; i++) {
      arr[i] = b[i];
   }
}

int main() {
   int n, i;
   printf("Enter the number of elements: ");
   scanf("%d",&n);
   float arr[n];

   printf("Enter %d elements:\n", n);
   for(i = 0; i < n; i++) {
      scanf("%f",&arr[i]);
   }

   printf("Input array: ");
   for(i = 0; i < n; i++) {
      printf("%f ", arr[i]);
   }

   bucketSort(arr, n);

   printf("\nSorted array: ");
   for(i = 0; i < n; i++) {
      printf("%f ", arr[i]);
   }
   
   return 0;
}