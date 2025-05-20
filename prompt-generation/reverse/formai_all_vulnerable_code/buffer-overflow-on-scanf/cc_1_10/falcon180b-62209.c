//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 100

typedef struct {
    char category[50];
    double amount;
    int date;
} Expense;

int main() {
    Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;
    int choice;
    int i;

    do {
        printf("\nExpense Tracker\n");
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Search expenses\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (numExpenses >= MAX_EXPENSES) {
                    printf("Maximum expenses reached.\n");
                } else {
                    printf("Enter expense category: ");
                    scanf("%s", expenses[numExpenses].category);
                    printf("Enter expense amount: ");
                    scanf("%lf", &expenses[numExpenses].amount);
                    printf("Enter expense date (dd/mm/yyyy): ");
                    scanf("%d/%d/%d", &expenses[numExpenses].date);
                    numExpenses++;
                }
                break;
            case 2:
                printf("\nExpenses:\n");
                for (i = 0; i < numExpenses; i++) {
                    printf("%s\t%.2lf\t%d\n", expenses[i].category, expenses[i].amount, expenses[i].date);
                }
                break;
            case 3:
                printf("\nEnter expense category to search: ");
                scanf("%s", expenses[numExpenses].category);
                for (i = 0; i < numExpenses; i++) {
                    if (strcmp(expenses[i].category, expenses[numExpenses].category) == 0) {
                        printf("%s\t%.2lf\t%d\n", expenses[i].category, expenses[i].amount, expenses[i].date);
                    }
                }
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice!= 4);

    return 0;
}