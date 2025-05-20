//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to print a cheerful message
void print_cheerful_message() {
  printf("Hello, world! I'm so happy to be here!\n");
}

// Function to count the number of vowels in a string
int count_vowels(char *string) {
  int count = 0;
  for (int i = 0; i < strlen(string); i++) {
    char c = string[i];
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
      count++;
    }
  }
  return count;
}

// Function to replace all the vowels in a string with the letter 'a'
char *replace_vowels_with_a(char *string) {
  for (int i = 0; i < strlen(string); i++) {
    char c = string[i];
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
      string[i] = 'a';
    }
  }
  return string;
}

// Main function
int main() {
  // Print a cheerful message
  print_cheerful_message();

  // Get a string from the user
  char string[100];
  printf("Enter a string: ");
  scanf("%s", string);

  // Count the number of vowels in the string
  int vowel_count = count_vowels(string);
  printf("The string \"%s\" contains %d vowels.\n", string, vowel_count);

  // Replace all the vowels in the string with the letter 'a'
  char *new_string = replace_vowels_with_a(string);
  printf("The new string is: %s\n", new_string);

  return 0;
}