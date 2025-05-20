//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: interoperable
#include <stdio.h>
#include <string.h>

// Function to split a string into an array of substrings
char **splitString(char *str, char *delim) {
  // Allocate memory for the array of substrings
  char **substrs = malloc(sizeof(char *) * 100);

  // Initialize the number of substrings to 0
  int numSubstrs = 0;

  // Split the string into substrings
  char *token = strtok(str, delim);
  while (token != NULL) {
    // Allocate memory for the substring
    substrs[numSubstrs] = malloc(strlen(token) + 1);

    // Copy the substring into the array
    strcpy(substrs[numSubstrs], token);

    // Increment the number of substrings
    numSubstrs++;

    // Get the next substring
    token = strtok(NULL, delim);
  }

  // Return the array of substrings
  return substrs;
}

// Function to print an array of substrings
void printSubstrings(char **substrs) {
  // Iterate over the array of substrings
  for (int i = 0; i < 100; i++) {
    // Print the substring
    if (substrs[i] != NULL) {
      printf("%s\n", substrs[i]);
    }
  }
}

// Main function
int main() {
  // Get the input string from the user
  char str[100];
  printf("Enter a string: ");
  scanf("%s", str);

  // Get the delimiter from the user
  char delim[10];
  printf("Enter a delimiter: ");
  scanf("%s", delim);

  // Split the string into substrings
  char **substrs = splitString(str, delim);

  // Print the substrings
  printSubstrings(substrs);

  // Free the memory allocated for the array of substrings
  for (int i = 0; i < 100; i++) {
    if (substrs[i] != NULL) {
      free(substrs[i]);
    }
  }
  free(substrs);

  return 0;
}