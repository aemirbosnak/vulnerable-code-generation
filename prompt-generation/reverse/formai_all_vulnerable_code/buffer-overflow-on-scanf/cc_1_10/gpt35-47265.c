//FormAI DATASET v1.0 Category: Memory Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 20

void shuffle(int *array, size_t n);
void print_board(int board[MAX_CARDS]);

int main(void) {
  int nCards, firstSelection, secondSelection;
  int board[MAX_CARDS], shownValues[MAX_CARDS] = {0};

  printf("Enter number of cards (maximum 20): ");
  scanf("%d", &nCards);

  if (nCards > MAX_CARDS || nCards < 1) {
    printf("Invalid input.\n");
    return 1;
  }

  if (nCards % 2 != 0) nCards--;

  // Initialize the board
  for (int i = 0; i < nCards; i += 2) {
    board[i] = board[i + 1] = (i / 2) + 1;
  }

  shuffle(board, nCards);

  // Play the game loop
  while (1) {
    print_board(shownValues);

    printf("Enter the index of the first selection: ");
    scanf("%d", &firstSelection);
    printf("Enter the index of the second selection: ");
    scanf("%d", &secondSelection);

    // Ensure valid card selections
    if (firstSelection >= nCards || secondSelection >= nCards ||
        shownValues[firstSelection] || shownValues[secondSelection])
    {
      printf("Invalid selections. Try again.\n");
      continue;
    }

    shownValues[firstSelection] = board[firstSelection];
    shownValues[secondSelection] = board[secondSelection];

    if (board[firstSelection] == board[secondSelection]) {
      printf("Match found!\n");
    } else {
      printf("No match found.\n");
      shownValues[firstSelection] = shownValues[secondSelection] = 0;
    }

    // Check for finished game condition
    int count = 0;
    for (int i = 0; i < nCards; i++) {
      if (shownValues[i]) count++;
    }
    if (count == nCards) break;
  }

  printf("Congratulations, you won!\n");

  return 0;
}

void shuffle(int *array, size_t n) {
  if (n > 1) {
    srand(time(NULL));
    for (size_t i = 0; i < n - 1; i++) {
      size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
      int t = array[j];
      array[j] = array[i];
      array[i] = t;
    }
  }
}

void print_board(int board[MAX_CARDS]) {
  for (int i = 0; i < MAX_CARDS; i++) {
    if (i % 5 == 0) printf("\n");
    if (board[i]) {
      printf("[%2d] ", board[i]);
    } else {
      printf("[  ] ");
    }
  }
  printf("\n");
}