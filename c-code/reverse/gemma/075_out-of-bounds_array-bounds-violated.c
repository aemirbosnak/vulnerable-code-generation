#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

int isPalindrome(char *str) {
  int length = strlen(str);
  for (int i = 0; i < length / 2; i++) {
    if (str[i] != str[length - 1 - i]) {
      return 0;
    }
  }
  return 1;
}

int main() {
  char str[BUFFER_SIZE];
  printf("Enter a string: ");
  scanf("%s", str);

  if (isPalindrome(str)) {
    printf("The string is a palindrome.\n");
  } else {
    printf("The string is not a palindrome.\n");
  }

  return 0;
}
