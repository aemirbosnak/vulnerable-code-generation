//FormAI DATASET v1.0 Category: String manipulation ; Style: energetic
#include <stdio.h>
#include <string.h>

int main() {
  char string[100];
  int length;

  printf("Welcome to our string manipulation program!\n");
  printf("Enter a string: ");
  scanf("%[^\n]", string);

  length = strlen(string);

  printf("\nYour string has %d characters.\n\n", length);

  // Let's convert the first letter to uppercase and the rest to lowercase
  printf("Let's capitalize the first letter and put the rest in lowercase.\n");

  string[0] = toupper(string[0]);

  for (int i = 1; i < length; i++) {
    string[i] = tolower(string[i]);
  }

  printf("\nHere is your new string: %s\n", string);

  // Now, let's reverse the string
  printf("\nNow, let's reverse your string.\n");

  char reverse[100];

  for (int i = 0; i < length; i++) {
    reverse[i] = string[length - i - 1];
  }

  printf("\nHere is your reversed string: %s\n", reverse);

  // Finally, let's check if the string is a palindrome or not
  printf("\nLastly, let's check if your string is a palindrome.\n");

  int flag = 0;

  for (int i = 0; i < length/2; i++) {
    if (string[i] != string[length - i - 1]) {
      flag = 1;
      break;
    }
  }

  if (flag == 0) {
    printf("\nCongratulations! Your string is a palindrome!\n");
  } else {
    printf("\nSorry, your string is not a palindrome. Try again later!\n");
  }

  return 0;
}