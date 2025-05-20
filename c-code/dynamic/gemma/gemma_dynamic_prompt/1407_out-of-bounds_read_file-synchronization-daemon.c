#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *fp = fopen("/etc/passwd", "r");
  if (fp == NULL) {
    perror("Error opening file");
    return 1;
  }

  char buffer[1024];
  size_t read_bytes = fread(buffer, 1, 1024, fp);
  if (read_bytes == -1) {
    perror("Error reading file");
    fclose(fp);
    return 1;
  }

  buffer[read_bytes] = '\0';
  printf("%s", buffer);

  fclose(fp);
  return 0;
}
