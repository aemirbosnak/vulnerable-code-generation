//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of elements in the array
#define MAX_SIZE 100

// Define the structure of an element
typedef struct {
  int value;
  char name[20];
} element;

// Define the comparison function for sorting the elements
int compare(const void *a, const void *b) {
  const element *ea = (const element *)a;
  const element *eb = (const element *)b;

  return strcmp(ea->name, eb->name);
}

// Define the main function
int main() {
  // Create an array of elements
  element elements[MAX_SIZE];

  // Get the number of elements from the user
  int n;
  printf("Enter the number of elements: ");
  scanf("%d", &n);

  // Get the values and names of the elements from the user
  for (int i = 0; i < n; i++) {
    printf("Enter the value of element %d: ", i + 1);
    scanf("%d", &elements[i].value);

    printf("Enter the name of element %d: ", i + 1);
    scanf("%s", elements[i].name);
  }

  // Sort the elements using the comparison function
  qsort(elements, n, sizeof(element), compare);

  // Print the sorted elements
  printf("\nThe sorted elements are:\n");
  for (int i = 0; i < n; i++) {
    printf("%d %s\n", elements[i].value, elements[i].name);
  }

  return 0;
}