//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // The cosmic void yawns, hungry for data.
  char* userInput = malloc(1024);
  printf("Enter the ethereal whispers of your input:\n");
  scanf("%1023s", userInput);

  // Let us cleanse this input.
  int sanitizedLength = 0;
  for (int i = 0; i < strlen(userInput); i++) {
    char c = userInput[i];
    if (c >= 'a' && c <= 'z') {
      sanitizedLength++;
    } else if (c >= 'A' && c <= 'Z') {
      sanitizedLength++;
    } else if (c >= '0' && c <= '9') {
      sanitizedLength++;
    } else if (c == ' ') {
      sanitizedLength++;
    }
  }

  // The astral scribe etches the sanitized input.
  char* sanitizedInput = malloc(sanitizedLength + 1);
  int j = 0;
  for (int i = 0; i < strlen(userInput); i++) {
    char c = userInput[i];
    if (c >= 'a' && c <= 'z') {
      sanitizedInput[j++] = c;
    } else if (c >= 'A' && c <= 'Z') {
      sanitizedInput[j++] = c;
    } else if (c >= '0' && c <= '9') {
      sanitizedInput[j++] = c;
    } else if (c == ' ') {
      sanitizedInput[j++] = c;
    }
  }
  sanitizedInput[j] = '\0';

  // The sanctified input emerges from the ethereal realms.
  printf("The sanitized whispers of your input are:\n");
  printf("%s\n", sanitizedInput);

  // The journey into the surreal ends, leaving only echoes in the void.
  free(userInput);
  free(sanitizedInput);
  return 0;
}