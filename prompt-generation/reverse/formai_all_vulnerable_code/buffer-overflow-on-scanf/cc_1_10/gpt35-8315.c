//FormAI DATASET v1.0 Category: Text processing ; Style: detailed
#include <stdio.h>
#include <string.h>

int main() {
  char sentence[200];
  char word[20];
  char new_word[20];
  char temp[200];
  int i, j, k, l, m, n;
  
  printf("Enter a sentence: ");
  fgets(sentence, 200, stdin);
  sentence[strcspn(sentence, "\n")] = 0; // Remove newline character
  
  printf("Enter a word to replace: ");
  scanf("%s", word);
  
  printf("Enter a new word: ");
  scanf("%s", new_word);
  
  m = strlen(sentence);
  n = strlen(word);
  
  for (i = 0, j = 0; i < m;) {
    if (sentence[i] != ' ' && sentence[i] != '\t') { // If not whitespace
      temp[j] = sentence[i];
      i++;
      j++;
    }
    else { // If whitespace
      temp[j] = '\0'; // Terminate the string
      if (strcmp(temp, word) == 0) { // If word to replace is found
        for (k = 0, l = 0; k < strlen(new_word); k++, j++, l++) { // Replace word with new word
          sentence[l] = new_word[k];
        }
      }
      else { // If word to replace not found
        for (k = 0, l = i - j; k < strlen(temp); k++, l++) {
          sentence[l] = temp[k];
        }
      }
      sentence[l] = ' '; // Add a space after each word
      j = 0; // Reset temp string
      i++; // Move to next character
    }
  }
  
  printf("\nNew sentence: %s", sentence);

  return 0;
}