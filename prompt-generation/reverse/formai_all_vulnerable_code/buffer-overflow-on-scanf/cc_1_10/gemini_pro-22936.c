//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1024

int main() {
  // Allocate memory for the strings
  char *str1 = malloc(MAX_STR_LEN);
  char *str2 = malloc(MAX_STR_LEN);

  // Get the strings from the user
  printf("Enter the first string: ");
  scanf("%s", str1);

  printf("Enter the second string: ");
  scanf("%s", str2);

  // Check if the strings are equal
  if (strcmp(str1, str2) == 0) {
    printf("The strings are equal.\n");
  } else {
    printf("The strings are not equal.\n");
  }

  // Check if the first string is a substring of the second string
  if (strstr(str2, str1) != NULL) {
    printf("The first string is a substring of the second string.\n");
  } else {
    printf("The first string is not a substring of the second string.\n");
  }

  // Concatenate the two strings
  char *str3 = malloc(MAX_STR_LEN);
  strcpy(str3, str1);
  strcat(str3, str2);
  printf("The concatenated string is: %s\n", str3);

  // Reverse the first string
  int len = strlen(str1);
  for (int i = 0; i < len / 2; i++) {
    char temp = str1[i];
    str1[i] = str1[len - i - 1];
    str1[len - i - 1] = temp;
  }
  printf("The reversed first string is: %s\n", str1);

  // Find the longest common substring of the two strings
  int lcs_len = 0;
  int lcs_start = 0;
  for (int i = 0; i < strlen(str1); i++) {
    for (int j = 0; j < strlen(str2); j++) {
      int k = 0;
      while (str1[i + k] == str2[j + k] && i + k < strlen(str1) && j + k < strlen(str2)) {
        k++;
      }
      if (k > lcs_len) {
        lcs_len = k;
        lcs_start = i;
      }
    }
  }
  char *lcs = malloc(lcs_len + 1);
  strncpy(lcs, str1 + lcs_start, lcs_len);
  lcs[lcs_len] = '\0';
  printf("The longest common substring is: %s\n", lcs);

  // Free the memory allocated for the strings
  free(str1);
  free(str2);
  free(str3);
  free(lcs);

  return 0;
}