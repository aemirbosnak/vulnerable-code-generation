//FormAI DATASET v1.0 Category: Expense Tracker ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense {
    char item[50];
    float amount;
};

int main() {
    int choice, num_expenses = 0;
    char option = 'y';
    struct Expense expenses[100]; // Maximum of 100 expenses that can be tracked

    while (option == 'y' || option == 'Y') {
        printf("\n1. Add new expense\n2. View all expenses\n3. View total expenses\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter item name: ");
                scanf("%s", expenses[num_expenses].item);
                printf("Enter amount: ");
                scanf("%f", &expenses[num_expenses].amount);
                num_expenses++;
                printf("\nExpense added successfully!\n");
                break;

            case 2:
                if (num_expenses == 0) {
                    printf("\nNo expenses added yet!\n");
                    break;
                }
                printf("\nAll expenses:\n");
                printf("No.  Item name         Amount\n");
                for (int i = 0; i < num_expenses; i++) {
                    printf("%d    %-15s   %.2f\n", i + 1, expenses[i].item, expenses[i].amount);
                }
                break;

            case 3:
                if (num_expenses == 0) {
                    printf("\nNo expenses added yet!\n");
                    break;
                }
                float total_expenses = 0;
                for (int i = 0; i < num_expenses; i++) {
                    total_expenses += expenses[i].amount;
                }
                printf("\nTotal expenses: %.2f\n", total_expenses);
                break;

            case 4:
                printf("\nGoodbye!\n");
                exit(0);

            default:
                printf("\nInvalid choice!\n");
                break;
        }

        printf("\nDo you want to perform another operation? (y/n): ");
        scanf(" %c", &option);
    }

    return 0;
}