//Code Llama-13B DATASET v1.0 Category: Expense Tracker ; Style: Ada Lovelace
/*
 * Unique C Expense Tracker Program
 *
 * This program allows users to track their expenses by category.
 *
 * The program takes in input from the user in the form of a category and
 * an amount, and then updates the total amount spent in that category.
 *
 * The program also allows the user to view the total amount spent in
 * each category and the overall total amount spent.
 *
 * The program uses a hash table to store the categories and their
 * corresponding amounts.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 100

struct Category {
    char name[50];
    double amount;
};

struct Category categories[MAX_CATEGORIES];

void add_expense(char* category, double amount) {
    for (int i = 0; i < MAX_CATEGORIES; i++) {
        if (strcmp(categories[i].name, category) == 0) {
            categories[i].amount += amount;
            return;
        }
    }
    // If the category is not found, add a new one
    for (int i = 0; i < MAX_CATEGORIES; i++) {
        if (strcmp(categories[i].name, "") == 0) {
            strcpy(categories[i].name, category);
            categories[i].amount = amount;
            return;
        }
    }
    printf("Error: too many categories\n");
}

void view_expenses(char* category) {
    for (int i = 0; i < MAX_CATEGORIES; i++) {
        if (strcmp(categories[i].name, category) == 0) {
            printf("Category: %s\nAmount: %f\n", categories[i].name, categories[i].amount);
            return;
        }
    }
    printf("Category not found\n");
}

void view_total_expenses() {
    double total = 0;
    for (int i = 0; i < MAX_CATEGORIES; i++) {
        total += categories[i].amount;
    }
    printf("Total amount spent: %f\n", total);
}

int main() {
    char command[50];
    char category[50];
    double amount;

    while (1) {
        printf("Enter a command: ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter category: ");
            scanf("%s", category);
            printf("Enter amount: ");
            scanf("%lf", &amount);
            add_expense(category, amount);
        } else if (strcmp(command, "view") == 0) {
            printf("Enter category: ");
            scanf("%s", category);
            view_expenses(category);
        } else if (strcmp(command, "total") == 0) {
            view_total_expenses();
        } else {
            printf("Invalid command\n");
        }
    }
    return 0;
}