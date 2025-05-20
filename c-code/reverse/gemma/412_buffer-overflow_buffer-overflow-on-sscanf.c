#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[1024];
  char *response = "POP3 server response: Message ID 123, Size: 1024";
  int result = sscanf(response, "%s", buffer);
  printf("Parsed message ID: %s", buffer);
  return 0;
}
