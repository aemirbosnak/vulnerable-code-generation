//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

/* Define structures */
struct expense {
    char name[100];
    double amount;
};

struct income {
    char name[100];
    double amount;
};

/* Declare functions */
void add_expense(struct expense expenses[], int *num_expenses);
void add_income(struct income incomes[], int *num_incomes);
void display_expenses(struct expense expenses[], int num_expenses);
void display_incomes(struct income incomes[], int num_incomes);

/* Main function */
int main() {
    int choice;
    int num_expenses = 0;
    int num_incomes = 0;
    struct expense expenses[100];
    struct income incomes[100];

    printf("===============================\n");
    printf("Welcome to the Personal Finance Planner\n");
    printf("===============================\n\n");

    while (1) {
        /* Display menu */
        printf("MENU:\n");
        printf("1. Add an expense\n");
        printf("2. Add an income\n");
        printf("3. Display expenses\n");
        printf("4. Display incomes\n");
        printf("5. Exit\n");

        /* Get user choice */
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense(expenses, &num_expenses);
                break;
            case 2:
                add_income(incomes, &num_incomes);
                break;
            case 3:
                display_expenses(expenses, num_expenses);
                break;
            case 4:
                display_incomes(incomes, num_incomes);
                break;
            case 5:
                printf("Exiting program\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}

/* Function to add an expense */
void add_expense(struct expense expenses[], int *num_expenses) {
    /* Get expense details from user */
    printf("Enter expense name: ");
    scanf("%s", expenses[*num_expenses].name);

    printf("Enter expense amount: ");
    scanf("%lf", &expenses[*num_expenses].amount);

    /* Update number of expenses */
    (*num_expenses)++;

    printf("Expense added successfully!\n\n");
}

/* Function to add an income */
void add_income(struct income incomes[], int *num_incomes) {
    /* Get income details from user */
    printf("Enter income name: ");
    scanf("%s", incomes[*num_incomes].name);

    printf("Enter income amount: ");
    scanf("%lf", &incomes[*num_incomes].amount);

    /* Update number of incomes */
    (*num_incomes)++;

    printf("Income added successfully!\n\n");
}

/* Function to display expenses */
void display_expenses(struct expense expenses[], int num_expenses) {
    if (num_expenses == 0) {
        printf("No expenses to display!\n\n");
        return;
    }

    /* Display header */
    printf("%-20s%-20s\n", "Expense Name", "Amount");

    /* Display expenses */
    for (int i = 0; i < num_expenses; i++) {
        printf("%-20s%-20.2lf\n", expenses[i].name, expenses[i].amount);
    }

    printf("\n");
}

/* Function to display incomes */
void display_incomes(struct income incomes[], int num_incomes) {
    if (num_incomes == 0) {
        printf("No incomes to display!\n\n");
        return;
    }

    /* Display header */
    printf("%-20s%-20s\n", "Income Name", "Amount");

    /* Display incomes */
    for (int i = 0; i < num_incomes; i++) {
        printf("%-20s%-20.2lf\n", incomes[i].name, incomes[i].amount);
    }

    printf("\n");
}