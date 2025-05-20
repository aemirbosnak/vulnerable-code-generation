//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EXPENSES 50

typedef struct {
    char description[50];
    float amount;
    time_t timestamp;
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense(const char *description, float amount) {
    if (num_expenses >= MAX_EXPENSES) {
        fprintf(stderr, "Expense tracker is full!\n");
        return;
    }

    strcpy(expenses[num_expenses].description, description);
    expenses[num_expenses].amount = amount;
    expenses[num_expenses].timestamp = time(NULL);

    num_expenses++;
}

void print_expenses() {
    if (num_expenses == 0) {
        printf("Nothing to print, no expenses yet!\n");
        return;
    }

    printf("============== Expense Tracker ==============\n");
    printf("Date            | Description        | Amount\n");
    printf("---------------------------------------------\n");

    for (int i = 0; i < num_expenses; i++) {
        char dt[20];
        strftime(dt, sizeof(dt), "%Y-%m-%d %H:%M:%S", localtime(&(expenses[i].timestamp)));
        printf("%s | %s | %.2f\n", dt, expenses[i].description, expenses[i].amount);
    }

    printf("---------------------------------------------\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nExpense Tracker\n");
        printf("1. Add Expense\n");
        printf("2. Print Expenses\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                {
                    char desc[50];
                    float amount;

                    printf("Enter description: ");
                    scanf("%s", desc);
                    printf("Enter amount: ");
                    scanf("%f", &amount);

                    add_expense(desc, amount);
                    printf("Expense added successfully!\n");
                    break;
                }
            case 2:
                {
                    print_expenses();
                    break;
                }
            case 3:
                {
                    printf("Exiting...\n");
                    exit(0);
                }
            default:
                {
                    printf("Invalid choice! Please try again.\n");
                    break;
                }
        }
    }

    return 0;
}