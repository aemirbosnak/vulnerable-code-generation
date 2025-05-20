//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 1000

struct Expense {
    char category[20];
    char description[50];
    float amount;
    time_t date;
};

void add_expense(struct Expense expenses[], int size, struct Expense new_expense) {
    if (size >= MAX_SIZE) {
        printf("Maximum size of %d expenses reached\n", MAX_SIZE);
        return;
    }
    strcpy(expenses[size].category, new_expense.category);
    strcpy(expenses[size].description, new_expense.description);
    expenses[size].amount = new_expense.amount;
    expenses[size].date = new_expense.date;
    size++;
}

void display_expenses(struct Expense expenses[], int size) {
    printf("Category\tDescription\tAmount\tDate\n");
    for (int i = 0; i < size; i++) {
        printf("%s\t%s\t\t%.2f\t%s\n", expenses[i].category, expenses[i].description, expenses[i].amount, ctime(&expenses[i].date));
    }
}

int main() {
    struct Expense expenses[MAX_SIZE];
    int size = 0;

    while (1) {
        printf("1. Add expense\n2. Display expenses\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                struct Expense new_expense;
                printf("Enter category: ");
                scanf("%s", new_expense.category);
                printf("Enter description: ");
                scanf("%s", new_expense.description);
                printf("Enter amount: ");
                scanf("%f", &new_expense.amount);
                new_expense.date = time(NULL);
                add_expense(expenses, size, new_expense);
                break;
            }
            case 2:
                display_expenses(expenses, size);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}