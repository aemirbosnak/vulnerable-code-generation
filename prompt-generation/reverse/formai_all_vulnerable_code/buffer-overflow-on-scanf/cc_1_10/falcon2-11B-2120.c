//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[50];
    float total;
    int count;
} expense_record;

expense_record expenses[100];
int expenses_count = 0;

void add_expense(char* name, float amount) {
    expense_record new_expense;
    strcpy(new_expense.name, name);
    new_expense.total = amount;
    new_expense.count = 1;
    expenses[expenses_count] = new_expense;
    expenses_count++;
}

void print_expenses() {
    int i;
    for (i = 0; i < expenses_count; i++) {
        printf("%s - $%.2f\n", expenses[i].name, expenses[i].total);
    }
}

void print_summary() {
    int i;
    float total_spent = 0.0;
    for (i = 0; i < expenses_count; i++) {
        total_spent += expenses[i].total;
    }
    printf("Total spent: $%.2f\n", total_spent);
}

int main() {
    srand(time(NULL));
    int choice;
    char name[50];
    float amount;
    printf("Welcome to the Expense Tracker!\n");
    while (1) {
        printf("1. Add expense\n2. Print expenses\n3. Print summary\n4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter expense name: ");
                fgets(name, sizeof(name), stdin);
                fgets(name, sizeof(name), stdin);
                printf("Enter expense amount: ");
                scanf("%f", &amount);
                add_expense(name, amount);
                break;
            case 2:
                print_expenses();
                break;
            case 3:
                print_summary();
                break;
            case 4:
                printf("Bye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}