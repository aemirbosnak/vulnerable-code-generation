//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 100

void greet(char *name) {
  printf("Hello, %s! Welcome to the peaceful string manipulation program.\n", name);
}

void showMenu() {
  printf("Please choose an option:\n");
  printf("1. Convert to uppercase\n");
  printf("2. Convert to lowercase\n");
  printf("3. Reverse the string\n");
  printf("4. Find the length of the string\n");
  printf("5. Compare two strings\n");
  printf("6. Quit\n");
}

void convertToUppercase(char *str) {
  int i;
  for (i = 0; str[i] != '\0'; i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      str[i] = str[i] - 32;
    }
  }
}

void convertToLowercase(char *str) {
  int i;
  for (i = 0; str[i] != '\0'; i++) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      str[i] = str[i] + 32;
    }
  }
}

void reverseString(char *str) {
  int i, j;
  char temp;
  i = 0;
  j = strlen(str) - 1;
  while (i < j) {
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
    i++;
    j--;
  }
}

int findLength(char *str) {
  int i;
  for (i = 0; str[i] != '\0'; i++);
  return i;
}

int compareStrings(char *str1, char *str2) {
  int i;
  for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++) {
    if (str1[i] != str2[i]) {
      return 0;
    }
  }
  return 1;
}

int main() {
  char name[MAX_STRING_SIZE];
  char str[MAX_STRING_SIZE];
  int choice;
  int length;
  int result;
  printf("What is your name?\n");
  scanf("%s", name);
  greet(name);
  showMenu();
  scanf("%d", &choice);
  switch (choice) {
    case 1:
      printf("Enter your string:\n");
      scanf(" %[^\n]s", str);
      convertToUppercase(str);
      printf("The string in uppercase is: %s\n", str);
      break;
    case 2:
      printf("Enter your string:\n");
      scanf(" %[^\n]s", str);
      convertToLowercase(str);
      printf("The string in lowercase is: %s\n", str);
      break;
    case 3:
      printf("Enter your string:\n");
      scanf(" %[^\n]s", str);
      reverseString(str);
      printf("The reversed string is: %s\n", str);
      break;
    case 4:
      printf("Enter your string:\n");
      scanf(" %[^\n]s", str);
      length = findLength(str);
      printf("The length of the string is: %d\n", length);
      break;
    case 5:
      printf("Enter your first string:\n");
      scanf(" %[^\n]s", str);
      printf("Enter your second string:\n");
      getchar();
      scanf(" %[^\n]s", str);
      result = compareStrings(str, str);
      if (result) {
        printf("The strings are equal.\n");
      } else {
        printf("The strings are not equal.\n");
      }
      break;
    case 6:
      printf("Thank you for using the program. Goodbye!\n");
      break;
    default:
      printf("Invalid choice. Please enter a valid option.\n");
      break;
  }
  return 0;
}