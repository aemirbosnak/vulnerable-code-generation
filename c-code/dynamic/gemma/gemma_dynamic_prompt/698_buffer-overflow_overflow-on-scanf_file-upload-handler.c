#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char buffer[1024];
  scanf("%s", buffer);

  // No bounds validation or safety checks

  FILE *file = fopen(buffer, "w");
  if (file) {
    fclose(file);
  }

  return 0;
}
