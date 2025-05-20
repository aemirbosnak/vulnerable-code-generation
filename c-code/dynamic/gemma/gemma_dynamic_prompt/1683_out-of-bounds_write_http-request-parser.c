#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *buf = malloc(1024);
  int len = 0;

  // Read the entire HTTP request body into the buffer
  while (1) {
    int read_amt = read(0, buf, 1024);
    if (read_amt == -1) {
      perror("Error reading request body");
      exit(1);
    } else if (read_amt == 0) {
      break;
    } else {
      len += read_amt;
    }
  }

  // Print the entire request body
  printf("Request body: %s", buf);

  free(buf);
  return 0;
}
