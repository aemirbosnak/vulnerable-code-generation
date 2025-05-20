//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

int main() {
  char input_sentence[200];
  char translated_sentence[200];
  int i = 0;
  int j = 0;

  printf("Enter a sentence in C Cat Language: ");
  gets(input_sentence);

  // Convert the input sentence to uppercase
  for (i = 0; input_sentence[i] != '\0'; i++) {
    if (input_sentence[i] >= 'a' && input_sentence[i] <= 'z') {
      input_sentence[i] -= 32;
    }
  }

  // Translate the sentence
  for (i = 0; input_sentence[i] != '\0'; i++) {
    switch (input_sentence[i]) {
      case 'a':
        translated_sentence[j] = 'A';
        j++;
        break;
      case 'e':
        translated_sentence[j] = 'E';
        j++;
        break;
      case 'i':
        translated_sentence[j] = 'I';
        j++;
        break;
      case 'o':
        translated_sentence[j] = 'O';
        j++;
        break;
      case 'u':
        translated_sentence[j] = 'U';
        j++;
        break;
      default:
        translated_sentence[j] = input_sentence[i];
        j++;
    }
  }

  // Print the translated sentence
  printf("Translated sentence: ");
  puts(translated_sentence);

  return 0;
}