#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char str[100];
  char substr[100];
  char rep[100];

  printf("Enter a string: ");
  scanf("%s", str);

  printf("Enter a substring to search for: ");
  scanf("%s", substr);

  printf("Enter a replacement string: ");
  scanf("%s", rep);

  int len_str = strlen(str);
  int len_substr = strlen(substr);
  int len_rep = strlen(rep);

  char *ptr = str;
  int i = 0;
  int found = 0;

  while (i < len_str) {
    if (strncmp(ptr, substr, len_substr) == 0) {
      found = 1;
      int j = 0;
      char *ptr_rep = rep;
      while (j < len_rep) {
        *(ptr + i) = *ptr_rep;
        j++;
        ptr_rep++;
      }
      i += len_rep - 1;
    } else {
      ptr++;
    }
  }

  if (found) {
    printf("The string after replacement is: %s\n", str);
  } else {
    printf("The substring was not found.\n");
  }

  return 0;
}
