//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: creative
#include<stdio.h>
#include<stdlib.h>

/* Function prototypes */
void printMainMenu(void);
void printDepositWithdrawMenu(void);
void printExpensesMenu(void);
void printIncomeMenu(void);
void depositMoney(float*, float*);
void withdrawMoney(float*, float*);
void addExpense(float*, float*);
void addIncome(float*, float*);
void displayCurrentBalance(float, float);
void displayExpenses(float);
void displayIncome(float);
void displaySummary(float, float, float);

int main()
{
    int choiceMainMenu, choiceDWMenu, choiceExpensesMenu, choiceIncomeMenu;
    float currentBalance = 0.0, expenses = 0.0, income = 0.0;

    do {
        /* Main menu */
        printMainMenu();
        scanf("%d", &choiceMainMenu);

        switch (choiceMainMenu) {
            case 1:
                /* Deposit/Withdraw menu */
                do {
                    printDepositWithdrawMenu();
                    scanf("%d", &choiceDWMenu);

                    switch (choiceDWMenu) {
                        case 1:
                            depositMoney(&currentBalance, &income);
                            break;
                        case 2:
                            withdrawMoney(&currentBalance, &expenses);
                            break;
                        case 3:
                            break;
                        default:
                            printf("Invalid choice, please try again.\n");
                    }
                } while (choiceDWMenu != 3);
                break;
            case 2:
                /* Expenses menu */
                do {
                    printExpensesMenu();
                    scanf("%d", &choiceExpensesMenu);

                    switch (choiceExpensesMenu) {
                        case 1:
                            addExpense(&currentBalance, &expenses);
                            break;
                        case 2:
                            displayExpenses(expenses);
                            break;
                        case 3:
                            break;
                        default:
                            printf("Invalid choice, please try again.\n");
                    }
                } while (choiceExpensesMenu != 3);
                break;
            case 3:
                /* Income menu */
                do {
                    printIncomeMenu();
                    scanf("%d", &choiceIncomeMenu);

                    switch (choiceIncomeMenu) {
                        case 1:
                            addIncome(&currentBalance, &income);
                            break;
                        case 2:
                            displayIncome(income);
                            break;
                        case 3:
                            break;
                        default:
                            printf("Invalid choice, please try again.\n");
                    }
                } while (choiceIncomeMenu != 3);
                break;
            case 4:
                /* Summary */
                displaySummary(currentBalance, expenses, income);
                break;
            case 5:
                /* Exit */
                printf("Exiting program. Thank you for using the Personal Finance Planner!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (1);

    return 0;
}

void printMainMenu()
{
    printf("Personal Finance Planner: Main menu\n");
    printf("1. Manage Deposits/Withdrawals\n");
    printf("2. Manage Expenses\n");
    printf("3. Manage Income\n");
    printf("4. Display Summary\n");
    printf("5. Exit\n");
    printf("Enter choice: ");
}

void printDepositWithdrawMenu()
{
    printf("Personal Finance Planner: Deposit/Withdraw menu\n");
    printf("1. Deposit money\n");
    printf("2. Withdraw money\n");
    printf("3. Return to main menu\n");
    printf("Enter choice: ");
}

void printExpensesMenu()
{
    printf("Personal Finance Planner: Expenses menu\n");
    printf("1. Add expense\n");
    printf("2. Display expenses\n");
    printf("3. Return to main menu\n");
    printf("Enter choice: ");
}

void printIncomeMenu()
{
    printf("Personal Finance Planner: Income menu\n");
    printf("1. Add income\n");
    printf("2. Display income\n");
    printf("3. Return to main menu\n");
    printf("Enter choice: ");
}

void depositMoney(float* currentBalance, float* income)
{
    float amount;

    printf("Personal Finance Planner: Deposit money\n");
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    *currentBalance += amount;
    *income += amount;

    printf("Deposit of $%.2f successful. Current balance: $%.2f\n", amount, *currentBalance);
}

void withdrawMoney(float* currentBalance, float* expenses)
{
    float amount;

    printf("Personal Finance Planner: Withdraw money\n");
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (*currentBalance >= amount) {
        *currentBalance -= amount;
        *expenses += amount;

        printf("Withdrawal of $%.2f successful. Current balance: $%.2f\n", amount, *currentBalance);
    } else {
        printf("Error: Insufficient funds. Withdrawal unsuccessful.\n");
    }
}

void addExpense(float* currentBalance, float* expenses)
{
    float amount;

    printf("Personal Finance Planner: Add expense\n");
    printf("Enter amount of expense: ");
    scanf("%f", &amount);

    if (*currentBalance >= amount) {
        *currentBalance -= amount;
        *expenses += amount;

        printf("Expense of $%.2f added successfully. Current balance: $%.2f\n", amount, *currentBalance);
    } else {
        printf("Error: Insufficient funds. Expense cannot be added.\n");
    }
}

void addIncome(float* currentBalance, float* income)
{
    float amount;

    printf("Personal Finance Planner: Add income\n");
    printf("Enter amount of income: ");
    scanf("%f", &amount);

    *currentBalance += amount;
    *income += amount;

    printf("Income of $%.2f added successfully. Current balance: $%.2f\n", amount, *currentBalance);
}

void displayCurrentBalance(float currentBalance, float expenses)
{
    printf("Personal Finance Planner: Current balance\n");
    printf("Current balance: $%.2f\n", currentBalance);
    printf("Expenses incurred: $%.2f\n", expenses);
    printf("Remaining balance: $%.2f\n", currentBalance - expenses);
}

void displayExpenses(float expenses)
{
    printf("Personal Finance Planner: Expenses list\n");
    printf("Expenses incurred: $%.2f\n", expenses);
}

void displayIncome(float income)
{
    printf("Personal Finance Planner: Income list\n");
    printf("Income earned: $%.2f\n", income);
}

void displaySummary(float currentBalance, float expenses, float income)
{
    printf("Personal Finance Planner: Summary\n");
    printf("Current balance: $%.2f\n", currentBalance);
    printf("Total expenses incurred: $%.2f\n", expenses);
    printf("Total income earned: $%.2f\n", income);
    printf("Remaining balance: $%.2f\n", currentBalance - expenses);
}