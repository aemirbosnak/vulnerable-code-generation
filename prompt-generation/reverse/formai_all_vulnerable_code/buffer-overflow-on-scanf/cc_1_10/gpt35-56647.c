//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: surprised
#include <stdio.h>

int main() {
  printf("Welcome to Personal Finance Planner!\n");
  printf("Are you ready to take control of your finances? (Y/N)\n");

  char answer[2];
  scanf("%s", &answer);

  if (answer[0] == 'Y' || answer[0] == 'y') {
    printf("Great! Let's get started.\n");

    float income, expenses, savings;

    printf("What is your monthly income? $");
    scanf("%f", &income);

    printf("What are your monthly expenses? $");
    scanf("%f", &expenses);

    savings = income - expenses;

    printf("Awesome! You have $%.2f left over each month to save or invest.\n", savings);

    printf("Do you have any specific savings goals in mind? (Y/N)\n");
    scanf("%s", &answer);

    if (answer[0] == 'Y' || answer[0] == 'y') {
      printf("Please enter your savings goal amount: $");
      float goal;
      scanf("%f", &goal);

      if (goal > savings) {
        printf("Sorry, it looks like your current income and expenses won't allow you to reach that goal.\n");
      } else {
        int months = goal / savings;
        printf("Great news! At this rate, you'll reach your goal in %d months.\n", months);
      }
    } else {
      printf("That's okay, it's always good to have some extra savings for a rainy day.\n");
    }

    printf("Thanks for using Personal Finance Planner! Have a great day! :)\n");

  } else {
    printf("Oh no! Let me know if you change your mind.\n");
  }

  return 0;
}