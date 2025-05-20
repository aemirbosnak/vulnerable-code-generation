//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: introspective
#include <stdio.h>
#include <string.h>

int main() {
  char input[1000], output[1000];
  printf("Enter a sentence in Cat language: ");
  scanf("%[^\n]", input);
  int len = strlen(input);
  int i;
  int index = 0;

  for(i = 0; i < len; i++) {
    if(input[i] == 'M') {
      output[index++] = 'C';
      output[index++] = ' ';
      output[index++] = 'A';
      output[index++] = 'T';
      output[index++] = ' ';
    }
    else if(input[i] == 'e') {
      output[index++] = 'm';
      output[index++] = 'i';
      output[index++] = 'a';
      output[index++] = 'u';
      output[index++] = ' ';
    }
    else if(input[i] == 'o') {
      output[index++] = 'r';
      output[index++] = 'a';
      output[index++] = 'n';
      output[index++] = 'g';
      output[index++] = 'e';
      output[index++] = ' ';
    }
    else if(input[i] == 'w') {
      output[index++] = 's';
      output[index++] = 'o';
      output[index++] = 'r';
      output[index++] = 'a';
      output[index++] = 'l';
      output[index++] = 'e';
      output[index++] = ' ';
    }
    else if(input[i] == 'h') {
      output[index++] = 't';
      output[index++] = 's';
      output[index++] = 'i';
      output[index++] = 'l';
      output[index++] = ' ';
    }
    else if(input[i] == 'n') {
      output[index++] = 'o';
      output[index++] = 'y';
      output[index++] = ' ';
    }
    else {
      output[index++] = input[i];
    }
  }

  output[index] = '\0';
  printf("\nTranslated sentence: %s\n", output);
  return 0;
}