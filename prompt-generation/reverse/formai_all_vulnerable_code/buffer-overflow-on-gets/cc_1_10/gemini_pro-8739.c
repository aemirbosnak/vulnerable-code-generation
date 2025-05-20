//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Reversing a string using pointer arithmetic
char *reverse(char *str) {
  char *start = str;
  char *end = str + strlen(str) - 1;
  while (start < end) {
    char temp = *start;
    *start = *end;
    *end = temp;
    start++;
    end--;
  }
  return str;
}

// Palindrome checker using dynamic memory allocation
int isPalindrome(char *str) {
  char *reversed = malloc(strlen(str) + 1);
  strcpy(reversed, str);
  reversed = reverse(reversed);
  int result = strcmp(str, reversed) == 0;
  free(reversed);
  return result;
}

// Main function with a poetic introduction
int main() {
  printf("\nIn a realm of words, where letters dance,\n");
  printf("A tale unfolds, of palindrome's trance.\n\n");

  // User input and dynamic memory allocation for the string
  char input[100];
  printf("Enter a string, let's see if it's true:\n");
  gets(input);
  char *str = malloc(strlen(input) + 1);
  strcpy(str, input);

  // Palindrome check and result display
  int palindrome = isPalindrome(str);
  if (palindrome == 1) {
    printf("\nOh, what a wonder behold!\nYour string, a palindrome we hold.\n");
  } else {
    printf("\nAlas, not a palindrome it seems,\nIn symmetry, it doesn't dream.\n");
  }

  // Memory cleanup and graceful farewell
  free(str);
  printf("\nIn the world of strings, our quest is done,\nUntil next time, when palindrome's run.\n\n");
  return 0;
}