//FormAI DATASET v1.0 Category: Expense Tracker ; Style: complete
#include <stdio.h>
#include <stdlib.h>

struct Expense {
    char title[50];
    float amount;
};

int main() {
    struct Expense expenses[100]; // Maximum number of expenses set to 100
    int expenseCount = 0;
    int choice;

    do {
        printf("\nExpense Tracker");
        printf("\n1. Add Expense");
        printf("\n2. View Expenses");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                fflush(stdin); // Cleanup input buffer
                printf("\nEnter expense title: ");
                fgets(expenses[expenseCount].title, sizeof(expenses[expenseCount].title), stdin);
                printf("Enter expense amount: ");
                scanf("%f", &expenses[expenseCount].amount);
                expenseCount++;
                printf("\nExpense added successfully!");
                break;
            case 2:
                printf("\nExpense List:\n");
                printf("%-50s %-10s\n", "Title", "Amount");
                printf("---------------------------------------------------------------\n");
                for (int i = 0; i < expenseCount; i++) {
                    printf("%-50s %-10.2f\n", expenses[i].title, expenses[i].amount);
                }
                break;
            case 3:
                printf("\nExiting...");
                exit(0);
                break;
            default:
                printf("\nInvalid choice!");
                break;
        }

    } while (choice != 3);

    return 0;
}