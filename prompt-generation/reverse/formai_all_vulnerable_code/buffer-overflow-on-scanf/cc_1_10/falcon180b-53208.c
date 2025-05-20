//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_NAME_LEN 100
#define MAX_CATEGORY_LEN 50
#define MAX_AMOUNT_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char category[MAX_CATEGORY_LEN];
    char amount[MAX_AMOUNT_LEN];
} ExpenseItem;

ExpenseItem items[MAX_ITEMS];
int num_items = 0;

void add_expense(char* name, char* category, char* amount) {
    if (num_items >= MAX_ITEMS) {
        printf("Error: Too many expenses.\n");
        return;
    }

    strcpy(items[num_items].name, name);
    strcpy(items[num_items].category, category);
    strcpy(items[num_items].amount, amount);

    num_items++;
}

void print_expenses() {
    printf("Expenses:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s - %s - %s\n", items[i].name, items[i].category, items[i].amount);
    }
}

void print_total() {
    float total = 0.0;
    for (int i = 0; i < num_items; i++) {
        total += atof(items[i].amount);
    }

    printf("Total Expenses: $%.2f\n", total);
}

int main() {
    char name[MAX_NAME_LEN];
    char category[MAX_CATEGORY_LEN];
    char amount[MAX_AMOUNT_LEN];

    while (1) {
        printf("Enter expense name: ");
        scanf("%s", name);
        printf("Enter expense category: ");
        scanf("%s", category);
        printf("Enter expense amount: ");
        scanf("%s", amount);

        add_expense(name, category, amount);
    }

    return 0;
}