#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char code[1024];
  gets(code);

  // Parse the code and identify data types and loops
  int i = 0;
  char *ptr = code;
  while (*ptr) {
    // Data type identification
    char data_type[32] = "";
    if (*ptr >= 'a' && *ptr <= 'z') {
      switch (*ptr) {
        case 'i':
          strcpy(data_type, "int");
          break;
        case 'f':
          strcpy(data_type, "float");
          break;
        case 'd':
          strcpy(data_type, "double");
          break;
        case 'c':
          strcpy(data_type, "char");
          break;
        default:
          break;
      }
    }

    // Loop identification
    char loop_type[32] = "";
    if (ptr[0] == 'for' || ptr[0] == 'while') {
      strcpy(loop_type, "Loop");
    }

    // Print the data type and loop type
    if (data_type[0] && loop_type[0]) {
      printf("Data type: %s, Loop type: %s\n", data_type, loop_type);
    }

    // Increment pointers and continue parsing
    ptr++;
    i++;
  }

  return 0;
}
