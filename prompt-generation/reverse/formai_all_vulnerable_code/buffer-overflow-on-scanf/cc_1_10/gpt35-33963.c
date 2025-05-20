//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct expense {
    char name[20];
    float amount;
    char category[20];
} expense;

void add_expense(expense *expenses, int *count) {
    printf("Enter expense name: ");
    scanf("%s", expenses[*count].name);

    printf("Enter amount: ");
    scanf("%f", &expenses[*count].amount);

    printf("Enter category: ");
    scanf("%s", expenses[*count].category);

    printf("Expense added!\n");

    (*count)++;
}

void show_expenses(expense *expenses, int count) {
    printf("Expenses:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s\n", expenses[i].name);
        printf("Amount: %.2f Credits\n", expenses[i].amount);
        printf("Category: %s\n", expenses[i].category);
        printf("\n");
    }
}

void show_categories(expense *expenses, int count) {
    printf("Categories:\n");
    for (int i = 0; i < count; i++) {
        int found = 0;
        for (int j = 0; j < i; j++) {
            if (strcmp(expenses[i].category, expenses[j].category) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("%s\n", expenses[i].category);
        }
    }
}

int main() {
    int count = 0;
    expense expenses[100];
    int option;

    printf("Welcome to the Expense Tracker, Cyberpunk edition!\n");

    do {
        printf("What would you like to do?\n");
        printf("1. Add an expense\n");
        printf("2. Show all expenses\n");
        printf("3. Show categories\n");
        printf("4. Exit\n");
        printf("Enter option: ");

        scanf("%d", &option);

        switch (option) {
            case 1:
                add_expense(expenses, &count);
                break;
            case 2:
                show_expenses(expenses, count);
                break;
            case 3:
                show_categories(expenses, count);
                break;
            case 4:
                printf("Exiting Expense Tracker... We'll see you again!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }

        printf("\n");

    } while (option != 4);

    return 0;
}