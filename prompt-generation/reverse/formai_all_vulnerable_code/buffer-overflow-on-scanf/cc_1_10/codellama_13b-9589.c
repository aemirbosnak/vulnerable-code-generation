//Code Llama-13B DATASET v1.0 Category: Periodic Table Quiz ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 118

typedef struct {
  char symbol[4];
  char name[20];
  int atomic_number;
  int group;
  int period;
} element_t;

element_t elements[MAX_ELEMENTS] = {
  {"H", "Hydrogen", 1, 1, 1},
  {"He", "Helium", 2, 18, 1},
  {"Li", "Lithium", 3, 1, 2},
  {"Be", "Beryllium", 4, 2, 2},
  {"B", "Boron", 5, 13, 2},
  {"C", "Carbon", 6, 14, 2},
  {"N", "Nitrogen", 7, 15, 2},
  {"O", "Oxygen", 8, 16, 2},
  {"F", "Fluorine", 9, 17, 2},
  {"Ne", "Neon", 10, 18, 2},
  // ...
};

int main() {
  srand(time(NULL));

  int num_correct = 0;
  int num_questions = 10;

  for (int i = 0; i < num_questions; i++) {
    int element_index = rand() % MAX_ELEMENTS;
    element_t *element = &elements[element_index];

    printf("What is the name of element %d?\n", element_index + 1);
    char answer[20];
    scanf("%s", answer);

    if (strcmp(answer, element->name) == 0) {
      num_correct++;
    }
  }

  printf("You scored %d out of %d.\n", num_correct, num_questions);

  return 0;
}