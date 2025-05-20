//FormAI DATASET v1.0 Category: Expense Tracker ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
   printf("Welcome to your Expense Tracker program!\n");
   printf("Please enter the date you're tracking expenses for (DD/MM/YYYY):\n");

   char date[10];
   scanf("%s", date);

   printf("Great, let's start tracking expenses for %s!\n", date);

   float totalExpenses = 0;
   int numExpenses = 0;

   while(1) {
      printf("\nEnter expense amount (press q to quit): $");
      char userInput[10];
      scanf("%s", userInput);

      if(userInput[0] == 'q') {
         break;
      }

      float expense = atof(userInput);

      if(expense == 0) {
         printf("Please enter a valid expense amount.\n");
         continue;
      }

      printf("Enter expense category: ");
      char category[20];
      scanf("%s", category);

      printf("Your expense for %s category is $%.2f\n", category, expense);

      totalExpenses += expense;
      numExpenses++;
   }

   printf("\nYou entered %d expenses and your total expenses for %s are: $%.2f\n", numExpenses, date, totalExpenses);

   if(numExpenses > 5 && totalExpenses > 500) {
      printf("Wow, looks like someone splurged this time! Maybe you should start saving up for next month.\n");
   } else {
      printf("Not bad, but try to keep your expenses under control and plan out your spending next time.\n");
   }

   printf("\nThank you for using your Expense Tracker program! Have a great day!\n");

   return 0;
}