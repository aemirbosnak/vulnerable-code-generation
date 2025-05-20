//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 256

int main(void) {
  char cryptic_string[MAX_STRING_LENGTH];
  char readable_string[MAX_STRING_LENGTH];
  int i, j;

  // Max manages to extract the cryptic string from the ancient computer.
  printf("Max has discovered the cryptic string:\n");
  scanf("%s", cryptic_string);

  // The cryptic string is in a disjointed and corrupted state.
  // Max must manipulate the string to make it readable again.

  // Step 1: Remove any leading or trailing whitespaces.
  i = 0;
  while (cryptic_string[i] == ' ') {
    i++;
  }

  int length = 0;
  while (cryptic_string[i + length] != '\0') {
    readable_string[length] = cryptic_string[i + length];
    length++;

    if (cryptic_string[i + length] == ' ') {
      readable_string[length] = '\0';
      i += length + 1;
      length = 0;
    }
  }

  // Step 2: Decode any special characters.
  for (i = 0; readable_string[i] != '\0'; i++) {
    switch (readable_string[i]) {
      case '+':
        readable_string[i] = ' ';
        break;
      case '-':
        readable_string[i] = '_';
        break;
      case '%':
        readable_string[i] = '&';
        break;
      case '/':
        readable_string[i] = '|';
        break;
      default:
        // No special character decoding needed.
        break;
    }
  }

  // Max has successfully decoded the cryptic string!
  printf("\nMax has decoded the readable string:\n");
  puts(readable_string);

  return 0;
}