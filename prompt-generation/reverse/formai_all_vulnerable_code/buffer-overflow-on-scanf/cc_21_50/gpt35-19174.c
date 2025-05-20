//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: future-proof
#include <stdio.h>
#include <string.h>

int main() {
  char phrase[1000];
  printf("Enter a phrase in C Cat Language: \n");
  scanf("%[^\n]", phrase);

  int i = 0;
  int phrase_length = strlen(phrase);

  for (i = 0; i < phrase_length; i++) {
    // Check for various C Cat keywords
    if (phrase[i] == 'm' && phrase[i+1] == 'e' && phrase[i+2] == 'o') {
      printf("int ");
      i += 2;
    } else if (phrase[i] == 'e' && phrase[i+1] == 'a' && phrase[i+2] == 't') {
      printf("return ");
      i += 2;
    } else if (phrase[i] == 'p' && phrase[i+1] == 'u' && phrase[i+2] == 'r' && phrase[i+3] == 'r') {
      printf("printf(");
      i += 3;
    } else if (phrase[i] == 'h' && phrase[i+1] == 'i' && phrase[i+2] == 's') {
      printf("if ");
      i += 2;
    } else if (phrase[i] == 'm' && phrase[i+1] == 'o' && phrase[i+2] == 'w') {
      printf("while ");
      i += 2;
    } else if (phrase[i] == 's' && phrase[i+1] == 'e' && phrase[i+2] == 'l' && phrase[i+3] == 'f') {
      printf("else if ");
      i += 3;
    } else if (phrase[i] == 'm' && phrase[i+1] == 'i' && phrase[i+2] == 'a' && phrase[i+3] == 'u') {
      printf("main() {");
      i += 3;
    } else if (phrase[i] == 'c' && phrase[i+1] == 'a' && phrase[i+2] == 't') {
      printf("+");
      i += 2;
    } else if (phrase[i] == 'd' && phrase[i+1] == 'o' && phrase[i+2] == 'g') {
      printf("-");
      i += 2;
    } else if (phrase[i] == 'w' && phrase[i+1] == 'h' && phrase[i+2] == 'i' && phrase[i+3] == 't' && phrase[i+4] == 'e') {
      printf("while (1) {");
      i += 4;
    } else {
      printf("%c", phrase[i]);
    }
  }

  return 0;
}