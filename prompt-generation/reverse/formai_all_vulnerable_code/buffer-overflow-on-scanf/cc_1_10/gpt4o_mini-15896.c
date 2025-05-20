//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[30];
    float amount;
} Entry;

Entry income[MAX_ENTRIES];
Entry expenses[MAX_ENTRIES];
int incomeCount = 0, expenseCount = 0;
float totalIncome = 0.0, totalExpenses = 0.0;

pthread_mutex_t lock;

void *add_income(void *arg) {
    Entry entry;
    printf("Enter income source: ");
    scanf("%s", entry.name);
    printf("Enter income amount: ");
    scanf("%f", &entry.amount);
    
    pthread_mutex_lock(&lock);
    income[incomeCount++] = entry;
    totalIncome += entry.amount;
    pthread_mutex_unlock(&lock);

    printf("Income added successfully!\n");
    return NULL;
}

void *add_expense(void *arg) {
    Entry entry;
    printf("Enter expense category: ");
    scanf("%s", entry.name);
    printf("Enter expense amount: ");
    scanf("%f", &entry.amount);
    
    pthread_mutex_lock(&lock);
    expenses[expenseCount++] = entry;
    totalExpenses += entry.amount;
    pthread_mutex_unlock(&lock);

    printf("Expense added successfully!\n");
    return NULL;
}

void *view_summary(void *arg) {
    pthread_mutex_lock(&lock);
    printf("\nPersonal Finance Summary:\n");
    printf("Total Income: %.2f\n", totalIncome);
    printf("Total Expenses: %.2f\n", totalExpenses);
    printf("Net Savings: %.2f\n", totalIncome - totalExpenses);
    
    printf("\nIncome Sources:\n");
    for (int i = 0; i < incomeCount; i++) {
        printf("%s: %.2f\n", income[i].name, income[i].amount);
    }
    
    printf("\nExpense Categories:\n");
    for (int i = 0; i < expenseCount; i++) {
        printf("%s: %.2f\n", expenses[i].name, expenses[i].amount);
    }
    pthread_mutex_unlock(&lock);

    return NULL;
}

int main() {
    pthread_t incomeThread, expenseThread, summaryThread;
    pthread_mutex_init(&lock, NULL);
    
    while (1) {
        int choice;
        printf("\nPersonal Finance Planner\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. View Summary\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                pthread_create(&incomeThread, NULL, add_income, NULL);
                pthread_join(incomeThread, NULL);
                break;
            case 2:
                pthread_create(&expenseThread, NULL, add_expense, NULL);
                pthread_join(expenseThread, NULL);
                break;
            case 3:
                pthread_create(&summaryThread, NULL, view_summary, NULL);
                pthread_join(summaryThread, NULL);
                break;
            case 4:
                printf("Exiting the planner.\n");
                pthread_mutex_destroy(&lock);
                return 0;
            default:
                printf("Invalid choice, please choose again.\n");
        }
    }
    
    return 0;
}