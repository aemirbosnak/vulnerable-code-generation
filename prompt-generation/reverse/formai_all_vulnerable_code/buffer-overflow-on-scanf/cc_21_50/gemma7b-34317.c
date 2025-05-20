//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char text_to_ascii(char letter) {
  switch (letter) {
    case 'a':
    case 'A':
      return 97;
    case 'b':
    case 'B':
      return 98;
    case 'c':
    case 'C':
      return 99;
    case 'd':
    case 'D':
      return 100;
    case 'e':
    case 'E':
      return 101;
    case 'f':
    case 'F':
      return 102;
    case 'g':
    case 'G':
      return 103;
    case 'h':
    case 'H':
      return 104;
    case 'i':
    case 'I':
      return 105;
    case 'j':
    case 'J':
      return 106;
    case 'k':
    case 'K':
      return 107;
    case 'l':
    case 'L':
      return 108;
    case 'm':
    case 'M':
      return 109;
    case 'n':
    case 'N':
      return 110;
    case 'o':
    case 'O':
      return 111;
    case 'p':
    case 'P':
      return 112;
    case 'q':
    case 'Q':
      return 113;
    case 'r':
    case 'R':
      return 114;
    case 's':
    case 'S':
      return 115;
    case 't':
    case 'T':
      return 116;
    case 'u':
    case 'U':
      return 117;
    case 'v':
    case 'V':
      return 118;
    case 'w':
    case 'W':
      return 119;
    case 'x':
    case 'X':
      return 120;
    case 'y':
    case 'Y':
      return 121;
    case 'z':
    case 'Z':
      return 122;
    default:
      return 0;
  }
}

int main() {
  char text[100];
  printf("Enter text: ");
  scanf("%s", text);

  int i = 0;
  for (i = 0; text[i] != '\0'; i++) {
    char letter = text[i];
    int ascii_value = text_to_ascii(letter);
    printf("%c ", ascii_value);
  }

  printf("\n");

  return 0;
}