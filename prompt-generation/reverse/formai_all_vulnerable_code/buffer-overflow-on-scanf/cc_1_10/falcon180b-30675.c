//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_CATEGORIES 50

typedef struct {
    char name[50];
    char category[50];
    double amount;
    time_t date;
} Expense;

Expense expenses[MAX_ITEMS];
int num_expenses = 0;
char categories[MAX_CATEGORIES][50];
int num_categories = 0;

void add_expense() {
    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);
    printf("Enter expense category: ");
    scanf("%s", expenses[num_expenses].category);
    printf("Enter expense amount: $");
    scanf("%lf", &expenses[num_expenses].amount);
    time_t now = time(NULL);
    expenses[num_expenses].date = now;
    num_expenses++;
}

void view_expenses() {
    printf("Expense Name | Expense Category | Expense Amount | Date\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%-20s | %-20s | $%.2lf | %s\n", expenses[i].name, expenses[i].category, expenses[i].amount, ctime(&expenses[i].date));
    }
}

void view_categories() {
    printf("Expense Categories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s\n", categories[i]);
    }
}

void add_category() {
    printf("Enter new category: ");
    scanf("%s", categories[num_categories]);
    num_categories++;
}

int main() {
    srand(time(NULL));
    printf("Welcome to the Expense Tracker 3000!\n");
    printf("Initializing...\n");
    for (int i = 0; i < MAX_CATEGORIES; i++) {
        categories[i][0] = '\0';
    }
    num_categories = 0;
    num_expenses = 0;
    add_category();
    add_category();
    add_category();
    add_category();
    add_category();
    add_expense();
    add_expense();
    add_expense();
    add_expense();
    add_expense();
    add_expense();
    add_expense();
    add_expense();
    add_expense();
    add_expense();
    view_expenses();
    view_categories();
    return 0;
}