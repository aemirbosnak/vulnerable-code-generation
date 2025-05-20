//FormAI DATASET v1.0 Category: Spell checking ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character is a valid alphabet or not
int isAlphabet(char ch) {
  return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}

// Function to check if a character is a valid punctuation or not
int isPunctuation(char ch) {
  return (ch == '.' || ch == ',' || ch == '?' || ch == '!');
}

// Function to convert all characters of a string to lowercase
void toLower(char *word) {
  int i;
  for (i = 0; i < strlen(word); i++) {
    word[i] = tolower(word[i]);
  }
}

int main() {
  // Create a file pointer to read the dictionary file
  FILE *fp;
  fp = fopen("dictionary.txt", "r");

  // Create a hash table to store the dictionary words
  int hashTable[26][500] = {0};

  // Read the dictionary file and insert the words into the hash table
  char dictionaryWord[50];
  int index;
  int hashVal;
  while (fscanf(fp, "%s", dictionaryWord) != EOF) {
    index = atoi(&dictionaryWord[0]) - 1;
    strcpy(dictionaryWord, &dictionaryWord[3]);
    toLower(dictionaryWord);
    hashVal = dictionaryWord[0] - 'a';
    hashTable[hashVal][index] = 1;
  }
  fclose(fp);

  // Input a sentence to check for spelling mistakes
  printf("Enter a sentence to check for spelling mistakes:\n");
  char sentence[500];
  fgets(sentence, 500, stdin);

  // Convert the sentence to lowercase and replace all punctuation marks with a space
  toLower(sentence);
  int i;
  for (i = 0; i < strlen(sentence); i++) {
    if (isPunctuation(sentence[i])) {
      sentence[i] = ' ';
    }
  }

  // Tokenize the sentence into words
  char *word;
  word = strtok(sentence, " ");
  int wordCount = 0;
  int spellMistakes = 0;
  int j;
  while (word != NULL) {
    wordCount++;
    // Check if the word is spelled correctly
    int isCorrect = 0;
    toLower(word);
    if (isAlphabet(word[0])) {
      hashVal = word[0] - 'a';
      for (j = 0; j < 500; j++) {
        if (hashTable[hashVal][j] == 1) {
          char dictWord[50];
          sprintf(dictWord, "%d_%s", j+1, word);
          if (strcmp(dictWord, dictionaryWord) == 0) {
            isCorrect = 1;
            break;
          }
        }
      }
    }
    // Print message for misspelled words and increment the count of spell mistakes
    if (!isCorrect) {
      printf("Potential spelling mistake '%s' at word number %d\n", word, wordCount);
      spellMistakes++;
    }
    word = strtok(NULL, " ");
  }
  // Print the summary of the spelling check
  if (spellMistakes == 0) {
    printf("No spelling mistakes found in the sentence!\n");
  } else {
    printf("%d potential spelling mistakes found in the sentence.\n", spellMistakes);
  }
  
  return 0; 
}