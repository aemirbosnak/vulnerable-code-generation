//FormAI DATASET v1.0 Category: Text processing ; Style: shape shifting
#include <stdio.h>
#include <string.h>

char alternatingCase(char c) {
  if (c >= 'A' && c <= 'Z')
    return c + ('a' - 'A');
  else if (c >= 'a' && c <= 'z')
    return c - ('a' - 'A');
  else
    return c;
}

void reverseWords(char *s) {
  int len = strlen(s);
  int start = 0, end = len - 1;
  
  // reverse entire string
  while (start < end) {
    char temp = s[start];
    s[start] = s[end];
    s[end] = temp;
    start++;
    end--;
  }

  start = 0;
  end = 0;

  // reverse individual words
  while (end <= len) {
    if (s[end] == ' ' || s[end] == '\0') {
      int word_end = end - 1;
      while (start < word_end) {
        char temp = s[start];
        s[start] = s[word_end];
        s[word_end] = temp;
        start++;
        word_end--;
      }
      start = end + 1;
    }
    end++;
  }
}

int main() {
  char input[100];

  printf("Enter a string: ");
  fgets(input, 100, stdin);

  int len = strlen(input);

  // remove trailing newline
  if (input[len - 1] == '\n')
    input[len - 1] = '\0';

  // shift each character by its index position
  for (int i = 0; i < len; i++) {
    char c = input[i];
    c += i;
    input[i] = alternatingCase(c);
  }

  reverseWords(input);

  printf("Processed string: %s\n", input);

  return 0;
}