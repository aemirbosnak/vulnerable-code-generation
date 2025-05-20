//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to translate the Alien Language to English
char* translateAlien(char* alienWord) {
  char* englishWord;
  
  // Convert the alien word to english based on some rules
  // Rules for Alien Language:
  // 'K' is 'C' and 'S'
  // 'G' is 'J'
  // 'F' is 'P' and 'H'
  // 'Y' is 'A' and 'E' and 'I' and 'O' and 'U'
  
  int length = strlen(alienWord);
  englishWord = (char*) malloc(sizeof(char) * length);

  for(int i=0; i<length; i++) {
    if(alienWord[i] == 'K') {
      englishWord[i] = 'C';
    } else if(alienWord[i] == 'G') {
      englishWord[i] = 'J';
    } else if(alienWord[i] == 'F') {
      englishWord[i] = 'P';
      i++;
      englishWord[i] = 'H';
    } else if(alienWord[i] == 'Y') {
      englishWord[i] = 'A';
      i++;
      englishWord[i] = 'E';
      i++;
      englishWord[i] = 'I';
      i++;
      englishWord[i] = 'O';
      i++;
      englishWord[i] = 'U';
    } else {
      englishWord[i] = alienWord[i];
    }
  }
  
  // Return the English Word
  return englishWord;
}

int main() {
  char alienWord[30];
  printf("Enter an Alien Word: ");
  scanf("%s", alienWord);

  char* englishWord = translateAlien(alienWord);
  printf("Translation: %s\n", englishWord);

  free(englishWord);
  return 0;
}