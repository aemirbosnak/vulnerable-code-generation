//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct expense {
    char *category;
    double amount;
    struct expense *next;
} expense;

expense *create_expense(char *category, double amount) {
    expense *new_expense = (expense *) malloc(sizeof(expense));
    new_expense->category = category;
    new_expense->amount = amount;
    new_expense->next = NULL;
    return new_expense;
}

void print_expenses(expense *root) {
    if (root == NULL) {
        printf("No expenses found.\n");
        return;
    }
    printf("Expenses:\n");
    printf("----------------\n");
    printf("Category\tAmount\n");
    while (root!= NULL) {
        printf("%s\t%.2f\n", root->category, root->amount);
        root = root->next;
    }
}

double calculate_total_expenses(expense *root) {
    double total = 0.0;
    if (root == NULL) {
        printf("No expenses found.\n");
        return 0.0;
    }
    while (root!= NULL) {
        total += root->amount;
        root = root->next;
    }
    return total;
}

int main() {
    char choice;
    expense *root = NULL;

    do {
        printf("\nExpense Tracker\n");
        printf("----------------\n");
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter category: ");
                char *category = (char *) malloc(100 * sizeof(char));
                scanf("%s", category);
                printf("Enter amount: ");
                double amount;
                scanf("%lf", &amount);
                root = create_expense(category, amount);
                break;
            case '2':
                printf("Total expenses: $%.2f\n", calculate_total_expenses(root));
                print_expenses(root);
                break;
            case '3':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice!= '3');

    return 0;
}