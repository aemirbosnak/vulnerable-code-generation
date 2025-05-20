//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// The mind-bending function
void mindbender(char *str, int *arr, int n) {
  // Reverse the string
  for (int i = 0; i < n / 2; i++) {
    char temp = str[i];
    str[i] = str[n - i - 1];
    str[n - i - 1] = temp;
  }

  // Shuffle the array
  for (int i = 0; i < n; i++) {
    int j = rand() % n;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }

  // Print the results
  printf("%s\n", str);
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  // Get the input string and array
  char str[MAX_SIZE];
  int arr[MAX_SIZE];
  int n;
  printf("Enter the string: ");
  scanf("%s", str);
  printf("Enter the size of the array: ");
  scanf("%d", &n);
  printf("Enter the elements of the array: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  // Call the mind-bending function
  mindbender(str, arr, n);

  return 0;
}