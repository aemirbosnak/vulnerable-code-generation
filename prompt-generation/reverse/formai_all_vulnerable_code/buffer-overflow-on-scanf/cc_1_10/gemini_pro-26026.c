//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: innovative
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define DIM 4
#define CARDS (DIM*DIM)
#define POSITIONS (CARDS*2)

int shuffled[POSITIONS];  // The shuffled deck
int picked[CARDS];       // The picked cards

void swap(int *el1, int *el2) {
  int temp = *el1;
  *el1 = *el2;
  *el2 = temp;
}

void shuffle(int *array, int size) {
  srand(time(NULL));
  int i = 0;
  while(i < size) {
    int j = rand() % size;
    swap(&array[i], &array[j]);
    i++;
  }
}

void display(int *deck, int size) {
  for(int i = 0; i < size; i++) {
    printf("%2d ", deck[i]);
  }
  puts("");
}

int compare(const void *a, const void *b) {
  return *(int*)a - *(int*)b;
}

void main() {
  int deck[CARDS] = {0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7};
  for(int i = 0; i < POSITIONS; i++) { shuffled[i] = i; }
  
  shuffle(shuffled, POSITIONS);
  display(shuffled, POSITIONS);

  for(int i = 0; i < CARDS; i++) {
    printf("Pick a card: ");
    int cardChosen = 0;
    scanf("%d", &cardChosen);
    picked[i] = shuffled[cardChosen];
  }
  display(picked, CARDS);

  qsort(picked, CARDS, sizeof(int), compare);
  int pairFound = 0;
  for(int i = 0; i < CARDS-1; i++) {
    if(picked[i] == picked[i+1]) {
      pairFound = 1;
      break;
    }
  }

  puts(pairFound ? "Pair found! 🎯" : "No pair found! 👎");
}