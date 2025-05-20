//FormAI DATASET v1.0 Category: Expense Tracker ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Expense {
    char category[MAX_SIZE];
    float amount;
    char date[MAX_SIZE];
};

void display_expense(struct Expense expenses[], int n) {
    printf("Expense History:\n");
    printf("----------------------------------------------\n");
    printf("|%-15s|%-10s|%-15s|\n", "CATEGORY", "AMOUNT", "DATE");
    printf("----------------------------------------------\n");
    for(int i=0; i<n; i++) {
        printf("|%-15s|%10.2f|%-15s|\n", expenses[i].category, expenses[i].amount, expenses[i].date);
    }
    printf("----------------------------------------------\n");
    printf("\n");
}

void add_expense(struct Expense expenses[], int* n) {
    struct Expense e;
    printf("Enter category (max 99 characters):\n");
    scanf("%s", e.category);
    printf("Enter amount:\n");
    scanf("%f", &e.amount);
    printf("Enter date (max 99 characters):\n");
    scanf("%s", e.date);
    strcpy(expenses[*n].category, e.category);
    expenses[*n].amount = e.amount;
    strcpy(expenses[*n].date, e.date);
    (*n)++;
    printf("Expense added successfully!\n\n");
}

float calculate_total(struct Expense expenses[], int n) {
    float total = 0;
    for(int i=0; i<n; i++) {
        total += expenses[i].amount;
    }
    return total;
}

void menu() {
    printf("Welcome to Expense Tracker!\n\n");
    printf("1. Display expense history\n");
    printf("2. Add expense\n");
    printf("3. Calculate total expenses\n");
    printf("4. Exit\n");
    printf("Enter your choice:\n");
}

int main() {
    struct Expense expenses[MAX_SIZE];
    int choice, n=0;
    float total = 0;
    do {
        menu();
        scanf("%d", &choice);
        printf("\n");
        switch(choice) {
            case 1: display_expense(expenses, n); break;
            case 2: add_expense(expenses, &n); break;
            case 3: total = calculate_total(expenses, n); printf("Total expenses: %.2f\n\n", total); break;
            case 4: printf("Thank you for using Expense Tracker!\n"); break;
            default: printf("Invalid choice! Please try again.\n\n");
        }
    } while(choice != 4);

    return 0;
}