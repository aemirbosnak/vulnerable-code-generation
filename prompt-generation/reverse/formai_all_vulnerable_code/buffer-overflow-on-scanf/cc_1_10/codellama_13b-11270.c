//Code Llama-13B DATASET v1.0 Category: String manipulation ; Style: happy
/*
 * Happy String Manipulation Program
 */

#include <stdio.h>
#include <string.h>

int main() {
  char str1[100], str2[100];
  int i, j;

  printf("Enter first string: ");
  scanf("%s", str1);
  printf("Enter second string: ");
  scanf("%s", str2);

  // Concatenate the two strings
  strcat(str1, str2);

  // Print the concatenated string
  printf("Concatenated string: %s\n", str1);

  // Reverse the first string
  for (i = strlen(str1) - 1, j = 0; i >= 0; i--, j++) {
    str1[j] = str1[i];
  }
  str1[j] = '\0';

  // Print the reversed string
  printf("Reversed string: %s\n", str1);

  // Get the length of the first string
  int len = strlen(str1);

  // Print the length of the first string
  printf("Length of first string: %d\n", len);

  // Get the first character of the first string
  char first_char = str1[0];

  // Print the first character of the first string
  printf("First character of first string: %c\n", first_char);

  // Get the last character of the first string
  char last_char = str1[len - 1];

  // Print the last character of the first string
  printf("Last character of first string: %c\n", last_char);

  return 0;
}