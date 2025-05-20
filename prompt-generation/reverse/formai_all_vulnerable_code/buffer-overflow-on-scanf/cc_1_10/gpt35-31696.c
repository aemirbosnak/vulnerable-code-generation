//FormAI DATASET v1.0 Category: Expense Tracker ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

// Struct to store expense information
typedef struct {
    char* name;
    double amount;
    time_t date;
} Expense;

// Global variables
Expense* expenses = NULL;
int numExpenses = 0;
bool running = true;
pthread_mutex_t expensesMutex = PTHREAD_MUTEX_INITIALIZER;

// Function to add an expense to the array
void addExpense(char* name, double amount, time_t date) {
    // Lock the mutex to ensure thread safety
    pthread_mutex_lock(&expensesMutex);
    
    // Allocate memory for the new expense
    Expense* expense = (Expense*) malloc(sizeof(Expense));
    expense->name = name;
    expense->amount = amount;
    expense->date = date;
    
    // Increase the size of the expenses array
    numExpenses++;
    expenses = (Expense*) realloc(expenses, numExpenses * sizeof(Expense));
    
    // Add the new expense to the array
    expenses[numExpenses - 1] = *expense;
    
    // Unlock the mutex
    pthread_mutex_unlock(&expensesMutex);
}

// Function to print the total expenses
void printExpenses() {
    // Lock the mutex to ensure thread safety
    pthread_mutex_lock(&expensesMutex);
    
    double total = 0;
    for (int i = 0; i < numExpenses; i++) {
        total += expenses[i].amount;
        printf("%d. %s - %.2lf - %s", i + 1, expenses[i].name, expenses[i].amount, ctime(&expenses[i].date));
    }
    
    printf("Total: %.2lf\n", total);
    
    // Unlock the mutex
    pthread_mutex_unlock(&expensesMutex);
}

// Thread function to handle user input
void* handleInput(void* arg) {
    while (running) {
        // Accept user input for a new expense
        char* name = (char*) malloc(100 * sizeof(char));
        printf("Enter expense name (or 'quit' to exit): ");
        scanf("%s", name);
        
        if (strcmp(name, "quit") == 0) {
            running = false;
            free(name);
            break;
        }
        
        double amount;
        printf("Enter expense amount: ");
        scanf("%lf", &amount);
        
        time_t date = time(NULL);
        
        // Add the new expense to the array
        addExpense(name, amount, date);
    }
    
    return NULL;
}

int main() {
    // Create a new thread to handle user input
    pthread_t inputThread;
    if (pthread_create(&inputThread, NULL, handleInput, NULL) != 0) {
        fprintf(stderr, "Error creating input thread.\n");
        return 1;
    }
    
    // Wait for the user to enter expenses
    while (running) {
        sleep(1);
    }
    
    // Print the final expenses and free the memory
    printExpenses();
    for (int i = 0; i < numExpenses; i++) {
        free(expenses[i].name);
    }
    free(expenses);
    
    return 0;
}