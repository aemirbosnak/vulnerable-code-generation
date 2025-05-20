//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_CATEGORY_LENGTH 50
#define MAX_AMOUNT_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    char amount[MAX_AMOUNT_LENGTH];
} expense_item;

expense_item expenses[MAX_ITEMS];
int num_items = 0;

void add_expense(void) {
    printf("Enter expense name: ");
    scanf("%s", expenses[num_items].name);

    printf("Enter expense description: ");
    scanf("%s", expenses[num_items].description);

    printf("Enter expense category: ");
    scanf("%s", expenses[num_items].category);

    printf("Enter expense amount: ");
    scanf("%s", expenses[num_items].amount);

    num_items++;
}

void display_expenses(void) {
    printf("\nExpense List:\n");

    for (int i = 0; i < num_items; i++) {
        printf("%d. %s\n", i+1, expenses[i].name);
        printf("%s\n", expenses[i].description);
        printf("%s\n", expenses[i].category);
        printf("%s\n\n", expenses[i].amount);
    }
}

int main() {
    printf("Welcome to the Expense Tracker!\n");

    int choice;
    do {
        printf("\nChoose an option:\n");
        printf("1. Add expense\n");
        printf("2. Display expenses\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                display_expenses();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option.\n");
        }
    } while (choice!= 3);

    return 0;
}