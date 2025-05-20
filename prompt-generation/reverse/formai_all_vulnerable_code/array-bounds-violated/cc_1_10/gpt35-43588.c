//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: curious
#include <stdio.h>
#include <string.h>

// Function to check if a character is a vowel
int isVowel(char c) {
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

// Function to translate a word from Alien Language to English
void translateWord(char word[]) {
  int i, j;
  int n = strlen(word);
  char newWord[n+1];
  strcpy(newWord, word);

  // Iterate through each character of the word
  for (i = 0; i < n; i++) {
    char c = newWord[i];
    if (c == 'z') {
      newWord[i] = 'e';
    } else if (isVowel(c)) {
      newWord[i] = 'a';
    } else {
      newWord[i] = (char)(((int) c) + 1);
    }
  }

  // Print the English translation
  printf("%s ", newWord);
}

// Function to translate a sentence from Alien Language to English
void translateSentence(char sentence[]) {
  int i, j;
  int n = strlen(sentence);
  char word[20];

  // Iterate through each character of the sentence
  for (i = 0, j = 0; i < n; i++) {
    char c = sentence[i];
    if (c == ' ') {
      word[j] = '\0';
      translateWord(word);
      j = 0;
    } else {
      word[j++] = c;
    }
  }

  // Translate the last word in the sentence
  word[j] = '\0';
  translateWord(word);
}

int main() {
  char sentence[100];

  // Get the sentence from the user
  printf("Enter a sentence in Alien Language: ");
  fgets(sentence, 100, stdin);

  // Remove the newline character at the end of the sentence
  sentence[strlen(sentence)-1] = '\0';

  // Translate the sentence to English
  printf("English Translation: ");
  translateSentence(sentence);

  return 0;
}