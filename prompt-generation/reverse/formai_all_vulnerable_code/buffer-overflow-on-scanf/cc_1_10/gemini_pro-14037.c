//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
char *reverseString(char *str) {
  int len = strlen(str);
  for (int i = 0; i < len / 2; i++) {
    char temp = str[i];
    str[i] = str[len - i - 1];
    str[len - i - 1] = temp;
  }
  return str;
}

// Function to check if a string is a palindrome
int isPalindrome(char *str) {
  int len = strlen(str);
  for (int i = 0; i < len / 2; i++) {
    if (str[i] != str[len - i - 1]) {
      return 0;
    }
  }
  return 1;
}

// Function to find the longest palindrome in a string
char *findLongestPalindrome(char *str) {
  int len = strlen(str);
  int maxLen = 1;
  int start = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      int currLen = j - i + 1;
      if (currLen > maxLen && isPalindrome(str + i)) {
        maxLen = currLen;
        start = i;
      }
    }
  }
  return strndup(str + start, maxLen);
}

int main() {
  // Get the input string from the user
  char str[100];
  printf("Enter a string: ");
  scanf("%s", str);

  // Reverse the string
  char *reversedStr = reverseString(str);
  printf("Reversed string: %s\n", reversedStr);

  // Check if the string is a palindrome
  if (isPalindrome(str)) {
    printf("The string is a palindrome.\n");
  } else {
    printf("The string is not a palindrome.\n");
  }

  // Find the longest palindrome in the string
  char *longestPalindrome = findLongestPalindrome(str);
  printf("Longest palindrome: %s\n", longestPalindrome);

  return 0;
}