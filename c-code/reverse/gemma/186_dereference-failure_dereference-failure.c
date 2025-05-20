#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

char *translate(char *alien) {
  char *english = malloc(strlen(alien) * 2);
  int i = 0;
  for (; alien[i] != '\0'; i++) {
    switch (alien[i]) {
      case 'a':
        english[i] = 'a';
        break;
      case 'b':
        english[i] = 'b';
        break;
      case 'c':
        english[i] = 'c';
        break;
      case 'd':
        english[i] = 'd';
        break;
      case 'e':
        english[i] = 'e';
        break;
      default:
        english[i] = alien[i];
    }
  }
  english[i] = '\0';
  return english;
}

int main() {
  char *alien = "abc";
  char *english = translate(alien);
  printf("%s", english);
  free(english);
  return 0;
}
