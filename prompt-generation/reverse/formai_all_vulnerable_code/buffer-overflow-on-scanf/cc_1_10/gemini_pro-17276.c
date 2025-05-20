//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cyberpunk-styled function to check if a string is a palindrome
int is_palindrome(const char *str) {
  // Initialize variables
  int len = strlen(str);  // Length of the string
  int i, j;              // Loop counters

  // Check if the string is empty or has only one character
  if (len <= 1) {
    return 1;  // Empty and single-character strings are considered palindromes
  }

  // Initialize the loop counters
  i = 0;  // Start at the beginning of the string
  j = len - 1;  // Start at the end of the string

  // Loop through the string, comparing characters from the beginning and the end
  while (i < j) {
    // If the characters are not equal, the string is not a palindrome
    if (str[i] != str[j]) {
      return 0;
    }

    // Increment the beginning counter and decrement the end counter
    i++;
    j--;
  }

  // If the loop completes without finding any mismatched characters, the string is a palindrome
  return 1;
}

// Main function
int main() {
  // Initialize variables
  char str[100];  // Input string
  int result;    // Result of the palindrome check

  // Get the input string from the user
  printf("Enter a string: ");
  scanf("%s", str);

  // Check if the string is a palindrome
  result = is_palindrome(str);

  // Print the result
  if (result) {
    printf("%s is a palindrome.\n", str);
  } else {
    printf("%s is not a palindrome.\n", str);
  }

  return 0;
}