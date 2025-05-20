//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_CATEGORY_LENGTH 20

struct item {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    float amount;
};

int main() {
    char input[100];
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    float amount;
    int i = 0;
    struct item expenses[MAX_ITEMS];

    printf("Welcome to the Expense Tracker, Mr. Holmes.\n");

    while (1) {
        printf("\nEnter 'add' to add an expense, 'view' to view expenses or 'exit' to quit: ");
        scanf("%s", input);

        if (strcmp(input, "add") == 0) {
            printf("\nEnter expense name: ");
            scanf("%s", name);

            printf("Enter expense category: ");
            scanf("%s", category);

            printf("Enter expense amount: ");
            scanf("%f", &amount);

            strcpy(expenses[i].name, name);
            strcpy(expenses[i].category, category);
            expenses[i].amount = amount;
            i++;

            printf("\nExpense added successfully!\n");
        } else if (strcmp(input, "view") == 0) {
            if (i == 0) {
                printf("\nNo expenses added yet.\n");
            } else {
                printf("\nExpenses:\n");
                for (int j = 0; j < i; j++) {
                    printf("\nName: %s\nCategory: %s\nAmount: %.2f\n", expenses[j].name, expenses[j].category, expenses[j].amount);
                }
            }
        } else if (strcmp(input, "exit") == 0) {
            printf("\nThank you for using the Expense Tracker, Mr. Holmes.\n");
            return 0;
        } else {
            printf("\nInvalid input. Please try again.\n");
        }
    }

    return 0;
}