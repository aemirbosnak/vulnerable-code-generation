//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LEN 1024
#define MAX_ERROR_LEN 256

// Error handling function that displays a nice message
void handleError(const char *msg) {
  printf("Oops! It looks like we have a problem here:\n");
  printf("  %s\n", msg);
  printf("But don't worry, we've got this! Let's try to recover gracefully...\n");
  printf("If you're feeling adventurous, you can try again by pressing Enter.");
  printf("\n");
}

int main() {
  // Variable to store the user's input
  char input[MAX_INPUT_LEN];

  // Ask the user for their name
  printf("What's your name? ");
  fgets(input, MAX_INPUT_LEN, stdin);

  // Try to convert the user's input to uppercase
  char uppercase[MAX_INPUT_LEN];
  for (int i = 0; i < strlen(input); i++) {
    uppercase[i] = toupper(input[i]);
  }

  // Check if the user's input is valid
  if (strcmp(input, uppercase) != 0) {
    handleError("Oops! It looks like your input isn't valid.");
  }

  // Do some more stuff here...
  printf("Hello, %s! How are you today?\n", input);

  // Ask the user for their favorite color
  printf("What's your favorite color? ");
  fgets(input, MAX_INPUT_LEN, stdin);

  // Try to convert the user's input to a number
  int color;
  if (sscanf(input, "%d", &color) != 1) {
    handleError("Oops! It looks like you didn't enter a valid color.");
  }

  // Print the user's favorite color
  printf("Ah, I see you like %d! That's a great choice.\n", color);

  return 0;
}