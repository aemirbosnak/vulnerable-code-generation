//Gemma-7B DATASET v1.0 Category: Text processing ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char buf[1000], c;
  int i = 0, n, repeat = 0, state = 0;

  printf("Enter a text: ");
  gets(buf);

  n = strlen(buf);
  for (i = 0; i < n; i++) {
    c = buf[i];
    switch (state) {
      case 0:
        if (c >= 'a' && c <= 'z') {
          repeat = 1;
          state = 1;
        } else if (c >= 'A' && c <= 'Z') {
          repeat = 1;
          state = 2;
        } else if (c == ' ') {
          repeat = 0;
          state = 0;
        }
        break;
      case 1:
        if (c >= 'a' && c <= 'z') {
          repeat = 2;
        } else if (c >= 'A' && c <= 'Z') {
          repeat = 2;
        } else if (c == ' ') {
          repeat = 0;
          state = 0;
        }
        break;
      case 2:
        if (c >= 'a' && c <= 'z') {
          repeat = 3;
        } else if (c >= 'A' && c <= 'Z') {
          repeat = 3;
        } else if (c == ' ') {
          repeat = 0;
          state = 0;
        }
        break;
    }

    if (repeat) {
      printf("%c repeated %d time(s) ", c, repeat);
    }
  }

  printf("\n");

  return 0;
}