//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: artistic
#include <stdio.h>

int main() {

  // input the number of elements
  int n;
  printf("Enter the number of elements: ");
  scanf("%d", &n);

  // input the elements
  int elements[n];
  printf("Enter the elements: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &elements[i]);
  }

  // sort the elements in ascending order
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (elements[i] > elements[j]) {
        int temp = elements[i];
        elements[i] = elements[j];
        elements[j] = temp;
      }
    }
  }

  // initialize variables
  int sum = 0;
  int count = 0;
  int i = 0;

  // keep selecting elements until the sum is greater than or equal to 50
  while (sum < 50 && i < n) {
    if (sum + elements[i] <= 50) {
      sum += elements[i];
      count++;
    }
    i++;
  }

  // output the selected elements and their sum
  printf("Selected elements: ");
  for (int j = 0; j < count; j++) {
    printf("%d ", elements[j]);
  }
  printf("\nTotal sum: %d\n", sum);

  return 0;
}