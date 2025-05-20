//FormAI DATASET v1.0 Category: Expense Tracker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_EXPENSES 10

struct Expense {
    char name[30];
    float amount;
    char category[20];
};

// Function to get user input
void get_input(struct Expense *e) {
    printf("Enter the name of the expense: ");
    scanf("%s", e->name);
    printf("Enter the amount of the expense: ");
    scanf("%f", &e->amount);
    printf("Enter the category of the expense: ");
    scanf("%s", e->category);
}

// Function to display list of expenses
void display_expenses(struct Expense expenses[], int count) {
    printf("Expenses:\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%.2f\t%s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

int main() {
    struct Expense expenses[MAX_EXPENSES];
    int count = 0;
    char input[10];

    printf("*** Expense Tracker ***\n");

    while (1) {
        printf("\nOptions:\n");
        printf("1. Add Expense\n");
        printf("2. Display Expenses\n");
        printf("3. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%s", input);

        if (strcmp(input, "1") == 0) {
            if (count < MAX_EXPENSES) {
                struct Expense e;
                get_input(&e);
                expenses[count] = e;
                count++;
                printf("Expense added successfully.\n");
            } else {
                printf("Error: Maximum expenses reached.\n");
            }
        } else if (strcmp(input, "2") == 0) {
            if (count == 0) {
                printf("No expenses to display.\n");
            } else {
                display_expenses(expenses, count);
            }
        } else if (strcmp(input, "3") == 0) {
            printf("Exiting the program.\n");
            break;
        } else {
            printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}