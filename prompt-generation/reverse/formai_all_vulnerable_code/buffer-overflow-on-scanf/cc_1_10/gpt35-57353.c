//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Dennis Ritchie
/*
    Program: Personal Finance Planner
    Author: [Your Name]
    Language: C
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense {
    char name[50];
    float amount;
};

struct Income {
    char name[50];
    float amount;
};

void get_expenses(struct Expense *expenses, int num_expenses);
void get_incomes(struct Income *incomes, int num_incomes);
void display_expenses(struct Expense *expenses, int num_expenses);
void display_incomes(struct Income *incomes, int num_incomes);

int main() {
    int num_expenses, num_incomes;

    printf("Personal Finance Planner\n\n");

    printf("Enter number of expenses: ");
    scanf("%d", &num_expenses);
    fflush(stdin); // clear input buffer

    struct Expense expenses[num_expenses];
    get_expenses(expenses, num_expenses);
    display_expenses(expenses, num_expenses);

    printf("\nEnter number of incomes: ");
    scanf("%d", &num_incomes);
    fflush(stdin); // clear input buffer

    struct Income incomes[num_incomes];
    get_incomes(incomes, num_incomes);
    display_incomes(incomes, num_incomes);

    float total_expenses = 0;
    for(int i = 0; i < num_expenses; i++) {
        total_expenses += expenses[i].amount;
    }

    float total_incomes = 0;
    for(int i = 0; i < num_incomes; i++) {
        total_incomes += incomes[i].amount;
    }

    printf("\nTotal Expenses: %.2f\n", total_expenses);
    printf("Total Incomes: %.2f\n", total_incomes);

    float balance = total_incomes - total_expenses;
    if(balance < 0.00f) {
        printf("You have a debt of %.2f\n", balance);
    } else {
        printf("You have a balance of %.2f\n", balance);
    }

    return 0;
}

void get_expenses(struct Expense *expenses, int num_expenses) {
    printf("\nEnter Expense Details:\n");
    for(int i = 0; i < num_expenses; i++) {
        printf("Expense %d Name: ", i + 1);
        fgets(expenses[i].name, 50, stdin);
        expenses[i].name[strcspn(expenses[i].name, "\n")] = '\0'; // remove newline character

        printf("Expense %d Amount: $", i + 1);
        scanf("%f", &expenses[i].amount);
        fflush(stdin); // clear input buffer
    }
}

void display_expenses(struct Expense *expenses, int num_expenses) {
    printf("\nExpense Details:\n");
    for(int i = 0; i < num_expenses; i++) {
        printf("Expense %d Name: %s | Amount: $%.2f\n", i + 1, expenses[i].name, expenses[i].amount);
    }
}

void get_incomes(struct Income *incomes, int num_incomes) {
    printf("\nEnter Income Details:\n");
    for(int i = 0; i < num_incomes; i++) {
        printf("Income %d Name: ", i + 1);
        fgets(incomes[i].name, 50, stdin);
        incomes[i].name[strcspn(incomes[i].name, "\n")] = '\0'; // remove newline character

        printf("Income %d Amount: $", i + 1);
        scanf("%f", &incomes[i].amount);
        fflush(stdin); // clear input buffer
    }
}

void display_incomes(struct Income *incomes, int num_incomes) {
    printf("\nIncome Details:\n");
    for(int i = 0; i < num_incomes; i++) {
        printf("Income %d Name: %s | Amount: $%.2f\n", i + 1, incomes[i].name, incomes[i].amount);
    }
}