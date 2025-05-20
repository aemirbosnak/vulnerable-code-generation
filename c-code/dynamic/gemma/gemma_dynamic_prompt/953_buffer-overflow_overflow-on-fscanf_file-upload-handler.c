#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[1024];

  printf("Enter file name: ");
  scanf("%s", buffer);

  // Exploit buffer overflow vulnerability
  sprintf(buffer, "File name: %s", buffer);

  printf("%s", buffer);

  return 0;
}
