//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

int main() {
   int budget;
   printf("Please enter your monthly budget: ");
   scanf("%d", &budget);
   
   int rent, food, utilities, shopping, otherExpenses, totalExpenses;
   
   printf("Enter your monthly rent: ");
   scanf("%d", &rent);
   
   printf("Enter your monthly food expenses: ");
   scanf("%d", &food);
   
   printf("Enter your monthly utilities: ");
   scanf("%d", &utilities);
   
   printf("Enter your monthly shopping expenses: ");
   scanf("%d", &shopping);
   
   printf("Enter your other monthly expenses: ");
   scanf("%d", &otherExpenses);
   
   totalExpenses = rent + food + utilities + shopping + otherExpenses;
   
   printf("\nYour total monthly expenses are: %d\n\n", totalExpenses);
   
   int savings, remainingBudget;
   savings = budget - totalExpenses;
   
   if (savings < 0){
       printf("Oh No!!!\nIt seems like you are spending more than your budget.\n");
   }
   
   printf("Your monthly savings: %d\n", savings);
   remainingBudget = budget - totalExpenses + savings;
   
   printf("Your remaining budget: %d\n", remainingBudget);
   
   if (remainingBudget >= budget/2){
      printf("\nGreat Job!\nYou are successfully saving more than half of your monthly budget.\n");
   }else if (remainingBudget >= budget/4){
      printf("\nYou are doing good!\nYou can still work on improving your savings.\n");
   }else{
      printf("\nYou need to work on your expenses and savings.\n");
   }
   
   return 0;
}