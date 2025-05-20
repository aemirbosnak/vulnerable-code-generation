//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: imaginative
#include <stdio.h>

void bucketSort(int array[], int size) {
  // Find minimum and maximum values in the array
  int minVal = array[0];
  int maxVal = array[0];
  
  for (int i = 1; i < size; i++) {
    if (array[i] < minVal) {
      minVal = array[i];
    } else if (array[i] > maxVal) {
      maxVal = array[i];
    }
  }

  // Create buckets for each value range
  int bucketCount = (maxVal - minVal) / 5 + 1;
  int buckets[bucketCount][5];

  // Place array elements in their corresponding bucket
  for (int i = 0; i < size; i++) {
    int bucketIndex = (array[i] - minVal) / 5;
    int j = 0;
    while (j < 5 && buckets[bucketIndex][j] != 0) {
      j++;
    }
    buckets[bucketIndex][j] = array[i];
  }

  // Sort elements within each bucket
  for (int i = 0; i < bucketCount; i++) {
    int bucketSize = 5;
    for (int j = 0; j < bucketSize; j++) {
      for (int k = 0; k < bucketSize - j - 1; k++) {
        if (buckets[i][k] > buckets[i][k + 1]) {
          int temp = buckets[i][k];
          buckets[i][k] = buckets[i][k + 1];
          buckets[i][k + 1] = temp;
        }
      }
    }
  }

  // Merge sorted buckets back into original array
  int index = 0;
  for (int i = 0; i < bucketCount; i++) {
    for (int j = 0; j < 5; j++) {
      if (buckets[i][j] != 0) {
        array[index] = buckets[i][j];
        index++;
      }
    }
  }
}

int main() {
  int array[10] = {198, 23, 28, 239, 34, 69, 42, 185, 0, 3};
  int size = sizeof(array) / sizeof(array[0]);
  printf("Array before sorting: \n");
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
  
  bucketSort(array, size);
  
  printf("Array after sorting: \n");
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
  return 0;
}