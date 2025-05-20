//FormAI DATASET v1.0 Category: Memory management ; Style: surprised
#include<stdio.h>
#include<stdlib.h>

int main() {
  printf("Welcome to the Memory Management surprise program!\n");
  printf("You're about to experience a whole new level of memory allocation and deallocation!\n");

  printf("Enter the number of elements you want to allocate dynamically in an array:\n");
  int n;
  scanf("%d", &n);

  int* arr = (int*) calloc (n, sizeof(int));
  if(arr == NULL) {
    printf("Oops! Memory allocation failed.");
    exit(0);
  }
  
  printf("Hooray! Memory allocation successful. Let's fill the array with some values.\n");
  
  for(int i=0; i<n; i++) {
    *(arr+i) = i+1;
    printf("Element %d added to array.\n", i+1);
  }
  
  printf("Array successfully filled with values.\n");

  printf("Enter the position of the array element to delete:\n");
  int position;
  scanf("%d", &position);

  if(position > n || position < 1) {
    printf("Invalid position entered. Exiting program.");
    free(arr);
    exit(0);
  }

  int* newArr = (int*) malloc((n-1)*sizeof(int));
  if(newArr == NULL) {
    printf("Oops! Memory allocation failed.");
    free(arr);
    exit(0);
  }

  printf("Hooray! New memory allocation successful. Copying values to new array...\n");
  
  int j = 0;
  for(int i=0; i<n; i++) {
    if(i != position-1) {
      *(newArr+j) = *(arr+i);
      j++;
    }
  }
  
  printf("Values successfully copied to new array.\n");

  printf("Original array: ");
  for(int i=0; i<n; i++) {
    printf("%d ", *(arr+i));
  }

  free(arr);
  printf("\nOriginal array memory deallocated successfully.\n");

  printf("New array: ");
  for(int i=0; i<n-1; i++) {
    printf("%d ", *(newArr+i));
  }

  free(newArr);
  printf("\nNew array memory deallocated successfully.\n");

  printf("Thank you for trying out our Memory Management program. We hope you were surprised!\n");
  
  return 0;
}