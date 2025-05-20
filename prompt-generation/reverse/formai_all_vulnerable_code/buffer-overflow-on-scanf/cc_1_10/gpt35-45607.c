//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct expense {
    char date[30];
    char description[50];
    float amount;
} Expense;

int main() {
    int num_expenses;
    char choice;
    float total_expenses = 0.0;

    printf("Welcome to your expense tracker\n\n");

    printf("How many expenses do you want to track? ");
    scanf("%d", &num_expenses);

    Expense expenses[num_expenses];

    for(int i=0; i<num_expenses; i++) {
        printf("Expense %d\n", i+1);

        printf("Date (DD/MM/YYYY): ");
        scanf("%s", expenses[i].date);

        printf("Description: ");
        scanf("%s", expenses[i].description);

        printf("Amount: ");
        scanf("%f", &expenses[i].amount);

        total_expenses += expenses[i].amount;

        printf("\n");
    }

    printf("Do you want to view your expenses? (y/n) ");
    scanf("%s", &choice);

    if(choice == 'y') {
        printf("\nExpense Details\n\n");
        printf("Date        Description            Amount\n");
        printf("------------------------------------------\n");
        for(int i=0; i<num_expenses; i++) {
            printf("%s    %-20s $%-10.2f\n", expenses[i].date, expenses[i].description, expenses[i].amount);
        }

        printf("------------------------------------------\n");
        printf("Total:                          $%-10.2f\n\n", total_expenses);
    }

    printf("Thank you for using the expense tracker!\n");
    
    return 0;
}