//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int monthlyIncome = 0;
int monthlyExpense = 0;
int savings = 0;

void* calculateBudget(void* arg) {
    int budget = monthlyIncome - monthlyExpense;
    if (budget > 0) {
        savings += budget;
        printf("You have a surplus budget of $%d this month. Your total savings is now $%d\n", budget, savings);
    } else {
        printf("You have a deficit budget of $%d this month. Your total savings is now $%d\n", abs(budget), savings);
    }
}

int main() {
    pthread_t thread1, thread2;

    printf("Welcome to your Personal Finance Planner\n");

    printf("Enter your monthly income: ");
    scanf("%d", &monthlyIncome);

    printf("Enter your monthly expense: ");
    scanf("%d", &monthlyExpense);

    printf("Calculating your budget...\n");

    pthread_create(&thread1, NULL, calculateBudget, NULL);
    pthread_join(thread1, NULL);

    printf("Would you like to project your savings after several months?\n");
    printf("Enter the number of months you would like to project: ");

    int numMonths;
    scanf("%d", &numMonths);

    for (int i = 1; i <= numMonths; i++) {
        printf("\nMonth %d:", i);
        printf("\nEnter your monthly income: ");
        scanf("%d", &monthlyIncome);

        printf("Enter your monthly expense: ");
        scanf("%d", &monthlyExpense);

        printf("Calculating your budget...\n");

        pthread_create(&thread2, NULL, calculateBudget, NULL);
        pthread_join(thread2, NULL);
    }

    printf("\nThank you for using Personal Finance Planner. Goodbye!\n");

    return 0;
}