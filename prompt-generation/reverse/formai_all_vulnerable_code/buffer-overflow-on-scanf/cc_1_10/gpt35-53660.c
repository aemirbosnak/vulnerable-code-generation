//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: configurable
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100

// Function to check if a given string is a palindrome
int isPalindrome(char str[]) {
  int length = strlen(str);
  for(int i = 0; i < length/2; i++) {
    if(str[i] != str[length-i-1]) {
      return 0;
    }
  }
  return 1;
}

int main() {
  char str[MAX_LENGTH];
  printf("Enter a string: ");
  fgets(str, MAX_LENGTH, stdin);                      // take input from user
  str[strcspn(str, "\n")] = '\0';                     // remove newline character

  // Ask user if they want to ignore case and/or punctuation
  int ignoreCase = 0;
  int ignorePunctuation = 0;
  printf("Do you want to ignore case? (y/n): ");
  char choice;
  scanf("%c", &choice);
  getchar();                                          // remove newline from buffer
  if(choice == 'y' || choice == 'Y') {
    ignoreCase = 1;
  }
  printf("Do you want to ignore punctuation? (y/n): ");
  scanf("%c", &choice);
  getchar();                                          // remove newline from buffer
  if(choice == 'y' || choice == 'Y') {
    ignorePunctuation = 1;
  }

  // Remove punctuation from string if necessary
  if(ignorePunctuation) {
    int j = 0;
    for(int i = 0; i < strlen(str); i++) {
      if(!ispunct(str[i])) {
        str[j++] = str[i];
      }
    }
    str[j] = '\0';
  }

  // Convert string to lowercase if necessary
  if(ignoreCase) {
    for(int i = 0; i < strlen(str); i++) {
      str[i] = tolower(str[i]);
    }
  }

  // Check if string is a palindrome
  if(isPalindrome(str)) {
    printf("The string is a palindrome.\n");
  } else {
    printf("The string is not a palindrome.\n");
  }

  return 0;
}