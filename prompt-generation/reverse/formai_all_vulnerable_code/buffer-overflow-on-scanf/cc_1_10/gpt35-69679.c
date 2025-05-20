//FormAI DATASET v1.0 Category: Expense Tracker ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_EXPENSES 100

struct Expense {
    char description[50];
    float amount;
    int day;
    int month;
    int year;
};

struct Summary {
    float total;
    float average;
    float max;
    float min;
};

struct Expense expenses[MAX_EXPENSES];
int count = 0;

void addExpense() {
    printf("Enter expense description: ");
    fgets(expenses[count].description, 50, stdin);
    printf("Enter amount: ");
    scanf("%f", &expenses[count].amount);
    printf("Enter date (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &expenses[count].day, &expenses[count].month, &expenses[count].year);
    getchar(); // Consume newline character from the input buffer
    count++;
}

void printExpenses() {
    printf("Description\tAmount\tDate\n");
    for (int i = 0; i < count; i++) {
        printf("%s", expenses[i].description);
        printf("\t%.2f\t", expenses[i].amount);
        printf("%02d/%02d/%04d\n", expenses[i].day, expenses[i].month, expenses[i].year);
    }
}

struct Summary summarizeExpenses() {
    struct Summary summary;
    float total = 0;
    float max = expenses[0].amount;
    float min = expenses[0].amount;
    for (int i = 0; i < count; i++) {
        total += expenses[i].amount;
        if (expenses[i].amount > max) {
            max = expenses[i].amount;
        }
        if (expenses[i].amount < min) {
            min = expenses[i].amount;
        }
    }
    summary.total = total;
    summary.average = total / count;
    summary.max = max;
    summary.min = min;
    return summary;
}

void printSummary(struct Summary summary) {
    printf("Total expenses: %.2f\n", summary.total);
    printf("Average expense: %.2f\n", summary.average);
    printf("Maximum expense: %.2f\n", summary.max);
    printf("Minimum expense: %.2f\n", summary.min);
}

int main() {
    int option;
    do {
        printf("\nExpense Tracker - Menu\n");
        printf("1. Add an expense\n");
        printf("2. Print all expenses\n");
        printf("3. Print expense summary\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        getchar(); // Consume newline character from the input buffer
        switch (option) {
            case 1:
                addExpense();
                break;
            case 2:
                printExpenses();
                break;
            case 3: {
                struct Summary summary = summarizeExpenses();
                printSummary(summary);
                break;
            }
            case 0:
                printf("Exiting. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
                break;
        }
    } while (option != 0);

    return 0;
}