//FormAI DATASET v1.0 Category: Expense Tracker ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 50

//structure for expense tracker
struct expense {
    char category[MAX_LEN];
    double amount;
};

int main() {
    int choice;
    double total = 0;
    struct expense expenses[MAX_LEN];
    char tempString[MAX_LEN];
    int count = 0;

    printf("***** Welcome to Your Expense Tracker *****\n\n");

    do {
        printf("What would you like to do?\n");
        printf("1. Add Expense\n");
        printf("2. View Total Expense\n");
        printf("3. View Expenses per Category\n");
        printf("4. Exit\n");
        printf("Enter Your Choice (1/2/3/4): ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\nAdd Expense\n");
            printf("Enter Category: ");
            scanf("%s", tempString);
            strcpy(expenses[count].category, tempString);
            printf("Enter Amount: ");
            scanf("%lf", &expenses[count].amount);

            total += expenses[count].amount;
            count++;
            printf("\nExpense Added Successfully!\n");
            break;

        case 2:
            printf("\nTotal Expense: $%lf\n\n", total);
            break;

        case 3:
            printf("\nView Expenses per Category\n");
            printf("Enter Category: ");
            scanf("%s", tempString);

            double categoryTotal = 0;
            int found = 0;
            for (int i = 0; i < count; i++) {
                if (strcmp(expenses[i].category, tempString) == 0) {
                    categoryTotal += expenses[i].amount;
                    found = 1;
                }
            }

            if (found == 1) {
                printf("Expenses for category %s: $%lf\n\n", tempString, categoryTotal);
            } else {
                printf("No expenses found for category %s\n\n", tempString);
            }
            break;

        case 4:
            printf("\nThank you for using Your Expense Tracker\n\n");
            break;

        default:
            printf("\nInvalid Choice! Try Again.\n\n");
            break;
        }

    } while (choice != 4);

    return 0;
}