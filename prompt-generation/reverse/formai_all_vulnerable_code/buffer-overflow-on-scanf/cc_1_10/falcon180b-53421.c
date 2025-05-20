//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

struct expense {
    char name[50];
    float amount;
    char category[20];
};

void add_expense(struct expense expenses[], int *size) {
    if (*size == MAX) {
        printf("Cannot add more expenses. List is full.\n");
        return;
    }

    printf("Enter expense name: ");
    scanf("%s", expenses[*size].name);

    printf("Enter expense amount: $");
    scanf("%f", &expenses[*size].amount);

    printf("Enter expense category: ");
    scanf("%s", expenses[*size].category);

    (*size)++;
}

void view_expenses(struct expense expenses[], int size) {
    printf("\nExpense List:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - $%.2f - %s\n", i+1, expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

void search_expense(struct expense expenses[], int size, char *query) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (strstr(expenses[i].name, query)!= NULL || strstr(expenses[i].category, query)!= NULL) {
            printf("%d. %s - $%.2f - %s\n", i+1, expenses[i].name, expenses[i].amount, expenses[i].category);
            count++;
        }
    }

    if (count == 0) {
        printf("No results found.\n");
    }
}

int main() {
    struct expense expenses[MAX];
    int size = 0;

    add_expense(expenses, &size);
    add_expense(expenses, &size);
    add_expense(expenses, &size);

    view_expenses(expenses, size);

    char query[50];
    printf("\nEnter search query: ");
    scanf("%s", query);

    search_expense(expenses, size, query);

    return 0;
}