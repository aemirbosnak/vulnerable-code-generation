#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[10];
  printf("Enter data: ");
  scanf("%s", buffer);

  // Overflow on fscanf
  scanf("%s", buffer);

  printf("Data stored: %s", buffer);

  return 0;
}
