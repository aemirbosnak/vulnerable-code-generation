//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_CATEGORY_LEN 50
#define MAX_AMOUNT_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char category[MAX_CATEGORY_LEN];
    char amount[MAX_AMOUNT_LEN];
} expense_t;

expense_t expenses[MAX_ITEMS];
int num_expenses = 0;

void add_expense() {
    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);
    printf("Enter expense category: ");
    scanf("%s", expenses[num_expenses].category);
    printf("Enter expense amount: ");
    scanf("%s", expenses[num_expenses].amount);
    num_expenses++;
}

void display_expenses() {
    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s - %s - %s\n", expenses[i].name, expenses[i].category, expenses[i].amount);
    }
}

void display_summary() {
    int total_expenses = 0;
    for (int i = 0; i < num_expenses; i++) {
        total_expenses += atoi(expenses[i].amount);
    }
    printf("Total expenses: %d\n", total_expenses);
}

int main() {
    int choice;
    do {
        printf("1. Add expense\n2. Display expenses\n3. Display summary\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                display_expenses();
                break;
            case 3:
                display_summary();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 4);

    return 0;
}