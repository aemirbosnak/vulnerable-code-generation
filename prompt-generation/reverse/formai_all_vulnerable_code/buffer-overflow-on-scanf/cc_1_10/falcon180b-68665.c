//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    float amount;
    char date[20];
} expense;

expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense() {
    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[num_expenses].amount);
    printf("Enter expense date (YYYY-MM-DD): ");
    scanf("%s", expenses[num_expenses].date);
    num_expenses++;
}

void display_expenses() {
    printf("\nExpense Report\n");
    printf("--------------------\n");
    printf("Name\tAmount\tDate\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s\t%.2f\t%s\n", expenses[i].name, expenses[i].amount, expenses[i].date);
    }
    printf("--------------------\n");
}

void search_expense() {
    char search_name[50];
    printf("Enter expense name to search: ");
    scanf("%s", search_name);
    int found = 0;
    for (int i = 0; i < num_expenses; i++) {
        if (strcmp(expenses[i].name, search_name) == 0) {
            printf("\nExpense found:\n");
            printf("Name: %s\n", expenses[i].name);
            printf("Amount: %.2f\n", expenses[i].amount);
            printf("Date: %s\n", expenses[i].date);
            found = 1;
        }
    }
    if (!found) {
        printf("\nExpense not found.\n");
    }
}

int main() {
    int choice;
    do {
        printf("\n");
        printf("1. Add expense\n");
        printf("2. Display expenses\n");
        printf("3. Search expense\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_expense();
                break;
            case 2:
                display_expenses();
                break;
            case 3:
                search_expense();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 4);

    return 0;
}