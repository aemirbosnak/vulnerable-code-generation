//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *str = "The quick brown fox jumped over the lazy dog.";
  int len = strlen(str);
  char *new_str = malloc(sizeof(char) * (len+1));
  for (int i = 0; i < len; i++) {
    new_str[i] = str[len-1-i];
  }
  new_str[len] = '\0';
  printf("%s\n", new_str);

  // Find the first occurrence of a character in a string
  char *chr = strchr(str, 'f');
  if (chr != NULL) {
    printf("The first occurrence of 'f' is at index %d.\n", chr-str);
  } else {
    printf("The character 'f' is not found.\n");
  }

  // Find the last occurrence of a character in a string
  chr = strrchr(str, 'o');
  if (chr != NULL) {
    printf("The last occurrence of 'o' is at index %d.\n", chr-str);
  } else {
    printf("The character 'o' is not found.\n");
  }

  // Find the number of occurrences of a character in a string
  int count = 0;
  for (int i = 0; i < len; i++) {
    if (str[i] == 'e') {
      count++;
    }
  }
  printf("The number of occurrences of 'e' is %d.\n", count);

  // Convert a string to uppercase
  for (int i = 0; i < len; i++) {
    str[i] = toupper(str[i]);
  }
  printf("The string in uppercase is %s.\n", str);

  // Convert a string to lowercase
  for (int i = 0; i < len; i++) {
    str[i] = tolower(str[i]);
  }
  printf("The string in lowercase is %s.\n", str);

  // Trim whitespace from a string
  char *trimmed_str = malloc(sizeof(char) * (len+1));
  int j = 0;
  for (int i = 0; i < len; i++) {
    if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n') {
      trimmed_str[j++] = str[i];
    }
  }
  trimmed_str[j] = '\0';
  printf("The trimmed string is %s.\n", trimmed_str);

  return 0;
}