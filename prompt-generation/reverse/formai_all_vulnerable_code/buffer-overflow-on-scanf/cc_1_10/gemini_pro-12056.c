//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count the number of words in a string
int countWords(char *str) {
  int count = 0;
  int i = 0;
  int inWord = 0;

  while (str[i] != '\0') {
    if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t') {
      if (!inWord) {
        count++;
        inWord = 1;
      }
    } else {
      inWord = 0;
    }
    i++;
  }

  return count;
}

// Function to reverse a string
char *reverseString(char *str) {
  int length = strlen(str);
  char *reversed = malloc(length + 1);
  int i;

  for (i = 0; i < length; i++) {
    reversed[i] = str[length - i - 1];
  }
  reversed[length] = '\0';

  return reversed;
}

// Function to print the longest word in a string
void printLongestWord(char *str) {
  int i = 0;
  int start = 0;
  int end = 0;
  int maxLen = 0;

  while (str[i] != '\0') {
    if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t') {
      end++;
    } else {
      if (end - start > maxLen) {
        maxLen = end - start;
      }
      start = i + 1;
      end = i + 1;
    }
    i++;
  }

  if (end - start > maxLen) {
    maxLen = end - start;
  }

  char *longestWord = malloc(maxLen + 1);
  strncpy(longestWord, str + start, maxLen);
  longestWord[maxLen] = '\0';

  printf("The longest word in the string is: %s\n", longestWord);
}

// Function to count the number of vowels in a string
int countVowels(char *str) {
  int count = 0;
  int i = 0;

  while (str[i] != '\0') {
    char c = str[i];
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
      count++;
    } else if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
      count++;
    }
    i++;
  }

  return count;
}

// Function to count the number of consonants in a string
int countConsonants(char *str) {
  int count = 0;
  int i = 0;

  while (str[i] != '\0') {
    char c = str[i];
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
      if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' && c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U') {
        count++;
      }
    }
    i++;
  }

  return count;
}

// Function to count the number of digits in a string
int countDigits(char *str) {
  int count = 0;
  int i = 0;

  while (str[i] != '\0') {
    char c = str[i];
    if (c >= '0' && c <= '9') {
      count++;
    }
    i++;
  }

  return count;
}

// Function to count the number of special characters in a string
int countSpecialCharacters(char *str) {
  int count = 0;
  int i = 0;

  while (str[i] != '\0') {
    char c = str[i];
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == ' ') {
      count++;
    }
    i++;
  }

  return count;
}

int main() {
  // Get the input string from the user
  char *str = malloc(100);
  printf("Enter a string: ");
  scanf("%s", str);

  // Print the number of words in the string
  printf("Number of words in the string: %d\n", countWords(str));

  // Print the reversed string
  printf("Reversed string: %s\n", reverseString(str));

  // Print the longest word in the string
  printLongestWord(str);

  // Print the number of vowels in the string
  printf("Number of vowels in the string: %d\n", countVowels(str));

  // Print the number of consonants in the string
  printf("Number of consonants in the string: %d\n", countConsonants(str));

  // Print the number of digits in the string
  printf("Number of digits in the string: %d\n", countDigits(str));

  // Print the number of special characters in the string
  printf("Number of special characters in the string: %d\n", countSpecialCharacters(str));

  return 0;
}