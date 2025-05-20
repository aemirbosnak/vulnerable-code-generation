//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Cryptic
#include <stdio.h>
#include <string.h>

void translate(char word[]) {
  int i;
  for (i = 0; word[i] != '\0'; i++) {
    
    if (word[i] == 'A') {
      printf("+_*");
    }
    else if (word[i] == 'B') {
      printf("*_+");
    }
    else if (word[i] == 'C') {
      printf("==^");
    }
    else if (word[i] == 'D') {
      printf("<.='");
    }
    else if (word[i] == 'E') {
      printf(")>_>");
    }
    else if (word[i] == 'F') {
      printf("=___");
    }
    else if (word[i] == 'G') {
      printf("(  .)");
    }
    else if (word[i] == 'H') {
      printf("^(oo)^");
    }
    else if (word[i] == 'I') {
      printf(")=w=");
    }
    else if (word[i] == 'J') {
      printf("[^_^]");
    }
    else if (word[i] == 'K') {
      printf("(* *))");
    }
    else if (word[i] == 'L') {
      printf("/|__|\\");
    }
    else if (word[i] == 'M') {
      printf("(,,)(,,)");
    }
    else if (word[i] == 'N') {
      printf("*)__(*");
    }
    else if (word[i] == 'O') {
      printf("(___)");
    }
    else if (word[i] == 'P') {
      printf("{*v*}");
    }
    else if (word[i] == 'Q') {
      printf("<~__~>");
    }
    else if (word[i] == 'R') {
      printf("^_^/");
    }
    else if (word[i] == 'S') {
      printf("(><)");
    }
    else if (word[i] == 'T') {
      printf("+_+");
    }
    else if (word[i] == 'U') {
      printf("(@_@)");
    }
    else if (word[i] == 'V') {
      printf("V_v");
    }
    else if (word[i] == 'W') {
      printf("(o)(o)");
    }
    else if (word[i] == 'X') {
      printf("(*o*)");
    }
    else if (word[i] == 'Y') {
      printf("@=@");
    }
    else if (word[i] == 'Z') {
      printf(">-<");
    }
    else {
      printf("%c", word[i]);
    }
  }
}

int main() {
  char input[100];
  printf("Please enter a word to translate: ");
  scanf("%s", input);
  printf("Translation: ");
  translate(input);
  printf("\n");
  return 0;
}