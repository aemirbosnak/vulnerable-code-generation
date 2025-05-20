#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char filename[100];
  scanf("%s", filename);

  int width, height;
  sscanf(filename, "%dx%d", &width, &height);

  // Process image data
  // ...

  return 0;
}
