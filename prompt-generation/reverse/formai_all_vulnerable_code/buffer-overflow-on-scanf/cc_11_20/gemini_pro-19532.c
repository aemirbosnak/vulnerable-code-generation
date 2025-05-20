//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Initialize an empty string
  char str[100] = "";

  // Get input from the user
  printf("Enter a string: ");
  scanf("%s", str);

  // Get the length of the string
  int len = strlen(str);

  // Reverse the string
  for (int i = 0; i < len / 2; i++) {
    char temp = str[i];
    str[i] = str[len - i - 1];
    str[len - i - 1] = temp;
  }

  // Print the reversed string
  printf("Reversed string: %s\n", str);

  // Find the longest word in the string
  char *longest_word = NULL;
  int longest_word_len = 0;
  char *curr_word = strtok(str, " ");
  while (curr_word != NULL) {
    int curr_word_len = strlen(curr_word);
    if (curr_word_len > longest_word_len) {
      longest_word = curr_word;
      longest_word_len = curr_word_len;
    }
    curr_word = strtok(NULL, " ");
  }

  // Print the longest word
  printf("Longest word: %s\n", longest_word);

  // Count the number of vowels in the string
  int vowel_count = 0;
  for (int i = 0; i < len; i++) {
    char ch = str[i];
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
        ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
      vowel_count++;
    }
  }

  // Print the number of vowels
  printf("Number of vowels: %d\n", vowel_count);

  // Check if the string is a palindrome
  int is_palindrome = 1;
  for (int i = 0; i < len / 2; i++) {
    if (str[i] != str[len - i - 1]) {
      is_palindrome = 0;
      break;
    }
  }

  // Print if the string is a palindrome
  if (is_palindrome) {
    printf("The string is a palindrome\n");
  } else {
    printf("The string is not a palindrome\n");
  }

  return 0;
}