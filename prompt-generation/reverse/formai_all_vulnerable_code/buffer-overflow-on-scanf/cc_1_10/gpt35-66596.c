//FormAI DATASET v1.0 Category: Expense Tracker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_EXPENSES 100 // Maximum number of allowed expenses
#define MAX_DESCRIPTION_LEN 50 // Maximum length of expense description

// Struct representing a single expense
typedef struct {
    char desc[MAX_DESCRIPTION_LEN];
    float amount;
} Expense;

// Global variables
Expense expenses[MAX_EXPENSES];
int numExpenses = 0;
float totalExpenses = 0.0;

// Mutex lock for accessing shared data
pthread_mutex_t lock;

// Thread function to add expenses
void* addExpense(void* arg) {
    // Lock the mutex before accessing shared data
    pthread_mutex_lock(&lock);

    printf("Enter expense description: ");
    scanf("%s", expenses[numExpenses].desc);

    printf("Enter expense amount: ");
    scanf("%f", &expenses[numExpenses].amount);

    totalExpenses += expenses[numExpenses].amount;
    numExpenses++;

    printf("Expense added successfully!\n");

    // Unlock the mutex before exiting
    pthread_mutex_unlock(&lock);

    return NULL;
}

// Thread function to display expenses
void* displayExpenses(void* arg) {
    // Lock the mutex before accessing shared data
    pthread_mutex_lock(&lock);

    printf("Expenses:\n");

    for (int i = 0; i < numExpenses; i++) {
        printf("%s: %.2f\n", expenses[i].desc, expenses[i].amount);
    }

    printf("Total expenses: %.2f\n", totalExpenses);

    // Unlock the mutex before exiting
    pthread_mutex_unlock(&lock);

    return NULL;
}

int main() {
    pthread_t addThreadId, displayThreadId;

    // Initialize mutex
    pthread_mutex_init(&lock, NULL);

    // Create threads
    pthread_create(&addThreadId, NULL, addExpense, NULL);
    pthread_create(&displayThreadId, NULL, displayExpenses, NULL);

    // Join threads
    pthread_join(addThreadId, NULL);
    pthread_join(displayThreadId, NULL);

    // Destroy mutex
    pthread_mutex_destroy(&lock);

    return 0;
}