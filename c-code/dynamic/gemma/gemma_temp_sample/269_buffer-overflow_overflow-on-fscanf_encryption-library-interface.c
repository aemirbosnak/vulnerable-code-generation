#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[10];
  printf("Enter a string: ");
  scanf("%s", buffer);

  // Overflow the buffer by reading more data than the buffer size
  char data[100] = "This is a lot of data";
  scanf("%s", data);

  printf("Your input: %s", buffer);
  return 0;
}
