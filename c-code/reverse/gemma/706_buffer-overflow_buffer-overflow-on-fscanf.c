#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char filename[1024];
  scanf("%s", filename);

  // Buffer overflow vulnerability
  if (strlen(filename) > 1024) {
    printf("Error: filename too long.\n");
    exit(1);
  }

  // Train and test image classification model
  // (code omitted for brevity)

  return 0;
}
