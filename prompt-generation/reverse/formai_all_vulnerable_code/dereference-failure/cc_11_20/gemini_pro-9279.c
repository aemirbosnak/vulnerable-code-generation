//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

char *alien_to_human(char *alien) {
  char *human = malloc(MAX_LEN);
  int i, j;
  for (i = 0, j = 0; alien[i] != '\0'; i++) {
    switch (alien[i]) {
      case 'a':
        human[j++] = 'z';
        break;
      case 'b':
        human[j++] = 'y';
        break;
      case 'c':
        human[j++] = 'x';
        break;
      case 'd':
        human[j++] = 'w';
        break;
      case 'e':
        human[j++] = 'v';
        break;
      case 'f':
        human[j++] = 'u';
        break;
      case 'g':
        human[j++] = 't';
        break;
      case 'h':
        human[j++] = 's';
        break;
      case 'i':
        human[j++] = 'r';
        break;
      case 'j':
        human[j++] = 'q';
        break;
      case 'k':
        human[j++] = 'p';
        break;
      case 'l':
        human[j++] = 'o';
        break;
      case 'm':
        human[j++] = 'n';
        break;
      case 'n':
        human[j++] = 'm';
        break;
      case 'o':
        human[j++] = 'l';
        break;
      case 'p':
        human[j++] = 'k';
        break;
      case 'q':
        human[j++] = 'j';
        break;
      case 'r':
        human[j++] = 'i';
        break;
      case 's':
        human[j++] = 'h';
        break;
      case 't':
        human[j++] = 'g';
        break;
      case 'u':
        human[j++] = 'f';
        break;
      case 'v':
        human[j++] = 'e';
        break;
      case 'w':
        human[j++] = 'd';
        break;
      case 'x':
        human[j++] = 'c';
        break;
      case 'y':
        human[j++] = 'b';
        break;
      case 'z':
        human[j++] = 'a';
        break;
      default:
        human[j++] = alien[i];
        break;
    }
  }
  human[j] = '\0';
  return human;
}

int main() {
  char *alien = "hello world";
  char *human = alien_to_human(alien);
  printf("%s\n", human);
  return 0;
}