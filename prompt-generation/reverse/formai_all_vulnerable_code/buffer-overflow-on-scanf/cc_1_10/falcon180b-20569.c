//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPENSES 100
#define MAX_CATEGORIES 10
#define MAX_CATEGORY_NAME_LENGTH 50
#define MAX_EXPENSE_NAME_LENGTH 100

typedef struct {
    char name[MAX_CATEGORY_NAME_LENGTH];
    int expenses[MAX_EXPENSES];
} Category;

typedef struct {
    char name[MAX_EXPENSE_NAME_LENGTH];
    float amount;
    char category[MAX_CATEGORY_NAME_LENGTH];
} Expense;

Category categories[MAX_CATEGORIES];
Expense expenses[MAX_EXPENSES];
int num_categories = 0;
int num_expenses = 0;

void add_category(char* name) {
    strcpy(categories[num_categories].name, name);
    num_categories++;
}

void add_expense(char* name, float amount, char* category) {
    strcpy(expenses[num_expenses].name, name);
    expenses[num_expenses].amount = amount;
    strcpy(expenses[num_expenses].category, category);
    num_expenses++;
}

int main() {
    char input[100];
    int choice;
    do {
        printf("1. Add category\n2. Add expense\n3. View expenses by category\n4. View total expenses\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter category name: ");
            scanf("%s", input);
            add_category(input);
            break;
        case 2:
            printf("Enter expense name: ");
            scanf("%s", input);
            printf("Enter category: ");
            scanf("%s", input);
            add_expense(input, 0, input);
            break;
        case 3:
            printf("Enter category: ");
            scanf("%s", input);
            for (int i = 0; i < num_expenses; i++) {
                if (strcmp(input, expenses[i].category) == 0) {
                    printf("Expense: %s\tAmount: $%.2f\n", expenses[i].name, expenses[i].amount);
                }
            }
            break;
        case 4:
            printf("Total expenses: $%.2f\n", 0);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    } while (choice!= 5);
    return 0;
}