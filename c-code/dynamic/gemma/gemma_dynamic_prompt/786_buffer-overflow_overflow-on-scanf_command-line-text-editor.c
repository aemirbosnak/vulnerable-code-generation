#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buf[1024];
  int i = 0;

  printf("Enter text: ");
  scanf("%s", buf);

  for (i = 0; buf[i] != '\0'; i++) {
    printf("%c", buf[i]);
  }

  return 0;
}
