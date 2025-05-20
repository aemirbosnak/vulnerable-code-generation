//FormAI DATASET v1.0 Category: Expense Tracker ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Expense {
    float amount;
    char category[50];
    char date[10];
};

float totalExpense(struct Expense expenses[], int numExpenses) {
    float total = 0.0;
    for(int i = 0; i < numExpenses; i++) {
        total += expenses[i].amount;
    }
    return total;
}

void printExpenses(struct Expense expenses[], int numExpenses) {
    printf("Date\t\tCategory\tAmount\n");
    for(int i = 0; i < numExpenses; i++) {
        printf("%s\t%s\t$%.2f\n", expenses[i].date, expenses[i].category, expenses[i].amount);
    }
}

int main() {
    int numExpenses = 0;
    struct Expense expenses[100];
    int choice;

    do {
        printf("\n\n1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. View Total Expense\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();      // flush the input buffer

        switch(choice) {
            case 1: {
                printf("\nEnter Date (mm/dd/yy): ");
                fgets(expenses[numExpenses].date, 10, stdin);
                expenses[numExpenses].date[strlen(expenses[numExpenses].date)-1] = '\0';
                printf("Enter Category: ");
                fgets(expenses[numExpenses].category, 50, stdin);
                expenses[numExpenses].category[strlen(expenses[numExpenses].category)-1] = '\0';
                printf("Enter Amount: ");
                scanf("%f", &expenses[numExpenses].amount);
                getchar();      // flush the input buffer
                numExpenses++;
                break;
            }
            case 2: {
                if(numExpenses > 0) {
                    printExpenses(expenses, numExpenses);
                }
                else {
                    printf("\nNo expenses found!\n");
                }
                break;
            }
            case 3: {
                if(numExpenses > 0) {
                    printf("\nTotal Expense: $%.2f\n", totalExpense(expenses, numExpenses));
                }
                else {
                    printf("\nNo expenses found!\n");
                }
                break;
            }
            default: {
                break;
            }
        }
    } while(choice != 4);

    return 0;
}