//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {
  int n, i, j, k, l, m, data[MAX], sum = 0, avg = 0;
  float prob[MAX], min, max, range, variance;

  printf("Enter the number of elements: ");
  scanf("%d", &n);

  printf("Enter the elements: ");
  for (i = 0; i < n; i++) {
    scanf("%d", &data[i]);
  }

  for (i = 0; i < n; i++) {
    sum += data[i];
  }

  avg = sum / n;

  min = data[0];
  max = data[0];

  for (i = 0; i < n; i++) {
    if (min > data[i]) {
      min = data[i];
    }
    if (max < data[i]) {
      max = data[i];
    }
  }

  range = max - min;

  variance = 0;

  for (i = 0; i < n; i++) {
    variance += (data[i] - avg) * (data[i] - avg);
  }

  variance = variance / n;

  printf("The average is: %d\n", avg);
  printf("The minimum is: %d\n", min);
  printf("The maximum is: %d\n", max);
  printf("The range is: %d\n", range);
  printf("The variance is: %.2f\n", variance);

  return 0;
}