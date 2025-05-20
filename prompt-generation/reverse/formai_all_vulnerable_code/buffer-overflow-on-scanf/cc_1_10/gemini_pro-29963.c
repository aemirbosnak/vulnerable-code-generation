//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

enum ErrorCode {
  NO_ERROR,
  INVALID_INPUT,
  MEMORY_ALLOCATION_FAILED,
  FILE_OPEN_FAILED,
  FILE_READ_FAILED,
  FILE_WRITE_FAILED,
  OTHER_ERROR
};

typedef struct Error {
  enum ErrorCode code;
  char *message;
} Error;

Error *create_error(enum ErrorCode code, char *message) {
  Error *error = malloc(sizeof(Error));
  if (error == NULL) {
    return NULL;
  }
  error->code = code;
  error->message = malloc(strlen(message) + 1);
  if (error->message == NULL) {
    free(error);
    return NULL;
  }
  strcpy(error->message, message);
  return error;
}

void free_error(Error *error) {
  if (error == NULL) {
    return;
  }
  free(error->message);
  free(error);
}

int main() {
  Error *error = NULL;

  // Example 1: Invalid input
  int input;
  printf("Enter a number: ");
  if (scanf("%d", &input) != 1) {
    error = create_error(INVALID_INPUT, "Invalid input");
    goto error_handling;
  }

  // Example 2: Memory allocation failed
  int *array = malloc(100 * sizeof(int));
  if (array == NULL) {
    error = create_error(MEMORY_ALLOCATION_FAILED, "Memory allocation failed");
    goto error_handling;
  }

  // Example 3: File open failed
  FILE *file = fopen("myfile.txt", "r");
  if (file == NULL) {
    error = create_error(FILE_OPEN_FAILED, "File open failed");
    goto error_handling;
  }

  // Example 4: File read failed
  char buffer[100];
  if (fread(buffer, 1, 100, file) != 100) {
    error = create_error(FILE_READ_FAILED, "File read failed");
    goto error_handling;
  }

  // Example 5: File write failed
  if (fwrite(buffer, 1, 100, file) != 100) {
    error = create_error(FILE_WRITE_FAILED, "File write failed");
    goto error_handling;
  }

  // Close the file
  fclose(file);

  // Free the memory
  free(array);

  // No error occurred
  printf("No error occurred\n");
  return EXIT_SUCCESS;

error_handling:
  // Print the error message
  printf("Error: %s\n", error->message);

  // Free the error
  free_error(error);

  // Exit the program
  return EXIT_FAILURE;
}