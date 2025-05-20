//Code Llama-13B DATASET v1.0 Category: Intrusion detection system ; Style: intelligent
// Intrusion detection system example program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

// Function to check if a character is a letter or digit
int is_alphanum(char c) {
  return isalpha(c) || isdigit(c);
}

// Function to check if a string is a palindrome
int is_palindrome(char *str) {
  int len = strlen(str);
  int i, j;
  for (i = 0, j = len - 1; i < len / 2; i++, j--) {
    if (str[i] != str[j]) {
      return 0;
    }
  }
  return 1;
}

// Function to check if a string is a unique string
int is_unique(char *str) {
  int len = strlen(str);
  int i, j;
  for (i = 0; i < len; i++) {
    for (j = i + 1; j < len; j++) {
      if (str[i] == str[j]) {
        return 0;
      }
    }
  }
  return 1;
}

// Function to check if a string is a prime number
int is_prime(char *str) {
  int len = strlen(str);
  int i, j;
  for (i = 2; i < len; i++) {
    if (str[i] % i == 0) {
      return 0;
    }
  }
  return 1;
}

// Function to check if a string is a palindrome and unique
int is_palindrome_unique(char *str) {
  return is_palindrome(str) && is_unique(str);
}

// Function to check if a string is a prime number and unique
int is_prime_unique(char *str) {
  return is_prime(str) && is_unique(str);
}

// Function to check if a string is a palindrome and prime
int is_palindrome_prime(char *str) {
  return is_palindrome(str) && is_prime(str);
}

// Main function
int main() {
  char str[MAX_LENGTH];
  scanf("%s", str);
  if (is_palindrome_unique(str)) {
    printf("Palindrome and unique\n");
  } else if (is_prime_unique(str)) {
    printf("Prime number and unique\n");
  } else if (is_palindrome_prime(str)) {
    printf("Palindrome and prime\n");
  } else {
    printf("None\n");
  }
  return 0;
}