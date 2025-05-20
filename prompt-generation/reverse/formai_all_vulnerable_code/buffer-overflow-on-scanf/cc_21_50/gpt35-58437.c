//FormAI DATASET v1.0 Category: String manipulation ; Style: relaxed
#include <stdio.h>
#include <string.h>

int main() {
  // declare a string variable
  char str[100];

  // prompt user to enter a string
  printf("Enter a string: ");
  scanf("%s", str);

  // print the original string
  printf("Original String: %s\n", str);

  // reverse the string
  int len = strlen(str);
  for(int i = 0; i < len / 2; i++) {
    char temp = str[i];
    str[i] = str[len - i - 1];
    str[len - i - 1] = temp;
  }

  // print the reversed string
  printf("Reversed String: %s\n", str);

  // check if the string is a palindrome
  int isPalindrome = 1; // assume the string is a palindrome
  for(int i = 0; i < len / 2; i++) {
    if(str[i] != str[len - i - 1]) {
      isPalindrome = 0; // the string is not a palindrome
      break;
    }
  }

  // print whether the string is a palindrome or not
  if(isPalindrome) {
    printf("The string is a palindrome.\n");
  } else {
    printf("The string is not a palindrome.\n");
  }

  // count the number of vowels in the string
  int vowels = 0;
  for(int i = 0; i < len; i++) {
    char c = str[i];
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
       c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
      vowels++;
    }
  }

  // print the number of vowels in the string
  printf("Number of vowels: %d\n", vowels);

  // convert the string to uppercase
  for(int i = 0; i < len; i++) {
    if(str[i] >= 'a' && str[i] <= 'z') {
      str[i] = str[i] - 32; // subtract 32 from ASCII code to convert to uppercase
    }
  }

  // print the string in uppercase
  printf("Uppercase String: %s\n", str);

  // convert the string to lowercase
  for(int i = 0; i < len; i++) {
    if(str[i] >= 'A' && str[i] <= 'Z') {
      str[i] = str[i] + 32; // add 32 to ASCII code to convert to lowercase
    }
  }

  // print the string in lowercase
  printf("Lowercase String: %s\n", str);

  return 0;
}