//FormAI DATASET v1.0 Category: Expense Tracker ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <pthread.h>

#define MAX_EXPENSES 100
#define MAX_EXPENSE_NAME 50
#define MAX_EXPENSE_CATEGORY 30

/* Data structure to hold expense information */
struct expense {
    char name[MAX_EXPENSE_NAME];
    char category[MAX_EXPENSE_CATEGORY];
    float amount;
};

/* Global variables */
struct expense expenses[MAX_EXPENSES];
int num_expenses = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

/* Function to add a new expense */
void add_expense(char name[], char category[], float amount) {
    pthread_mutex_lock(&mutex);

    /* Check if maximum number of expenses have been reached */
    if (num_expenses >= MAX_EXPENSES) {
        printf("Maximum number of expenses reached!\n");
        pthread_mutex_unlock(&mutex);
        return;
    }

    /* Add new expense to the list */
    struct expense new_expense;
    strcpy(new_expense.name, name);
    strcpy(new_expense.category, category);
    new_expense.amount = amount;
    expenses[num_expenses++] = new_expense;
    printf("Expense added!\n");

    pthread_mutex_unlock(&mutex);
}

/* Function to view all expenses */
void view_expenses() {
    pthread_mutex_lock(&mutex);

    printf("All Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s (%s) - $%.2f\n", expenses[i].name, expenses[i].category, expenses[i].amount);
    }

    pthread_mutex_unlock(&mutex);
}

/* Function to calculate total expenses */
void calculate_total() {
    pthread_mutex_lock(&mutex);

    float total = 0;
    for (int i = 0; i < num_expenses; i++) {
        total += expenses[i].amount;
    }

    printf("Total expenses: $%.2f\n", total);

    pthread_mutex_unlock(&mutex);
}

/* Main function */
int main() {
    char command[20];

    /* Display available commands */
    printf("Welcome to the Expense Tracker!\n");
    printf("Available commands: add, view, total, exit\n");

    /* Loop until user enters 'exit' command */
    while (1) {
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            char name[MAX_EXPENSE_NAME], category[MAX_EXPENSE_CATEGORY];
            float amount;
            printf("Enter expense name: ");
            scanf("%s", name);
            printf("Enter expense category: ");
            scanf("%s", category);
            printf("Enter expense amount: ");
            scanf("%f", &amount);
            add_expense(name, category, amount);
        } else if (strcmp(command, "view") == 0) {
            view_expenses();
        } else if (strcmp(command, "total") == 0) {
            calculate_total();
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command!\n");
        }
    }

    return 0;
}