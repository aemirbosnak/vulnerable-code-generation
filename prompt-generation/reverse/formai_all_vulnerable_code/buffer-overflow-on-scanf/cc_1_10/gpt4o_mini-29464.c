//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_EXPENSES 100
#define NAME_SIZE 50

typedef struct {
    char name[NAME_SIZE];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int expense_count = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *add_expense(void *arg) {
    char name[NAME_SIZE];
    float amount;

    while (1) {
        printf("Enter expense name (or 'exit' to stop adding): ");
        scanf("%s", name);
        if (strcmp(name, "exit") == 0) {
            break;
        }
        printf("Enter expense amount: ");
        scanf("%f", &amount);

        pthread_mutex_lock(&mutex);
        if (expense_count < MAX_EXPENSES) {
            strcpy(expenses[expense_count].name, name);
            expenses[expense_count].amount = amount;
            expense_count++;
            printf("Expense added: %s - $%.2f\n", name, amount);
        } else {
            printf("Expense list is full!\n");
        }
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void *view_expenses(void *arg) {
    while (1) {
        sleep(5); // Viewing expenses every 5 seconds
        pthread_mutex_lock(&mutex);
        printf("\nCurrent Expenses:\n");
        for (int i = 0; i < expense_count; i++) {
            printf("%d. %s - $%.2f\n", i + 1, expenses[i].name, expenses[i].amount);
        }
        printf("\n");
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void *delete_expense(void *arg) {
    int index;

    while (1) {
        printf("Enter the index of the expense to delete (or -1 to stop deleting): ");
        scanf("%d", &index);
        if (index == -1) {
            break;
        }

        pthread_mutex_lock(&mutex);
        if (index > 0 && index <= expense_count) {
            for (int i = index - 1; i < expense_count - 1; i++) {
                expenses[i] = expenses[i + 1];
            }
            expense_count--;
            printf("Expense deleted successfully.\n");
        } else {
            printf("Invalid index!\n");
        }
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t add_thread, view_thread, delete_thread;

    pthread_create(&add_thread, NULL, add_expense, NULL);
    pthread_create(&view_thread, NULL, view_expenses, NULL);
    pthread_create(&delete_thread, NULL, delete_expense, NULL);

    pthread_join(add_thread, NULL);
    pthread_cancel(view_thread); // Stop the viewing thread
    pthread_cancel(delete_thread); // Stop the deletion thread

    pthread_mutex_destroy(&mutex);
    printf("Exiting Expense Tracker.\n");
    return 0;
}