#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[10];
  char* url = "GET /hello?name=John&age=100&description=This is a long description that will cause a buffer overflow";
  char* ptr = url;

  // Malformed scanf format string that overflows the buffer
  sprintf(buffer, "scanf(\"%s %s %[^\"]\", %s)", ptr);

  // Print the parsed data
  printf("Name: %s\n", buffer);
  printf("Age: %s\n", buffer + 16);
  printf("Description: %s\n", buffer + 32);

  return 0;
}
