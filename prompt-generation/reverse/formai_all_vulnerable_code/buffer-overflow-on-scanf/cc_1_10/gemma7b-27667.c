//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: protected
#include <stdio.h>
#include <time.h>

#define MAX_WORDS 10

typedef struct Word {
  char word[20];
  int frequency;
} Word;

Word words[MAX_WORDS];

void initializeWords() {
  for (int i = 0; i < MAX_WORDS; i++) {
    words[i].word[0] = '\0';
    words[i].frequency = 0;
  }
}

void addWord(char* word) {
  for (int i = 0; i < MAX_WORDS; i++) {
    if (words[i].word[0] == '\0') {
      strcpy(words[i].word, word);
      words[i].frequency = 1;
      return;
    } else if (strcmp(words[i].word, word) == 0) {
      words[i].frequency++;
      return;
    }
  }

  // If no space, allocate more memory
  printf("Error: insufficient memory.\n");
}

int main() {
  initializeWords();

  char word[20];

  // Type words here
  scanf("%s", word);
  addWord(word);

  // Print word statistics
  for (int i = 0; i < MAX_WORDS; i++) {
    if (words[i].word[0] != '\0') {
      printf("%s: %d occurrences\n", words[i].word, words[i].frequency);
    }
  }

  return 0;
}