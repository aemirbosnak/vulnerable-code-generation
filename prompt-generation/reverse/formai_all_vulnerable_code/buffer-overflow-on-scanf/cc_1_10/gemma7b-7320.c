//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: complex
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 1000
#define WORDS_PER_LINE 50

typedef struct Word {
  char word[20];
  struct Word* next;
} Word;

Word* InsertWord(Word* head, char* word) {
  Word* newWord = malloc(sizeof(Word));
  strcpy(newWord->word, word);
  newWord->next = NULL;

  if (head == NULL) {
    head = newWord;
  } else {
    head->next = newWord;
  }

  return head;
}

void PrintWords(Word* head) {
  Word* currentWord = head;
  while (currentWord) {
    printf("%s ", currentWord->word);
    currentWord = currentWord->next;
  }
  printf("\n");
}

int main() {
  time_t start, end;
  char input[20];
  Word* head = NULL;

  start = time(NULL);

  printf("Enter words (separate with space): ");
  scanf("%s", input);

  char* words = strtok(input, " ");

  while (words) {
    InsertWord(head, words);
    words = strtok(NULL, " ");
  }

  PrintWords(head);

  end = time(NULL);

  printf("Time taken: %.2f seconds\n", end - start);

  return 0;
}