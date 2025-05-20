//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_CATEGORY_LENGTH 30
#define MAX_AMOUNT_LENGTH 10

struct item {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    char amount[MAX_AMOUNT_LENGTH];
};

int main() {
    struct item expenses[MAX_ITEMS];
    int num_expenses = 0;

    char input[MAX_AMOUNT_LENGTH];
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    char temp[MAX_ITEMS][MAX_AMOUNT_LENGTH];
    int i;

    printf("Welcome to Sherlock Holmes' Expense Tracker\n");

    while (1) {
        printf("\nEnter an expense (name, category, amount): ");
        scanf("%s %s %s", name, category, input);

        for (i = 0; i < num_expenses; i++) {
            if (strcmp(expenses[i].name, name) == 0 && strcmp(expenses[i].category, category) == 0) {
                printf("\nDuplicate expense found!\n");
                break;
            }
        }

        if (i == num_expenses) {
            strcpy(expenses[num_expenses].name, name);
            strcpy(expenses[num_expenses].category, category);
            strcpy(temp[num_expenses], input);
            num_expenses++;
        }
    }

    printf("\nExpense Report:\n");

    for (i = 0; i < num_expenses; i++) {
        printf("\nName: %s\nCategory: %s\nAmount: %s\n", expenses[i].name, expenses[i].category, temp[i]);
    }

    return 0;
}