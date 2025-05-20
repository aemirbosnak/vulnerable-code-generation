//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 1000

typedef struct {
    char name[100];
    float amount;
    int date;
} Expense;

int main() {
    int numExpenses = 0;
    Expense expenses[MAX_EXPENSES];

    char choice;
    do {
        printf("\nExpense Tracker\n");
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Exit\n");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                if(numExpenses >= MAX_EXPENSES) {
                    printf("Maximum expenses reached.\n");
                } else {
                    printf("Enter expense name: ");
                    scanf("%s", expenses[numExpenses].name);
                    printf("Enter expense amount: ");
                    scanf("%f", &expenses[numExpenses].amount);
                    printf("Enter expense date (YYYY-MM-DD): ");
                    scanf("%d", &expenses[numExpenses].date);
                    numExpenses++;
                    printf("Expense added successfully.\n");
                }
                break;
            case '2':
                if(numExpenses == 0) {
                    printf("No expenses added yet.\n");
                } else {
                    printf("\nExpense List:\n");
                    printf("------------------\n");
                    for(int i=0; i<numExpenses; i++) {
                        printf("%-20s %-10.2f %s\n", expenses[i].name, expenses[i].amount, ctime(&expenses[i].date));
                    }
                }
                break;
            case '3':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= '3');

    return 0;
}