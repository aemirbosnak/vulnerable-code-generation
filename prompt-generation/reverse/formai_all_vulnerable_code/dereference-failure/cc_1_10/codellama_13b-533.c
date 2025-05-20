//Code Llama-13B DATASET v1.0 Category: Memory management ; Style: cheerful
// A cheerful C memory management program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store memory information
typedef struct {
  void *ptr;
  size_t size;
} mem_info;

// Function to allocate memory
void *cheerful_malloc(size_t size) {
  void *ptr = malloc(size);
  if (ptr == NULL) {
    fprintf(stderr, "Oops! Out of memory\n");
    exit(1);
  }
  return ptr;
}

// Function to free memory
void cheerful_free(void *ptr) {
  if (ptr == NULL) {
    fprintf(stderr, "Oops! Trying to free a null pointer\n");
    exit(1);
  }
  free(ptr);
}

// Function to allocate memory and store information
mem_info *cheerful_calloc(size_t nmemb, size_t size) {
  void *ptr = cheerful_malloc(nmemb * size);
  mem_info *info = cheerful_malloc(sizeof(mem_info));
  info->ptr = ptr;
  info->size = nmemb * size;
  return info;
}

// Function to free memory and store information
void cheerful_cfree(mem_info *info) {
  if (info == NULL) {
    fprintf(stderr, "Oops! Trying to free a null pointer\n");
    exit(1);
  }
  cheerful_free(info->ptr);
  cheerful_free(info);
}

// Example usage
int main() {
  mem_info *info = cheerful_calloc(10, sizeof(int));
  int *array = info->ptr;
  for (int i = 0; i < 10; i++) {
    array[i] = i * i;
  }
  printf("The squares of the first 10 numbers are: ");
  for (int i = 0; i < 10; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
  cheerful_cfree(info);
  return 0;
}