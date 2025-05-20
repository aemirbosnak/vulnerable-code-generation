#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *buf = malloc(10);
  int i = 0;

  // Read the request header
  printf("Enter the request header: ");
  scanf("%s", buf);

  // Out-of-bounds read
  for (i = 0; buf[i] != '\0'; i++) {
    if (i > 9) {
      printf("Error: Out-of-bounds read.\n");
      exit(1);
    }
  }

  // Print the parsed header
  printf("Parsed header: %s\n", buf);

  free(buf);
  return 0;
}
