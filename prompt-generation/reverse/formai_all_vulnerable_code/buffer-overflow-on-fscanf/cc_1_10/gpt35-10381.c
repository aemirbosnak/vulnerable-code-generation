//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

struct Element {
  char symbol[3];
  int atomic_number;
  char name[20];
  float atomic_mass;
};

int main() {
  struct Element elements[118];
  FILE *fp = fopen("periodic_table.txt", "r");

  if (fp == NULL) {
    printf("Error reading file...\n");
    return 1;
  }

  char symbol[3], name[20];
  int atomic_number;
  float atomic_mass;

  int i = 0;
  while (fscanf(fp, "%s %d %s %f", symbol, &atomic_number, name, &atomic_mass) != EOF) {
    strcpy(elements[i].symbol, symbol);
    elements[i].atomic_number = atomic_number;
    strcpy(elements[i].name, name);
    elements[i].atomic_mass = atomic_mass;

    i++;
  }

  fclose(fp);

  printf("Welcome to the Periodic Table Quiz!\n\n");
  printf("Enter the correct atomic symbol for each element below:\n");

  int score = 0;
  for (int i = 0; i < 5; i++) {
    int index = rand() % 118;
    printf("%d. %s: ", i+1, elements[index].name);

    char guess[3];
    scanf("%s", guess);

    if (strcmp(guess, elements[index].symbol) == 0) {
      printf("Correct!\n");
      score++;
    } else {
      printf("Incorrect. The correct symbol is %s.\n", elements[index].symbol);
    }
  }

  printf("\nQuiz complete!\n");
  printf("You scored %d out of 5.\n", score);

  return 0;
}