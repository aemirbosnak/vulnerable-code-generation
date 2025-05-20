//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define MAX_EXPENSES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int expense_count = 0;
pthread_mutex_t mutex_lock;

void *add_expense(void *arg) {
    while (1) {
        pthread_mutex_lock(&mutex_lock);
        if (expense_count >= MAX_EXPENSES) {
            printf("Expense list is full! Cannot add more expenses.\n");
            pthread_mutex_unlock(&mutex_lock);
            return NULL;
        }
        Expense new_expense;
        printf("Enter expense name: ");
        scanf("%s", new_expense.name);
        printf("Enter expense amount: ");
        scanf("%f", &new_expense.amount);
        
        expenses[expense_count] = new_expense;
        expense_count++;
        printf("Added expense: %s - $%.2f\n", new_expense.name, new_expense.amount);
        pthread_mutex_unlock(&mutex_lock);
    }
}

void *view_expenses(void *arg) {
    while (1) {
        pthread_mutex_lock(&mutex_lock);
        printf("\nCurrent Expenses:\n");
        float total = 0;
        for (int i = 0; i < expense_count; i++) {
            printf("%d. %s - $%.2f\n", i + 1, expenses[i].name, expenses[i].amount);
            total += expenses[i].amount;
        }
        printf("Total Expenses: $%.2f\n", total);
        pthread_mutex_unlock(&mutex_lock);
        sleep(5); // Update every 5 seconds
    }
}

int main() {
    pthread_t add_thread, view_thread;

    // Initialize mutex lock
    if (pthread_mutex_init(&mutex_lock, NULL) != 0) {
        printf("Mutex initialization failed\n");
        return 1;
    }

    // Create threads
    pthread_create(&add_thread, NULL, add_expense, NULL);
    pthread_create(&view_thread, NULL, view_expenses, NULL);

    // Wait for threads to finish (they won't in this example)
    pthread_join(add_thread, NULL);
    pthread_join(view_thread, NULL);

    // Destroy mutex lock
    pthread_mutex_destroy(&mutex_lock);
    return 0;
}