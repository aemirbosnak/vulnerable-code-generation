//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char str[] = "Hello, world!";

  // Print the length of the string
  printf("The length of the string is: %d\n", strlen(str));

  // Print the string backwards
  for (int i = strlen(str) - 1; i >= 0; i--) {
    printf("%c", str[i]);
  }
  printf("\n");

  // Convert the string to uppercase
  for (int i = 0; i < strlen(str); i++) {
    str[i] = toupper(str[i]);
  }
  printf("The uppercase string is: %s\n", str);

  // Convert the string to lowercase
  for (int i = 0; i < strlen(str); i++) {
    str[i] = tolower(str[i]);
  }
  printf("The lowercase string is: %s\n", str);

  // Find the first occurrence of a character in the string
  char c = 'o';
  int index = strchr(str, c) - str;
  printf("The first occurrence of '%c' is at index: %d\n", c, index);

  // Find the last occurrence of a character in the string
  index = strrchr(str, c) - str;
  printf("The last occurrence of '%c' is at index: %d\n", c, index);

  // Find the first occurrence of a substring in the string
  char substring[] = "world";
  index = strstr(str, substring) - str;
  printf("The first occurrence of '%s' is at index: %d\n", substring, index);

  // Find the last occurrence of a substring in the string
  index = strrchr(str, substring) - str;
  printf("The last occurrence of '%s' is at index: %d\n", substring, index);

  // Replace all occurrences of a character in the string with another character
  char oldChar = 'o';
  char newChar = 'a';
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] == oldChar) {
      str[i] = newChar;
    }
  }
  printf("The string with all occurrences of '%c' replaced with '%c': %s\n", oldChar, newChar, str);

  // Replace all occurrences of a substring in the string with another substring
  char oldSubstring[] = "world";
  char newSubstring[] = "universe";
  char *ptr = str;
  while ((ptr = strstr(ptr, oldSubstring)) != NULL) {
    memcpy(ptr, newSubstring, strlen(newSubstring));
    ptr += strlen(newSubstring);
  }
  printf("The string with all occurrences of '%s' replaced with '%s': %s\n", oldSubstring, newSubstring, str);

  // Split the string into an array of substrings based on a delimiter
  char delimiter = ' ';
  char *tokens[10];
  int numTokens = 0;
  char *token = strtok(str, &delimiter);
  while (token != NULL) {
    tokens[numTokens++] = token;
    token = strtok(NULL, &delimiter);
  }
  printf("The string split into an array of substrings based on '%c':\n", delimiter);
  for (int i = 0; i < numTokens; i++) {
    printf("%s\n", tokens[i]);
  }

  // Join an array of substrings into a single string with a delimiter
  char joinedString[100];
  joinedString[0] = '\0';
  for (int i = 0; i < numTokens; i++) {
    strcat(joinedString, tokens[i]);
    if (i < numTokens - 1) {
      strcat(joinedString, &delimiter);
    }
  }
  printf("The array of substrings joined into a single string with '%c' as the delimiter: %s\n", delimiter, joinedString);

  return 0;
}