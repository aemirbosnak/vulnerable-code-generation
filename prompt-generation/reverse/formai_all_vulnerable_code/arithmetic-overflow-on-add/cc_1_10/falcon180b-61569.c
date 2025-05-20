//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    float amount;
    int month;
    int day;
    int year;
} Expense;

typedef struct {
    char name[50];
    int num_expenses;
    Expense expenses[MAX_EXPENSES];
} Category;

Category categories[MAX_CATEGORIES];
int num_categories;

void add_category() {
    printf("Enter category name: ");
    scanf("%s", categories[num_categories].name);
    categories[num_categories].num_expenses = 0;
    num_categories++;
}

void add_expense() {
    int i;
    for(i = 0; i < num_categories; i++) {
        if(categories[i].num_expenses >= MAX_EXPENSES) {
            printf("Category %s is full.\n", categories[i].name);
            return;
        }
    }
    printf("Enter category name: ");
    scanf("%s", categories[num_categories].name);
    printf("Enter expense name: ");
    scanf("%s", categories[num_categories].expenses[categories[num_categories].num_expenses].name);
    printf("Enter expense amount: ");
    scanf("%f", &categories[num_categories].expenses[categories[num_categories].num_expenses].amount);
    printf("Enter expense date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &categories[num_categories].expenses[categories[num_categories].num_expenses].month, &categories[num_categories].expenses[categories[num_categories].num_expenses].day, &categories[num_categories].expenses[categories[num_categories].num_expenses].year);
    categories[num_categories].num_expenses++;
    num_categories++;
}

void view_expenses() {
    int i, j;
    printf("\nExpenses:\n");
    for(i = 0; i < num_categories; i++) {
        printf("Category: %s\n", categories[i].name);
        for(j = 0; j < categories[i].num_expenses; j++) {
            printf("- %s: $%.2f (%d/%d/%d)\n", categories[i].expenses[j].name, categories[i].expenses[j].amount, categories[i].expenses[j].month, categories[i].expenses[j].day, categories[i].expenses[j].year);
        }
    }
}

int main() {
    int choice;
    char cont;

    num_categories = 0;

    printf("Welcome to the Expense Tracker!\n");

    do {
        printf("\nMenu:\n");
        printf("1. Add category\n");
        printf("2. Add expense\n");
        printf("3. View expenses\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
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