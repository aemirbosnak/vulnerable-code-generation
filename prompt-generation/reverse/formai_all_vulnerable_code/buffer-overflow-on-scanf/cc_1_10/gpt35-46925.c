//FormAI DATASET v1.0 Category: Expense Tracker ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EXPENSES 1000
#define CATEGORY_LENGTH 50

struct Expense {
    char category[CATEGORY_LENGTH];
    float amount;
    time_t date;
};

float calculateTotal(struct Expense expenses[], int count) {
    float total = 0;
    int i;
    for (i = 0; i < count; i++) {
        total += expenses[i].amount;
    }
    return total;
}

void printExpenses(struct Expense expenses[], int count) {
    int i;
    for (i = 0; i < count; i++) {
        printf("[%s] - $%.2f - %s", expenses[i].category, expenses[i].amount, ctime(&expenses[i].date));
    }
}

void addExpense(struct Expense expenses[], int *count) {
    char category[CATEGORY_LENGTH];
    float amount;
    printf("Enter category: ");
    fgets(category, CATEGORY_LENGTH, stdin);
    printf("Enter amount: ");
    scanf("%f", &amount);
    getchar(); // consume newline character
    time_t now = time(NULL);
    struct tm *tm_now = localtime(&now);
    printf("Added expense on %s", asctime(tm_now));
    strncpy(expenses[*count].category, category, CATEGORY_LENGTH);
    expenses[*count].amount = amount;
    expenses[*count].date = now;
    (*count)++;
}

int main() {
    struct Expense expenses[MAX_EXPENSES];
    int count = 0;
    char choice;
    do {
        printf("\n\n1. Add Expense\n");
        printf("2. List Expenses\n");
        printf("3. Calculate Total\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%c", &choice);
        getchar(); // consume newline character
        switch(choice) {
            case '1':
                addExpense(expenses, &count);
                break;
            case '2':
                printExpenses(expenses, count);
                break;
            case '3':
                printf("Total expenses so far: $%.2f", calculateTotal(expenses, count));
                break;
            case '4':
                printf("Exiting program...");
                break;
            default:
                printf("Invalid choice.");
        }
    } while (choice != '4');
    return 0;
}