//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: safe
#include <stdio.h>
#include <string.h>

int main() {
  int score = 0;
  char answer[20];

  printf("Welcome to the Periodic Table Quiz!\n");
  printf("You will be asked 10 questions about the elements in the periodic table.\n");
  printf("Type the correct symbol for each element to get one point!\n");

  // Question 1
  printf("\nQuestion 1: What is the symbol for Carbon?\n");
  scanf("%s", answer);
  if (strcmp(answer, "C") == 0) {
    printf("Correct!\n");
    score++;
  } else {
    printf("Incorrect. The correct answer is C.\n");
  }

  // Question 2
  printf("\nQuestion 2: What is the symbol for Gold?\n");
  scanf("%s", answer);
  if (strcmp(answer, "Au") == 0) {
    printf("Correct!\n");
    score++;
  } else {
    printf("Incorrect. The correct answer is Au.\n");
  }

  // Question 3
  printf("\nQuestion 3: What is the symbol for Calcium?\n");
  scanf("%s", answer);
  if (strcmp(answer, "Ca") == 0) {
    printf("Correct!\n");
    score++;
  } else {
    printf("Incorrect. The correct answer is Ca.\n");
  }

  // Question 4
  printf("\nQuestion 4: What is the symbol for Nitrogen?\n");
  scanf("%s", answer);
  if (strcmp(answer, "N") == 0) {
    printf("Correct!\n");
    score++;
  } else {
    printf("Incorrect. The correct answer is N.\n");
  }

  // Question 5
  printf("\nQuestion 5: What is the symbol for Iron?\n");
  scanf("%s", answer);
  if (strcmp(answer, "Fe") == 0) {
    printf("Correct!\n");
    score++;
  } else {
    printf("Incorrect. The correct answer is Fe.\n");
  }

  // Question 6
  printf("\nQuestion 6: What is the symbol for Hydrogen?\n");
  scanf("%s", answer);
  if (strcmp(answer, "H") == 0) {
    printf("Correct!\n");
    score++;
  } else {
    printf("Incorrect. The correct answer is H.\n");
  }

  // Question 7
  printf("\nQuestion 7: What is the symbol for Sodium?\n");
  scanf("%s", answer);
  if (strcmp(answer, "Na") == 0) {
    printf("Correct!\n");
    score++;
  } else {
    printf("Incorrect. The correct answer is Na.\n");
  }

  // Question 8
  printf("\nQuestion 8: What is the symbol for Neon?\n");
  scanf("%s", answer);
  if (strcmp(answer, "Ne") == 0) {
    printf("Correct!\n");
    score++;
  } else {
    printf("Incorrect. The correct answer is Ne.\n");
  }

  // Question 9
  printf("\nQuestion 9: What is the symbol for Oxygen?\n");
  scanf("%s", answer);
  if (strcmp(answer, "O") == 0) {
    printf("Correct!\n");
    score++;
  } else {
    printf("Incorrect. The correct answer is O.\n");
  }

  // Question 10
  printf("\nQuestion 10: What is the symbol for Silver?\n");
  scanf("%s", answer);
  if (strcmp(answer, "Ag") == 0) {
    printf("Correct!\n");
    score++;
  } else {
    printf("Incorrect. The correct answer is Ag.\n");
  }

  printf("\nYou scored %d out of 10!\n", score);
  return 0;
}