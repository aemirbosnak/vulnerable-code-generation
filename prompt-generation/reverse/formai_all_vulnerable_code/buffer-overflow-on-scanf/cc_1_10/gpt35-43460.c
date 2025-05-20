//FormAI DATASET v1.0 Category: Expense Tracker ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct _expense {
    char item[50];
    float amount;
    time_t timestamp;
} Expense;

void clearBuffer() {
    int c = getchar();
    while (c != '\n' && c != EOF) {
        c = getchar();
    }
}

void addExpense(Expense *expenses, int *count) {
    printf("Enter name of expense item: ");
    fgets(expenses[*count].item, 50, stdin);
    strtok(expenses[*count].item, "\n"); // remove '\n' from fgets buffer
    printf("Enter amount spent: ");
    scanf("%f", &expenses[*count].amount);
    clearBuffer();
    expenses[*count].timestamp = time(NULL);
    (*count)++;
    printf("Expense added successfully.\n");
    printf("==========================\n");
}

void printExpenses(Expense *expenses, int count) {
    printf("Expense Tracker\n");
    printf("==========================\n");
    for (int i = 0; i < count; i++) {
        struct tm *timestamp = localtime(&expenses[i].timestamp);
        printf("Item: %s\n", expenses[i].item);
        printf("Amount: %.2f\n", expenses[i].amount);
        printf("Date: %d/%d/%d\n", timestamp->tm_mday, timestamp->tm_mon + 1, timestamp->tm_year + 1900);
        printf("==========================\n");
    }
}

int main() {
    Expense expenses[100];
    int count = 0;
    int choice = 0;

    printf("Welcome to Expense Tracker!\n");

    while (1) {
        printf("Enter choice:\n");
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Exit\n");
        printf("> ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1:
                addExpense(expenses, &count);
                break;
            case 2:
                printExpenses(expenses, count);
                break;
            case 3:
                printf("Exiting Expense Tracker...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}