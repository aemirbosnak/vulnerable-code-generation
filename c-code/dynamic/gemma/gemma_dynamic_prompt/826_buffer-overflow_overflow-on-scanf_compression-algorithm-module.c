#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  char buffer[10];
  scanf("%s", buffer);

  if (buffer[0] == 'a') {
    printf("Vulnerable system!\n");
  } else {
    printf("Safe system!\n");
  }

  return 0;
}
