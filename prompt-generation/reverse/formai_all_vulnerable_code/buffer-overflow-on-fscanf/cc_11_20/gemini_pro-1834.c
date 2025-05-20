//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_LEN 20

char *dictionary[MAX_WORDS];
int num_words;

int main(void) {
  // Load the dictionary
  FILE *fp = fopen("dictionary.txt", "r");
  if (fp == NULL) {
    fprintf(stderr, "Error: could not open dictionary file\n");
    return 1;
  }

  char word[MAX_LEN];
  while (fscanf(fp, "%s", word) != EOF) {
    dictionary[num_words++] = strdup(word);
  }

  fclose(fp);

  // Get the input text
  char text[10000];
  printf("Enter the text to be checked:\n");
  scanf("%[^\n]%*c", text);

  // Check the spelling of each word in the text
  char *p = text;
  while (*p != '\0') {
    // Get the next word
    char word[MAX_LEN];
    int i = 0;
    while (*p != '\0' && !isspace(*p)) {
      word[i++] = *p++;
    }
    word[i] = '\0';

    // Look up the word in the dictionary
    int found = 0;
    for (i = 0; i < num_words; i++) {
      if (strcmp(word, dictionary[i]) == 0) {
        found = 1;
        break;
      }
    }

    // Print an error message if the word is not found
    if (!found) {
      printf("Error: the word '%s' is not in the dictionary\n", word);
    }

    // Move on to the next word
    while (*p != '\0' && isspace(*p)) {
      p++;
    }
  }

  return 0;
}