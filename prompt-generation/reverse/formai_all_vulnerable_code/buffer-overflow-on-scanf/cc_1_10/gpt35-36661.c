//FormAI DATASET v1.0 Category: Memory management ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to the Memory Management Program!\n");
  printf("Please enter the size of the memory block you want to allocate (in bytes): ");
  int size;
  scanf("%d", &size);

  // Allocate memory block
  char* block = (char*) malloc(size);
  if (block == NULL) {
    printf("Error: Failed to allocate memory block.\n");
    return 1;
  }
  printf("Successfully allocated memory block of size %d bytes!\n\n", size);

  // Fill memory block with random letters
  for (int i = 0; i < size; i++) {
    block[i] = 'A' + rand() % 26;
  }
  printf("Filled memory block with random letters.\n\n");

  // Print memory block contents
  printf("Memory block contents:\n");
  for (int i = 0; i < size; i++) {
    printf("%c", block[i]);
  }
  printf("\n\n");

  // Reallocate memory block
  printf("Now, let's reallocate the memory block.\n");
  printf("Please enter the new size of the memory block you want to allocate (in bytes): ");
  int newSize;
  scanf("%d", &newSize);

  char* newBlock = (char*) realloc(block, newSize);
  if (newBlock == NULL) {
    printf("Error: Failed to reallocate memory block.\n");
    free(block);
    return 1;
  }
  block = newBlock;
  printf("Successfully reallocated memory block of size %d bytes!\n\n", newSize);

  // Fill new memory block with random numbers
  for (int i = 0; i < newSize; i++) {
    block[i] = rand() % 10;
  }
  printf("Filled new memory block with random numbers.\n\n");

  // Print new memory block contents
  printf("New memory block contents:\n");
  for (int i = 0; i < newSize; i++) {
    printf("%d", block[i]);
  }
  printf("\n\n");

  // Free memory block
  free(block);
  printf("Successfully freed memory block.\n");

  return 0;
}