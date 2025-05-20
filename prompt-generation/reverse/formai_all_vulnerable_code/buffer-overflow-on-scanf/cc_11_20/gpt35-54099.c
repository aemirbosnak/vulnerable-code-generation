//FormAI DATASET v1.0 Category: Syntax parsing ; Style: medieval
#include <stdio.h>

int main() {
  printf("Hark! Gathering input from thine keyboard...\n");
  char input[50];
  scanf("%s", input);
  printf("Parsing thy input with great care, sire...\n");

  int curlyBraces = 0;
  int parentheses = 0;
  int brackets = 0;
  int quotes = 0;
  int singleQuotes = 0;
  int comments = 0;

  for (int i = 0; input[i] != '\0'; i++) {
    char currentChar = input[i];
    switch (currentChar) {
      case '{':
        curlyBraces++;
        break;
      case '}':
        curlyBraces--;
        break;
      case '(':
        parentheses++;
        break;
      case ')':
        parentheses--;
        break;
      case '[':
        brackets++;
        break;
      case ']':
        brackets--;
        break;
      case '"':
        quotes++;
        break;
      case '\'':
        singleQuotes++;
        break;
      case '/':
        if (input[i+1] == '*') {
          comments++;
        }
        break;
      case '*':
        if (input[i+1] == '/') {
          comments--;
        }
        break;
      default:
        break;
    }
  }

  if (curlyBraces != 0) {
    printf("Error, sire! Thou hath %d unclosed curly braces!\n", curlyBraces);
  }
  if (parentheses != 0) {
    printf("Error, sire! Thou hath %d unclosed parentheses!\n", parentheses);
  }
  if (brackets != 0) {
    printf("Error, sire! Thou hath %d unclosed brackets!\n", brackets);
  }
  if (quotes % 2 != 0) {
    printf("Error, sire! Thou hath %d unclosed quotes!\n", quotes);
  }
  if (singleQuotes % 2 != 0) {
    printf("Error, sire! Thou hath %d unclosed single quotes!\n", singleQuotes);
  }
  if (comments != 0) {
    printf("Error, sire! Thou hath %d unclosed comments!\n", comments);
  }

  printf("Thy input was parsed without error, sire!\n");
  return 0;
}