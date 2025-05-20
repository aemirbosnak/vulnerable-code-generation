//Falcon2-11B DATASET v1.0 Category: Personal Finance Planner ; Style: ephemeral
#include <stdio.h>

int main()
{
   // Defining variables
   float income, expense, balance;
   int month;
   char monthName[10];

   // Prompts user for income
   printf("Enter your monthly income: ");
   scanf("%f", &income);

   // Prompts user for expenses
   printf("Enter your monthly expenses: ");
   scanf("%f", &expense);

   // Calculates net income
   balance = income - expense;

   // Prints the net income
   printf("Your net income for this month is $%.2f\n", balance);

   // Prints the month
   printf("It is %s\n", monthName);

   // Loops until user quits
   while(1)
   {
      // Prompts user to enter month
      printf("Enter month (1-12): ");
      scanf("%d", &month);

      // Checks if month is valid
      if (month > 0 && month <= 12)
      {
         // Prints the month name
         strcpy(monthName, "January");
         if (month == 1)
            strcpy(monthName, "January");
         else if (month == 2)
            strcpy(monthName, "February");
         else if (month == 3)
            strcpy(monthName, "March");
         else if (month == 4)
            strcpy(monthName, "April");
         else if (month == 5)
            strcpy(monthName, "May");
         else if (month == 6)
            strcpy(monthName, "June");
         else if (month == 7)
            strcpy(monthName, "July");
         else if (month == 8)
            strcpy(monthName, "August");
         else if (month == 9)
            strcpy(monthName, "September");
         else if (month == 10)
            strcpy(monthName, "October");
         else if (month == 11)
            strcpy(monthName, "November");
         else if (month == 12)
            strcpy(monthName, "December");

         // Prints the month name
         printf("It is %s\n", monthName);

         // Calculates net income
         balance = income - expense;

         // Prints the net income
         printf("Your net income for this month is $%.2f\n", balance);

         // Prompts user to enter month
         printf("Enter month (1-12): ");
         scanf("%d", &month);
      }
      else
      {
         printf("Invalid month\n");
         break;
      }
   }

   return 0;
}