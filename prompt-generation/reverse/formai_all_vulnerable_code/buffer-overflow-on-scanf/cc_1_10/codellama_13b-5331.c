//Code Llama-13B DATASET v1.0 Category: Text to ASCII art generator ; Style: Alan Turing
// C Text to ASCII art generator program
#include <stdio.h>
#include <string.h>

int main() {
  char text[100];
  printf("Enter a text to convert: ");
  scanf("%s", text);

  int len = strlen(text);
  for (int i = 0; i < len; i++) {
    int ascii = (int)text[i];
    if (ascii >= 97 && ascii <= 122) {
      // Lowercase letters
      int offset = ascii - 97;
      printf("%c%c%c%c%c%c\n", ' ', ' ', ' ', ' ', ' ', ' ');
      printf("%c%c%c%c%c%c\n", ' ', ' ', ' ', ' ', ' ', ' ');
      printf("%c%c%c%c%c%c\n", ' ', ' ', ' ', ' ', ' ', ' ');
      printf("%c%c%c%c%c%c\n", ' ', ' ', ' ', ' ', ' ', ' ');
      printf("%c%c%c%c%c%c\n", ' ', ' ', ' ', ' ', ' ', ' ');
      printf("%c%c%c%c%c%c\n", ' ', ' ', ' ', ' ', ' ', ' ');
    } else if (ascii >= 65 && ascii <= 90) {
      // Uppercase letters
      int offset = ascii - 65;
      printf("%c%c%c%c%c%c\n", ' ', ' ', ' ', ' ', ' ', ' ');
      printf("%c%c%c%c%c%c\n", ' ', ' ', ' ', ' ', ' ', ' ');
      printf("%c%c%c%c%c%c\n", ' ', ' ', ' ', ' ', ' ', ' ');
      printf("%c%c%c%c%c%c\n", ' ', ' ', ' ', ' ', ' ', ' ');
      printf("%c%c%c%c%c%c\n", ' ', ' ', ' ', ' ', ' ', ' ');
      printf("%c%c%c%c%c%c\n", ' ', ' ', ' ', ' ', ' ', ' ');
    } else if (ascii >= 48 && ascii <= 57) {
      // Numbers
      int offset = ascii - 48;
      printf("%c%c%c%c%c%c\n", ' ', ' ', ' ', ' ', ' ', ' ');
      printf("%c%c%c%c%c%c\n", ' ', ' ', ' ', ' ', ' ', ' ');
      printf("%c%c%c%c%c%c\n", ' ', ' ', ' ', ' ', ' ', ' ');
      printf("%c%c%c%c%c%c\n", ' ', ' ', ' ', ' ', ' ', ' ');
      printf("%c%c%c%c%c%c\n", ' ', ' ', ' ', ' ', ' ', ' ');
      printf("%c%c%c%c%c%c\n", ' ', ' ', ' ', ' ', ' ', ' ');
    } else if (ascii == 32) {
      // Space
      printf("%c%c%c%c%c%c\n", ' ', ' ', ' ', ' ', ' ', ' ');
      printf("%c%c%c%c%c%c\n", ' ', ' ', ' ', ' ', ' ', ' ');
      printf("%c%c%c%c%c%c\n", ' ', ' ', ' ', ' ', ' ', ' ');
      printf("%c%c%c%c%c%c\n", ' ', ' ', ' ', ' ', ' ', ' ');
      printf("%c%c%c%c%c%c\n", ' ', ' ', ' ', ' ', ' ', ' ');
      printf("%c%c%c%c%c%c\n", ' ', ' ', ' ', ' ', ' ', ' ');
    } else {
      // Other characters
      printf("%c%c%c%c%c%c\n", ' ', ' ', ' ', ' ', ' ', ' ');
      printf("%c%c%c%c%c%c\n", ' ', ' ', ' ', ' ', ' ', ' ');
      printf("%c%c%c%c%c%c\n", ' ', ' ', ' ', ' ', ' ', ' ');
      printf("%c%c%c%c%c%c\n", ' ', ' ', ' ', ' ', ' ', ' ');
      printf("%c%c%c%c%c%c\n", ' ', ' ', ' ', ' ', ' ', ' ');
      printf("%c%c%c%c%c%c\n", ' ', ' ', ' ', ' ', ' ', ' ');
    }
  }
  return 0;
}