#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buf[1024];
  int len = 0;

  printf("Enter text: ");
  scanf("%s", buf);

  len = strlen(buf) + 1;
  if (len > 1024) {
    printf("Error: Buffer overflow.\n");
  } else {
    printf("Text: %s\n", buf);
  }

  return 0;
}
