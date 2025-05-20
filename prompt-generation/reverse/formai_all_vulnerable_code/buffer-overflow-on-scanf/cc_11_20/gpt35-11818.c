//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char c;
  char alienStr[10] = "";
  char englishStr[10] = "";
  int i = 0, j = 0, k = 0, n = 0, len = 0, choice = 0;

  printf("Welcome to the Alien Language Translator!\n");

  printf("What do you want to translate?\n");
  printf("1. From Alien Language to English\n");
  printf("2. From English to Alien Language\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);
  
  getchar(); // To clear the newline character in the buffer

  if (choice == 1) {
    printf("Enter the Alien Language string: ");
    while ((c = getchar()) != '\n') {
      if (i == 0) {
        printf("Translating...\n");
      }
      if (c == ' ') {
        alienStr[i] = '\0';
        len = strlen(alienStr);
        for (j = 0; j < len; j++) {
          n = alienStr[j] - '0';
          englishStr[k++] = n + 96;
        }
        englishStr[k++] = ' ';
        i = 0;
      } else {
        alienStr[i++] = c;
      }
    }
    alienStr[i] = '\0';
    len = strlen(alienStr);
    for (j = 0; j < len; j++) {
      n = alienStr[j] - '0';
      englishStr[k++] = n + 96;
    }
    englishStr[k] = '\0';

    printf("Translated string: %s\n", englishStr);
  } else if (choice == 2) {
    printf("Enter the English string: ");
    while ((c = getchar()) != '\n') {
      if (i == 0) {
        printf("Translating...\n");
      }
      if (c == ' ') {
        englishStr[i] = '\0';
        len = strlen(englishStr);
        for (j = 0; j < len; j++) {
          n = englishStr[j] - 96;
          alienStr[k++] = n + '0';
        }
        alienStr[k++] = ' ';
        i = 0;
      } else {
        englishStr[i++] = c;
      }
    }
    englishStr[i] = '\0';
    len = strlen(englishStr);
    for (j = 0; j < len; j++) {
      n = englishStr[j] - 96;
      alienStr[k++] = n + '0';
    }
    alienStr[k] = '\0';

    printf("Translated string: %s\n", alienStr);
  } else {
    printf("Invalid choice!\n");
  }

  return 0;
}