//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
    int date;
} Expense;

void print_expenses(Expense* expenses, int count) {
    printf("Expenses:\n");
    for (int i = 0; i < count; i++) {
        printf("%s - $%.2f - %d\n", expenses[i].name, expenses[i].amount, expenses[i].date);
    }
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int count = 0;

    while (count < MAX_EXPENSES) {
        printf("Enter expense name (or 'done' to finish): ");
        char name[MAX_NAME_LENGTH];
        scanf("%s", name);

        if (strcmp(name, "done") == 0) {
            break;
        }

        printf("Enter expense amount: ");
        float amount;
        scanf("%f", &amount);

        printf("Enter expense date (YYYY-MM-DD): ");
        int date;
        scanf("%d", &date);

        strcpy(expenses[count].name, name);
        expenses[count].amount = amount;
        expenses[count].date = date;
        count++;
    }

    printf("Expenses:\n");
    print_expenses(expenses, count);

    return 0;
}