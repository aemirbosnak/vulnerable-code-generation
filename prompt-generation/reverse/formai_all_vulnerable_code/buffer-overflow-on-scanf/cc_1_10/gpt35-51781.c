//FormAI DATASET v1.0 Category: Expense Tracker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_EXPENSES 1000

pthread_mutex_t lock;   // Define mutex lock to avoid race condition
int numExpenses = 0;    // Initialize number of expenses

typedef struct Expense {
    char* name;
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];

void* addExpense(void* arg) {
    pthread_mutex_lock(&lock);   // Lock mutex to prevent race condition
    
    char* name = (char*) arg;
    float amount;
    printf("Enter the amount of the expense: ");
    scanf("%f", &amount);
    
    Expense newExpense = {name, amount};   // Create new expense struct
    expenses[numExpenses++] = newExpense;  // Add new expense to array
    
    pthread_mutex_unlock(&lock);  // Unlock mutex
    
    return NULL;
}

int main() {
    pthread_t threads[2];
    
    char* names[2] = {"Food", "Transportation"};   // Names of expenses
    
    for (int i = 0; i < 2; i++) {
        pthread_create(&threads[i], NULL, addExpense, (void*) names[i]);   // Create thread for each expense
    }
    
    for (int i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);   // Wait for all threads to finish
    }
    
    // Print all expenses
    printf("\nExpenses:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%s: $%.2f\n", expenses[i].name, expenses[i].amount);
    }
    
    return 0;
}