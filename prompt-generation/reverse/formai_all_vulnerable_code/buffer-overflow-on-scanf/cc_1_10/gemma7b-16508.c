//Gemma-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_ANSWERS 10

typedef struct {
  char name[20];
  int age;
  int lucky_number;
} Person;

int main() {
  Person person;
  int answer_index = 0;
  char answers[MAX_ANSWERS][200];

  printf("Please enter your name: ");
  scanf("%s", person.name);

  printf("Please enter your age: ");
  scanf("%d", &person.age);

  person.lucky_number = rand() % 11 + 1;

  answers[answer_index][0] = 'H';
  answers[answer_index][1] = 'A';
  answers[answer_index][2] = 'P';
  answers[answer_index][3] = 'P';
  answers[answer_index][4] = '\0';

  answer_index++;

  answers[answer_index][0] = 'F';
  answers[answer_index][1] = 'O';
  answers[answer_index][2] = 'R';
  answers[answer_index][3] = 'T';
  answers[answer_index][4] = '\0';

  answer_index++;

  answers[answer_index][0] = 'A';
  answers[answer_index][1] = 'C';
  answers[answer_index][2] = 'C';
  answers[answer_index][3] = 'O';
  answers[answer_index][4] = '\0';

  answer_index++;

  printf("Your fortune: ");
  printf("%s", answers[answer_index - 1]);

  return 0;
}