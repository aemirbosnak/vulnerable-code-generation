//FormAI DATASET v1.0 Category: Expense Tracker ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    float amount;
} Expense;

void clearScreen() {
    system("clear||cls");
}

void printHeader() {
    clearScreen();
    printf("\n====================================\n");
    printf("   PARANOID EXPENSE TRACKER v1.0\n");
    printf("====================================\n\n");
}

void printMenu() {
    printf("====================================\n");
    printf("              MENU\n");
    printf("====================================\n");
    printf("1. Add expense\n");
    printf("2. View expenses\n");
    printf("3. Exit\n");
    printf("====================================\n\n");
}

void addExpense(Expense expenses[], int* numExpenses) {
    printHeader();
    printf("ENTER EXPENSE DETAILS:\n");
    printf("Name: ");
    scanf("%s", expenses[*numExpenses].name);
    printf("Amount: ");
    scanf("%f", &expenses[*numExpenses].amount);
    (*numExpenses)++;
    printf("\nEXPENSE ADDED SUCCESSFULLY. PRESS ENTER TO RETURN TO MAIN MENU.");
    getchar();
    getchar();
}

void viewExpenses(Expense expenses[], int numExpenses) {
    printHeader();
    printf("YOUR EXPENSES:\n\n");
    if (numExpenses == 0) {
        printf("No expenses added yet.\n");
    } else {
        printf("%-20s%-10s\n", "Name", "Amount");
        printf("------------------------------------\n");
        float totalAmount = 0;
        for (int i = 0; i < numExpenses; i++) {
            printf("%-20s%.2f\n", expenses[i].name, expenses[i].amount);
            totalAmount += expenses[i].amount;
        }
        printf("------------------------------------\n");
        printf("%-20s%.2f\n", "TOTAL", totalAmount);
    }
    printf("\nPRESS ENTER TO RETURN TO MAIN MENU.");
    getchar();
    getchar();
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;
    int choice = 0;

    while (choice != 3) {
        printHeader();
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(expenses, &numExpenses);
                break;
            case 2:
                viewExpenses(expenses, numExpenses);
                break;
            case 3:
                printf("THANK YOU FOR USING PARANOID EXPENSE TRACKER v1.0\n");
                break;
            default:
                printf("INVALID CHOICE. PRESS ENTER TO RETURN TO MAIN MENU.");
                getchar();
                getchar();
                break;
        }
    }

    return 0;
}