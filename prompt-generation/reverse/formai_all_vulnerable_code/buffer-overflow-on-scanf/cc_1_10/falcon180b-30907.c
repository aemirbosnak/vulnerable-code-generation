//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    float amount;
    int date;
} expense;

expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense() {
    char name[50];
    float amount;
    int date;

    printf("Enter expense name: ");
    scanf("%s", name);

    printf("Enter expense amount: $");
    scanf("%f", &amount);

    printf("Enter expense date (YYYY-MM-DD): ");
    scanf("%d-%d-%d", &date, &date+1, &date+3);

    strcpy(expenses[num_expenses].name, name);
    expenses[num_expenses].amount = amount;
    expenses[num_expenses].date = date;

    num_expenses++;
}

void view_expenses() {
    int i;

    printf("\nExpenses:\n");
    for(i=0; i<num_expenses; i++) {
        printf("%s - $%.2f - %d\n", expenses[i].name, expenses[i].amount, expenses[i].date);
    }
}

void search_expense() {
    char name[50];

    printf("\nEnter expense name to search: ");
    scanf("%s", name);

    int i;
    for(i=0; i<num_expenses; i++) {
        if(strcmp(expenses[i].name, name) == 0) {
            printf("\n%s - $%.2f - %d\n", expenses[i].name, expenses[i].amount, expenses[i].date);
        }
    }
}

int main() {
    int choice;

    do {
        printf("\nExpense Tracker\n");
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Search expense\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_expense();
                break;
            case 2:
                view_expenses();
                break;
            case 3:
                search_expense();
                break;
            case 4:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while(choice!= 4);

    return 0;
}