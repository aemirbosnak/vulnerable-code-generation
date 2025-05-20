//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: genious
#include <stdio.h>

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int n, k;
  printf("Enter size of array: ");
  scanf("%d", &n);

  int arr[n];
  printf("Enter elements of array: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  printf("Enter value of k: ");
  scanf("%d", &k);

  int sumArr[n - k + 1];
  int sum = 0;
  for (int i = 0; i < k; i++) {
    sum += arr[i];
  }
  sumArr[0] = sum;

  for (int i = k; i < n; i++) {
    sum += arr[i];
    sum -= arr[i - k];
    sumArr[i - k + 1] = sum;
  }

  printf("Sums of %d consecutive elements: ", k);
  printArray(sumArr, n - k + 1);

  int maxSumIndex = 0;
  for (int i = 1; i < n - k + 1; i++) {
    if (sumArr[i] > sumArr[maxSumIndex]) {
      maxSumIndex = i;
    }
  }

  printf("Maximum sum of %d consecutive elements is %d\n", k, sumArr[maxSumIndex]);

  return 0;
}