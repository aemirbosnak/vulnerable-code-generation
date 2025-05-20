//FormAI DATASET v1.0 Category: String manipulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char input[100];
  char reversed[100];
  int length, i, j;

  printf("Welcome to the String Reversal Program!\n");
  printf("Please enter a string to be reversed: ");
  scanf("%s", input);

  length = strlen(input);

  for(i = 0; i < length; i++) {
    reversed[i] = input[length - 1 - i];
  }
  reversed[length] = '\0';

  printf("\nThe reversed string is: %s\n", reversed);

  printf("\nBut that's not all!\n");
  printf("We can also convert your string to all uppercase or lowercase.\n");
  printf("Would you like to convert your string to uppercase (U) or lowercase (L)? ");
  char choice;
  scanf(" %c", &choice);

  if(choice == 'U') {
    for(i = 0; i < length; i++) {
      if(input[i] >= 'a' && input[i] <= 'z') {
        input[i] = input[i] - 32;
      }
    }
    printf("\nThe uppercase string is: %s\n", input);
  }
  else if(choice == 'L') {
    for(i = 0; i < length; i++) {
      if(input[i] >= 'A' && input[i] <= 'Z') {
        input[i] = input[i] + 32;
      }
    }
    printf("\nThe lowercase string is: %s\n", input);
  }
  else {
    printf("\nInvalid choice.\n");
  }

  printf("\nThank you for using the String Reversal Program. Goodbye!\n");

  return 0;
}