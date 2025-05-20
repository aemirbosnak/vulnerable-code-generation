//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 3

double income = 0.0;
double expenses = 0.0;
double savings = 0.0;
double investments = 0.0;

// Mutex locks for each of the variables
pthread_mutex_t income_lock;
pthread_mutex_t expenses_lock;
pthread_mutex_t savings_lock;
pthread_mutex_t investment_lock;

// Function to calculate and store the income
void *calculate_income(void *param) {
    double monthly_income;
    printf("Enter your monthly income: ");
    scanf("%lf", &monthly_income);

    pthread_mutex_lock(&income_lock);
    income += monthly_income;
    pthread_mutex_unlock(&income_lock);

    pthread_exit(NULL);
}

// Function to calculate and store the expenses
void *calculate_expenses(void *param) {
    double monthly_expenses;
    printf("Enter your monthly expenses: ");
    scanf("%lf", &monthly_expenses);

    pthread_mutex_lock(&expenses_lock);
    expenses += monthly_expenses;
    pthread_mutex_unlock(&expenses_lock);

    pthread_exit(NULL);
}

// Function to calculate and store the savings
void *calculate_savings(void *param) {
    pthread_mutex_lock(&income_lock);
    pthread_mutex_lock(&expenses_lock);

    savings = income - expenses;

    pthread_mutex_unlock(&income_lock);
    pthread_mutex_unlock(&expenses_lock);

    pthread_exit(NULL);
}

// Function to calculate and store the investments
void *calculate_investments(void *param) {
    pthread_mutex_lock(&savings_lock);
    double max_investment = savings * 0.3;
    printf("Enter your monthly investment: ");
    scanf("%lf", &investments);

    if (investments > max_investment) {
        investments = max_investment;
        printf("Your investment has reached the maximum allowable limit of 30%% of your savings.");
    }

    pthread_mutex_lock(&investment_lock);
    investments += investments;
    pthread_mutex_unlock(&investment_lock);
    pthread_mutex_unlock(&savings_lock);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;

    // Initialize Mutex locks
    pthread_mutex_init(&income_lock, NULL);
    pthread_mutex_init(&expenses_lock, NULL);
    pthread_mutex_init(&savings_lock, NULL);
    pthread_mutex_init(&investment_lock, NULL);

    // Create threads for each of the functions
    rc = pthread_create(&threads[0], NULL, calculate_income, NULL);
    if (rc) {
        printf("Error: unable to create thread\n");
        exit(EXIT_FAILURE);
    }

    rc = pthread_create(&threads[1], NULL, calculate_expenses, NULL);
    if (rc) {
        printf("Error: unable to create thread\n");
        exit(EXIT_FAILURE);
    }

    rc = pthread_create(&threads[2], NULL, calculate_savings, NULL);
    if (rc) {
        printf("Error: unable to create thread\n");
        exit(EXIT_FAILURE);
    }

    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
    pthread_join(threads[2], NULL);

    // Create a thread to calculate investments from savings
    rc = pthread_create(&threads[3], NULL, calculate_investments, NULL);
    if (rc) {
        printf("Error: unable to create thread\n");
        exit(EXIT_FAILURE);
    }

    pthread_join(threads[3], NULL);

    // Print out the results
    printf("Monthly Income: %lf\n", income);
    printf("Monthly Expenses: %lf\n", expenses);
    printf("Monthly Savings: %lf\n", savings);
    printf("Monthly Investments: %lf\n", investments);

    // Destroy Mutex locks
    pthread_mutex_destroy(&income_lock);
    pthread_mutex_destroy(&expenses_lock);
    pthread_mutex_destroy(&savings_lock);
    pthread_mutex_destroy(&investment_lock);

    return 0;
}