#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[1024];
  FILE* file = fopen("text.txt", "r");
  size_t size = 0;

  if (file) {
    while (fgets(buffer, 1024, file) != NULL) {
      size_t len = strlen(buffer);
      buffer[len - 1] = '\0';
      printf("%s\n", buffer);
    }
    fclose(file);
  } else {
    printf("Error opening file.\n");
  }

  return 0;
}
