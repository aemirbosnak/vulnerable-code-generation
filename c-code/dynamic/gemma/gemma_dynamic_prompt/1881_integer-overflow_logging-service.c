#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int num = 0;
  char buffer[1024];

  printf("Enter a number: ");
  scanf("%d", &num);

  // Overflow the integer
  num = num * num + num / num;

  // Store the overflowed number in the buffer
  sprintf(buffer, "Overflowed number: %d", num);

  // Print the buffer
  printf("%s\n", buffer);

  return 0;
}
