//MISTRAL-7B DATASET v1.0 Category: Personal Finance Planner ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structures and constants
typedef struct {
    char name[50];
    float amount;
} Transaction;

#define MAX_TRANSACTIONS 100
#define MONTHS_IN_YEAR 12

// Global variables
Transaction transactions[MAX_TRANSACTIONS];
int current_transaction = 0;
float monthly_income = 0;
float monthly_expenses = 0;
float savings_goal = 0;
float current_savings = 0;
int month = 1;

// Function prototypes
void record_transaction(char* description, float amount);
void calculate_totals();
void display_totals();
void next_month();

int main() {
    char description[100];
    float income;

    printf("\nWelcome to thee Savvy Scribe, a humble financial planner!\n");
    printf("Enter thine monthly income:\n");
    scanf("%f", &income);
    monthly_income = income;

    while (month <= MONTHS_IN_YEAR) {
        printf("\nMonth %d:\n", month);
        printf("Enter a description for this month's income (leave blank for none):\n");
        scanf("%s", description);
        if (strcmp(description, "") != 0) {
            record_transaction(description, monthly_income);
        }

        printf("Enter monthly expenses (leave blank when done):\n");
        while (1) {
            printf("Description: ");
            scanf("%s", description);
            if (strcmp(description, "") == 0) {
                break;
            }
            printf("Amount: ");
            float expense;
            scanf("%f", &expense);
            record_transaction(description, -expense);
        }

        calculate_totals();
        display_totals();
        next_month();
    }

    printf("\nThy financial year hath come to an end!\n");
    printf("Total savings: %.2f\n", current_savings);

    return 0;
}

void record_transaction(char* description, float amount) {
    transactions[current_transaction].amount = amount;
    strcpy(transactions[current_transaction].name, description);
    current_transaction++;
}

void calculate_totals() {
    int i;
    for (i = 0; i < current_transaction; i++) {
        if (transactions[i].amount > 0) {
            monthly_income += transactions[i].amount;
        } else {
            monthly_expenses += transactions[i].amount;
        }
    }
}

void display_totals() {
    printf("Monthly income: %.2f\n", monthly_income);
    printf("Monthly expenses: %.2f\n", monthly_expenses);
    current_savings += monthly_income - monthly_expenses;
}

void next_month() {
    monthly_expenses = 0;
    month++;
}