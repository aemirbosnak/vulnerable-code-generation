//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: scalable
#include <stdio.h>
#include <string.h>

void translate(char word[], int length);

int main() {
  char word[100]; // Input word
  int length; // Length of input word

  printf("Enter a word: ");
  scanf("%s", word);

  length = strlen(word);

  translate(word, length);

  return 0;
}

void translate(char word[], int length) {
  int i;

  // Translate each character
  for (i = 0; i < length; i++) {
    if (word[i] == 'a') {
      printf("K");
    } else if (word[i] == 'b') {
      printf("Z");
    } else if (word[i] == 'c') {
      printf("M");
    } else if (word[i] == 'd') {
      printf("L");
    } else if (word[i] == 'e') {
      printf("H");
    } else if (word[i] == 'f') {
      printf("Q");
    } else if (word[i] == 'g') {
      printf("P");
    } else if (word[i] == 'h') {
      printf("U");
    } else if (word[i] == 'i') {
      printf("W");
    } else if (word[i] == 'j') {
      printf("Y");
    } else if (word[i] == 'k') {
      printf("V");
    } else if (word[i] == 'l') {
      printf("F");
    } else if (word[i] == 'm') {
      printf("A");
    } else if (word[i] == 'n') {
      printf("C");
    } else if (word[i] == 'o') {
      printf("R");
    } else if (word[i] == 'p') {
      printf("B");
    } else if (word[i] == 'q') {
      printf("E");
    } else if (word[i] == 'r') {
      printf("G");
    } else if (word[i] == 's') {
      printf("S");
    } else if (word[i] == 't') {
      printf("N");
    } else if (word[i] == 'u') {
      printf("J");
    } else if (word[i] == 'v') {
      printf("X");
    } else if (word[i] == 'w') {
      printf("I");
    } else if (word[i] == 'x') {
      printf("O");
    } else if (word[i] == 'y') {
      printf("T");
    } else if (word[i] == 'z') {
      printf("D");
    } else {
      printf("%c", word[i]); // Print the character as is
    }
  }

  printf("\n"); // Add new line
}