//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    double amount;
} item;

void add_item(item *items, int *num_items, int max_items) {
    printf("Enter the name of the item: ");
    scanf("%s", items[*num_items].name);
    printf("Enter the amount: $");
    scanf("%lf", &items[*num_items].amount);
    (*num_items)++;
}

void display_items(item *items, int num_items) {
    printf("Item\tAmount\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t$%.2f\n", items[i].name, items[i].amount);
    }
}

int main() {
    item items[MAX_ITEMS];
    int num_items = 0;

    printf("Welcome to the Personal Finance Planner!\n");
    printf("Please enter your income:\n");
    double income;
    scanf("%lf", &income);

    add_item(items, &num_items, MAX_ITEMS);
    printf("Please enter your expenses:\n");

    while (num_items < MAX_ITEMS) {
        add_item(items, &num_items, MAX_ITEMS);
    }

    double total_expenses = 0.0;
    for (int i = 0; i < num_items; i++) {
        total_expenses += items[i].amount;
    }

    double savings = income - total_expenses;

    printf("\nYour total expenses are: $%.2f\n", total_expenses);
    printf("Your total savings are: $%.2f\n", savings);

    return 0;
}