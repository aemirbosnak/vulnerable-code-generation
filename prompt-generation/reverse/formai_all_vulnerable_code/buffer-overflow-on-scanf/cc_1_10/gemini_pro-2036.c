//GEMINI-pro DATASET v1.0 Category: Mortgage Calculator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>

typedef struct {
    double principal;
    double interest_rate;
    int term_years;
    int term_months;
    double monthly_payment;
    double total_interest;
    double total_paid;
} mortgage_info_t;

typedef struct {
    mortgage_info_t *mortgage_info;
    int num_threads;
    sem_t *sem;
} mortgage_calc_args_t;

void *mortgage_calc_thread(void *args) {
    mortgage_calc_args_t *args_t = (mortgage_calc_args_t *)args;
    mortgage_info_t *mortgage_info = args_t->mortgage_info;
    int num_threads = args_t->num_threads;
    sem_t *sem = args_t->sem;

    // Calculate the monthly payment
    double monthly_rate = mortgage_info->interest_rate / 1200;
    double num_months = mortgage_info->term_years * 12 + mortgage_info->term_months;
    mortgage_info->monthly_payment = mortgage_info->principal * monthly_rate / (1 - pow(1 + monthly_rate, -num_months));

    // Calculate the total interest and total paid
    mortgage_info->total_interest = mortgage_info->monthly_payment * num_months - mortgage_info->principal;
    mortgage_info->total_paid = mortgage_info->monthly_payment * num_months;

    // Signal the semaphore to indicate that the calculation is finished
    sem_post(sem);

    // Exit the thread
    pthread_exit(NULL);
}

int main(int argc, char **argv) {
    // Get the input from the user
    double principal;
    double interest_rate;
    int term_years;
    int term_months;

    printf("Enter the loan amount: ");
    scanf("%lf", &principal);

    printf("Enter the interest rate (%%): ");
    scanf("%lf", &interest_rate);

    printf("Enter the loan term (years): ");
    scanf("%d", &term_years);

    printf("Enter the loan term (months): ");
    scanf("%d", &term_months);

    // Create a semaphore to synchronize the threads
    sem_t sem;
    sem_init(&sem, 0, 0);

    // Create a thread pool
    int num_threads = 4;
    pthread_t threads[num_threads];

    // Create the mortgage info struct
    mortgage_info_t mortgage_info;
    mortgage_info.principal = principal;
    mortgage_info.interest_rate = interest_rate;
    mortgage_info.term_years = term_years;
    mortgage_info.term_months = term_months;

    // Create the mortgage calc args struct
    mortgage_calc_args_t args;
    args.mortgage_info = &mortgage_info;
    args.num_threads = num_threads;
    args.sem = &sem;

    // Create the threads
    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, mortgage_calc_thread, (void *)&args);
    }

    // Wait for the threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the results
    printf("\nMortgage Information\n");
    printf("--------------------\n");
    printf("Principal: $%.2f\n", mortgage_info.principal);
    printf("Interest Rate: %.2f%%\n", mortgage_info.interest_rate);
    printf("Term: %d years %d months\n", mortgage_info.term_years, mortgage_info.term_months);
    printf("Monthly Payment: $%.2f\n", mortgage_info.monthly_payment);
    printf("Total Interest: $%.2f\n", mortgage_info.total_interest);
    printf("Total Paid: $%.2f\n", mortgage_info.total_paid);

    // Destroy the semaphore
    sem_destroy(&sem);

    return 0;
}