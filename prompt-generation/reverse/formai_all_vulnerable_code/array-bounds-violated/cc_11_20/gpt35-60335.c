//FormAI DATASET v1.0 Category: String manipulation ; Style: ephemeral
#include <stdio.h>
#include <string.h>

int main() {

  // Welcome message
  printf("Welcome to my C String Manipulation program!\n");

  // Input string
  char input[50];
  printf("Please enter a string: ");
  scanf("%s", input);

  // Length of input string
  int length = strlen(input);
  printf("The length of your string is %d.\n", length);

  // Reverse the string
  char reversed[length];
  int i;
  for (i = 0; i < length; i++) {
    reversed[i] = input[length-i-1];
  }
  reversed[length] = '\0';
  printf("Your string reversed is: %s\n", reversed);

  // Check if the string is a palindrome
  int palindrome = 1;
  for (i = 0; i < length; i++) {
    if (input[i] != reversed[i]) {
      palindrome = 0;
      break;
    }
  }
  if (palindrome) {
    printf("Your string is a palindrome!\n");
  } else {
    printf("Your string is not a palindrome.\n");
  }

  // Modify the string to remove duplicate characters
  char modified[length];
  int j, k = 0;
  for (i = 0; i < length; i++) {
    int duplicate = 0;
    for (j = 0; j < k; j++) {
      if (input[i] == modified[j]) {
        duplicate = 1;
        break;
      }
    }
    if (!duplicate) {
      modified[k] = input[i];
      k++;
    }
  }
  modified[k] = '\0';
  printf("Your string with duplicate characters removed is: %s\n", modified);

  // Find the number of vowels in the string
  int vowels = 0;
  for (i = 0; i < length; i++) {
    if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u') {
      vowels++;
    }
  }
  printf("The number of vowels in your string is: %d\n", vowels);

  // Exit message
  printf("Thank you for using my C String Manipulation program!\n");

  return 0;
}