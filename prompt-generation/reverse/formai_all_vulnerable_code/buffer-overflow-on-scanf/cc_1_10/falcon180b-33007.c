//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_EXPENSES 100
#define MAX_THREADS 10

// Structure for expense
typedef struct {
    char category[50];
    float amount;
    time_t date;
} Expense;

// Mutex and condition variables for synchronization
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cv = PTHREAD_COND_INITIALIZER;

// Semaphore to limit the number of threads
sem_t semaphore;

// Array to store expenses
Expense expenses[MAX_EXPENSES];

// Number of expenses
int num_expenses = 0;

// Function to initialize semaphore
void init_semaphore() {
    sem_init(&semaphore, 0, MAX_THREADS);
}

// Function to add expense
void* add_expense(void* arg) {
    char category[50];
    float amount;
    time_t date;

    // Wait for semaphore
    sem_wait(&semaphore);

    // Get input from user
    printf("Enter category: ");
    scanf("%s", category);
    printf("Enter amount: ");
    scanf("%f", &amount);
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", &date);

    // Convert date string to time_t
    struct tm tm;
    strptime(date, "%Y-%m-%d", &tm);
    time(&date);

    // Add expense to array
    expenses[num_expenses] = (Expense) {
       .category = category,
       .amount = amount,
       .date = date
    };
    num_expenses++;

    // Signal main thread
    pthread_cond_signal(&cv);

    // Release semaphore
    sem_post(&semaphore);

    return NULL;
}

// Function to display expenses
void display_expenses() {
    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s: $%.2f (%s)\n", expenses[i].category, expenses[i].amount, ctime(&expenses[i].date));
    }
}

// Main function
int main() {
    init_semaphore();

    // Create threads for adding expenses
    pthread_t threads[MAX_THREADS];
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, add_expense, NULL);
    }

    // Wait for all threads to finish
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Display expenses
    display_expenses();

    return 0;
}