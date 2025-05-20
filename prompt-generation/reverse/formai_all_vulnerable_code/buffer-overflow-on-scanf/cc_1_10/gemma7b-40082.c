//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: configurable
#include <stdio.h>
#include <time.h>

#define MAX_WORDS 100
#define WORDS_PER_LINE 20

typedef struct Word {
  char word[20];
  struct Word* next;
} Word;

Word* head = NULL;

void addWord(char* word) {
  Word* newWord = malloc(sizeof(Word));
  strcpy(newWord->word, word);
  newWord->next = NULL;

  if (head == NULL) {
    head = newWord;
  } else {
    head->next = newWord;
    head = newWord;
  }
}

void startTest() {
  char word[20];
  int i = 0;

  printf("Please enter a word: ");
  scanf("%s", word);

  addWord(word);

  for (i = 0; i < MAX_WORDS - 1; i++) {
    printf("Enter a word: ");
    scanf("%s", word);

    addWord(word);
  }

  time_t start = time(NULL);

  for (i = 0; i < WORDS_PER_LINE; i++) {
    printf("%s ", head->word);
    head = head->next;
  }

  time_t end = time(NULL);

  printf("\nTime taken: %.2f seconds\n", (double)(end - start) / WORDS_PER_LINE);
}

int main() {
  startTest();

  return 0;
}