//FormAI DATASET v1.0 Category: Expense Tracker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_EXPENSES 100
#define MAX_NAME_LENGTH 50

struct Expense {
    char name[MAX_NAME_LENGTH];
    double amount;
};

struct Tracker {
    struct Expense expenses[MAX_EXPENSES];
    int count;
    double balance;
    pthread_mutex_t lock;
};

void* add_expense(void* arg) {
    struct Tracker* tracker = (struct Tracker*) arg;
    while (1) {
        struct Expense expense;
        printf("Enter expense name (or 'q' to quit): ");
        scanf("%s", expense.name);
        if (expense.name[0] == 'q') {
            break;
        }
        printf("Enter expense amount: ");
        scanf("%lf", &expense.amount);
        pthread_mutex_lock(&tracker->lock);
        tracker->expenses[tracker->count++] = expense;
        tracker->balance -= expense.amount;
        pthread_mutex_unlock(&tracker->lock);
    }
    return NULL;
}

void print_expenses(struct Expense* expenses, int count) {
    for (int i = 0; i < count; i++) {
        printf("Expense %d: %s: $%.2lf\n", i+1, expenses[i].name, expenses[i].amount);
    }
}

void* print_balances(void* arg) {
    struct Tracker* tracker = (struct Tracker*) arg;
    while (1) {
        pthread_mutex_lock(&tracker->lock);
        printf("Current balance: $%.2lf\n", tracker->balance);
        printf("Expenses:\n");
        print_expenses(tracker->expenses, tracker->count);
        pthread_mutex_unlock(&tracker->lock);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_mutex_t lock;
    pthread_mutex_init(&lock, NULL);

    struct Tracker tracker = {.count = 0, .balance = 0, .lock = lock};

    pthread_t add_expense_thread, print_balances_thread;

    if (pthread_create(&add_expense_thread, NULL, add_expense, &tracker) != 0) {
        fprintf(stderr, "Error creating add_expense_thread\n");
        return 1;
    }

    if (pthread_create(&print_balances_thread, NULL, print_balances, &tracker) != 0) {
        fprintf(stderr, "Error creating print_balances_thread\n");
        return 1;
    }

    pthread_join(add_expense_thread, NULL);
    pthread_join(print_balances_thread, NULL);

    pthread_mutex_destroy(&lock);

    return 0;
}