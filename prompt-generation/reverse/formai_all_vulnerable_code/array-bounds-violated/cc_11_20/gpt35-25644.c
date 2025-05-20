//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: energetic
#include <stdio.h>

int main() {
  printf("Welcome to the User Input Sanitizer! Let's keep your input clean and safe.\n");
  printf("What's your name? ");
  char name[50];
  fgets(name, 50, stdin);
  printf("Hi %s! Please enter a sentence: ", name);
  char sentence[100];
  fgets(sentence, 100, stdin);
  
  printf("\nSanitizing your input...\n");
  
  // Remove digits
  char sanitized_sentence[100];
  int j = 0;
  for (int i = 0; sentence[i] != '\0'; i++) {
    if (!(sentence[i] >= '0' && sentence[i] <= '9')) {
      sanitized_sentence[j] = sentence[i];
      j++;
    }
  }
  sanitized_sentence[j] = '\0';
  printf("Digits removed: %s\n", sanitized_sentence);
  
  // Remove symbols
  char symbols[] = {'\'', '\"', ',', '.', '(', ')', '[', ']', '{', '}', '?', '!', ';', ':', '-'};
  char sanitized_sentence2[100];
  j = 0;
  for (int i = 0; sanitized_sentence[i] != '\0'; i++) {
    int is_symbol = 0;
    for (int k = 0; k < 15; k++) {
      if (sanitized_sentence[i] == symbols[k]) {
        is_symbol = 1;
        break;
      }
    }
    if (!is_symbol) {
      sanitized_sentence2[j] = sanitized_sentence[i];
      j++;
    }
  }
  sanitized_sentence2[j] = '\0';
  printf("Symbols removed: %s\n", sanitized_sentence2);
  
  // Remove leading and trailing whitespace
  char sanitized_sentence3[100];
  j = 0;
  for (int i = 0; sanitized_sentence2[i] != '\0'; i++) {
    if (sanitized_sentence2[i] != ' ' || (i > 0 && sanitized_sentence2[i-1] != ' ')) {
      sanitized_sentence3[j] = sanitized_sentence2[i];
      j++;
    }
  }
  if (sanitized_sentence3[j-1] == ' ') {
    sanitized_sentence3[j-1] = '\0';
  } else {
    sanitized_sentence3[j] = '\0';
  }
  printf("Leading and trailing whitespace removed: %s\n", sanitized_sentence3);
  
  printf("\nThanks for using the User Input Sanitizer! Your sanitized sentence is: %s\n", sanitized_sentence3);
  return 0;
}