//MISTRAL-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
  char symbol[3];
  char name[20];
  int group;
  int period;
} Element;

void print_element(Element e) {
  printf("%-3s %-20s %d %d\n", e.symbol, e.name, e.group, e.period);
}

Element read_element() {
  Element e;
  printf("Enter symbol: ");
  scanf("%s", e.symbol);
  printf("Enter name: ");
  scanf("%s", e.name);
  printf("Enter group number: ");
  scanf("%d", &e.group);
  printf("Enter period number: ");
  scanf("%d", &e.period);
  return e;
}

int main() {
  srand(time(NULL));
  int num_elements = 118; // Number of elements in the periodic table
  Element elements[num_elements];
  for (int i = 0; i < num_elements; i++) {
    elements[i] = read_element();
  }

  printf("\nPERIODIC TABLE QUIZ\n\n");

  int num_questions = 10;
  int score = 0;

  for (int i = 0; i < num_questions; i++) {
    int index1 = rand() % num_elements;
    int index2 = rand() % num_elements;

    while (index1 == index2) {
      index2 = rand() % num_elements;
    }

    Element e1 = elements[index1];
    Element e2 = elements[index2];

    printf("Question %d:\n", i + 1);
    printf("Which element has the symbol '%s' and is in group %d and period %d?\n", e1.symbol, e1.group, e1.period);
    printf("a) %s\n", e2.name);
    printf("b) %s\n", e1.name);
    printf("c) %s\n", e2.symbol);

    char answer[2];
    scanf("%s", answer);

    if (strcmp(answer, e1.symbol) == 0) {
      printf("Correct!\n");
      score++;
    } else {
      printf("Incorrect. The correct answer is '%s'.\n", e1.symbol);
    }

    printf("\n");
  }

  printf("\nYour final score is %d out of %d.\n", score, num_questions);

  return 0;
}