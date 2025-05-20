//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

void bucketSort(int arr[], int n) {
   int i,j;
   int buckets[SIZE];

   for(i = 0; i < SIZE; i++) {
      buckets[i] = 0;
   }

   for(i = 0; i < n; i++) {
      ++buckets[arr[i]];
   }

   for(i = 0, j = 0; j < SIZE; j++) {
      while(buckets[j]-- > 0) {
         arr[i++] = j;
      }
   }
}

int main() {
   int arr[SIZE];
   int i, n;

   printf("Enter %d integer elements\n", SIZE);

   for(i = 0; i < SIZE; i++) {
      scanf("%d", &arr[i]);
   }

   printf("\nOriginal array is : ");
   for(i = 0; i < SIZE; i++) {
      printf("%d ", arr[i]);
   }

   printf("\n");

   bucketSort(arr, SIZE);

   printf("\nSorted array is : ");
   
   for(i = 0; i < SIZE; i++) {
      printf("%d ", arr[i]);
   }

   printf("\n");

   return 0;
}