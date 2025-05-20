//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

#define BUFFERSIZE 1024

int main() {
  char buffer[BUFFERSIZE];
  int i, len;

  // Get a string from the user.
  printf("Enter a string: ");
  fgets(buffer, BUFFERSIZE, stdin);

  // Remove the newline character from the end of the string.
  len = strlen(buffer);
  if (buffer[len - 1] == '\n') {
    buffer[len - 1] = '\0';
  }

  // Reverse the string.
  for (i = 0; i < len / 2; i++) {
    char temp = buffer[i];
    buffer[i] = buffer[len - i - 1];
    buffer[len - i - 1] = temp;
  }

  // Print the reversed string.
  printf("The reversed string is: %s\n", buffer);

  // Convert the string to uppercase.
  for (i = 0; i < len; i++) {
    buffer[i] = toupper(buffer[i]);
  }

  // Print the uppercase string.
  printf("The uppercase string is: %s\n", buffer);

  // Convert the string to lowercase.
  for (i = 0; i < len; i++) {
    buffer[i] = tolower(buffer[i]);
  }

  // Print the lowercase string.
  printf("The lowercase string is: %s\n", buffer);

  // Remove all spaces from the string.
  for (i = 0; i < len; i++) {
    if (buffer[i] == ' ') {
      memmove(&buffer[i], &buffer[i + 1], len - i);
      len--;
    }
  }

  // Print the string with no spaces.
  printf("The string with no spaces is: %s\n", buffer);

  // Remove all vowels from the string.
  for (i = 0; i < len; i++) {
    if (buffer[i] == 'a' || buffer[i] == 'e' || buffer[i] == 'i' || buffer[i] == 'o' ||
        buffer[i] == 'u') {
      memmove(&buffer[i], &buffer[i + 1], len - i);
      len--;
    }
  }

  // Print the string with no vowels.
  printf("The string with no vowels is: %s\n", buffer);

  return 0;
}