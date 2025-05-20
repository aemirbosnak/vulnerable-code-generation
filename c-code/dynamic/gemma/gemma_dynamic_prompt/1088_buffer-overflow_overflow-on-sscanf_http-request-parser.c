#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[1024];
  char* ptr = buffer;
  int nread = 0;

  printf("Enter an HTTP request: ");
  scanf("%s", buffer);

  nread = strlen(buffer) + 1;
  if (nread > 1024) {
    printf("Error: Buffer overflow.\n");
  } else {
    ptr = realloc(buffer, nread);
    if (ptr == NULL) {
      printf("Error: Memory allocation failed.\n");
    } else {
      printf("Your HTTP request: %s\n", ptr);
    }
  }

  return 0;
}
