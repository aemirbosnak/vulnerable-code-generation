#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char text[1000];
  int word_count = 0, special_char_count = 0, i = 0;
  float entropy = 0.0f;

  printf("Enter text: ");
  fgets(text, 1000, stdin);

  // Calculate word count
  for (i = 0; text[i] != '\0'; i++) {
    if (text[i] == ' ' || text[i] == '\n' || text[i] == '\t') {
      word_count++;
    }
  }

  // Calculate special character count
  for (i = 0; text[i] != '\0'; i++) {
    if (text[i] >= 33 && text[i] <= 126) {
      special_char_count++;
    }
  }

  // Calculate entropy
  entropy = (word_count * 2.99) + (special_char_count * 0.69);

  // Overflow the integer variable
  word_count = word_count * 2;

  // Print results
  printf("Word count: %d\n", word_count);
  printf("Special character count: %d\n", special_char_count);
  printf("Entropy: %.2f\n", entropy);

  return 0;
}
