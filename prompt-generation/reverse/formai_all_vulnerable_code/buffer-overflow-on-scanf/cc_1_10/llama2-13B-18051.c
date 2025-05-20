//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define MAX_DEPTH 5

// Function to search for a string in a recursive manner
int search_recursive(char *str, char *arr[], int start, int end) {
  if (start > end) {
    return 0; // Base case: End of the array reached
  }

  // Middle element of the current subarray
  int mid = (start + end) / 2;

  // Check if the middle element matches the search string
  if (strcmp(str, arr[mid]) == 0) {
    // Found the search string, return the index of the middle element
    return mid;
  }

  // Recursively search the left and right subarrays
  int left = search_recursive(str, arr, start, mid - 1);
  int right = search_recursive(str, arr, mid + 1, end);

  // If either the left or right subarray contains the search string, return its index
  if (left != 0 || right != 0) {
    return left < right ? left : right;
  }

  // If neither the left nor right subarray contains the search string, continue searching
  return search_recursive(str, arr, start, end);
}

int main() {
  char arr[MAX_LENGTH][MAX_LENGTH];
  int i, j, n, found = 0;

  // Read the input array from the user
  printf("Enter an array of strings, separated by a newline:\n");
  for (i = 0; i < MAX_LENGTH; i++) {
    scanf("%s", arr[i]);
  }

  // Search for the search string
  char str[MAX_LENGTH];
  printf("Enter the search string:\n");
  scanf("%s", str);
  int index = search_recursive(str, arr, 0, MAX_LENGTH - 1);

  // Print the result
  if (index != 0) {
    printf("The search string %s is found at index %d\n", str, index);
  } else {
    printf("The search string %s is not found\n", str);
  }

  return 0;
}