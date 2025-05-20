#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buf[1024];
  int i = 0;

  // Get the user input
  printf("Enter text: ");
  fgets(buf, 1024, stdin);

  // Print the user input
  printf("Your text: %s", buf);

  // Loop over the user input and print the characters in reverse order
  for (i = strlen(buf) - 1; i >= 0; i--) {
    printf("%c", buf[i]);
  }

  return 0;
}
