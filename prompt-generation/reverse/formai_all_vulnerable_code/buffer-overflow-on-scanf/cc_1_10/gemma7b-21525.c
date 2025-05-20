//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct MemoryCell {
  int data;
  struct MemoryCell* next;
} MemoryCell;

MemoryCell* createCell(int data) {
  MemoryCell* cell = (MemoryCell*)malloc(sizeof(MemoryCell));
  cell->data = data;
  cell->next = NULL;
  return cell;
}

void playMemoryGame() {
  MemoryCell* head = createCell(1);
  head = createCell(2);
  head = createCell(3);
  head = createCell(4);
  head = createCell(5);

  int guessNumber;

  printf("Enter the number you want to find: ");
  scanf("%d", &guessNumber);

  MemoryCell* currentCell = head;

  while (currentCell) {
    if (currentCell->data == guessNumber) {
      printf("You found the number! Congratulations!");
      break;
    } else if (currentCell->data < guessNumber) {
      currentCell = currentCell->next;
    } else {
      printf("The number you entered is too high. Try again: ");
      scanf("%d", &guessNumber);
    }
  }

  if (currentCell == NULL) {
    printf("Sorry, the number was not found.");
  }
}

int main() {
  playMemoryGame();

  return 0;
}