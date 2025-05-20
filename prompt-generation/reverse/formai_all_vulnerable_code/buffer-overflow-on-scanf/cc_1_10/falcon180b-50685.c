//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 100

typedef struct {
    char category[50];
    float amount;
    char date[20];
} Expense;

int main() {
    Expense expenses[MAX_EXPENSES];
    int num_expenses = 0;
    char choice;

    do {
        printf("Expense Tracker\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                if(num_expenses >= MAX_EXPENSES) {
                    printf("Maximum number of expenses reached.\n");
                } else {
                    printf("Enter expense category: ");
                    scanf("%s", expenses[num_expenses].category);
                    printf("Enter expense amount: ");
                    scanf("%f", &expenses[num_expenses].amount);
                    printf("Enter expense date (dd/mm/yyyy): ");
                    scanf("%s", expenses[num_expenses].date);
                    num_expenses++;
                }
                break;
            case '2':
                printf("Expense Summary:\n");
                for(int i=0; i<num_expenses; i++) {
                    printf("%s - %.2f - %s\n", expenses[i].category, expenses[i].amount, expenses[i].date);
                }
                break;
            case '3':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while(choice!= '3');

    return 0;
}