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
    scanf("%s", message);

    if (strlen(message) > index) {
      printf("Error: buffer overflow\n");
    } else {
      strcpy(buffer + index, message);
      index += strlen(message);

      printf("Message stored: %s\n", buffer);
    }
  }

  return 0;
}
