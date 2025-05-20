//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_MEMORY 10

typedef struct MemoryCell {
  int value;
  struct MemoryCell* next;
} MemoryCell;

void initMemory(MemoryCell** head) {
  *head = NULL;
}

void insertMemory(MemoryCell** head, int value) {
  MemoryCell* newCell = malloc(sizeof(MemoryCell));
  newCell->value = value;
  newCell->next = NULL;

  if (*head == NULL) {
    *head = newCell;
  } else {
    (*head)->next = newCell;
  }
}

void playMemoryGame(MemoryCell** head) {
  int guess, attempts = 0;

  printf("Guess the number: ");
  scanf("%d", &guess);

  while (attempts < MAX_MEMORY && guess != (*head)->value) {
    attempts++;

    if (guess < (*head)->value) {
      printf("Too low. Try again: ");
    } else {
      printf("Too high. Try again: ");
    }

    scanf("%d", &guess);
  }

  if (guess == (*head)->value) {
    printf("Congratulations! You won!\n");
  } else {
    printf("Sorry, you lost. The answer was: %d\n", (*head)->value);
  }
}

int main() {
  MemoryCell* head = NULL;
  initMemory(&head);
  insertMemory(&head, 5);
  insertMemory(&head, 10);
  insertMemory(&head, 15);
  insertMemory(&head, 20);

  playMemoryGame(&head);

  return 0;
}