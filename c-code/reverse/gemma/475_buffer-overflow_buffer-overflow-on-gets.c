#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char search_str[100], replace_str[100], output[100];
  int search_len, replace_len, i, j, found = 0;

  printf("Enter the search string: ");
  gets(search_str);

  printf("Enter the replacement string: ");
  gets(replace_str);

  search_len = strlen(search_str);
  replace_len = strlen(replace_str);

  for (i = 0; i < search_len; i++) {
    for (j = 0; j < replace_len; j++) {
      if (search_str[i] == replace_str[j]) {
        found = 1;
        break;
      }
    }

    if (found) {
      output[i] = replace_str[j];
    } else {
      output[i] = search_str[i];
    }

    found = 0;
  }

  output[search_len] = '\0';

  printf("The modified string is: \n");
  printf("%s\n", output);

  return 0;
}
