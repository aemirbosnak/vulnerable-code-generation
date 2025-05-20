//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

struct expense {
    char name[50];
    float amount;
    int date;
};

void add_expense(struct expense *expenses, int num_expenses) {
    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[num_expenses].amount);
    printf("Enter expense date (YYYY-MM-DD): ");
    scanf("%d", &expenses[num_expenses].date);
    num_expenses++;
}

void display_expenses(struct expense expenses[], int num_expenses) {
    for (int i = 0; i < num_expenses; i++) {
        printf("%s\t%.2f\t%d\n", expenses[i].name, expenses[i].amount, expenses[i].date);
    }
}

void sort_expenses(struct expense expenses[], int num_expenses, int sort_by) {
    for (int i = 0; i < num_expenses - 1; i++) {
        for (int j = i + 1; j < num_expenses; j++) {
            if (sort_by == 1) {
                if (expenses[i].amount > expenses[j].amount) {
                    struct expense temp = expenses[i];
                    expenses[i] = expenses[j];
                    expenses[j] = temp;
                }
            } else if (sort_by == 2) {
                if (expenses[i].date < expenses[j].date) {
                    struct expense temp = expenses[i];
                    expenses[i] = expenses[j];
                    expenses[j] = temp;
                }
            }
        }
    }
}

int main() {
    struct expense expenses[MAX_EXPENSES];
    int num_expenses = 0;

    while (num_expenses < MAX_EXPENSES) {
        printf("Do you want to add an expense? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'y') {
            add_expense(expenses, num_expenses);
        } else if (choice == 'n') {
            break;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    printf("Enter 1 to sort by expense amount or 2 to sort by expense date: ");
    int sort_by;
    scanf("%d", &sort_by);

    sort_expenses(expenses, num_expenses, sort_by);

    printf("Sorted expenses:\n");
    display_expenses(expenses, num_expenses);

    return 0;
}