//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EXPENSES 100

typedef struct {
    char category[50];
    float amount;
    time_t date;
} Expense;

void add_expense(Expense* expenses, int num_expenses, char* category, float amount) {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Error: Maximum number of expenses reached.\n");
        return;
    }

    strcpy(expenses[num_expenses].category, category);
    expenses[num_expenses].amount = amount;
    time(&expenses[num_expenses].date);

    num_expenses++;
}

void display_expenses(Expense* expenses, int num_expenses) {
    printf("Expenses:\n");
    printf("Category\tAmount\tDate\n");

    for (int i = 0; i < num_expenses; i++) {
        printf("%s\t%f\t%s\n", expenses[i].category, expenses[i].amount, ctime(&expenses[i].date));
    }
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int num_expenses = 0;

    while (1) {
        printf("Enter category, amount, and date (YYYY-MM-DD HH:MM:SS):\n");
        char category[50];
        scanf("%s", category);
        float amount;
        scanf("%f", &amount);
        time_t date;
        struct tm* timeinfo;

        strptime(category, "%Y-%m-%d %H:%M:%S", &timeinfo);
        date = mktime(timeinfo);

        add_expense(expenses, num_expenses, category, amount);
        num_expenses++;

        display_expenses(expenses, num_expenses);
    }

    return 0;
}