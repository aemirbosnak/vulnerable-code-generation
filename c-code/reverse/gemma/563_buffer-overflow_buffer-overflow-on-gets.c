#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
  char source_code[1000];
  gets(source_code);

  // Parse the source code string
  char *token = strtok(source_code, " ");
  while (token) {
    // Identify the data type
    char data_type[20];
    int i = 0;
    for (; token[i] && !isdigit(token[i]); i++) {
      data_type[i] = token[i];
    }
    data_type[i] = '\0';

    // Print the data type
    printf("Data type: %s\n", data_type);

    // Identify the loop
    char loop_type[20];
    i = 0;
    for (; token[i] && !isalnum(token[i]); i++) {
      loop_type[i] = token[i];
    }
    loop_type[i] = '\0';

    // Print the loop type
    printf("Loop type: %s\n", loop_type);

    // Handle remaining characters
    token = strtok(NULL, " ");
  }

  return 0;
}
