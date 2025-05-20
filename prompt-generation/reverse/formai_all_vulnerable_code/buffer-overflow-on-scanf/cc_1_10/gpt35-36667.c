//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Struct for the finance data
struct finance_data {
  float income;
  float expenses;
  float savings;
  float debt;
  float net_worth;
};

// Thread function to calculate income
void* income_calculation(void* arg) {
  struct finance_data* data = (struct finance_data*) arg;
  float income = 0;
  printf("Enter your income: ");
  scanf("%f", &income);
  data->income = income;
  pthread_exit(NULL);
}

// Thread function to calculate expenses
void* expenses_calculation(void* arg) {
  struct finance_data* data = (struct finance_data*) arg;
  float expenses = 0;
  printf("Enter your expenses: ");
  scanf("%f", &expenses);
  data->expenses = expenses;
  pthread_exit(NULL);
}

// Thread function to calculate savings
void* savings_calculation(void* arg) {
  struct finance_data* data = (struct finance_data*) arg;
  data->savings = data->income - data->expenses;
  pthread_exit(NULL);
}

// Thread function to calculate debt
void* debt_calculation(void* arg) {
  struct finance_data* data = (struct finance_data*) arg;
  float debt = 0;
  printf("Enter your debt: ");
  scanf("%f", &debt);
  data->debt = debt;
  pthread_exit(NULL);
}

// Thread function to calculate net worth
void* net_worth_calculation(void* arg) {
  struct finance_data* data = (struct finance_data*) arg;
  data->net_worth = data->savings - data->debt;
  pthread_exit(NULL);
}

int main() {
  struct finance_data data;
  pthread_t threads[5];
  int rc;

  // Create threads for each finance calculation
  rc = pthread_create(&threads[0], NULL, income_calculation, (void*) &data);
  if (rc) {
    printf("ERROR %d: Failed to create income thread\n", rc);
    exit(EXIT_FAILURE);
  }

  rc = pthread_create(&threads[1], NULL, expenses_calculation, (void*) &data);
  if (rc) {
    printf("ERROR %d: Failed to create expenses thread\n", rc);
    exit(EXIT_FAILURE);
  }

  rc = pthread_create(&threads[2], NULL, savings_calculation, (void*) &data);
  if (rc) {
    printf("ERROR %d: Failed to create savings thread\n", rc);
    exit(EXIT_FAILURE);
  }

  rc = pthread_create(&threads[3], NULL, debt_calculation, (void*) &data);
  if (rc) {
    printf("ERROR %d: Failed to create debt thread\n", rc);
    exit(EXIT_FAILURE);
  }

  rc = pthread_create(&threads[4], NULL, net_worth_calculation, (void*) &data);
  if (rc) {
    printf("ERROR %d: Failed to create net worth thread\n", rc);
    exit(EXIT_FAILURE);
  }

  // Join all the threads
  for (int i = 0; i < 5; i++) {
    rc = pthread_join(threads[i], NULL);
    if (rc) {
      printf("ERROR %d: Failed to join thread %d\n", rc, i);
      exit(EXIT_FAILURE);
    }
  }

  // Print the finance data
  printf("\n====== PERSONAL FINANCE PLANNER ======\n");
  printf("Income: $%.2f\n", data.income);
  printf("Expenses: $%.2f\n", data.expenses);
  printf("Savings: $%.2f\n", data.savings);
  printf("Debt: $%.2f\n", data.debt);
  printf("Net Worth: $%.2f\n", data.net_worth);

  exit(EXIT_SUCCESS);
}