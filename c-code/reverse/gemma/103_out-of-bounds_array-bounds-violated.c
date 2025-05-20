#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char input[1024];
  int i = 0;

  // Prompt for user name
  printf("Enter your hero's name: ");

  // Get user input and sanitize
  scanf("%s", input);
  for (i = 0; input[i] != '\0'; i++) {
    if (!isalnum(input[i])) {
      input[i] = ' ';
    }
  }

  // Prompt for quest objective
  printf("What is your quest objective? ");

  // Get user input and sanitize
  scanf("%s", input);
  for (i = 0; input[i] != '\0'; i++) {
    if (!isalnum(input[i])) {
      input[i] = '_';
    }
  }

  // Print welcome message
  printf("Welcome, %s, on your journey to %s!\n", input, input);

  return 0;
}
