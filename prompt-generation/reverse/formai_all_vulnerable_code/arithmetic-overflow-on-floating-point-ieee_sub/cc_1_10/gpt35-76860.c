//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Enter your monthly income: ");
  double income;
  scanf("%lf", &income);

  printf("My love, let us budget our household expenses,\n\
  And live a life of financial security.\n\n\
  Shall we start by allocating our income into categories?\n\
  For our love, let us divide it into three!\n\n\
  Our first category shall be necessities,\n\
  For we need to eat, pay bills, and have a roof over our heads.\n\
  It should not exceed 50 percent of our income.\n");

  double necessities;
  do {
    printf("How much will we allocate for necessities? ");
    scanf("%lf", &necessities);
    if (necessities > income/2) {
      printf("My darling, the amount exceeds 50 percent of our income.\n\
      Please enter a valid amount.\n");
    }
  } while (necessities > income/2);

  printf("\n\
  Our second category shall be for wants,\n\
  For we deserve to enjoy the fruits of our labor.\n\
  Let us allocate 30 percent of our income to it.\n");

  double wants;
  do {
    printf("How much will we allocate for our wants? ");
    scanf("%lf", &wants);
    if (wants > income*0.3) {
      printf("My sweet, the amount exceeds 30 percent of our income.\n\
      Please enter a valid amount.\n");
    }
  } while (wants > income*0.3);

  double savings = income - necessities - wants;
  printf("\n\
  Our last category shall be for our future,\n\
  For we must save for unexpected events and for our dreams.\n\
  We will allocate the remaining %.2lf percent to our savings.\n", (savings/income)*100);

  printf("\n\
  My dearest, let us strive to stick to our plan.\n\
  And let us check our savings every month,\n\
  For it is a testament to our love and commitment to each other.\n\
  And to our dreams that will come true.\n");

  return 0;
}