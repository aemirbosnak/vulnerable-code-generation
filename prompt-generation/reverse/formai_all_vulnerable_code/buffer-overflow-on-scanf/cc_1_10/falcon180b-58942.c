//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    float amount;
    char date[20];
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense() {
    char name[50];
    float amount;
    char date[20];

    printf("Enter expense name: ");
    scanf("%s", name);

    printf("Enter expense amount: ");
    scanf("%f", &amount);

    printf("Enter expense date (YYYY-MM-DD): ");
    scanf("%s", date);

    strcpy(expenses[num_expenses].name, name);
    expenses[num_expenses].amount = amount;
    strcpy(expenses[num_expenses].date, date);

    num_expenses++;
}

void list_expenses() {
    printf("Name\tAmount\tDate\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s\t%.2f\t%s\n", expenses[i].name, expenses[i].amount, expenses[i].date);
    }
}

void sort_expenses_by_date() {
    for (int i = 0; i < num_expenses - 1; i++) {
        for (int j = i + 1; j < num_expenses; j++) {
            if (strcmp(expenses[i].date, expenses[j].date) > 0) {
                Expense temp = expenses[i];
                expenses[i] = expenses[j];
                expenses[j] = temp;
            }
        }
    }
}

void sort_expenses_by_amount() {
    for (int i = 0; i < num_expenses - 1; i++) {
        for (int j = i + 1; j < num_expenses; j++) {
            if (expenses[i].amount > expenses[j].amount) {
                Expense temp = expenses[i];
                expenses[i] = expenses[j];
                expenses[j] = temp;
            }
        }
    }
}

int main() {
    int choice;

    do {
        printf("1. Add expense\n");
        printf("2. List expenses\n");
        printf("3. Sort expenses by date\n");
        printf("4. Sort expenses by amount\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                list_expenses();
                break;
            case 3:
                sort_expenses_by_date();
                list_expenses();
                break;
            case 4:
                sort_expenses_by_amount();
                list_expenses();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}