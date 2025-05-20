//FormAI DATASET v1.0 Category: Text processing ; Style: energetic
#include <stdio.h>
#include <string.h>

int main() {
  char text[1000];
  printf("Enter some text: ");
  fgets(text, 1000, stdin);
  
  // convert to lowercase
  int len = strlen(text);
  for (int i = 0; i < len; i++) {
    if (text[i] >= 'A' && text[i] <= 'Z') {
      text[i] += 32;
    }
  }
  
  // count words
  int words = 1;
  for (int i = 0; i < len; i++) {
    if (text[i] == ' ' || text[i] == '\n' || text[i] == '\t') {
      words++;
    }
  }
  
  // remove white spaces
  char processed_text[len];
  int j = 0;
  for (int i = 0; i < len; i++) {
    if (!(text[i] == ' ' || text[i] == '\n' || text[i] == '\t')) {
      processed_text[j] = text[i];
      j++;
    }
  }
  processed_text[j] = '\0';
  
  // reverse string
  len = strlen(processed_text);
  char reversed_text[len];
  j = 0;
  for (int i = len-1; i >= 0; i--) {
    reversed_text[j] = processed_text[i];
    j++;
  }
  reversed_text[j] = '\0';
  
  // output result
  printf("\nHere's what we did to your text:\n");
  printf("1. Converted to lowercase\n");
  printf("2. Counted %d words\n", words);
  printf("3. Removed white spaces\n");
  printf("4. Reversed text\n\n");
  printf("Processed text: %s\n", reversed_text);
  
  return 0;
}