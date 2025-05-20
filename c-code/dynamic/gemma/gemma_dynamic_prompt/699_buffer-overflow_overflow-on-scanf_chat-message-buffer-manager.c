#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char message[1024];
  int message_length = 0;

  printf("Enter your message: ");
  scanf("%s", message);

  message_length = strlen(message) + 1;

  if (message_length > 1024) {
    printf("Error: Message too long.\n");
  } else {
    printf("Your message: %s\n", message);
  }

  return 0;
}
