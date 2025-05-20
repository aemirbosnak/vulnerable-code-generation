//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_AMOUNT_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char amount[MAX_AMOUNT_LEN];
} ExpenseItem;

int main() {
    int numItems = 0;
    ExpenseItem items[MAX_ITEMS];

    printf("Welcome to the Expense Tracker!\n");

    // Loop until user wants to exit
    while (1) {
        printf("\n");
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Exit\n");
        printf("\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (numItems >= MAX_ITEMS) {
                printf("Error: Maximum number of items reached.\n");
            } else {
                printf("Enter expense name: ");
                scanf("%s", items[numItems].name);

                printf("Enter expense amount: ");
                scanf("%s", items[numItems].amount);

                numItems++;
            }
            break;

        case 2:
            if (numItems == 0) {
                printf("No expenses added.\n");
            } else {
                printf("\nExpenses:\n");
                for (int i = 0; i < numItems; i++) {
                    printf("%d. %s - %s\n", i+1, items[i].name, items[i].amount);
                }
            }
            break;

        case 3:
            printf("Thank you for using the Expense Tracker!\n");
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}