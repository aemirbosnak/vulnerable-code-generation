#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char code[1024];
  gets(code);

  // Identify data types
  char data_type[256];
  int data_type_index = 0;
  for (int i = 0; code[i] != '\0'; i++) {
    if (code[i] >= 'a' && code[i] <= 'z') {
      data_type[data_type_index++] = code[i];
    }
  }

  // Identify loop structures
  char loop_structure[256];
  int loop_structure_index = 0;
  for (int i = 0; code[i] != '\0'; i++) {
    if (code[i] == 'for' || code[i] == 'while' || code[i] == 'do') {
      loop_structure[loop_structure_index++] = code[i];
    }
  }

  // Print results
  printf("Data types:\n");
  for (int i = 0; data_type[i] != '\0'; i++) {
    printf("%c ", data_type[i]);
  }

  printf("\nLoop structures:\n");
  for (int i = 0; loop_structure[i] != '\0'; i++) {
    printf("%c ", loop_structure[i]);
  }

  return 0;
}
