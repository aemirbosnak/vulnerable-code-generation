//Falcon2-11B DATASET v1.0 Category: Searching algorithm ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *search(char *str, char *search_str) {
  int len = strlen(str);
  int len_search = strlen(search_str);

  if (len == 0 || len_search == 0) {
    return NULL;
  }

  int i = 0;
  while (i < len) {
    int j = 0;
    while (j < len_search) {
      if (str[i] == search_str[j]) {
        if (j == len_search - 1) {
          return str + i - len_search + 1;
        } else {
          i++;
          j = 0;
        }
      }
      j++;
    }
    i++;
  }

  return NULL;
}

int main() {
  char str[100];
  char search_str[100];
  printf("Enter the string to search: ");
  fgets(str, sizeof(str), stdin);
  str[strcspn(str, "\n")] = 0;
  printf("Enter the search string: ");
  fgets(search_str, sizeof(search_str), stdin);
  search_str[strcspn(search_str, "\n")] = 0;

  char *result = search(str, search_str);
  if (result!= NULL) {
    printf("Found at index %d\n", (int) result - (int) str);
  } else {
    printf("Not found\n");
  }

  return 0;
}