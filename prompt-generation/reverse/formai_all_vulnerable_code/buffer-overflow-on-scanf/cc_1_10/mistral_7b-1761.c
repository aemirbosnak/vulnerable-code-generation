//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

// Expense struct definition
typedef struct {
    char name[50];
    float cost;
    char category[20];
} Expense;

// Global variables
Expense expenses[100];
int num_expenses = 0;

// Function to add an expense to the array
void add_expense(char name[], char category[], float cost) {
    if (num_expenses < 100) {
        strcpy(expenses[num_expenses].name, name);
        strcpy(expenses[num_expenses].category, category);
        expenses[num_expenses].cost = cost;
        num_expenses++;
    } else {
        printf("Array is full. Cannot add expense.\n");
    }
}

// Function to display all expenses and their totals
void display_expenses() {
    float total = 0.0;
    printf("\nExpenses:\n");
    printf("%-20s %-10s %-15s\n", "Name", "Category", "Cost");
    for (int i = 0; i < num_expenses; i++) {
        printf("%-20s %-10s $%.2f\n", expenses[i].name, expenses[i].category, expenses[i].cost);
        total += expenses[i].cost;
    }
    printf("\nTotal expenses: $%.2f\n", total);
}

int main() {
    char name[50], category[20];
    float cost;
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add expense\n");
        printf("2. Display expenses\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter category: ");
                scanf("%s", category);
                printf("Enter cost: ");
                scanf("%f", &cost);
                add_expense(name, category, cost);
                break;
            case 2:
                display_expenses();
                break;
            case 3:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}