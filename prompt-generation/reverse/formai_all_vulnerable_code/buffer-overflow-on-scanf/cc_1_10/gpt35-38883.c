//FormAI DATASET v1.0 Category: Spell checking ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

// Cyberpunk style spell checker

void check_spell(char *word) {
  // List of common misspellings in a dystopian society
  char *misspellings[] = {
    "tech", "tek",
    "cyber", "siber",
    "hacker", "haxor",
    "jacker", "j4ck3r",
    "cyborg", "syborg",
    "neural", "nural",
    "augment", "augm3nt",
    "genetic", "g3n3tic",
    "virus", "viruz",
    "crypto", "krypto",
    "stealth", "st3alth",
    "power", "pow3r"
  };

  // Strip trailing punctuation
  int len = strlen(word);
  if (word[len-1] == '.' || word[len-1] == ',' || word[len-1] == '!') {
    word[len-1] = '\0';
  }

  // Check if word is a misspelling
  for (int i = 0; i < sizeof(misspellings)/sizeof(char *); i += 2) {
    if (strcmp(word, misspellings[i]) == 0) {
      printf("Did you mean '%s'?\n", misspellings[i+1]);
      return;
    }
  }

  // If not a misspelling, print confirmation
  printf("No spelling mistakes found.\n");
}

int main() {
  char word[20];

  printf("Enter word to spell check: ");
  scanf("%s", word);

  check_spell(word);

  return 0;
}