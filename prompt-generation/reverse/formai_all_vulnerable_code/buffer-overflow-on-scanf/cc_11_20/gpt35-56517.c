//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  printf("Welcome to the Happy Periodic Table Quiz!\n\n");
  printf("You will be asked 10 multiple choice questions regarding elements in the Periodic Table.\n");
  printf("For each question, type the number of the correct answer (1-4).\n");
  printf("Let's get started!\n\n");

  char questions[10][200] = {
    "What is the symbol for gold? \n1. Ge \n2. Au \n3. Ag \n4. Bi \n",
    "What is the atomic number of oxygen? \n1. 8 \n2. 6 \n3. 2 \n4. 10 \n",
    "Which element is a noble gas? \n1. Ar \n2. Na \n3. K \n4. H \n",
    "What element has the chemical symbol Hg? \n1. Hydrogen \n2. Mercury \n3. Helium \n4. Nitrogen \n",
    "What is the most abundant gas in the Earth's atmosphere? \n1. Nitrogen \n2. Oxygen \n3. Carbon dioxide \n4. Helium \n",
    "What is the symbol for sodium? \n1. Na \n2. No \n3. Ni \n4. Nb \n",
    "What is the atomic number for carbon? \n1. 6 \n2. 12 \n3. 10 \n4. 8 \n",
    "Which element is used as a coolant in nuclear reactors? \n1. Uranium \n2. Plutonium \n3. Boron \n4. Helium \n",
    "What is the chemical symbol for iron? \n1. Ir \n2. Fe \n3. Au \n4. Ag \n",
    "What is the atomic number of calcium? \n1. 20 \n2. 12 \n3. 16 \n4. 24 \n"
  };

  int answers[] = {2, 1, 1, 2, 1, 1, 1, 3, 2, 1};
  int score = 0;

  printf("Question 1:\n%s\n", questions[0]);
  int choice1;
  scanf("%d", &choice1);
  if (choice1 == answers[0]) {
    printf("Correct!\n\n");
    score++;
  } else {
    printf("Incorrect.\n\n");
  }

  printf("Question 2:\n%s\n", questions[1]);
  int choice2;
  scanf("%d", &choice2);
  if (choice2 == answers[1]) {
    printf("Correct!\n\n");
    score++;
  } else {
    printf("Incorrect.\n\n");
  }

  printf("Question 3:\n%s\n", questions[2]);
  int choice3;
  scanf("%d", &choice3);
  if (choice3 == answers[2]) {
    printf("Correct!\n\n");
    score++;
  } else {
    printf("Incorrect.\n\n");
  }

  printf("Question 4:\n%s\n", questions[3]);
  int choice4;
  scanf("%d", &choice4);
  if (choice4 == answers[3]) {
    printf("Correct!\n\n");
    score++;
  } else {
    printf("Incorrect.\n\n");
  }

  printf("Question 5:\n%s\n", questions[4]);
  int choice5;
  scanf("%d", &choice5);
  if (choice5 == answers[4]) {
    printf("Correct!\n\n");
    score++;
  } else {
    printf("Incorrect.\n\n");
  }

  printf("Question 6:\n%s\n", questions[5]);
  int choice6;
  scanf("%d", &choice6);
  if (choice6 == answers[5]) {
    printf("Correct!\n\n");
    score++;
  } else {
    printf("Incorrect.\n\n");
  }

  printf("Question 7:\n%s\n", questions[6]);
  int choice7;
  scanf("%d", &choice7);
  if (choice7 == answers[6]) {
    printf("Correct!\n\n");
    score++;
  } else {
    printf("Incorrect.\n\n");
  }

  printf("Question 8:\n%s\n", questions[2]);
  int choice8;
  scanf("%d", &choice8);
  if (choice8 == answers[7]) {
    printf("Correct!\n\n");
    score++;
  } else {
    printf("Incorrect.\n\n");
  }

  printf("Question 9:\n%s\n", questions[8]);
  int choice9;
  scanf("%d", &choice9);
  if (choice9 == answers[8]) {
    printf("Correct!\n\n");
    score++;
  } else {
    printf("Incorrect.\n\n");
  }

  printf("Question 10:\n%s\n", questions[9]);
  int choice10;
  scanf("%d", &choice10);
  if (choice10 == answers[9]) {
    printf("Correct!\n\n");
    score++;
  } else {
    printf("Incorrect.\n\n");
  }

  printf("You scored %d out of 10!\n", score);
  printf("Thanks for playing the Happy Periodic Table Quiz!\n");
  return 0;
}