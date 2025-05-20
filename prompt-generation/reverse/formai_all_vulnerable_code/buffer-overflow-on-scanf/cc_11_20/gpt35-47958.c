//FormAI DATASET v1.0 Category: Memory management ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main() {
  // This is a shape-shifting memory management program
  printf("Welcome to the Shape-Shifting Memory Management program!\n");
  int choice;
  unsigned int size;
  void *memory = NULL;
  do {
    printf("Please enter a menu option:\n");
    printf("1. Allocate Memory\n");
    printf("2. Free Memory\n");
    printf("3. Reallocate Memory\n");
    printf("4. Display Memory Content\n");
    printf("5. Exit the Program\n");

    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter the size of the memory in bytes: ");
        scanf("%u", &size);
        memory = malloc(size);
        if (memory == NULL) {
          printf("Error: Memory allocation failed.\n");
        } else {
          printf("Memory allocation successful.\n");
        }
        break;
      case 2:
        free(memory);
        memory = NULL;
        printf("Memory freed successfully.\n");
        break;
      case 3:
        printf("Enter the new size of the memory in bytes: ");
        scanf("%u", &size);
        void *new_mem = realloc(memory, size);
        if (new_mem == NULL) {
          printf("Error: Memory re-allocation failed.\n");
        } else {
          printf("Memory re-allocation successful.\n");
          memory = new_mem;
        }
        break;
      case 4:
        if (memory != NULL) {
          printf("Memory content:\n");
          printf("[ ");
          for (int i = 0; i < size; i++) {
            printf("%hhu ", ((char *)memory)[i]);
          }
          printf("]\n");
        } else {
          printf("Memory is not allocated yet.\n");
        }
        break;
      case 5:
        printf("Exiting the program. Goodbye!\n");
        if (memory != NULL) {
          free(memory);
        }
        exit(0);
        break;
      default:
        printf("Error: Invalid menu option entered. Please try again.\n");
        break;
    }
    printf("\n");
  } while (choice != 5);

  return 0;
}