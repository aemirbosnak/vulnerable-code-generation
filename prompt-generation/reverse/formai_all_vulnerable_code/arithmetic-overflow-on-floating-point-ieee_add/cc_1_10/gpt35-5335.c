//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: excited
#include <stdio.h>

int main() {

//Greet the user
printf("Hello! Welcome to your Personal Finance Planner!\n");
printf("This program will help you keep track of your monthly expenses and budget.\n");

//Ask for user's monthly income
float income;
printf("\nWhat is your monthly income? ");
scanf("%f", &income);

//Ask for user's fixed monthly expenses
float rent;
printf("\nWhat is your monthly rent/mortgage payment? ");
scanf("%f", &rent);

float utilities;
printf("What is your monthly utilities payment? ");
scanf("%f", &utilities);

float carPayment;
printf("What is your monthly car payment? ");
scanf("%f", &carPayment);

float phoneBill;
printf("What is your monthly phone bill? ");
scanf("%f", &phoneBill);

float totalFixedExpenses = rent + utilities + carPayment + phoneBill;
float leftoverIncome = income - totalFixedExpenses;

//Display user's fixed expenses and leftover income
printf("\nYour fixed monthly expenses are:\n");
printf("- Rent/Mortgage: $%.2f\n", rent);
printf("- Utilities: $%.2f\n", utilities);
printf("- Car payment: $%.2f\n", carPayment);
printf("- Phone bill: $%.2f\n", phoneBill);
printf("\nYour leftover income is: $%.2f\n", leftoverIncome);

//Ask for user's variable expenses for the month
float grocery;
printf("\nHow much did you spend on groceries this month? ");
scanf("%f", &grocery);

float diningOut;
printf("How much did you spend on dining out this month? ");
scanf("%f", &diningOut);

float entertainment;
printf("How much did you spend on entertainment this month? ");
scanf("%f", &entertainment);

float shopping;
printf("How much did you spend on shopping this month? ");
scanf("%f", &shopping);

float totalVariableExpenses = grocery + diningOut + entertainment + shopping;
float totalExpenses = totalFixedExpenses + totalVariableExpenses;

//Display user's variable expenses and total expenses
printf("\nYour variable expenses for the month are:\n");
printf("- Groceries: $%.2f\n", grocery);
printf("- Dining out: $%.2f\n", diningOut);
printf("- Entertainment: $%.2f\n", entertainment);
printf("- Shopping: $%.2f\n", shopping);
printf("\nYour total expenses for the month are: $%.2f\n", totalExpenses);

//Check if user went over budget or stayed within budget
if (totalExpenses > income) {
    float amountOver = totalExpenses - income;
    printf("\nUh oh! You went over budget by $%.2f. Let's cut back next month.\n", amountOver);
} else {
    float amountLeft = income - totalExpenses;
    printf("\nCongratulations! You stayed within budget this month and have $%.2f left over.\n", amountLeft);
}

return 0;
}