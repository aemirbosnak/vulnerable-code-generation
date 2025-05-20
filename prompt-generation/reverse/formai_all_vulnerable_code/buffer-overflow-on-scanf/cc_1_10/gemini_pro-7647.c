//GEMINI-pro DATASET v1.0 Category: Educational ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string is a palindrome
int isPalindrome(char *str) {
  int len = strlen(str);

  for (int i = 0, j = len - 1; i < len / 2; i++, j--) {
    if (str[i] != str[j]) {
      return 0;
    }
  }

  return 1;
}

// Function to generate all subsets of a string
void generateSubsets(char *str, int n) {
  // Create an array to store the subsets
  char **subsets = (char **)malloc(sizeof(char *) * (1 << n));

  // Iterate over all possible bitmasks
  for (int i = 0; i < (1 << n); i++) {
    subsets[i] = (char *)malloc(sizeof(char) * (n + 1));
    int j = 0;

    // Iterate over each bit in the bitmask
    for (int k = 0; k < n; k++) {
      // If the bit is set, add the corresponding character to the subset
      if ((i & (1 << k)) != 0) {
        subsets[i][j++] = str[k];
      }
    }

    // Null-terminate the subset
    subsets[i][j] = '\0';
  }

  // Print all the subsets
  for (int i = 0; i < (1 << n); i++) {
    if (isPalindrome(subsets[i])) {
      printf("%s\n", subsets[i]);
    }
    free(subsets[i]);
  }

  free(subsets);
}

int main() {
  // Get the input string from the user
  char str[100];
  printf("Enter a string: ");
  scanf("%s", str);

  // Generate all subsets of the string
  generateSubsets(str, strlen(str));

  return 0;
}