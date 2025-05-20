#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buf[1024];
  FILE *f = fopen("text.txt", "r");
  if (f) {
    fgets(buf, 1024, f);
    printf("%s", buf);
  } else {
    perror("Error opening file");
  }
  return 0;
}
