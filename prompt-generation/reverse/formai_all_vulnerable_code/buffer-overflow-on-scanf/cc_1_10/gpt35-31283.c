//FormAI DATASET v1.0 Category: Expense Tracker ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense {
    char category[50];
    float amount;
};

int main() {
    int option, count = 0, i;
    float total = 0;
    struct Expense expenses[100];

    while (1) {
        printf("\n1. Add Expense\n2. View Expense\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\nEnter category: ");
                scanf("%s", expenses[count].category);

                printf("Enter amount: ");
                scanf("%f", &expenses[count].amount);

                total += expenses[count].amount;
                count++;
                printf("\nExpense added successfully.\n");
                break;

            case 2:
                printf("\nExpenses: \n");
                for (i = 0; i < count; i++) {
                    printf("%s: $%.2f\n", expenses[i].category, expenses[i].amount);
                }
                printf("\nTotal Expenses: $%.2f\n", total);
                break;

            case 3:
                printf("\nThank you for using the Expense Tracker.\n");
                exit(0);

            default:
                printf("\nInvalid option. Please choose again.\n");
        }
    }

    return 0;
}