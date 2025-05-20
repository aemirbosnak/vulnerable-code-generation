#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[10];
  int index = 0;

  while (1) {
    char message[1024];
    printf("Enter message: ");
    scanf("%s", message);

    if (strlen(message) > 1024) {
      printf("Message too long.\n");
    } else {
      memcpy(buffer + index, message, strlen(message));
      index += strlen(message);

      if (index >= 10) {
        index = 0;
      }
    }

    printf("Message stored: %s\n", buffer);
  }
}
