//FormAI DATASET v1.0 Category: Expense Tracker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char category[20];
  int expense;
  FILE *fp;
  char filename[20];
  int total = 0;

  printf("Enter filename to save expenses: ");
  scanf("%s", filename);

  fp = fopen(filename, "w+");

  if (fp == NULL) {
    printf("Error opening file. Exiting program.\n");
    exit(1);
  }

  printf("Welcome to the Expense Tracker!\n");
  printf("Enter 'quit' for category to stop tracking.\n");

  while (1) {
    printf("Enter category: ");
    scanf("%s", category);

    if (strcmp(category, "quit") == 0) {
      break;
    }

    printf("Enter expense for %s: ", category);
    scanf("%d", &expense);

    fprintf(fp, "%s: %d\n", category, expense);
    total += expense;
  }

  fprintf(fp, "Total: %d\n", total);
  printf("Expenses saved to %s\n", filename);

  fseek(fp, 0, SEEK_SET);

  char buffer[255];
  printf("\nExpenses:\n");

  while (fgets(buffer, 255, fp)) {
    printf("%s", buffer);
  }

  fclose(fp);

  return 0;
}