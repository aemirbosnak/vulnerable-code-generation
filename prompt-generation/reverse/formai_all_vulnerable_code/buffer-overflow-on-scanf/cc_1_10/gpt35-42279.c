//FormAI DATASET v1.0 Category: Expense Tracker ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Expense {
    char category[20];
    float amount;
};

void add_expense(struct Expense *expenses, int *num_expenses, float *total_spent);
void view_expenses(struct Expense *expenses, int *num_expenses, float *total_spent);
void view_category(struct Expense *expenses, int *num_expenses, float *total_spent, char category[20]);

int main() {
    struct Expense expenses[100];
    int num_expenses = 0;
    float total_spent = 0;
    int choice;
    char category[20];

    printf("Expense Tracker\n");
    while(1) {
        printf("1. Add Expense\n");
        printf("2. View All Expenses\n");
        printf("3. View Expenses by Category\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_expense(expenses, &num_expenses, &total_spent);
                break;
            case 2:
                view_expenses(expenses, &num_expenses, &total_spent);
                break;
            case 3:
                printf("Enter category to view expenses: ");
                scanf("%s", category);
                view_category(expenses, &num_expenses, &total_spent, category);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

void add_expense(struct Expense *expenses, int *num_expenses, float *total_spent) {
    float amount;
    char category[20];

    printf("Enter category (one word): ");
    scanf("%s", category);

    printf("Enter amount spent: $");
    scanf("%f", &amount);

    strcpy(expenses[*num_expenses].category, category);
    expenses[*num_expenses].amount = amount;

    *num_expenses += 1;
    *total_spent += amount;

    printf("Expense added successfully!\n");
}

void view_expenses(struct Expense *expenses, int *num_expenses, float *total_spent) {
    printf("Total expenses: $%.2f\n", *total_spent);

    if(*num_expenses == 0) {
        printf("No expenses to show.\n");
        return;
    }

    printf("Category\tAmount Spent\n");
    for(int i = 0; i < *num_expenses; i++) {
        printf("%s\t$%.2f\n", expenses[i].category, expenses[i].amount);
    }   
}

void view_category(struct Expense *expenses, int *num_expenses, float *total_spent, char category[20]) {
    float category_total = 0;
    int count = 0;

    for(int i = 0; i < *num_expenses; i++) {
        if(strcmp(category, expenses[i].category) == 0) {
            category_total += expenses[i].amount;
            count += 1;
        }
    }

    printf("Category: %s\n", category);
    printf("Total spent: $%.2f\n", category_total);
    if(count == 0) {
        printf("No expenses for this category.\n");
        return;
    }
    printf("Amount Spent\n");
    for(int i = 0; i < *num_expenses; i++) {
        if(strcmp(category, expenses[i].category) == 0) {
            printf("$%.2f\n", expenses[i].amount);
        }
    }
}