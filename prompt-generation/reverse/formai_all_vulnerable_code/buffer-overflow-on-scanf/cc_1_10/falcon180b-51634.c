//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    float amount;
    char category[50];
    char date[20];
} Expense;

int main() {
    int numExpenses = 0;
    Expense expenses[MAX_EXPENSES];
    char choice;
    do {
        printf("Welcome to Happy Expense Tracker!\n");
        printf("Please choose an option:\n");
        printf("1. Add expense\n2. View expenses\n3. Exit\n");
        scanf("%c", &choice);
        switch (choice) {
            case '1':
                if (numExpenses >= MAX_EXPENSES) {
                    printf("Sorry, you have reached the maximum number of expenses.\n");
                } else {
                    printf("Enter expense name: ");
                    scanf("%s", expenses[numExpenses].name);
                    printf("Enter expense amount: $");
                    scanf("%f", &expenses[numExpenses].amount);
                    printf("Enter expense category: ");
                    scanf("%s", expenses[numExpenses].category);
                    printf("Enter expense date (YYYY-MM-DD): ");
                    scanf("%s", expenses[numExpenses].date);
                    numExpenses++;
                    printf("Expense added successfully!\n");
                }
                break;
            case '2':
                if (numExpenses == 0) {
                    printf("No expenses to view.\n");
                } else {
                    printf("Expenses:\n");
                    for (int i = 0; i < numExpenses; i++) {
                        printf("%s - $%.2f - %s - %s\n", expenses[i].name, expenses[i].amount, expenses[i].category, expenses[i].date);
                    }
                }
                break;
            case '3':
                printf("Thank you for using Happy Expense Tracker!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= '3');
    return 0;
}