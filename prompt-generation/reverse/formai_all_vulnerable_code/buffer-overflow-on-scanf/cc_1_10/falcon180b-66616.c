//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_CATEGORIES 50

typedef struct {
    char name[50];
    float amount;
    time_t date;
    int category;
} expense;

typedef struct {
    char name[50];
    int id;
} category;

category categories[MAX_CATEGORIES];
int num_categories;

expense expenses[MAX_EXPENSES];
int num_expenses;

void add_category() {
    printf("Enter category name: ");
    scanf("%s", categories[num_categories].name);
    categories[num_categories].id = num_categories;
    num_categories++;
}

void add_expense() {
    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);
    printf("Enter amount: ");
    scanf("%f", &expenses[num_expenses].amount);
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", expenses[num_expenses].date);
    printf("Enter category: ");
    scanf("%d", &expenses[num_expenses].category);
    num_expenses++;
}

void view_expenses() {
    printf("\nExpenses:\n");
    printf("%-20s %-10s %-15s %-20s\n", "Name", "Amount", "Date", "Category");
    for(int i=0; i<num_expenses; i++) {
        struct tm *t = localtime(&expenses[i].date);
        printf("%-20s %-10.2f %-15s %-20s\n", expenses[i].name, expenses[i].amount, asctime(t), categories[expenses[i].category].name);
    }
}

void view_categories() {
    printf("\nCategories:\n");
    for(int i=0; i<num_categories; i++) {
        printf("%d. %s\n", i+1, categories[i].name);
    }
}

int main() {
    num_categories = 0;
    num_expenses = 0;

    add_category();
    add_category();
    add_category();

    add_expense();
    add_expense();

    view_categories();
    view_expenses();

    return 0;
}