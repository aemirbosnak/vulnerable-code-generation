//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_EXPENSE_LENGTH 50

typedef struct {
    char expense[MAX_EXPENSE_LENGTH];
    double amount;
} expense_t;

void read_expenses(const char* filename, expense_t expenses[MAX_EXPENSES]) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %lf", expenses[count].expense, &expenses[count].amount) == 2) {
        count++;
        if (count >= MAX_EXPENSES) {
            fprintf(stderr, "Error: too many expenses\n");
            exit(1);
        }
    }

    fclose(file);
}

void calculate_totals(expense_t expenses[MAX_EXPENSES], int count) {
    double total_amount = 0.0;
    double avg_amount = 0.0;
    double max_amount = 0.0;

    for (int i = 0; i < count; i++) {
        total_amount += expenses[i].amount;
        avg_amount += expenses[i].amount;
    }

    avg_amount /= count;
    total_amount /= count;

    for (int i = 0; i < count; i++) {
        if (expenses[i].amount > max_amount) {
            max_amount = expenses[i].amount;
        }
    }

    printf("Total amount spent: %.2lf\n", total_amount);
    printf("Average amount spent: %.2lf\n", avg_amount);
    printf("Maximum expense amount: %.2lf\n", max_amount);
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    expense_t expenses[MAX_EXPENSES];
    read_expenses(argv[1], expenses);
    calculate_totals(expenses, MAX_EXPENSES);

    return 0;
}