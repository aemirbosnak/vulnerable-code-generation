//Code Llama-13B DATASET v1.0 Category: Periodic Table Quiz ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ELEMENTS 118
#define MAX_QUESTIONS 10
#define MAX_ANSWERS 4

typedef struct {
  char symbol[3];
  char name[20];
  int atomic_number;
} Element;

Element elements[MAX_ELEMENTS] = {
  {"H", "Hydrogen", 1},
  {"He", "Helium", 2},
  // ...
  {"Uuo", "Uranium-233", 92},
  {"Uup", "Uranium-234", 92},
  {"Uus", "Uranium-235", 92},
  {"Uut", "Uranium-238", 92}
};

void shuffle(int *array, int n) {
  if (n > 1) {
    int i;
    for (i = 0; i < n - 1; i++) {
      int j = i + rand() / (RAND_MAX / (n - i) + 1);
      int t = array[j];
      array[j] = array[i];
      array[i] = t;
    }
  }
}

int main() {
  srand(time(NULL));

  int i, j;
  int question_index[MAX_QUESTIONS];
  int correct_answers = 0;

  for (i = 0; i < MAX_QUESTIONS; i++) {
    question_index[i] = i;
  }
  shuffle(question_index, MAX_QUESTIONS);

  for (i = 0; i < MAX_QUESTIONS; i++) {
    int question = question_index[i];
    int answer = -1;

    printf("Question %d: What is the name of element %d?\n", question + 1, elements[question].atomic_number);

    for (j = 0; j < MAX_ANSWERS; j++) {
      printf("%d. %s\n", j + 1, elements[question].name);
    }

    printf("Enter answer: ");
    scanf("%d", &answer);

    if (answer == question) {
      correct_answers++;
    }
  }

  printf("You scored %d out of %d.\n", correct_answers, MAX_QUESTIONS);

  return 0;
}