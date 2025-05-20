//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: sophisticated
#include <stdio.h>
#include <time.h>

#define MAX_WORDS 1000

typedef struct Word {
  char word[20];
  struct Word* next;
} Word;

Word* head = NULL;

void addWord(char* word) {
  Word* newNode = malloc(sizeof(Word));
  newNode->word[0] = '\0';
  strcpy(newNode->word, word);
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }
}

void startTest() {
  char word[20];
  int i = 0;

  printf("Start typing words, one per line. Press Enter to submit.\n");

  while (i < MAX_WORDS) {
    printf("Word %d: ", i + 1);
    scanf("%s", word);

    if (strcmp(word, "") == 0) {
      break;
    }

    addWord(word);
    i++;
  }

  printf("You have finished typing. Thank you.\n");
}

int main() {
  time_t start, end;
  double timeTaken;

  start = clock();
  startTest();
  end = clock();

  timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

  printf("Total time taken: %.2lf seconds\n", timeTaken);

  return 0;
}