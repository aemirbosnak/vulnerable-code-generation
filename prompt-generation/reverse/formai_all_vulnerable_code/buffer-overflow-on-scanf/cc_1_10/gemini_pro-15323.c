//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A custom function to swap two characters in a string
void swap(char *x, char *y) {
  char temp = *x;
  *x = *y;
  *y = temp;
}

// A custom function to reverse a string
void reverse(char *str) {
  int i, len;
  len = strlen(str);
  for (i = 0; i < len / 2; i++) {
    swap(&str[i], &str[len - i - 1]);
  }
}

// A custom function to check if a string is a palindrome
int isPalindrome(char *str) {
  int i, len;
  len = strlen(str);
  for (i = 0; i < len / 2; i++) {
    if (str[i] != str[len - i - 1]) {
      return 0;
    }
  }
  return 1;
}

// A custom function to count the number of vowels in a string
int countVowels(char *str) {
  int i, count = 0;
  for (i = 0; str[i] != '\0'; i++) {
    if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
        str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
      count++;
    }
  }
  return count;
}

// A custom function to count the number of consonants in a string
int countConsonants(char *str) {
  int i, count = 0;
  for (i = 0; str[i] != '\0'; i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u') {
        count++;
      }
    } else if (str[i] >= 'A' && str[i] <= 'Z') {
      if (str[i] != 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'O' && str[i] != 'U') {
        count++;
      }
    }
  }
  return count;
}

// A custom function to count the number of words in a string
int countWords(char *str) {
  int i, count = 0;
  for (i = 0; str[i] != '\0'; i++) {
    if (str[i] == ' ') {
      count++;
    }
  }
  return count + 1;
}

// A custom function to count the number of lines in a string
int countLines(char *str) {
  int i, count = 0;
  for (i = 0; str[i] != '\0'; i++) {
    if (str[i] == '\n') {
      count++;
    }
  }
  return count + 1;
}

// A custom function to count the number of characters in a string
int countChars(char *str) {
  int i, count = 0;
  for (i = 0; str[i] != '\0'; i++) {
    count++;
  }
  return count;
}

int main() {
  char str[100];
  int choice;

  printf("Enter a string: ");
  gets(str);

  printf("1. Reverse the string\n");
  printf("2. Check if the string is a palindrome\n");
  printf("3. Count the number of vowels in the string\n");
  printf("4. Count the number of consonants in the string\n");
  printf("5. Count the number of words in the string\n");
  printf("6. Count the number of lines in the string\n");
  printf("7. Count the number of characters in the string\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      reverse(str);
      printf("Reversed string: %s\n", str);
      break;
    case 2:
      if (isPalindrome(str)) {
        printf("The string is a palindrome\n");
      } else {
        printf("The string is not a palindrome\n");
      }
      break;
    case 3:
      printf("Number of vowels: %d\n", countVowels(str));
      break;
    case 4:
      printf("Number of consonants: %d\n", countConsonants(str));
      break;
    case 5:
      printf("Number of words: %d\n", countWords(str));
      break;
    case 6:
      printf("Number of lines: %d\n", countLines(str));
      break;
    case 7:
      printf("Number of characters: %d\n", countChars(str));
      break;
    default:
      printf("Invalid choice\n");
  }

  return 0;
}