//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CATEGORIES 20
#define MAX_EXPENSES 50
#define MAX_DESCRIPTION 200

typedef struct {
    char name[MAX_DESCRIPTION];
    float amount;
    time_t date;
} expense;

typedef struct {
    char name[MAX_DESCRIPTION];
    int num_expenses;
    expense expenses[MAX_EXPENSES];
} category;

category categories[MAX_CATEGORIES];
int num_categories = 0;

void add_category() {
    printf("Enter category name: ");
    scanf("%s", categories[num_categories].name);
    categories[num_categories].num_expenses = 0;
    num_categories++;
}

void add_expense() {
    printf("Enter expense name: ");
    scanf("%s", categories[num_categories - 1].expenses[categories[num_categories - 1].num_expenses].name);
    printf("Enter expense amount: ");
    scanf("%f", &categories[num_categories - 1].expenses[categories[num_categories - 1].num_expenses].amount);
    categories[num_categories - 1].expenses[categories[num_categories - 1].num_expenses].date = time(NULL);
    categories[num_categories - 1].num_expenses++;
}

void view_expenses() {
    printf("Category: %s\n", categories[num_categories - 1].name);
    printf("Expenses:\n");
    for (int i = 0; i < categories[num_categories - 1].num_expenses; i++) {
        printf("Name: %s\nAmount: $%.2f\nDate: %s", categories[num_categories - 1].expenses[i].name, categories[num_categories - 1].expenses[i].amount, ctime(&categories[num_categories - 1].expenses[i].date));
    }
}

int main() {
    printf("Welcome to the Expense Tracker!\n");
    while (1) {
        printf("\n1. Add Category\n2. Add Expense\n3. View Expenses\n4. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
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
    }
    return 0;
}