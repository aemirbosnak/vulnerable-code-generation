//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

char *morse_code[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
  "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----",
  "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----", "|", ".-.-.-",
  "--..--", "..--..", "...-..-", "....-.."
};

char *morse_decode[] = {
  "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N",
  "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "0",
  "1", "2", "3", "4", "5", "6", "7", "8", "9", " ", "!", "/", "?", "&"
};

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <text>\n", argv[0]);
    return 1;
  }

  char *text = argv[1];
  int len = strlen(text);

  char *morse_code_string = malloc(len * 4);
  int morse_code_index = 0;

  for (int i = 0; i < len; i++) {
    char c = text[i];
    if (c >= 'A' && c <= 'Z') {
      c -= 'A';
    } else if (c >= 'a' && c <= 'z') {
      c -= 'a';
    } else if (c >= '0' && c <= '9') {
      c += 'A' - '0' - 10;
    } else if (c == ' ') {
      c = 36;
    } else if (c == '!') {
      c = 37;
    } else if (c == '/') {
      c = 38;
    } else if (c == '?') {
      c = 39;
    } else if (c == '&') {
      c = 40;
    } else {
      printf("Invalid character: %c\n", c);
      return 1;
    }

    strcpy(&morse_code_string[morse_code_index], morse_code[c]);
    morse_code_index += strlen(morse_code[c]);
    morse_code_string[morse_code_index++] = ' ';
  }

  printf("%s\n", morse_code_string);

  free(morse_code_string);

  return 0;
}