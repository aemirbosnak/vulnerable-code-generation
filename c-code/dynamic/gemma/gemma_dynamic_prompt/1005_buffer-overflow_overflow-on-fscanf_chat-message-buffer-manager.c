#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[1024];
  int index = 0;

  while (1) {
    char message[1024];

    printf("Enter message: ");
    fscanf(stdin, "%s", message);

    if (index + strlen(message) >= 1024) {
      printf("Buffer overflow!\n");
    } else {
      memcpy(buffer + index, message, strlen(message));
      index += strlen(message);
    }

    printf("Message stored: %s\n", buffer);
  }
}
