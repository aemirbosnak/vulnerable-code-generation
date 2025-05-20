//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 10
#define MAX_INCOME 10

int expenses[MAX_EXPENSES];
int incomes[MAX_INCOME];

int numExpenses = 0;
int numIncomes = 0;


void addExpense(int expense) {
    if (numExpenses >= MAX_EXPENSES) {
        printf("Sorry, you have reached the maximum number of expenses!");
        return;
    }

    expenses[numExpenses++] = expense;
}

void addIncome(int income) {
    if (numIncomes >= MAX_INCOME) {
        printf("Sorry, you have reached the maximum number of incomes!");
        return;
    }

    incomes[numIncomes++] = income;
}

int calculateTotal(int arr[], int size) {
    int total = 0;

    for (int i = 0; i < size; i++) {
        total += arr[i];
    }

    return total;
}


int main() {
    int choice;
    int option = 1;

    while (option) {
        printf("Choose an option: \n");
        printf("1. Add an expense\n");
        printf("2. Add an income\n");
        printf("3. Show total expenses\n");
        printf("4. Show total incomes\n");
        printf("5. Show the overall balance\n");
        printf("0. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int expense;
                printf("Enter the expense amount: ");
                scanf("%d", &expense);

                addExpense(expense);
                printf("\nExpense added successfully!\n");
                break;
            }
            case 2: {
                int income;
                printf("Enter the income amount: ");
                scanf("%d", &income);

                addIncome(income);
                printf("\nIncome added successfully!\n");
                break;
            }
            case 3: {
                int totalExpenses = calculateTotal(expenses, numExpenses);
                printf("\nTotal expenses: %d\n", totalExpenses);
                break;
            }
            case 4: {
                int totalIncomes = calculateTotal(incomes, numIncomes);
                printf("\nTotal incomes: %d\n", totalIncomes);
                break;
            }
            case 5: {
                int totalExpenses = calculateTotal(expenses, numExpenses);
                int totalIncomes = calculateTotal(incomes, numIncomes);

                int balance = totalIncomes - totalExpenses;
                printf("\nOverall balance: %d\n", balance);
                break;
            }
            case 0: {
                option = 0;
                printf("\nExiting the program. Goodbye!\n");
                break;
            }
            default: {
                printf("\nInvalid option!\n");  
                break;
            }
        }
        printf("\n");
    }

    return 0;
}