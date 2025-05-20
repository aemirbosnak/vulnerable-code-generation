//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

// Function to check if a character is an alphabet
int is_alpha(int c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Function to convert a string to lowercase
void str_lower(char *str) {
  for (int i = 0; str[i]; i++)
    str[i] = tolower(str[i]);
}

// Function to reverse a string
void str_reverse(char *str, int start, int end) {
  char temp;

  for (; start < end; start++, end--) {
    temp = str[start];
    str[start] = str[end];
    str[end] = temp;
  }
}

// Function to check if a given string is a palindrome
int is_palindrome(char *str) {
  int len = strlen(str);

  if (len <= 1)
    return 1;

  str_lower(str);

  for (int i = 0; i < len / 2; i++) {
    if (!is_alpha(str[i]))
      continue;

    int j = len - i - 1;

    if (str[i] != str[j])
      return 0;
  }

  return 1;
}

int main() {
  char input[MAX_LENGTH];

  printf("Enter a string: ");
  fgets(input, MAX_LENGTH, stdin);

  // Remove newline character from the input string
  if (input[strlen(input) - 1] == '\n')
    input[strlen(input) - 1] = '\0';

  if (is_palindrome(input))
    printf("The given string is a palindrome.\n");
  else
    printf("The given string is not a palindrome.\n");

  return 0;
}