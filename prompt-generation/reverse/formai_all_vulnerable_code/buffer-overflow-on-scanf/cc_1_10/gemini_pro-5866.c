//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the input string
#define MAX_STRING_LENGTH 100

// Function to check if a string is a palindrome
int is_palindrome(char *str) {
  // Get the length of the string
  int len = strlen(str);

  // Check if the string is empty
  if (len == 0) {
    return 1;
  }

  // Check if the first and last characters of the string are the same
  if (str[0] != str[len - 1]) {
    return 0;
  }

  // Check if the middle characters of the string are the same
  if (len % 2 == 0) {
    if (str[len / 2] != str[len / 2 - 1]) {
      return 0;
    }
  }

  // Return true if the string is a palindrome
  return 1;
}

// Main function
int main() {
  // Get the input string from the user
  char str[MAX_STRING_LENGTH];
  printf("Enter a string: ");
  scanf("%s", str);

  // Check if the string is a palindrome
  int result = is_palindrome(str);

  // Print the result
  if (result) {
    printf("The string '%s' is a palindrome\n", str);
  } else {
    printf("The string '%s' is not a palindrome\n", str);
  }

  return 0;
}