//FormAI DATASET v1.0 Category: Error handling ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if the input string is a valid integer
int is_integer(char *str) {
  int length = strlen(str);
  for (int i = 0; i < length; i++) {
    if (isdigit(str[i]) == 0) {
      return 0;
    }
  }
  return 1;
}

int main() {
  char input[10];
  printf("Please enter a number: ");
  scanf("%s", input);

  if (!is_integer(input)) {
    printf("Error: Please enter a valid integer.\n");
    exit(1); // Quit program with error code 1
  }

  int num = atoi(input);
  if (num < 0) {
    printf("Error: Please enter a positive integer.\n");
    exit(1); // Quit program with error code 1
  }

  // Allocate memory for an integer array of 'num' size
  int *arr = (int *)malloc(num * sizeof(int));
  if (arr == NULL) {
    printf("Error: Memory allocation failed.\n");
    exit(1); // Quit program with error code 1
  }

  // Populate the array
  for (int i = 0; i < num; i++) {
    printf("Please enter element %d: ", i+1);
    scanf("%d", &arr[i]);
  }

  // Calculate the sum of all array elements
  int sum = 0;
  for (int i = 0; i < num; i++) {
    sum += arr[i];
  }

  printf("The sum is: %d\n", sum);

  // Free allocated memory
  free(arr);

  return 0;
}