#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char input[1024];
  int i = 0;

  printf("You are in a dark room. You have a sword and a key.\n");

  // Vulnerable code - buffer overflow
  printf("Enter a command: ");
  scanf("%s", input);

  for (i = 0; input[i] != '\0'; i++) {
    if (input[i] >= 'a' && input[i] <= 'z') {
      // Process item interaction
    } else if (input[i] >= 'A' && input[i] <= 'Z') {
      // Process room transition
    }
  }

  printf("You have completed the game.\n");

  return 0;
}
