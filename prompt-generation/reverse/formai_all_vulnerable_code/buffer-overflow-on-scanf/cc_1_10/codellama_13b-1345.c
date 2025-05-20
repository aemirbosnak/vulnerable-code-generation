//Code Llama-13B DATASET v1.0 Category: Alien Language Translator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

// Function to translate a string from English to Alien
void translate_to_alien(char* english, char* alien) {
  int i, len = strlen(english);
  for (i = 0; i < len; i++) {
    if (english[i] == 'a') {
      alien[i] = 'z';
    } else if (english[i] == 'e') {
      alien[i] = 'x';
    } else if (english[i] == 'i') {
      alien[i] = 'c';
    } else if (english[i] == 'o') {
      alien[i] = 'v';
    } else if (english[i] == 'u') {
      alien[i] = 'b';
    } else {
      alien[i] = english[i];
    }
  }
}

// Function to translate a string from Alien to English
void translate_to_english(char* alien, char* english) {
  int i, len = strlen(alien);
  for (i = 0; i < len; i++) {
    if (alien[i] == 'z') {
      english[i] = 'a';
    } else if (alien[i] == 'x') {
      english[i] = 'e';
    } else if (alien[i] == 'c') {
      english[i] = 'i';
    } else if (alien[i] == 'v') {
      english[i] = 'o';
    } else if (alien[i] == 'b') {
      english[i] = 'u';
    } else {
      english[i] = alien[i];
    }
  }
}

int main() {
  char english[MAX_LEN], alien[MAX_LEN];

  printf("Enter a string to translate: ");
  scanf("%s", english);

  translate_to_alien(english, alien);
  printf("The translated string is: %s\n", alien);

  translate_to_english(alien, english);
  printf("The original string is: %s\n", english);

  return 0;
}