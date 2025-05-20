//FormAI DATASET v1.0 Category: Funny ; Style: innovative
#include <stdio.h>

int main() {

  int i, n, sum = 0;
  printf("Enter the number of integers: ");
  scanf("%d", &n);

  // Allocating memory dynamically
  
  int* ptr = (int*) malloc(n * sizeof(int));

  if (ptr == NULL) {
      printf("Memory allocation failed.\n");
      return 0;
  }

  printf("Enter your integers separated by a space: ");

  for (i = 0; i < n; i++){
      scanf("%d", ptr + i);
      sum += *(ptr + i);
  }

  printf("The sum of your integers is: %d\n", sum);

  // Sorting the integers in ascending order

  for (i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (*(ptr + i) > *(ptr + j)) {
        int temp = *(ptr + i);
        *(ptr + i) = *(ptr + j);
        *(ptr + j) = temp;
      }
    }
  }

  printf("Your integers in ascending order: ");
  for (i = 0; i < n; i++){
      printf("%d ", *(ptr + i));
  }

  // Finding the second largest integer

  int second_largest, largest = *ptr;

  for (i = 0; i < n; i++) {
    if (*(ptr + i) > largest) {
      second_largest = largest;
      largest = *(ptr + i);
    } else if (*(ptr + i) > second_largest && *(ptr + i) != largest) {
      second_largest = *(ptr + i);
    }
  }

  printf("\nThe second largest integer is: %d\n", second_largest);

  // Reversing the order of the integers

  printf("Your integers in reverse order: ");
  for (i = n - 1; i >= 0; i--) {
    printf("%d ", *(ptr + i));
  }

  // Freeing the memory

  free(ptr);

  return 0;
}