#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

char *translate(char *alien_str) {
  int alien_len = strlen(alien_str) + 1;
  char *english_str = malloc(alien_len);

  if (english_str == NULL) {
    return NULL;
  }

  for (int i = 0; i < alien_len; i++) {
    switch (alien_str[i]) {
      case 'a':
        english_str[i] = 'a';
        break;
      case 'b':
        english_str[i] = 'b';
        break;
      case 'c':
        english_str[i] = 'c';
        break;
      case 'd':
        english_str[i] = 'd';
        break;
      case 'e':
        english_str[i] = 'e';
        break;
      default:
        english_str[i] = alien_str[i];
    }
  }

  return english_str;
}

int main() {
  char *alien_str = "abc";
  char *english_str = translate(alien_str);

  if (english_str) {
    printf("%s", english_str);
  } else {
    printf("Error allocating memory");
  }

  return 0;
}
