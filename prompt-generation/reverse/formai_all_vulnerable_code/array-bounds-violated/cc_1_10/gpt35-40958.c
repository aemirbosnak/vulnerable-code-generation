//FormAI DATASET v1.0 Category: String manipulation ; Style: peaceful
#include <stdio.h>
#include <string.h>

int main() {
  char str1[100], str2[100];
  int i, j;

  // Request user input for the first string
  printf("Please enter the first string: ");
  fgets(str1, sizeof(str1), stdin);

  // Request user input for the second string
  printf("Please enter the second string: ");
  fgets(str2, sizeof(str2), stdin);

  // Remove newline character from input strings
  str1[strcspn(str1, "\n")] = '\0';
  str2[strcspn(str2, "\n")] = '\0';

  // Concatenate the two strings
  strcat(str1, str2);

  // Search for a specified substring in the concatenated string
  char substr[20];
  printf("Please enter a substring to search for: ");
  fgets(substr, sizeof(substr), stdin);
  substr[strcspn(substr, "\n")] = '\0';

  int substr_len = strlen(substr);
  int str_len = strlen(str1);
  int found = 0;

  for (i = 0; i <= str_len - substr_len; i++) {
    for (j = 0; j < substr_len; j++) {
      if (str1[i+j] != substr[j]) {
        break;
      }
    }
    if (j == substr_len) {
      printf("Substring '%s' found at position %d.\n", substr, i+1);
      found = 1;
    }
  }

  if (!found) {
    printf("Substring not found.\n");
  }

  // Reverse the concatenated string
  str_len = strlen(str1);
  char reversed_str[str_len];
  for (i = str_len-1, j = 0; i >= 0; i--, j++) {
    reversed_str[j] = str1[i];
  }
  reversed_str[j] = '\0';

  printf("The reversed string is: %s\n", reversed_str);

  return 0;
}