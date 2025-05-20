//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    double amount;
    time_t date;
} expense;

int main() {
    expense expenses[MAX_EXPENSES];
    int num_expenses = 0;
    char choice;

    srand(time(NULL));

    do {
        printf("Enter 'a' to add an expense, 'd' to delete an expense, 'p' to print expenses, or 'q' to quit:\n");
        scanf("%c", &choice);

        switch(choice) {
            case 'a':
                if(num_expenses >= MAX_EXPENSES) {
                    printf("Maximum number of expenses reached.\n");
                } else {
                    printf("Enter expense name:\n");
                    scanf("%s", expenses[num_expenses].name);
                    printf("Enter expense amount:\n");
                    scanf("%lf", &expenses[num_expenses].amount);
                    expenses[num_expenses].date = time(NULL);
                    num_expenses++;
                    printf("Expense added.\n");
                }
                break;
            case 'd':
                if(num_expenses == 0) {
                    printf("No expenses to delete.\n");
                } else {
                    int index;
                    printf("Enter expense index to delete:\n");
                    scanf("%d", &index);
                    if(index >= 0 && index < num_expenses) {
                        num_expenses--;
                        for(int i = index; i < num_expenses; i++) {
                            expenses[i] = expenses[i+1];
                        }
                        printf("Expense deleted.\n");
                    } else {
                        printf("Invalid expense index.\n");
                    }
                }
                break;
            case 'p':
                printf("Expenses:\n");
                for(int i = 0; i < num_expenses; i++) {
                    printf("%s: $%.2lf (%s)\n", expenses[i].name, expenses[i].amount, ctime(&expenses[i].date));
                }
                break;
            case 'q':
                printf("Quitting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= 'q');

    return 0;
}