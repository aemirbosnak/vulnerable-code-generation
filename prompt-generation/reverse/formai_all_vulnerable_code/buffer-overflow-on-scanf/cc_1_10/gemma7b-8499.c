//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
  char str[1000];
  printf("Enter a message: ");
  scanf("%s", str);

  int i, flag = 0;
  for (i = 0; str[i] != '\0'; i++) {
    // Check for uppercase letters
    if (isupper(str[i])) {
      flag = 1;
    }

    // Check for exclamation marks
    if (str[i] == '!') {
      flag = 1;
    }

    // Check for dollar signs
    if (str[i] == '$') {
      flag = 1;
    }

    // Check for special characters
    if (!isalnum(str[i])) {
      flag = 1;
    }

    // Check for repeated words
    char word[20];
    int count = 0;
    for (int j = i; str[j] != '\0' && str[j] == str[i]; j++) {
      word[count++] = str[j];
    }
    if (count > 1) {
      flag = 1;
    }
  }

  if (flag) {
    printf("Your message contains spam-like content.\n");
  } else {
    printf("Your message does not contain any spam-like content.\n");
  }

  return 0;
}