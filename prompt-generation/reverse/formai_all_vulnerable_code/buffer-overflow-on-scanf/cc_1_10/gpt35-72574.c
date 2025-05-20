//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

struct expense {
    char desc[50];
    float cost;
    int day, month, year;
};

struct expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void addExpense(char *desc, float cost, int day, int month, int year) {
    if(num_expenses >= MAX_EXPENSES) {
        printf("Error: Too many expenses!\n");
        return;
    }
    struct expense e;
    strcpy(e.desc, desc);
    e.cost = cost;
    e.day = day;
    e.month = month;
    e.year = year;
    expenses[num_expenses++] = e;
    printf("Expense added successfully!\n");
}

void viewAllExpenses() {
    if(num_expenses == 0) {
        printf("No expenses added yet!\n");
        return;
    }
    printf("Expenses:\n");
    for(int i=0; i<num_expenses; i++) {
        printf("%d. Desc: %s, Cost: %0.2f, Date: %d-%d-%d\n", i+1, expenses[i].desc, expenses[i].cost, expenses[i].day, expenses[i].month, expenses[i].year);
    }
}

void viewExpensesOfDate(int day, int month, int year) {
    if(num_expenses == 0) {
        printf("No expenses added yet!\n");
        return;
    }
    int count = 0;
    printf("Expenses on %d-%d-%d:\n", day, month, year);
    for(int i=0; i<num_expenses; i++) {
        if(expenses[i].day == day && expenses[i].month == month && expenses[i].year == year) {
            printf("%d. Desc: %s, Cost: %0.2f\n", ++count, expenses[i].desc, expenses[i].cost);
        }
    }
    if(count == 0) {
        printf("No expenses found on this date!\n");
    }
}

int main() {
    char option;
    char desc[50];
    float cost;
    int day, month, year;
    do {
        printf("Options:\n1. Add expense\n2. View all expenses\n3. View expenses of a particular date\n4. Exit\nEnter option: ");
        scanf(" %c", &option);
        switch(option) {
            case '1':
                printf("Enter description: ");
                scanf(" %[^\n]", desc);
                printf("Enter cost: ");
                scanf("%f", &cost);
                printf("Enter date (DD-MM-YYYY): ");
                scanf("%d-%d-%d", &day, &month, &year);
                addExpense(desc, cost, day, month, year);
                break;
            case '2':
                viewAllExpenses();
                break;
            case '3':
                printf("Enter date (DD-MM-YYYY): ");
                scanf("%d-%d-%d", &day, &month, &year);
                viewExpensesOfDate(day, month, year);
                break;
            case '4':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option!\n");
        }
    } while(option != '4');
    return 0;
}