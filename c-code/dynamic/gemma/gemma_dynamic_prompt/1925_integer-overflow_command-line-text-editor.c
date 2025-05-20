#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[10000];
  int i = 0;
  int j = 0;

  printf("Enter text: ");
  fgets(buffer, 10000, stdin);

  for (i = 0; buffer[i] != '\0'; i++) {
    if (buffer[i] >= 'a' && buffer[i] <= 'z') {
      buffer[i] += 32;
    } else if (buffer[i] >= 'A' && buffer[i] <= 'Z') {
      buffer[i] -= 32;
    }
  }

  printf("Modified text: ");
  puts(buffer);

  return 0;
}
