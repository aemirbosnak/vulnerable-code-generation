#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

char *translate(char *alien_str) {
  int alien_len = strlen(alien_str);
  char *english_str = malloc((alien_len + 1) * sizeof(char));

  for (int i = 0; i < alien_len; i++) {
    if (alien_str[i] >= 'a' && alien_str[i] <= 'z') {
      english_str[i] = alien_str[i] - 32;
    } else {
      english_str[i] = alien_str[i];
    }
  }

  english_str[alien_len] = '\0';

  return english_str;
}

int main() {
  char *alien_str = "xyz";
  char *english_str = translate(alien_str);

  printf("%s", english_str);

  free(english_str);

  return 0;
}
