//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: futuristic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the maximum length of the input string
#define MAX_STRING_LENGTH 100

// Define the error codes
#define ERR_INVALID_INPUT -1
#define ERR_NON_ALPHA_CHAR -2
#define ERR_EMPTY_STRING -3

// Function to check if the input string is a palindrome
int is_palindrome(char *str) {
  // Check if the input string is valid
  if (str == NULL || strlen(str) == 0) {
    return ERR_INVALID_INPUT;
  }

  // Check if the input string contains only alphabetic characters
  for (int i = 0; i < strlen(str); i++) {
    if (!isalpha(str[i])) {
      return ERR_NON_ALPHA_CHAR;
    }
  }

  // Convert the input string to lowercase
  for (int i = 0; i < strlen(str); i++) {
    str[i] = tolower(str[i]);
  }

  // Check if the input string is a palindrome
  int i = 0;
  int j = strlen(str) - 1;
  while (i < j) {
    if (str[i] != str[j]) {
      return 0;
    }
    i++;
    j--;
  }

  return 1;
}

// Function to get the input string from the user
char *get_input_string() {
  // Allocate memory for the input string
  char *str = (char *)malloc(MAX_STRING_LENGTH * sizeof(char));

  // Get the input string from the user
  printf("Enter a string: ");
  scanf("%s", str);

  // Return the input string
  return str;
}

// Function to print the result
void print_result(int result) {
  // Print the result
  if (result == 1) {
    printf("The input string is a palindrome.\n");
  } else if (result == 0) {
    printf("The input string is not a palindrome.\n");
  } else {
    printf("An error occurred while checking the input string.\n");
  }
}

// Main function
int main() {
  // Get the input string from the user
  char *str = get_input_string();

  // Check if the input string is a palindrome
  int result = is_palindrome(str);

  // Print the result
  print_result(result);

  // Free the memory allocated for the input string
  free(str);

  return 0;
}