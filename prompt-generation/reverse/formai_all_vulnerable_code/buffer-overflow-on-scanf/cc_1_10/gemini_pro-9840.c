//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

// Thread function to calculate income
void *calculate_income(void *args) {
    int *income = (int *)args;
    printf("Enter your monthly income: ");
    scanf("%d", income);
    return NULL;
}

// Thread function to calculate expenses
void *calculate_expenses(void *args) {
    int *expenses = (int *)args;
    printf("Enter your monthly expenses: ");
    scanf("%d", expenses);
    return NULL;
}

// Thread function to calculate savings
void *calculate_savings(void *args) {
    int *income = (int *)((void **)args)[0];
    int *expenses = (int *)((void **)args)[1];
    int *savings = (int *)args;
    *savings = *income - *expenses;
    return NULL;
}

int main() {
    int income, expenses, savings;

    // Create threads to calculate income and expenses
    pthread_t income_thread, expenses_thread;
    pthread_create(&income_thread, NULL, calculate_income, &income);
    pthread_create(&expenses_thread, NULL, calculate_expenses, &expenses);

    // Join the income and expenses threads
    pthread_join(income_thread, NULL);
    pthread_join(expenses_thread, NULL);

    // Create a thread to calculate savings
    pthread_t savings_thread;
    pthread_create(&savings_thread, NULL, calculate_savings, &savings);

    // Join the savings thread
    pthread_join(savings_thread, NULL);

    // Print the calculated savings
    printf("Your monthly savings: %d\n", savings);

    return 0;
}