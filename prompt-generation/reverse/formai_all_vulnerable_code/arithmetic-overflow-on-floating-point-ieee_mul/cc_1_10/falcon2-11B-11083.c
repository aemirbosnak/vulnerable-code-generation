//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[20];
    float amount;
    int month;
    int year;
} Expense;

void addExpense(Expense* expenses, int size) {
    printf("Enter expense details:\n");
    printf("Name: ");
    fgets(expenses[size].name, sizeof(expenses[size].name), stdin);
    fflush(stdin);

    printf("Amount: ");
    scanf("%f", &expenses[size].amount);

    printf("Month: ");
    scanf("%d", &expenses[size].month);

    printf("Year: ");
    scanf("%d", &expenses[size].year);

    expenses[size].amount = round(expenses[size].amount * 100) / 100.0;
}

void displayExpenses(Expense* expenses, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s - %.2f - %d/%d\n", expenses[i].name, expenses[i].amount, expenses[i].month, expenses[i].year);
    }
}

int main() {
    srand(time(0));
    int size = 0;
    Expense expenses[10];

    printf("Welcome to the Expense Tracker!\n");

    while (1) {
        int choice = 0;

        printf("1. Add expense\n");
        printf("2. Display expenses\n");
        printf("3. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(expenses, size);
                size++;
                break;
            case 2:
                displayExpenses(expenses, size);
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}