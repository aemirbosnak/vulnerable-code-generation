//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_CATEGORIES 10
#define MAX_CATEGORY_NAME_LENGTH 50
#define MAX_EXPENSE_NAME_LENGTH 100

typedef struct {
    char name[MAX_CATEGORY_NAME_LENGTH];
    int expenses[MAX_EXPENSES];
} category;

typedef struct {
    char name[MAX_EXPENSE_NAME_LENGTH];
    int amount;
    int category;
} expense;

category categories[MAX_CATEGORIES];
expense expenses[MAX_EXPENSES];
int num_categories = 0;
int num_expenses = 0;

void add_category() {
    char name[MAX_CATEGORY_NAME_LENGTH];
    printf("Enter category name: ");
    scanf("%s", name);
    strcpy(categories[num_categories].name, name);
    num_categories++;
}

void add_expense() {
    char name[MAX_EXPENSE_NAME_LENGTH];
    int amount, category;
    printf("Enter expense name: ");
    scanf("%s", name);
    printf("Enter expense amount: ");
    scanf("%d", &amount);
    printf("Enter expense category (0-%d): ", num_categories - 1);
    scanf("%d", &category);
    strcpy(expenses[num_expenses].name, name);
    expenses[num_expenses].amount = amount;
    expenses[num_expenses].category = category;
    num_expenses++;
}

void view_expenses() {
    printf("Category\tExpense\tAmount\n");
    for(int i=0; i<num_categories; i++) {
        printf("%s:\n", categories[i].name);
        for(int j=0; j<num_expenses; j++) {
            if(expenses[j].category == i) {
                printf("\t%s\t\t%d\n", expenses[j].name, expenses[j].amount);
            }
        }
    }
}

int main() {
    int choice;
    do {
        printf("1. Add category\n2. Add expense\n3. View expenses\n4. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_category();
                break;
            case 2:
                add_expense();
                break;
            case 3:
                view_expenses();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while(1);
    return 0;
}