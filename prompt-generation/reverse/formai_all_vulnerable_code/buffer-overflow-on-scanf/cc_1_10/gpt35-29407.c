//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
    char category[20];
    float amount;
};

void add_expense(struct expense* ptr, int* num_expenses) {
    printf("Enter Category (max 20 characters): ");
    scanf("%s", ptr[*num_expenses].category);
    printf("Enter Amount: ");
    scanf("%f", &ptr[*num_expenses].amount);
    (*num_expenses)++;
}

float calculate_total(struct expense* ptr, int num_expenses) {
    float total = 0;
    for (int i = 0; i < num_expenses; i++) {
        total += ptr[i].amount;
    }
    return total;
}

void display_expenses(struct expense* ptr, int num_expenses) {
    printf("------------------------------------\n");
    printf("      CATEGORY      |     AMOUNT   \n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%-20s| %10.2f\n", ptr[i].category, ptr[i].amount);
    }
    printf("------------------------------------\n");
    printf("TOTAL: %10.2f\n", calculate_total(ptr, num_expenses));
}

int main() {
    int option = 0, num_expenses = 0;
    struct expense* expenses = (struct expense*) malloc(sizeof(struct expense) * 100);
    while (option != 3) {
        printf("\n********** EXPENSE TRACKER *********\n");
        printf("1. Add Expense\n2. View Expenses\n3. Exit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                add_expense(expenses, &num_expenses);
                break;
            case 2:
                display_expenses(expenses, num_expenses);
                break;
            case 3:
                break;
            default:
                printf("\nInvalid Option! Try Again.\n");
        }
    }
    free(expenses);
    expenses = NULL;
    return 0;
}