//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: thoughtful
#include <stdio.h>
#include <time.h>

#define MAX_WORDS 100
#define WORDS_PER_PAGE 20

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
    head->next = InsertWord(head->next, word);
  }

  return head;
}

void PrintWords(Word* head) {
  Word* currentWord = head;
  int i = 0;

  while (currentWord) {
    printf("%s ", currentWord->word);
    currentWord = currentWord->next;

    if (i % WORDS_PER_PAGE == WORDS_PER_PAGE - 1) {
      printf("\n");
    }

    i++;
  }
}

int main() {
  Word* head = NULL;

  clock_t start, end;
  double timeTaken;

  char word[20];

  printf("Enter a word: ");
  scanf("%s", word);

  InsertWord(head, word);

  printf("Enter more words (optional): ");
  scanf("%s", word);

  if (word[0] != '\0') {
    InsertWord(head, word);
  }

  start = clock();
  PrintWords(head);
  end = clock();

  timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

  printf("\nTime taken: %.2f seconds\n", timeTaken);

  return 0;
}