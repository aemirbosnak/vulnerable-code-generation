#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char str[1001];
  int i, attempts = 2;

  printf("Enter a string: ");
  scanf("%s", str);

  if (isPalindrome(str)) {
    printf("The string is a palindrome.\n");
  } else {
    printf("The string is not a palindrome.\n");
  }

  return 0;
}

int isPalindrome(char *str) {
  int len = strlen(str);
  int i;

  for (i = 0; i < len / 2; i++) {
    if (str[i] != str[len - 1 - i]) {
      return 0;
    }
  }

  return 1;
}
