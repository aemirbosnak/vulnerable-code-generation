//FormAI DATASET v1.0 Category: Expense Tracker ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
    char name[50];
    float cost;
    int quantity;
    float total;
};

int main() {
    int num_expenses;
    struct expense expenses[10];

    printf("Welcome to the Expense Tracker!\n");
    printf("How many items would you like to input? (Up to 10)\n");
    scanf("%d", &num_expenses);
    getchar();

    if (num_expenses > 10 || num_expenses < 1) {
        printf("Invalid number of items. Please enter 1 to 10.\n");
        exit(0);
    }

    for (int i=0; i<num_expenses; i++) {
        printf("Enter the name of item %d: ", i+1);
        fgets(expenses[i].name, 50, stdin);
        printf("Enter the cost of item %d: ", i+1);
        scanf("%f", &expenses[i].cost);
        printf("Enter the quantity of item %d: ", i+1);
        scanf("%d", &expenses[i].quantity);
        expenses[i].total = expenses[i].cost * expenses[i].quantity;
        getchar();
    }

    printf("\n");

    float grand_total = 0;

    printf("Expenses for Each Item\n");
    printf("----------------------\n");
    for (int i=0; i<num_expenses; i++) {
        printf("%d. %s", i+1, expenses[i].name);
        printf("Price: $%.2f\n", expenses[i].cost);
        printf("Quantity: %d\n", expenses[i].quantity);
        printf("Total: $%.2f\n", expenses[i].total);
        printf("\n");
        grand_total += expenses[i].total;
    }

    printf("----------------------\n");
    printf("Total Expense: $%.2f\n", grand_total);
    printf("----------------------\n");

    return 0;
}