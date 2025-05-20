#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char input[1024];
  int i = 0;

  for (i = 0; i < 3; i++) {
    printf("Enter your name: ");
    fgets(input, 1024, stdin);

    // Sanitize input by replacing specific characters with spaces or underscores
    input[strcspn(input, "AEIOUaeiou")] = ' ';
    input[strcspn(input, "[]\\|\\:*\"\\?\\") - 1] = '_';
  }

  printf("Welcome, %s! We're glad you're here.\n", input);

  return 0;
}
