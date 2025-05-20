//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A function to reverse a string
char *reverse(char *str) {
  char *p1, *p2;
  if (!str || !*str)
    return str;
  for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2) {
    *p1 ^= *p2;
    *p2 ^= *p1;
    *p1 ^= *p2;
  }
  return str;
}

// A function to remove all vowels from a string
char *remove_vowels(char *str) {
  char *p, *q;
  for (p = q = str; *p; ++p) {
    if (*p != 'a' && *p != 'e' && *p != 'i' && *p != 'o' && *p != 'u' && *p != 'A' && *p != 'E' &&
        *p != 'I' && *p != 'O' && *p != 'U') {
      *q++ = *p;
    }
  }
  *q = '\0';
  return str;
}

// A function to count the number of words in a string
int count_words(char *str) {
  int count = 0;
  char *p;
  for (p = str; *p; ++p) {
    if (*p == ' ' || *p == '\t' || *p == '\n')
      count++;
  }
  return count + 1;
}

int main() {
  char str[100];
  printf("Enter a string: ");
  scanf("%s", str);

  printf("Reversed string: %s\n", reverse(str));
  printf("String without vowels: %s\n", remove_vowels(str));
  printf("Number of words in the string: %d\n", count_words(str));

  return 0;
}