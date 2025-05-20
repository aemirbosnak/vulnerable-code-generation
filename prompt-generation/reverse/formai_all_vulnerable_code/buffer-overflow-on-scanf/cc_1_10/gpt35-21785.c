//FormAI DATASET v1.0 Category: Expense Tracker ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 100

// structure to hold expense details
typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
    time_t timestamp;
} Expense;

int num_entries = 0;
float total_expense = 0.0;
Expense expenses[MAX_ENTRIES];
pthread_mutex_t expense_mutex = PTHREAD_MUTEX_INITIALIZER;

// add a new expense
void add_expense(char *name, float amount) {
    pthread_mutex_lock(&expense_mutex);
    if (num_entries >= MAX_ENTRIES) {
        printf("Cannot add expense, maximum entries reached!\n");
        pthread_mutex_unlock(&expense_mutex);
        return;
    }
    Expense new_expense;
    strcpy(new_expense.name, name);
    new_expense.amount = amount;
    new_expense.timestamp = time(NULL);
    expenses[num_entries++] = new_expense;
    total_expense += amount;
    pthread_mutex_unlock(&expense_mutex);
    printf("Expense added successfully!\n");
}

// print all expenses
void print_expenses() {
    pthread_mutex_lock(&expense_mutex);
    if (num_entries == 0) {
        printf("No expenses found.\n");
        pthread_mutex_unlock(&expense_mutex);
        return;
    }
    printf("Name\tAmount\tTimestamp\n");
    for (int i = 0; i < num_entries; i++) {
        Expense e = expenses[i];
        printf("%s\t%.2f\t%s", e.name, e.amount, ctime(&e.timestamp));
    }
    printf("Total Expense: %.2f\n", total_expense);
    pthread_mutex_unlock(&expense_mutex);
}

// clear all expenses
void clear_expenses() {
    pthread_mutex_lock(&expense_mutex);
    num_entries = 0;
    total_expense = 0.0;
    printf("All expenses cleared!\n");
    pthread_mutex_unlock(&expense_mutex);
}

// handle SIGINT signal by clearing expenses and exiting
void sigint_handler(int signum) {
    printf("Received SIGINT signal, exiting...\n");
    clear_expenses();
    exit(0);
}

// thread function to continuously read user input
void* read_input(void* arg) {
    while (true) {
        char name[MAX_NAME_LENGTH];
        float amount;
        printf("\nEnter expense name: ");
        scanf("%s", name);
        printf("Enter expense amount: ");
        scanf("%f", &amount);
        add_expense(name, amount);
        usleep(10000);
    }
    return NULL;
}

int main() {
    // register SIGINT signal handler
    signal(SIGINT, sigint_handler);

    // create thread to continuously read user input
    pthread_t input_thread;
    pthread_create(&input_thread, NULL, &read_input, NULL);

    // print expenses every 10 seconds
    while (true) {
        print_expenses();
        sleep(10);
    }
    return 0;
}