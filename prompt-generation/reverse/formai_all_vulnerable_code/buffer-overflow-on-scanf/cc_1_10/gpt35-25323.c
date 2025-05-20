//FormAI DATASET v1.0 Category: Expense Tracker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
    int id;
    float amount;
    char category[20];
    char date[20];
};

void addExpense(struct expense *expenses, int *count) {
    printf("Enter the amount:\n");
    scanf("%f", &expenses[*count].amount);
    getchar(); // Consume newline character
    printf("Enter the category:\n");
    fgets(expenses[*count].category, 20, stdin);
    expenses[*count].category[strcspn(expenses[*count].category, "\n")] = 0; // Remove newline character
    printf("Enter the date (dd/mm/yyyy):\n");
    fgets(expenses[*count].date, 20, stdin);
    expenses[*count].date[strcspn(expenses[*count].date, "\n")] = 0; // Remove newline character
    expenses[*count].id = *count + 1; // Increment ID
    *count += 1; // Increment count
    printf("Expense added successfully.\n");
}

void displayExpenses(struct expense *expenses, int count) {
    printf("%-5s%-10s%-20s%-20s\n", "ID", "Amount", "Category", "Date");
    for (int i = 0; i < count; i++) {
        printf("%-5d%-10.2f%-20s%-20s\n", expenses[i].id, expenses[i].amount, expenses[i].category, expenses[i].date);
    }
}

int main() {
    struct expense expenses[100];
    int count = 0;
    int choice;
    do {
        printf("Choose an option:\n1. Add an expense\n2. Display all expenses\n3. Exit\n");
        scanf("%d", &choice);
        getchar(); // Consume newline character
        switch (choice) {
            case 1:
                addExpense(expenses, &count);
                break;
            case 2:
                displayExpenses(expenses, count);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 3);
    return 0;
}