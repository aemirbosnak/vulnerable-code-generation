//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string is a palindrome
int isPalindrome(char *str) {
  int len = strlen(str);

  // Check if the string is empty or has only one character
  if (len == 0 || len == 1) {
    return 1;
  }

  // Iterate over the string and check if the first and last characters are the same
  for (int i = 0; i < len / 2; i++) {
    if (str[i] != str[len - i - 1]) {
      return 0;
    }
  }

  // If all the characters match, the string is a palindrome
  return 1;
}

// Function to check if a number is a palindrome
int isPalindromeNumber(int num) {
  int reversedNum = 0;
  int originalNum = num;

  // Iterate over the number and reverse it
  while (num != 0) {
    reversedNum = reversedNum * 10 + num % 10;
    num /= 10;
  }

  // Check if the reversed number is the same as the original number
  return originalNum == reversedNum;
}

int main() {
  // Get the input from the user
  char str[100];
  int num;
  printf("Enter a string: ");
  scanf("%s", str);
  printf("Enter a number: ");
  scanf("%d", &num);

  // Check if the string is a palindrome
  if (isPalindrome(str)) {
    printf("The string is a palindrome.\n");
  } else {
    printf("The string is not a palindrome.\n");
  }

  // Check if the number is a palindrome
  if (isPalindromeNumber(num)) {
    printf("The number is a palindrome.\n");
  } else {
    printf("The number is not a palindrome.\n");
  }

  return 0;
}