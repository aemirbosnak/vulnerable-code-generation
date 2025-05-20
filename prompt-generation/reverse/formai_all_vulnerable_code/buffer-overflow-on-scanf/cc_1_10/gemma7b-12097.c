//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_HISTORY_SIZE 10

typedef struct CalculatorHistory {
  char **history;
  int size;
  int currentPosition;
} CalculatorHistory;

CalculatorHistory *initHistory(int size) {
  CalculatorHistory *history = malloc(sizeof(CalculatorHistory));
  history->history = malloc(size * sizeof(char *));
  history->size = size;
  history->currentPosition = 0;
  return history;
}

void addToHistory(CalculatorHistory *history, char *expression) {
  if (history->currentPosition >= history->size) {
    history->history = realloc(history->history, (history->size * 2) * sizeof(char *));
    history->size *= 2;
  }
  history->history[history->currentPosition++] = expression;
}

void printHistory(CalculatorHistory *history) {
  for (int i = 0; i < history->currentPosition; i++) {
    printf("%s\n", history->history[i]);
  }
}

int main() {
  CalculatorHistory *history = initHistory(MAX_HISTORY_SIZE);

  char *expression;

  // Get the expression from the user
  printf("Enter an expression: ");
  expression = malloc(100);
  scanf("%s", expression);

  // Add the expression to the history
  addToHistory(history, expression);

  // Print the history
  printHistory(history);

  return 0;
}