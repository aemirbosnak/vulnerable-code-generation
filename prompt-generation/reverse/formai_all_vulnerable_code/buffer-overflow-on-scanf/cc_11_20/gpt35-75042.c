//FormAI DATASET v1.0 Category: Memory management ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to the Memory Management Simulation\n\n");
  int size, choice, num;
  int* array = NULL;

  while (1) {
    printf("Enter the size of array you want to create: ");
    scanf("%d", &size);

    array = (int*) malloc(size * sizeof(int));  // Allocating memory "malloc"

    if (array == NULL) {
      printf("Memory allocation failed. Try again.\n");
      continue;
    }

    printf("Memory allocation successful!\n\n");

    while (1) {
      printf("Enter 1 to read from array\n");
      printf("Enter 2 to write to array\n");
      printf("Enter 3 to reallocate memory\n");
      printf("Enter 4 to free memory and exit program\n");

      scanf("%d", &choice);

      switch(choice) {
        case 1:
          printf("Enter the index you want to read from: ");
          scanf("%d", &num);
          if (num >= size || num < 0) {
            printf("Index is out of range. Try again.\n");
          } else {
            printf("The value at index %d is: %d\n", num, array[num]);
          }
          break;

        case 2:
          printf("Enter the index you want to write to: ");
          scanf("%d", &num);
          if (num >= size || num < 0) {
            printf("Index is out of range. Try again.\n");
          } else {
            printf("Enter the value you want to write to index %d: ", num);
            scanf("%d", &array[num]);
          }
          break;

        case 3:
          printf("Enter the new size of the array: ");
          scanf("%d", &size);

          array = (int*) realloc(array, size * sizeof(int));  // Reallocating memory "realloc"

          if (array == NULL) {
            printf("Memory reallocation failed. Try again.\n");
            continue;
          }

          printf("Memory reallocation successful!\n\n");

          break;

        case 4:
          free(array);  // Freeing memory "free"
          printf("Memory freed and program exiting. Goodbye!\n");
          exit(0);  // Exiting program
          break;

        default:
          printf("Invalid choice. Try again.\n");
      }
    }
  }

  return 0;
}