//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void trans(char **a) {
  int i = 0;
  char b[20] = "";
  while (*a[i] != '\0') {
    switch (*a[i]) {
      case 'a':
        b[i] = 'a';
        break;
      case 'b':
        b[i] = 'b';
        break;
      case 'c':
        b[i] = 'c';
        break;
      case 'd':
        b[i] = 'd';
        break;
      case 'e':
        b[i] = 'e';
        break;
      case 'f':
        b[i] = 'f';
        break;
      case 'g':
        b[i] = 'g';
        break;
      case 'h':
        b[i] = 'h';
        break;
      case 'i':
        b[i] = 'i';
        break;
      case 'j':
        b[i] = 'j';
        break;
      case 'k':
        b[i] = 'k';
        break;
      case 'l':
        b[i] = 'l';
        break;
      case 'm':
        b[i] = 'm';
        break;
      case 'n':
        b[i] = 'n';
        break;
      case 'o':
        b[i] = 'o';
        break;
      case 'p':
        b[i] = 'p';
        break;
      case 'q':
        b[i] = 'q';
        break;
      case 'r':
        b[i] = 'r';
        break;
      case 's':
        b[i] = 's';
        break;
      case 't':
        b[i] = 't';
        break;
      case 'u':
        b[i] = 'u';
        break;
      case 'v':
        b[i] = 'v';
        break;
      case 'w':
        b[i] = 'w';
        break;
      case 'x':
        b[i] = 'x';
        break;
      case 'y':
        b[i] = 'y';
        break;
      case 'z':
        b[i] = 'z';
        break;
    }
    i++;
  }
  b[i] = '\0';
  *a = strdup(b);
}

int main() {
  char *a = malloc(10);
  a = "Hello, world!";
  trans(&a);
  printf("%s", a);
  free(a);
  return 0;
}