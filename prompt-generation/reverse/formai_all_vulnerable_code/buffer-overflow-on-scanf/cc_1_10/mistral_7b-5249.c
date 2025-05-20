//MISTRAL-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void swap(int *a, int *b) {
 int temp;
 temp = *a;
 *a = *b;
 *b = temp;
}

void bucketSort(int arr[], int n) {
 int i, j, index, min, max, bucketSize;
 int *bucketArr[10];

 for (i = 0; i < 10; i++) {
  bucketArr[i] = (int *)calloc(SIZE, sizeof(int));
 }

 for (i = 0; i < n; i++) {
  index = arr[i] / (SIZE / 10);
  bucketArr[index][arr[i] % (SIZE / 10)]++;
 }

 for (i = 0; i < 10; i++) {
  for (j = 0; j < SIZE; j++) {
   if (bucketArr[i][j] != 0) {
    min = bucketArr[i][j];
    for (index = j; index > 0 && arr[index - 1] > min; index--) {
     swap(&arr[index], &arr[index - 1]);
    }
    for (; index < n && arr[index] > min; index++) {
     swap(&arr[index], &arr[index - 1]);
    }
    for (; index > 0 && bucketArr[i][index - 1] < min; index--) {
      bucketArr[i][index] += bucketArr[i][index - 1];
      swap(&arr[index], &arr[index - 1]);
    }
    bucketArr[i][--index] = min;
   }
  }
 }

 for (i = 0; i < 10; i++) {
  free(bucketArr[i]);
 }
}

int main() {
 int i, arr[SIZE];

 printf("Enter %d integers: ", SIZE);
 for (i = 0; i < SIZE; i++) {
  scanf("%d", &arr[i]);
 }

 printf("Unsorted Array: ");
 for (i = 0; i < SIZE; i++) {
  printf("%d ", arr[i]);
 }
 printf("\n");

 bucketSort(arr, SIZE);

 printf("Sorted Array: ");
 for (i = 0; i < SIZE; i++) {
  printf("%d ", arr[i]);
 }
 printf("\n");

 return 0;
}