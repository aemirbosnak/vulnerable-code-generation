//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5
#define MAX_EXPENSES 100

typedef struct {
    int id;
    char category[20];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int numExpenses = 0;

void addExpense(Expense* expense) {
    if (numExpenses >= MAX_EXPENSES) {
        printf("Error: Maximum number of expenses reached.\n");
        return;
    }

    expenses[numExpenses] = *expense;
    numExpenses++;
}

void printExpenses() {
    printf("Expenses:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("ID: %d, Category: %s, Amount: $%.2f\n", expenses[i].id, expenses[i].category, expenses[i].amount);
    }
}

void* threadFunc(void* arg) {
    char input[50];
    while (1) {
        printf("Enter expense category: ");
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) {
            break;
        }

        float amount;
        printf("Enter expense amount: $");
        scanf("%f", &amount);

        Expense expense = {.id = numExpenses,.category = input,.amount = amount};
        addExpense(&expense);
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, threadFunc, NULL);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printExpenses();

    return 0;
}