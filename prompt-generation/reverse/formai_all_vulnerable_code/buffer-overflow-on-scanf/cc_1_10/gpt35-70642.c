//FormAI DATASET v1.0 Category: Expense Tracker ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

struct Expense {
    int id;
    char name[50];
    float cost;
    int year;
    int month;
    int day;
};

// Function to add new expense
void addExpense(struct Expense expenses[], int *totalExpenses) {
    if (*totalExpenses >= MAX_EXPENSES) {
        printf("Maximum number of expenses reached!\n");
        return;
    }

    struct Expense newExpense;

    // Get expense details from user
    printf("Enter name of expense: ");
    scanf("%49s", newExpense.name);
    printf("Enter cost of expense: $");
    scanf("%f", &newExpense.cost);
    printf("Enter date of expense (YYYY/MM/DD): ");
    scanf("%d/%d/%d", &newExpense.year, &newExpense.month, &newExpense.day);

    newExpense.id = *totalExpenses + 1;

    expenses[*totalExpenses] = newExpense;
    (*totalExpenses)++;

    printf("Expense added successfully!\n");
}

// Function to display all expenses
void displayExpenses(struct Expense expenses[], int totalExpenses) {
    if (totalExpenses == 0) {
        printf("No expenses recorded yet.\n");
        return;
    }

    printf("%-5s%-20s%-15s%-15s\n", "ID", "Name", "Cost", "Date");

    for (int i = 0; i < totalExpenses; i++) {
        printf("%-5d%-20s$%-14.2f%4d/%02d/%02d\n",
                expenses[i].id, expenses[i].name,
                expenses[i].cost, expenses[i].year, expenses[i].month, expenses[i].day);
    }
}

// Function to find and display expenses by date
void displayExpensesByDate(struct Expense expenses[], int totalExpenses, int year, int month, int day) {
    printf("Expenses for %d/%02d/%02d:\n", year, month, day);

    for (int i = 0; i < totalExpenses; i++) {
        if (expenses[i].year == year && expenses[i].month == month && expenses[i].day == day) {
            printf("%-5d%-20s$%-14.2f\n", expenses[i].id, expenses[i].name, expenses[i].cost);
        }
    }
}

int main() {
    struct Expense expenses[MAX_EXPENSES] = {0};
    int totalExpenses = 0;

    char menuChoice;
    int year, month, day;

    printf("====================\n");
    printf("Futuristic Expense Tracker\n");
    printf("====================\n");

    // Display menu and take user input
    do {
        printf("\nChoose an option:\n");
        printf("1) Add a new expense\n");
        printf("2) Display all expenses\n");
        printf("3) Show expenses by date\n");
        printf("4) Quit program\n");
        printf("> ");
        scanf(" %c", &menuChoice);

        // Handle menu choice
        switch (menuChoice) {
            case '1':
                addExpense(expenses, &totalExpenses);
                break;
            case '2':
                displayExpenses(expenses, totalExpenses);
                break;
            case '3':
                printf("Enter date to show expenses (YYYY/MM/DD): ");
                scanf("%d/%d/%d", &year, &month, &day);
                displayExpensesByDate(expenses, totalExpenses, year, month, day);
                break;
            case '4':
                printf("Thank you for using Futuristic Expense Tracker!\n");
                break;
            default:
                printf("Invalid input. Please choose again.\n");
                break;
        }
    } while (menuChoice != '4');

    return 0;
}