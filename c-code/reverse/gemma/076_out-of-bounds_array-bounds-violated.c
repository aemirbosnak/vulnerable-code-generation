#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1024

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
  char str[MAX_LENGTH];
  scanf("%s", str);
  if (isPalindrome(str)) {
    printf("Palindrome!\n");
  } else {
    printf("Not a palindrome.\n");
  }
  return 0;
}
