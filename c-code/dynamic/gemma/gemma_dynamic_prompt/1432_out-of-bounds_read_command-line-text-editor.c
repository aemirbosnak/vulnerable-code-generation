#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buf[1024];
  FILE *f = fopen("/etc/passwd", "r");
  if (f) {
    fscanf(f, "%s", buf);
    printf("%s", buf);
  } else {
    perror("Error opening file");
  }
  return 0;
}
