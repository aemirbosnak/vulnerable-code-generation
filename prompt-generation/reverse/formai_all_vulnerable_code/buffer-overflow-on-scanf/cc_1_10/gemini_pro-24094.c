//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string is a palindrome
int is_palindrome(char *str) {
  // Find the length of the string
  int len = strlen(str);

  // Iterate over the string from both sides and compare the characters
  for (int i = 0, j = len - 1; i < j; i++, j--) {
    if (str[i] != str[j]) {
      return 0; // Not a palindrome
    }
  }

  // If all characters match, the string is a palindrome
  return 1;
}

// Function to check if a number is a palindrome
int is_number_palindrome(int num) {
  // Convert the number to a string
  char str[100];
  sprintf(str, "%d", num);

  // Check if the string is a palindrome
  return is_palindrome(str);
}

int main() {
  // Get the input string from the user
  char str[100];
  printf("Enter a string: ");
  scanf("%s", str);

  // Check if the string is a palindrome
  if (is_palindrome(str)) {
    printf("%s is a palindrome\n", str);
  } else {
    printf("%s is not a palindrome\n", str);
  }

  // Get the input number from the user
  int num;
  printf("Enter a number: ");
  scanf("%d", &num);

  // Check if the number is a palindrome
  if (is_number_palindrome(num)) {
    printf("%d is a palindrome\n", num);
  } else {
    printf("%d is not a palindrome\n", num);
  }

  return 0;
}