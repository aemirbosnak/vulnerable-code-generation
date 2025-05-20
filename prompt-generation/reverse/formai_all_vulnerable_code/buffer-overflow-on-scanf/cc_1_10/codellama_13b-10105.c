//Code Llama-13B DATASET v1.0 Category: String manipulation ; Style: visionary
/*
 * Program: String Manipulation Program
 * Author: [Your Name]
 * Date: [Date]
 *
 * Description: This program takes a string as input and performs
 * various string manipulation operations on it.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
  char input[100];
  char output[100];

  printf("Enter a string: ");
  scanf("%s", input);

  // Reverse the string
  int length = strlen(input);
  for (int i = 0; i < length; i++) {
    output[i] = input[length - i - 1];
  }
  output[length] = '\0';

  printf("Reversed string: %s\n", output);

  // Capitalize the first letter
  output[0] = toupper(output[0]);
  printf("Capitalized string: %s\n", output);

  // Remove spaces
  int j = 0;
  for (int i = 0; i < length; i++) {
    if (output[i] != ' ') {
      output[j++] = output[i];
    }
  }
  output[j] = '\0';

  printf("String without spaces: %s\n", output);

  // Remove duplicates
  j = 1;
  for (int i = 1; i < length; i++) {
    if (output[i] != output[i - 1]) {
      output[j++] = output[i];
    }
  }
  output[j] = '\0';

  printf("String without duplicates: %s\n", output);

  return 0;
}