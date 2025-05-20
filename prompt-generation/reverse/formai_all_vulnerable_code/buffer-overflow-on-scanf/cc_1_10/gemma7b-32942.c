//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX_HISTORY 10

char history[MAX_HISTORY][20];

void storeHistory(char *expr) {
  int i = 0;
  for (i = 0; i < MAX_HISTORY; i++) {
    if (history[i][0] == '\0') {
      strcpy(history[i], expr);
      return;
    }
  }

  // If all history slots are full, remove the oldest entry
  int oldestIndex = 0;
  for (i = 1; i < MAX_HISTORY; i++) {
    if (history[i][0] != '\0') {
      oldestIndex = i;
    }
  }

  strcpy(history[oldestIndex], expr);
}

char *getHistory(int index) {
  return history[index];
}

int main() {
  char expr[20];
  char *historyEntry;
  int historyIndex = 0;

  printf("Enter an expression: ");
  scanf("%s", expr);

  storeHistory(expr);

  printf("History:\n");
  for (int i = 0; i < MAX_HISTORY; i++) {
    historyEntry = getHistory(i);
    if (historyEntry[0] != '\0') {
      printf("%d. %s\n", i + 1, historyEntry);
    }
  }

  return 0;
}