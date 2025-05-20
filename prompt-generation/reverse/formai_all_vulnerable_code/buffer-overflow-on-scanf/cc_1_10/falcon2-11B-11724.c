//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
    char description[100];
    double amount;
};

int main() {
    struct expense expenses[10];
    int i, j, k;
    char input[100];
    double total = 0;

    printf("Welcome to the Expense Tracker!\n");
    printf("Enter the number of expenses:\n");
    scanf("%d", &k);
    for (i = 0; i < k; i++) {
        printf("Enter expense %d:\n", i + 1);
        printf("Description: ");
        scanf("%s", input);
        printf("Amount: ");
        scanf("%lf", &expenses[i].amount);
        strcpy(expenses[i].description, input);
    }
    for (i = 0; i < k; i++) {
        printf("Expense %d:\n", i + 1);
        printf("Description: %s\n", expenses[i].description);
        printf("Amount: %.2f\n", expenses[i].amount);
    }
    printf("Total amount: %.2f\n", total);
    printf("Do you want to add another expense? (Y/N): ");
    scanf(" %c", &input);
    if (input == 'y') {
        for (i = 0; i < k; i++) {
            if (strcmp(expenses[i].description, input) == 0) {
                printf("Expense already exists.\n");
                break;
            }
        }
        printf("Enter the amount of the new expense: ");
        scanf("%lf", &total);
        for (i = 0; i < k; i++) {
            if (strcmp(expenses[i].description, input) == 0) {
                expenses[i].amount += total;
                break;
            }
        }
    }
    printf("Total amount: %.2f\n", total);
    printf("Thank you for using the Expense Tracker!\n");
    return 0;
}