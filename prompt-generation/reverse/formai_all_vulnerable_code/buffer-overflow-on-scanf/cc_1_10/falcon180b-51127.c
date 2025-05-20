//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    float amount;
    char category[50];
} Expense;

Expense expenses[MAX_EXPENSES];
char categories[MAX_CATEGORIES][50];
int num_categories;
int num_expenses;

void add_category() {
    printf("Enter category name: ");
    scanf("%s", categories[num_categories]);
    num_categories++;
}

void add_expense() {
    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[num_expenses].amount);
    printf("Enter expense category: ");
    scanf("%s", expenses[num_expenses].category);
    num_expenses++;
}

void view_expenses() {
    printf("\nExpense Report\n");
    printf("=================\n");
    for(int i=0; i<num_expenses; i++) {
        printf("%-20s %-10s %-20s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

int main() {
    int choice;
    char cont;

    do {
        printf("\nWelcome to the Expense Tracker!\n");
        printf("=============================\n");
        printf("1. Add category\n");
        printf("2. Add expense\n");
        printf("3. View expenses\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
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
                printf("Are you sure you want to exit? (y/n): ");
                scanf(" %c", &cont);
                if(cont == 'y' || cont == 'Y') {
                    exit(0);
                }
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(1);

    return 0;
}