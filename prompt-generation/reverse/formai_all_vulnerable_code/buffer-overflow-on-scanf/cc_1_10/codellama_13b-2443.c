//Code Llama-13B DATASET v1.0 Category: String manipulation ; Style: scalable
// scalable string manipulation example program
#include <stdio.h>
#include <string.h>

// prototype for custom string functions
void str_reverse(char *str);
void str_uppercase(char *str);
void str_lowercase(char *str);

// main program
int main() {
  // define variables
  char str[100];

  // get input from user
  printf("Enter a string: ");
  scanf("%s", str);

  // reverse string
  str_reverse(str);
  printf("Reversed string: %s\n", str);

  // convert to uppercase
  str_uppercase(str);
  printf("Uppercase string: %s\n", str);

  // convert to lowercase
  str_lowercase(str);
  printf("Lowercase string: %s\n", str);

  return 0;
}

// custom string functions
void str_reverse(char *str) {
  int i, j;
  char temp;

  // reverse the string
  for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
  }
}

void str_uppercase(char *str) {
  int i;

  // convert to uppercase
  for (i = 0; i < strlen(str); i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      str[i] = str[i] - 32;
    }
  }
}

void str_lowercase(char *str) {
  int i;

  // convert to lowercase
  for (i = 0; i < strlen(str); i++) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      str[i] = str[i] + 32;
    }
  }
}