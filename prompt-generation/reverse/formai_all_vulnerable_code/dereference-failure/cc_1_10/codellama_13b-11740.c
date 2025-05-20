//Code Llama-13B DATASET v1.0 Category: String manipulation ; Style: complete
// String manipulation example program in C
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
  char str[] = "Hello World";
  char newStr[100];

  // Convert to uppercase
  for (int i = 0; i < strlen(str); i++) {
    newStr[i] = toupper(str[i]);
  }

  printf("Original string: %s\n", str);
  printf("Uppercase string: %s\n", newStr);

  // Convert to lowercase
  for (int i = 0; i < strlen(str); i++) {
    newStr[i] = tolower(str[i]);
  }

  printf("Lowercase string: %s\n", newStr);

  // Reverse the string
  int len = strlen(str);
  for (int i = 0; i < len / 2; i++) {
    char temp = newStr[i];
    newStr[i] = newStr[len - i - 1];
    newStr[len - i - 1] = temp;
  }

  printf("Reversed string: %s\n", newStr);

  // Concatenate strings
  char str2[] = "!";
  strcat(newStr, str2);
  printf("Concatenated string: %s\n", newStr);

  // Substring
  char subStr[5];
  strncpy(subStr, newStr, 5);
  printf("Substring: %s\n", subStr);

  // Trim whitespace
  char trimStr[50];
  strcpy(trimStr, newStr);
  char* end = trimStr + strlen(trimStr) - 1;
  while (end > trimStr && isspace(*end)) {
    *end = '\0';
    end--;
  }
  printf("Trimmed string: %s\n", trimStr);

  // Replace character
  char replaceStr[50];
  strcpy(replaceStr, newStr);
  char* ptr = strchr(replaceStr, 'H');
  *ptr = 'J';
  printf("Replaced string: %s\n", replaceStr);

  return 0;
}