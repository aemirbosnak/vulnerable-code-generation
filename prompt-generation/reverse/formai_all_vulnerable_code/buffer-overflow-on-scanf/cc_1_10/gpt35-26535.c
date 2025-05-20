//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Romeo and Juliet
/* Romeo and Juliet's Personal Finance Planner */

#include <stdio.h>
#include <string.h>

/* Define the structure for the user's financial information */
struct finance {
  float income;
  float expenses;
  float savings;
  char name[20];
};

int main() {
  struct finance romeo, juliet;
  char answer[3];

  /* Romeo's financial input */
  printf("Romeo, what is your monthly income? ");
  scanf("%f", &romeo.income);
  printf("What are your monthly expenses? ");
  scanf("%f", &romeo.expenses);
  printf("How much do you want to save each month? ");
  scanf("%f", &romeo.savings);

  /* Juliet's financial input */
  printf("\nJuliet, what is your monthly income? ");
  scanf("%f", &juliet.income);
  printf("What are your monthly expenses? ");
  scanf("%f", &juliet.expenses);
  printf("How much do you want to save each month? ");
  scanf("%f", &juliet.savings);

  /* Determine each person's net income */
  float romeo_net = romeo.income - romeo.expenses;
  float juliet_net = juliet.income - juliet.expenses;

  /* Determine each person's projected savings */
  float romeo_projected = romeo_net + romeo.savings;
  float juliet_projected = juliet_net + juliet.savings;

  /* Decide which person will save more */
  if (romeo_projected > juliet_projected) {
    printf("\nOh Romeo, thy wallet is fat,\nWhile Juliet's coin falls flat.");
  }
  else if (juliet_projected > romeo_projected) {
    printf("\nOh Juliet, thy purse is swelled,\nWhile Romeo's money is dwindled.");
  }
  else {
    printf("\nOh fortunate pair, with equal sum,\nYour future's bright, your finances done.");
  }

  /* Ask if the users want financial advice */
  printf("\nWould you like some financial advice? (Yes or No) ");
  scanf("%s", answer);
  if (strcmp(answer, "Yes") == 0) {
    printf("\nDear Romeo and Juliet,\nTo keep your finances right on fleek,\nYou must budget each day of the week!\nTrack your spending and save what you can,\nAnd soon you'll be a wealthy man and woman.");
  }
  else {
    printf("\nVery well then, farewell and good luck on your financial journey!");
  }

  return 0;
}