//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000

typedef struct {
    char name[50];
    int amount;
    int category;
} Expense;

Expense expenses[MAX_ITEMS];
int num_expenses = 0;

void add_expense() {
    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);
    printf("Enter expense amount: ");
    scanf("%d", &expenses[num_expenses].amount);
    printf("Enter expense category (1-10): ");
    scanf("%d", &expenses[num_expenses].category);
    num_expenses++;
}

void view_expenses() {
    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s - $%d - Category %d\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

void delete_expense() {
    printf("Enter expense name to delete: ");
    char name[50];
    scanf("%s", name);
    for (int i = 0; i < num_expenses; i++) {
        if (strcmp(name, expenses[i].name) == 0) {
            num_expenses--;
            for (int j = i; j < num_expenses; j++) {
                expenses[j] = expenses[j+1];
            }
            break;
        }
    }
}

void categorize_expenses() {
    int total_expenses = 0;
    int category_count[10] = {0};
    for (int i = 0; i < num_expenses; i++) {
        total_expenses += expenses[i].amount;
        category_count[expenses[i].category-1]++;
    }
    printf("Total expenses: $%d\n", total_expenses);
    printf("Expense categories:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d: $%d\n", i+1, category_count[i] * expenses[0].amount);
    }
}

int main() {
    int choice = 0;
    while (choice!= 4) {
        printf("1. Add expense\n2. View expenses\n3. Delete expense\n4. Categorize expenses\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                view_expenses();
                break;
            case 3:
                delete_expense();
                break;
            case 4:
                categorize_expenses();
                break;
        }
    }
    return 0;
}