//FormAI DATASET v1.0 Category: Expense Tracker ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

struct expense {
    char name[30];
    float amount;
};

void printMenu() {
    printf("\nExpenses Tracker\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

int main() {
    struct expense expenses[MAX_EXPENSES];
    int numExpenses = 0;
    int choice;

    do {
        printMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                printf("\nEnter name of expense: ");
                scanf("%s", expenses[numExpenses].name);

                printf("Enter amount: ");
                scanf("%f", &expenses[numExpenses].amount);

                numExpenses++;
                break;
            }
            case 2: {
                printf("\nExpense\tAmount\n");
                printf("-------\t------\n");

                for(int i = 0; i < numExpenses; i++) {
                    printf("%s\t$%.2f\n", expenses[i].name, expenses[i].amount);
                }

                break;
            }
            case 3: {
                printf("\nExiting program...\n");
                break;
            }
            default: {
                printf("\nInvalid choice. Please try again.\n");
            }
        }
    } while(choice != 3);

    return 0;
}