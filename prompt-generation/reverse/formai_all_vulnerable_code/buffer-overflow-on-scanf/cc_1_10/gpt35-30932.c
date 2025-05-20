//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: irregular
#include<stdio.h>
#include<stdlib.h>

// This program is a personal finance planner made in C
// It helps you track your daily expenses and income to manage your finances better

int main() {

    printf("\n\n\t\t WELCOME TO PERSONAL FINANCE PLANNER \n\n");

    // Initialize variables
    float income = 0, expense = 0, balance = 0;
    char choice;

    // Loop until user decides to exit
    while(1) {

        printf("Enter your choice:\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. View Balance\n");
        printf("4. Exit\n");

        // Get input from user
        scanf(" %c", &choice);

        switch(choice) {

            case '1':

                printf("Enter amount of income: ");
                float incomeAmt;
                scanf("%f", &incomeAmt);

                // Update balance with income amount
                balance += incomeAmt;

                printf("Income Added Successfully!\n\n");

                break;

            case '2':

                printf("Enter amount of expense: ");
                float expenseAmt;
                scanf("%f", &expenseAmt);

                // Check if balance is sufficient to make expense
                if(balance >= expenseAmt) {
                    balance -= expenseAmt;
                    printf("Expense Added Successfully!\n\n");
                } else {
                    printf("Sorry, Insufficient Balance!\n\n");
                }

                break;

            case '3':

                printf("Balance: %.2f \n\n", balance);
                printf("Press any key to continue\n");
                getchar(); // consumes the \n character left from scanf
                getchar();

                break;

            case '4':

                printf("\nExiting Personal Finance Planner...\n");
                exit(0);

            default:

                printf("Invalid Input! Please Try Again.\n\n");

                break;

        }

    }
    
    return 0;
}