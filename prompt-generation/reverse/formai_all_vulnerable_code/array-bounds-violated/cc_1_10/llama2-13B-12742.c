//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to print an error message
void error(const char* message) {
  printf("😱 OOPS! %s\n", message);
}

// Function to print a warning message
void warning(const char* message) {
  printf("🤔 WARNING: %s\n", message);
}

// Function to print an informational message
void info(const char* message) {
  printf("📝 INFO: %s\n", message);
}

int main() {
  // Try to divide by zero
  int result = 10 / 0;

  // Handle the error
  if (result == -1) {
    error("Division by zero detected!");
  } else {
    warning("But it still worked?! 😳");
  }

  // Try to access an invalid array index
  int arr[5] = {1, 2, 3, 4, 5};
  int invalid_index = arr[6];

  // Handle the error
  if (invalid_index == -1) {
    error("Invalid array index detected!");
  } else {
    warning("But it still returned a value?! 😱");
  }

  // Try to use a null pointer
  int* null_ptr = NULL;

  // Handle the error
  if (null_ptr == NULL) {
    error("Null pointer detected!");
  } else {
    warning("But it still worked?! 😳");
  }

  // Try to allocate insufficient memory
  int* big_array = malloc(100 * sizeof(int));

  // Handle the error
  if (big_array == NULL) {
    error("Insufficient memory detected!");
  } else {
    warning("But it still allocated memory?! 😳");
  }

  // Free the memory
  free(big_array);

  return 0;
}