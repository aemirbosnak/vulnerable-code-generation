//FormAI DATASET v1.0 Category: Expense Tracker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
    char category[20];
    float cost;
    struct expense *next;
};

struct expense *head = NULL;
struct expense *current = NULL;

void add_expense(char *category, float cost) {
    struct expense *new_expense = malloc(sizeof(struct expense));
    strcpy(new_expense->category, category);
    new_expense->cost = cost;
    new_expense->next = NULL;

    if (head == NULL) {
        head = new_expense;
    } else {
        current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_expense;
    }
}

void print_expenses() {
    if (head == NULL) {
        printf("No expenses found.\n");
    } else {
        current = head;
        printf("Category\tCost\n");
        while (current != NULL) {
            printf("%s\t\t%.2f\n", current->category, current->cost);
            current = current->next;
        }
    }
}

void total_expenses() {
    if (head == NULL) {
        printf("No expenses found.\n");
    } else {
        current = head;
        float total = 0.0;
        while (current != NULL) {
            total += current->cost;
            current = current->next;
        }
        printf("Total expenses: %.2f\n", total);
    }
}

int main() {
    char choice;
    char category[20];
    float cost;

    while (1) {
        printf("\nExpense Tracker\n");
        printf("---------------\n");
        printf("1. Add Expense\n");
        printf("2. Print Expenses\n");
        printf("3. Total Expenses\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        choice = getchar();

        switch (choice) {
            case '1':
                printf("Enter category: ");
                scanf("%s", category);
                printf("Enter cost: ");
                scanf("%f", &cost);
                add_expense(category, cost);
                break;
            case '2':
                print_expenses();
                break;
            case '3':
                total_expenses();
                break;
            case '4':
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
        while ((getchar()) != '\n');
    }

    return 0;
}