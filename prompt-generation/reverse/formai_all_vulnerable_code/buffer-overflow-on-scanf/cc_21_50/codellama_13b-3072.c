//Code Llama-13B DATASET v1.0 Category: Text to ASCII art generator ; Style: shape shifting
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

void text_to_ascii_art(char *text, char *output) {
  int len = strlen(text);
  for (int i = 0; i < len; i++) {
    char c = text[i];
    switch (c) {
      case 'A':
        output[i] = ' /_\\ ';
        break;
      case 'B':
        output[i] = ' (0.0) ';
        break;
      case 'C':
        output[i] = ' (__) ';
        break;
      case 'D':
        output[i] = ' (___) ';
        break;
      case 'E':
        output[i] = ' 3|3 ';
        break;
      case 'F':
        output[i] = ' |)~( ';
        break;
      case 'G':
        output[i] = ' |-/ ';
        break;
      case 'H':
        output[i] = ' (|-|) ';
        break;
      case 'I':
        output[i] = ' (|) ';
        break;
      case 'J':
        output[i] = ' (/_/ ';
        break;
      case 'K':
        output[i] = ' |< ';
        break;
      case 'L':
        output[i] = ' (/_) ';
        break;
      case 'M':
        output[i] = ' ^^ ';
        break;
      case 'N':
        output[i] = ' >_< ';
        break;
      case 'O':
        output[i] = ' o.o ';
        break;
      case 'P':
        output[i] = ' |D ';
        break;
      case 'Q':
        output[i] = ' (,_,) ';
        break;
      case 'R':
        output[i] = ' |2 ';
        break;
      case 'S':
        output[i] = ' 4| ';
        break;
      case 'T':
        output[i] = ' (__) ';
        break;
      case 'U':
        output[i] = ' |_| ';
        break;
      case 'V':
        output[i] = ' /_/ ';
        break;
      case 'W':
        output[i] = ' |\\| ';
        break;
      case 'X':
        output[i] = ' >_< ';
        break;
      case 'Y':
        output[i] = ' |_| ';
        break;
      case 'Z':
        output[i] = ' 2/_2 ';
        break;
      case 'a':
        output[i] = ' /_/ ';
        break;
      case 'b':
        output[i] = ' (0.0) ';
        break;
      case 'c':
        output[i] = ' (__) ';
        break;
      case 'd':
        output[i] = ' (___) ';
        break;
      case 'e':
        output[i] = ' 3|3 ';
        break;
      case 'f':
        output[i] = ' |)~( ';
        break;
      case 'g':
        output[i] = ' |-/ ';
        break;
      case 'h':
        output[i] = ' (|-|) ';
        break;
      case 'i':
        output[i] = ' (|) ';
        break;
      case 'j':
        output[i] = ' (/_/ ';
        break;
      case 'k':
        output[i] = ' |< ';
        break;
      case 'l':
        output[i] = ' (/_) ';
        break;
      case 'm':
        output[i] = ' ^^ ';
        break;
      case 'n':
        output[i] = ' >_< ';
        break;
      case 'o':
        output[i] = ' o.o ';
        break;
      case 'p':
        output[i] = ' |D ';
        break;
      case 'q':
        output[i] = ' (,_,) ';
        break;
      case 'r':
        output[i] = ' |2 ';
        break;
      case 's':
        output[i] = ' 4| ';
        break;
      case 't':
        output[i] = ' (__) ';
        break;
      case 'u':
        output[i] = ' |_| ';
        break;
      case 'v':
        output[i] = ' /_/ ';
        break;
      case 'w':
        output[i] = ' |\\| ';
        break;
      case 'x':
        output[i] = ' >_< ';
        break;
      case 'y':
        output[i] = ' |_| ';
        break;
      case 'z':
        output[i] = ' 2/_2 ';
        break;
      default:
        output[i] = ' ';
        break;
    }
  }
}

int main() {
  char text[MAX_LEN];
  char output[MAX_LEN];
  printf("Enter text: ");
  scanf("%s", text);
  text_to_ascii_art(text, output);
  printf("%s\n", output);
  return 0;
}