//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5
#define MAX_EXPENSES 100

// Struct for expenses
typedef struct {
    char description[50];
    float amount;
} Expense;

// Global variables
Expense expenses[MAX_EXPENSES];
int numExpenses = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function prototypes
void *addExpense(void *arg);
void printExpenses();

// Main function
int main() {
    pthread_t threads[NUM_THREADS];

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, addExpense, NULL);
    }

    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print expenses
    printExpenses();

    return 0;
}

// Function to add expenses
void *addExpense(void *arg) {
    char input[100];

    printf("Enter expense description: ");
    scanf("%s", input);

    printf("Enter expense amount: $");
    scanf("%f", &expenses[numExpenses].amount);
    strcpy(expenses[numExpenses].description, input);

    numExpenses++;
}

// Function to print expenses
void printExpenses() {
    printf("\nExpenses:\n");

    pthread_mutex_lock(&mutex);
    for (int i = 0; i < numExpenses; i++) {
        printf("%s - $%.2f\n", expenses[i].description, expenses[i].amount);
    }
    pthread_mutex_unlock(&mutex);
}