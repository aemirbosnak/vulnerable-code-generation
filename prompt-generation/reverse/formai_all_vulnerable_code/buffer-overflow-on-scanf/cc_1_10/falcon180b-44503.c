//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Define global variables
double income;
double expenses[10];
int num_expenses;
double savings;

// Function prototypes
void add_expense();
void remove_expense();
void display_expenses();
void calculate_savings();

// Main function
int main() {
    int choice;
    char cont;

    do {
        printf("\nPersonal Finance Planner\n");
        printf("1. Add expense\n");
        printf("2. Remove expense\n");
        printf("3. Display expenses\n");
        printf("4. Calculate savings\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_expense();
                break;
            case 2:
                remove_expense();
                break;
            case 3:
                display_expenses();
                break;
            case 4:
                calculate_savings();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &cont);
    } while(cont == 'y' || cont == 'Y');

    return 0;
}

// Function to add an expense
void add_expense() {
    if(num_expenses == 10) {
        printf("Cannot add more than 10 expenses!\n");
        return;
    }

    printf("Enter the expense amount: ");
    scanf("%lf", &expenses[num_expenses]);
    num_expenses++;

    printf("Expense added successfully!\n");
}

// Function to remove an expense
void remove_expense() {
    if(num_expenses == 0) {
        printf("No expenses to remove!\n");
        return;
    }

    printf("Enter the expense number to remove: ");
    int num;
    scanf("%d", &num);

    if(num >= 0 && num < num_expenses) {
        for(int i=num; i<num_expenses-1; i++) {
            expenses[i] = expenses[i+1];
        }
        num_expenses--;
    } else {
        printf("Invalid expense number!\n");
    }
}

// Function to display expenses
void display_expenses() {
    if(num_expenses == 0) {
        printf("No expenses to display!\n");
        return;
    }

    printf("Expenses:\n");
    for(int i=0; i<num_expenses; i++) {
        printf("%d. %.2lf\n", i+1, expenses[i]);
    }
}

// Function to calculate savings
void calculate_savings() {
    printf("Enter your income: ");
    scanf("%lf", &income);

    double total_expenses = 0.0;
    for(int i=0; i<num_expenses; i++) {
        total_expenses += expenses[i];
    }

    savings = income - total_expenses;

    printf("Your savings are: %.2lf\n", savings);
}