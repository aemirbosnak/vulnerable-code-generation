//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    double amount;
} expense;

int main() {
    expense expenses[MAX_EXPENSES];
    int num_expenses = 0;
    char choice;
    double total_expenses = 0.0;

    do {
        printf("\nWelcome to the Expense Tracker 3000!\n");
        printf("Please choose an option:\n");
        printf("A - Add expense\n");
        printf("R - Remove expense\n");
        printf("L - List expenses\n");
        printf("T - Total expenses\n");
        printf("Q - Quit\n");

        scanf(" %c", &choice);

        switch(choice) {
            case 'A':
                if(num_expenses >= MAX_EXPENSES) {
                    printf("Sorry, you can't add any more expenses.\n");
                } else {
                    printf("Enter expense name: ");
                    scanf("%s", expenses[num_expenses].name);
                    printf("Enter expense amount: $");
                    scanf("%lf", &expenses[num_expenses].amount);
                    num_expenses++;
                    printf("Expense added successfully!\n");
                }
                break;
            case 'R':
                if(num_expenses == 0) {
                    printf("Sorry, there are no expenses to remove.\n");
                } else {
                    printf("Enter expense name to remove: ");
                    scanf("%s", expenses[num_expenses - 1].name);
                    num_expenses--;
                    printf("Expense removed successfully!\n");
                }
                break;
            case 'L':
                printf("List of expenses:\n");
                for(int i = 0; i < num_expenses; i++) {
                    printf("%s - $%.2lf\n", expenses[i].name, expenses[i].amount);
                }
                break;
            case 'T':
                total_expenses = 0.0;
                for(int i = 0; i < num_expenses; i++) {
                    total_expenses += expenses[i].amount;
                }
                printf("Total expenses: $%.2lf\n", total_expenses);
                break;
            case 'Q':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while(choice!= 'Q');

    return 0;
}