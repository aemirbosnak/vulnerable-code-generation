#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[1024];
  int size = 0;

  while (1) {
    char message[1024];
    printf("Enter message: ");
    scanf("%s", message);

    if (size + strlen(message) >= 1024) {
      printf("Error: buffer overflow!\n");
    } else {
      strcpy(buffer + size, message);
      size += strlen(message);
    }
  }

  return 0;
}
