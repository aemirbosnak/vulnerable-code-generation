//MISTRAL-7B DATASET v1.0 Category: Personal Finance Planner ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#define MAX_ITEMS 10

typedef struct {
    char name[50];
    float amount;
} Item;

void main() {
    int month, i, j;
    Item income[MAX_ITEMS], expense[MAX_ITEMS];
    float total_income = 0.0, total_expense = 0.0, balance;

    printf("Personal Finance Planner\n");
    printf("------------------------\n");

    for (i = 0; i < MAX_ITEMS; i++) {
        printf("Enter income source name and amount (or 'quit' to finish):\n");
        scanf("%s", income[i].name);
        if (strcmp(income[i].name, "quit") == 0)
            break;
        scanf("%f", &income[i].amount);
        total_income += income[i].amount;
    }

    printf("\nEnter expense name and amount (or 'quit' to finish):\n");
    for (i = 0; i < MAX_ITEMS; i++) {
        scanf("%s", expense[i].name);
        if (strcmp(expense[i].name, "quit") == 0)
            break;
        scanf("%f", &expense[i].amount);
        total_expense += expense[i].amount;
    }

    printf("\nEnter the number of months to plan: ");
    scanf("%d", &month);

    for (i = 0; i < month; i++) {
        balance = total_income;
        printf("\nMonth %d:\n", i + 1);
        for (j = 0; j < MAX_ITEMS; j++) {
            if (strcmp(income[j].name, "Salary") == 0) {
                balance += income[j].amount;
                printf("  Income: %s %10.2f\n", income[j].name, income[j].amount);
            }
            if (strcmp(expense[j].name, "Rent") == 0) {
                if (balance < expense[j].amount) {
                    printf("  Error: Insufficient balance for expense %s\n", expense[j].name);
                    goto next_month;
                }
                balance -= expense[j].amount;
                printf("  Expense: %s %10.2f\n", expense[j].name, expense[j].amount);
            }
        }
        printf("  Balance: %10.2f\n", balance);
    }

next_month:;
}