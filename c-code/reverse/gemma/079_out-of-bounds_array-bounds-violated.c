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

  if (strlen(str) > 1000) {
    printf("Error: String too long.\n");
    return 1;
  }

  for (i = 0; i < attempts; i++) {
    int isPalindrome = 1;
    int l = 0;
    int r = strlen(str) - 1;

    while (l < r) {
      if (str[l] != str[r]) {
        isPalindrome = 0;
      }
      l++;
      r--;
    }

    if (isPalindrome) {
      printf("The string is a palindrome.\n");
      return 0;
    } else {
      printf("Error: String is not a palindrome.\n");
    }

    if (attempts - 1 == 0) {
      printf("Sorry, no more attempts.\n");
      return 1;
    }
  }

  return 1;
}
