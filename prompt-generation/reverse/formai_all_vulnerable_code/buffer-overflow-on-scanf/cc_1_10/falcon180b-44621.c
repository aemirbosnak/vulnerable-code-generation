//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

typedef struct {
    char name[50];
    double amount;
    time_t date;
} expense;

int main() {
    expense expenses[100];
    int num_expenses = 0;
    double total_expenses = 0;
    char choice;

    do {
        printf("Enter choice:\n1. Add expense\n2. View expenses\n3. View total expenses\n4. Quit\n");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                printf("Enter expense name: ");
                scanf("%s", expenses[num_expenses].name);
                printf("Enter expense amount: $");
                scanf("%lf", &expenses[num_expenses].amount);
                time(&expenses[num_expenses].date);
                num_expenses++;
                break;

            case '2':
                printf("Expenses:\n");
                for(int i=0; i<num_expenses; i++) {
                    printf("%s: $%.2f on %s\n", expenses[i].name, expenses[i].amount, ctime(&expenses[i].date));
                }
                break;

            case '3':
                total_expenses = 0;
                for(int i=0; i<num_expenses; i++) {
                    total_expenses += expenses[i].amount;
                }
                printf("Total expenses: $%.2f\n", total_expenses);
                break;

            case '4':
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= '4');

    return 0;
}