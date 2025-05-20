//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define MAX_EXPENSES 1000

typedef struct expense {
    char category[50];
    double amount;
    int month;
    int day;
    int year;
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *add_expense(void *arg) {
    char category[50];
    double amount;
    int month, day, year;

    printf("Enter expense category: ");
    scanf("%s", category);
    printf("Enter expense amount: $");
    scanf("%lf", &amount);
    printf("Enter expense date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &month, &day, &year);

    pthread_mutex_lock(&lock);
    if (num_expenses >= MAX_EXPENSES) {
        printf("Maximum number of expenses reached.\n");
        pthread_mutex_unlock(&lock);
        return NULL;
    }
    strcpy(expenses[num_expenses].category, category);
    expenses[num_expenses].amount = amount;
    expenses[num_expenses].month = month;
    expenses[num_expenses].day = day;
    expenses[num_expenses].year = year;
    num_expenses++;
    pthread_mutex_unlock(&lock);

    return NULL;
}

void *display_expenses(void *arg) {
    int i;

    printf("Expenses:\n");
    for (i = 0; i < num_expenses; i++) {
        printf("%s $%.2lf %d/%d/%d\n", expenses[i].category, expenses[i].amount,
               expenses[i].month, expenses[i].day, expenses[i].year);
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int i;

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, add_expense, NULL);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock);

    return 0;
}