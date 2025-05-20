//Code Llama-13B DATASET v1.0 Category: Searching algorithm ; Style: automated
/*
 * A unique C Searching algorithm example program in an automated style
 *
 * Author: [Your Name]
 * Date:   [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the search key and its corresponding value
typedef struct {
  char key[50];
  char value[50];
} KeyValue;

// Function to sort the KeyValue array based on the key
void sortKeyValue(KeyValue arr[], int n) {
  // Implement bubble sort algorithm
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (strcmp(arr[j].key, arr[j + 1].key) > 0) {
        KeyValue temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

// Function to search for a given key in the KeyValue array
int searchKeyValue(KeyValue arr[], int n, char *key) {
  // Implement a linear search algorithm
  for (int i = 0; i < n; i++) {
    if (strcmp(arr[i].key, key) == 0) {
      return i;
    }
  }
  return -1;
}

int main() {
  // Initialize the KeyValue array
  KeyValue arr[50];
  int n = 50;
  for (int i = 0; i < n; i++) {
    scanf("%s %s", arr[i].key, arr[i].value);
  }

  // Sort the KeyValue array based on the key
  sortKeyValue(arr, n);

  // Search for a given key in the KeyValue array
  char key[50];
  scanf("%s", key);
  int index = searchKeyValue(arr, n, key);
  if (index == -1) {
    printf("Key not found\n");
  } else {
    printf("Value: %s\n", arr[index].value);
  }

  return 0;
}