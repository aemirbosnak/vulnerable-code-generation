//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: protected
#include <stdio.h>
#include <string.h>

char* translate(char word[]) {
  int i, j, len = strlen(word);
  char newWord[len+1];
  
  for(i = 0; i < len; i++) {
    switch(word[i]) {
      case 'a':
        newWord[i] = 'b';
        break;
      case 'b':
        newWord[i] = 'c';
        break;
      case 'c':
        newWord[i] = 'd';
        break;
      case 'd':
        newWord[i] = 'e';
        break;
      case 'e':
        newWord[i] = 'f';
        break;
      case 'f':
        newWord[i] = 'g';
        break;
      case 'g':
        newWord[i] = 'h';
        break;
      case 'h':
        newWord[i] = 'i';
        break;
      case 'i':
        newWord[i] = 'j';
        break;
      case 'j':
        newWord[i] = 'k';
        break;
      case 'k':
        newWord[i] = 'l';
        break;
      case 'l':
        newWord[i] = 'm';
        break;
      case 'm':
        newWord[i] = 'n';
        break;
      case 'n':
        newWord[i] = 'o';
        break;
      case 'o':
        newWord[i] = 'p';
        break;
      case 'p':
        newWord[i] = 'q';
        break;
      case 'q':
        newWord[i] = 'r';
        break;
      case 'r':
        newWord[i] = 's';
        break;
      case 's':
        newWord[i] = 't';
        break;
      case 't':
        newWord[i] = 'u';
        break;
      case 'u':
        newWord[i] = 'v';
        break;
      case 'v':
        newWord[i] = 'w';
        break;
      case 'w':
        newWord[i] = 'x';
        break;
      case 'x':
        newWord[i] = 'y';
        break;
      case 'y':
        newWord[i] = 'z';
        break;
      case 'z':
        newWord[i] = 'a';
        break;
      default:
        // If not a letter, just copy the character
        newWord[i] = word[i];
        break;
    }
  }
  
  // Add null terminator at end of newWord
  newWord[len] = '\0';
  
  // Return the translated word
  return newWord;
}

int main() {
  char phrase[100];
  printf("Enter a phrase in the alien language: ");
  fgets(phrase, 100, stdin);
  // Remove newline character at end of phrase if it exists
  if(phrase[strlen(phrase)-1] == '\n') {
    phrase[strlen(phrase)-1] = '\0';
  }
  char* translatedPhrase = translate(phrase);
  printf("Translated phrase: %s\n", translatedPhrase);
  return 0;
}