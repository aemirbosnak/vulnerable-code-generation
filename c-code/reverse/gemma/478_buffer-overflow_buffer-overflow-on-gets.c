#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char search_str[100], replace_str[100], output_str[100];
  int i, len_search, len_replace, len_output;

  printf("Enter the search string: ");
  gets(search_str);

  printf("Enter the replacement string: ");
  gets(replace_str);

  len_search = strlen(search_str);
  len_replace = strlen(replace_str);
  len_output = len_search + len_replace - 1;

  output_str[0] = '\0';
  for (i = 0; i < len_search; i++) {
    if (strcmp(search_str + i, replace_str) == 0) {
      memcpy(output_str + len_output, replace_str, len_replace);
      len_output += len_replace - 1;
    } else {
      output_str[i] = search_str[i];
    }
  }

  printf("The output string is: ");
  puts(output_str);

  return 0;
}
