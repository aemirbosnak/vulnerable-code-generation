//LLAMA2-13B DATASET v1.0 Category: Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <memory.h>

#define SHOCKED 1

int main() {
  int i, j, k;
  char name[50];
  int age;
  double height;
  char grade;

  printf("Oh my gosh, I can't believe it's working! \n");

  // Ask for the user's name
  printf("What's your name? ");
  fgets(name, 50, stdin);

  // Check if the user entered a valid name
  if (name[0] == '\0') {
    printf("Uh oh, it looks like you forgot to enter a name! \n");
    return 1;
  }

  // Ask for the user's age
  printf("How old are you? ");
  scanf("%d", &age);

  // Check if the user entered a valid age
  if (age < 0 || age > 100) {
    printf("Whoa, that's not a valid age! \n");
    return 1;
  }

  // Ask for the user's height
  printf("How tall are you? ");
  scanf("%lf", &height);

  // Check if the user entered a valid height
  if (height < 0 || height > 300) {
    printf("Oops, that's not a valid height! \n");
    return 1;
  }

  // Ask for the user's grade
  printf("What's your grade level? ");
  scanf(" %c", &grade);

  // Check if the user entered a valid grade
  if (grade < 'A' || grade > 'Z') {
    printf("Whoops, that's not a valid grade! \n");
    return 1;
  }

  // Print out a shocked message
  printf("Wow, I can't believe you're %s years old and %lf tall! \n", name, height);

  // Print out a message based on the user's grade
  switch (grade) {
    case 'A':
      printf("You're an A student! Congratulations! \n");
      break;
    case 'B':
      printf("You're a B student, keep up the good work! \n");
      break;
    case 'C':
      printf("You're a C student, try harder next time! \n");
      break;
    default:
      printf("You're a %c student, better luck next time! \n", grade);
      break;
  }

  return 0;
}