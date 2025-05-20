//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_EXPENSES 100
#define MAX_INCOME 100
#define NAME_LEN 50

typedef struct {
    char name[NAME_LEN];
    float amount;
} Income;

typedef struct {
    char name[NAME_LEN];
    float amount;
} Expense;

Income incomes[MAX_INCOME];
Expense expenses[MAX_EXPENSES];
int income_count = 0;
int expense_count = 0;

pthread_mutex_t lock;

void* add_income(void* arg) {
    char name[NAME_LEN];
    float amount;

    printf("Enter income source: ");
    scanf("%s", name);
    printf("Enter amount: ");
    scanf("%f", &amount);

    pthread_mutex_lock(&lock);
    strcpy(incomes[income_count].name, name);
    incomes[income_count].amount = amount;
    income_count++;
    printf("Income added: %s - %.2f\n", name, amount);
    pthread_mutex_unlock(&lock);

    return NULL;
}

void* add_expense(void* arg) {
    char name[NAME_LEN];
    float amount;

    printf("Enter expense name: ");
    scanf("%s", name);
    printf("Enter amount: ");
    scanf("%f", &amount);

    pthread_mutex_lock(&lock);
    strcpy(expenses[expense_count].name, name);
    expenses[expense_count].amount = amount;
    expense_count++;
    printf("Expense added: %s - %.2f\n", name, amount);
    pthread_mutex_unlock(&lock);

    return NULL;
}

void* view_summary(void* arg) {
    float total_income = 0.0, total_expense = 0.0;

    pthread_mutex_lock(&lock);
    for (int i = 0; i < income_count; i++) {
        total_income += incomes[i].amount;
    }
    
    for (int j = 0; j < expense_count; j++) {
        total_expense += expenses[j].amount;
    }
    pthread_mutex_unlock(&lock);

    printf("\n--- Financial Summary ---\n");
    printf("Total Income: %.2f\n", total_income);
    printf("Total Expenses: %.2f\n", total_expense);
    printf("Net Income: %.2f\n", total_income - total_expense);
    printf("-------------------------\n");

    return NULL;
}

int main() {
    pthread_t threads[3];
    int choice;

    pthread_mutex_init(&lock, NULL);

    while (1) {
        printf("\nPersonal Finance Planner\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. View Summary\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                pthread_create(&threads[0], NULL, add_income, NULL);
                pthread_join(threads[0], NULL);
                break;
            case 2:
                pthread_create(&threads[1], NULL, add_expense, NULL);
                pthread_join(threads[1], NULL);
                break;
            case 3:
                pthread_create(&threads[2], NULL, view_summary, NULL);
                pthread_join(threads[2], NULL);
                break;
            case 4:
                printf("Exiting the program.\n");
                pthread_mutex_destroy(&lock);
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}