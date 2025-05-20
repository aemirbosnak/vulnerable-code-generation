//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: active
#include <stdio.h>

// This program will translate the Alien language from planet Krypzon.

int main() {
  char in[100], out[100];
  int i, j, option;

  printf("Select an option:\n1. Translate English to Alien\n2. Translate Alien to English\n");
  scanf("%d", &option);

  if (option == 1) {
    printf("Enter English text to be translated:\n");
    scanf(" %[^\n]", in);

    for (i = 0, j = 0; in[i] != '\0'; i++) {
      if (in[i] == 'a') {
        out[j] = 'z';
        out[j+1] = 'o';
        out[j+2] = 'r';
        out[j+3] = 'q';
        j += 4;
      }
      else if (in[i] == 'b') {
        out[j] = 'l';
        out[j+1] = 'a';
        out[j+2] = 't';
        out[j+3] = 'h';
        j += 4;
      }
      else if (in[i] == 'c') {
        out[j] = '6';
        out[j+1] = '7';
        out[j+2] = '8';
        j += 3;
      }
      else if (in[i] == 'd') {
        out[j] = 'm';
        out[j+1] = 'i';
        out[j+2] = 'x';
        j += 3;
      }
      else if (in[i] == 'e') {
        out[j] = 'u';
        out[j+1] = 'l';
        out[j+2] = 't';
        j += 3;
      }
      else {
        out[j] = in[i];
        j++;
      }
    }

    out[j] = '\0'; // add null character to end of string
    printf("Alien translation: %s\n", out);
  }
  else if (option == 2) {
    printf("Enter Alien text to be translated:\n");
    scanf(" %[^\n]", in);

    for (i = 0, j = 0; in[i] != '\0'; i++) {
      if (in[i] == 'z' && in[i+1] == 'o' && in[i+2] == 'r' && in[i+3] == 'q') {
        out[j] = 'a';
        j++;
        i += 3;
      }
      else if (in[i] == 'l' && in[i+1] == 'a' && in[i+2] == 't' && in[i+3] == 'h') {
        out[j] = 'b';
        j++;
        i += 3;
      }
      else if (in[i] == '6' && in[i+1] == '7' && in[i+2] == '8') {
        out[j] = 'c';
        j++;
        i += 2;
      }
      else if (in[i] == 'm' && in[i+1] == 'i' && in[i+2] == 'x') {
        out[j] = 'd';
        j++;
        i += 2;
      }
      else if (in[i] == 'u' && in[i+1] == 'l' && in[i+2] == 't') {
        out[j] = 'e';
        j++;
        i += 2;
      }
      else {
        out[j] = in[i];
        j++;
      }
    }

    out[j] = '\0'; // add null character to end of string
    printf("English translation: %s\n", out);
  }
  else {
    printf("Invalid option selected.\n");
  }

  return 0;
}