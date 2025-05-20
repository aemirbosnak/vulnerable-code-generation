//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float amount;
    char category[50];
} expense;

expense expenses[MAX_ITEMS];
int num_expenses = 0;

void add_expense() {
    if (num_expenses >= MAX_ITEMS) {
        printf("Sorry, you can't add more expenses.\n");
        return;
    }
    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[num_expenses].amount);
    printf("Enter expense category: ");
    scanf("%s", expenses[num_expenses].category);
    num_expenses++;
}

void view_expenses() {
    printf("Name\tAmount\tCategory\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s\t%.2f\t%s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

void search_expense() {
    printf("Enter expense name to search: ");
    char name[50];
    scanf("%s", name);
    for (int i = 0; i < num_expenses; i++) {
        if (strcmp(expenses[i].name, name) == 0) {
            printf("Name: %s\nAmount: %.2f\nCategory: %s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
        }
    }
}

int main() {
    printf("Welcome to the Expense Tracker!\n");
    while (1) {
        printf("\nWhat would you like to do?\n1. Add expense\n2. View expenses\n3. Search expense\n4. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                view_expenses();
                break;
            case 3:
                search_expense();
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}