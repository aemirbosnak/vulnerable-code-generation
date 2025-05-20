#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main() {
  int file_size = 10000000000; // 10GB file size, overflows int
  int upload_size = file_size + 1; // Intentional overflow

  printf("File size: %d", file_size);
  printf("\nUpload size: %d", upload_size);

  return 0;
}
