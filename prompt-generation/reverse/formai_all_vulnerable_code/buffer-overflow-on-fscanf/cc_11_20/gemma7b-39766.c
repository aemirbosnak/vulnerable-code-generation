//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
  char str[200];
  int i, j, flag = 0;
  printf("Enter a word: ");
  gets(str);

  for (i = 0; str[i] != '\0'; i++) {
    if (!isalnum(str[i])) {
      flag = 1;
      break;
    }
  }

  if (flag) {
    printf("Error: Invalid input.\n");
  } else {
    for (j = 0; str[j] != '\0'; j++) {
      str[j] = tolower(str[j]);
    }

    int word_length = 0;
    for (i = 0; str[i] != '\0'; i++) {
      word_length++;
    }

    char dictionary[1000][20];
    int dictionary_size = 0;

    // Read the dictionary
    FILE *fp = fopen("dictionary.txt", "r");
    if (fp) {
      while (fscanf(fp, "%s", dictionary[dictionary_size]) != EOF) {
        dictionary_size++;
      }
      fclose(fp);
    }

    flag = 0;
    for (i = 0; dictionary_size > i; i++) {
      if (strcmp(str, dictionary[i]) == 0) {
        flag = 1;
        break;
      }
    }

    if (flag) {
      printf("Word found: %s\n", str);
    } else {
      printf("Word not found.\n");
    }
  }

  return 0;
}