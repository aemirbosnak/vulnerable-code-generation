//FormAI DATASET v1.0 Category: Expense Tracker ; Style: artistic
#include<stdio.h>
#include<stdlib.h>

//Expense Tracker Program

//Structure to hold expense details
typedef struct expense {
    char category[20];
    float amount;
} EXPENSE;

//Function to get expense details from user
void getExpenseDetails(EXPENSE* exp) {
    printf("Enter category: ");
    scanf("%s", exp->category);
    printf("Enter amount: ");
    scanf("%f", &(exp->amount));
}

//Function to display expense details
void displayExpenseDetails(EXPENSE exp) {
    printf("%-20s %.2f\n", exp.category, exp.amount);
}

int main() {
    //Array to hold all expenses
    EXPENSE* expenses = NULL;
    int numExpenses = 0;

    //Welcome message
    printf("Welcome to Expense Tracker!\n");

    //Loop to get expenses from user
    char choice = 'y';
    while (choice == 'y') {
        //Increase size of expenses array
        numExpenses++;
        expenses = (EXPENSE*) realloc(expenses, numExpenses * sizeof(EXPENSE));

        //Get expense details from user
        printf("\nExpense %d:\n", numExpenses);
        getExpenseDetails(&expenses[numExpenses-1]);

        //Ask user if they want to add another expense
        printf("\nDo you want to add another expense? (y/n): ");
        scanf(" %c", &choice);
    }

    //Display all expenses
    printf("\nAll expenses:\n");
    printf("%-20s %s\n", "Category", "Amount");
    printf("--------------------  \n");
    for (int i = 0; i < numExpenses; i++) {
        displayExpenseDetails(expenses[i]);
    }

    //Free allocated memory
    free(expenses);
    expenses = NULL;

    //Goodbye message
    printf("\nThank you for using Expense Tracker!\n");

    return 0;
}