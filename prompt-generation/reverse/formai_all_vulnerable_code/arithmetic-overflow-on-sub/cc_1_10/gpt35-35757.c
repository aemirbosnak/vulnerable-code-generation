//FormAI DATASET v1.0 Category: Error handling ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum ErrorCode {
  ERROR_NONE = 0,
  ERROR_INVALID_ARGUMENT,
  ERROR_NULL_POINTER,
  ERROR_OUT_OF_RANGE
};

const char *GetErrorMessage(int code) {
  switch (code) {
    case ERROR_NONE:
      return "No error";
    case ERROR_INVALID_ARGUMENT:
      return "Invalid argument";
    case ERROR_NULL_POINTER:
      return "Null pointer";
    case ERROR_OUT_OF_RANGE:
      return "Out of range";
    default:
      return "Unknown error";
  }
}

void handleError(int code, char *message) {
  fprintf(stderr, "Error (%d): %s\n", code, message);
  exit(code);
}

void validateString(char *str, char *argName) {
  if (str == NULL) {
    char message[100];
    sprintf(message, "%s cannot be null", argName);
    handleError(ERROR_NULL_POINTER, message);
  }
}

void validateIntRange(int val, int min, int max, char *argName) {
  if (val < min || val > max) {
    char message[100];
    sprintf(message, "%s should be between %d and %d", argName, min, max);
    handleError(ERROR_OUT_OF_RANGE, message);
  }
}

int getValue(int argc, char *argv[]) {
  if (argc < 2) {
    handleError(ERROR_INVALID_ARGUMENT, "Usage: program <value>");
  }
  
  char *endPtr;
  int val = strtol(argv[1], &endPtr, 10);
  
  if (endPtr == argv[1] || *endPtr != '\0') {
    handleError(ERROR_INVALID_ARGUMENT, "Value must be a valid integer");
  }
  
  validateIntRange(val, 0, 100, "Value");
  return val;
}

int main(int argc, char *argv[]) {
  int val = getValue(argc, argv);
  printf("Value: %d\n", val);
  return 0;
}