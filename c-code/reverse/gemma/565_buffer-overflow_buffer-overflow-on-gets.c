#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char code[1024];
  printf("Enter a C code snippet: ");
  fgets(code, 1024, stdin);

  // Identify data types
  char *type = strstr(code, "int") ? "int" : strstr(code, "double") ? "double" : strstr(code, "float") ? "float" : "Unknown";

  // Identify loop constructs
  char *loop = strstr(code, "for") || strstr(code, "while") ? "Loop present" : "No loop";

  // Report findings
  printf("Data type: %s\n", type);
  printf("Loop construct: %s\n", loop);

  return 0;
}
