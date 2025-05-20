//FormAI DATASET v1.0 Category: Spell checking ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
  char word[100], dictWord[100];
  int i, j, k, found = 0;
  int numWords = 0, numMistakes = 0;
  char *filename = "dictionary.txt";
  FILE *dict = fopen(filename, "r");
  if (!dict) {
     printf("Error opening dictionary file \"%s\".\n", filename);
     return 1;
  }
  // welcome message
  printf("Welcome to the Spell Checker!");
  printf("\n\n");
  // loop until user enters "exit"
  while (1) {
    found = 0;
    printf("Enter a word to check (or \"exit\" to quit): ");
    // read user input
    scanf("%s", word);
    // check if user wants to exit
    if (strcmp(word, "exit") == 0) {
      printf("Thank you for using our Spell Checker! Bye bye\n");
      break;
    }
    // remove non-letters
    k = 0;
    for (i = 0; word[i] != '\0'; i++) {
      if (isalpha(word[i])) {
        word[k++] = tolower(word[i]);
      }
    }
    word[k] = '\0';
    // look for word in the dictionary
    fseek(dict, 0L, SEEK_SET);
    while (fscanf(dict, "%s", dictWord) == 1) {
      if (strcmp(word, dictWord) == 0) {
        printf("Good news! \"%s\" is spelled correctly.\n", word);
        found = 1;
        break;
      }
    }
    if (!found) {
        // display all words that are one letter away from the input word
        printf("Oops! \"%s\" is spelled incorrectly. Here are some suggestions:\n", word);
        fseek(dict, 0L, SEEK_SET);
        while (fscanf(dict, "%s", dictWord) == 1) {
          if (strlen(dictWord) == strlen(word)) {
            numMistakes = 0;
            for (i = 0; word[i] != '\0'; i++) {
              if (word[i] != dictWord[i]) {
                numMistakes++;
              }
            }
            if (numMistakes == 1) {
              printf("- %s\n", dictWord);
              numWords++;
            }
          }
        }
        // display a fun message if no suggestions are found
        if (numWords == 0) {
          printf("Sorry, we couldn't find any suggestions. Maybe you're just too creative!\n");
        }
    }
  }
  // close dictionary file
  fclose(dict);
  return 0;
}