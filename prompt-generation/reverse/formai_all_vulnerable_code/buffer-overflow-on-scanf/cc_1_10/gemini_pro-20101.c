//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: immersive
// Embark on an Immersive Sanitization Adventure!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prepare a secret message for the uninitiated
char secretMessage[] = "Mea culpa, mea maxima culpa";

// Ascend the Ivory Tower of Sanitization
void purifyInput(char *input) {
  char sanitizedInput[strlen(input) + 1];
  int i = 0;
  int j = 0;

  // Scrutinize each character, purging the unholy
  while (input[i] != '\0') {
    if (input[i] >= 'a' && input[i] <= 'z') {
      sanitizedInput[j++] = input[i];
    } else if (input[i] >= 'A' && input[i] <= 'Z') {
      sanitizedInput[j++] = input[i];
    } else if (input[i] >= '0' && input[i] <= '9') {
      sanitizedInput[j++] = input[i];
    } else if (input[i] == ' ') {
      sanitizedInput[j++] = input[i];
    }
    i++;
  }

  sanitizedInput[j] = '\0';

  // Behold, the sanitized input, cleansed of impurities!
  strcpy(input, sanitizedInput);
}

// Commence the Interrogation
int main() {
  char input[100];

  printf("Mortal, speak your unholy input: ");
  scanf("%s", input);

  // Summon the Sanitization Council!
  purifyInput(input);

  // Reveal the sanitized truth
  printf("Your purified words, devoid of taint: %s\n", input);

  // Confirm the secret with the initiated
  if (strcmp(input, secretMessage) == 0) {
    printf("You have uttered the forbidden phrase! Woe betide thee!\n");
  } else {
    printf("Your words have been deemed acceptable. You may pass.\n");
  }

  return 0;
}