//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    float amount;
    int date;
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense() {
    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[num_expenses].amount);
    printf("Enter expense date (YYYY-MM-DD): ");
    scanf("%d", &expenses[num_expenses].date);
    num_expenses++;
}

void view_expenses() {
    printf("Expense Name | Expense Amount | Expense Date\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s | %.2f | %d\n", expenses[i].name, expenses[i].amount, expenses[i].date);
    }
}

void remove_expense() {
    printf("Enter expense name to remove: ");
    char name[50];
    scanf("%s", name);
    for (int i = 0; i < num_expenses; i++) {
        if (strcmp(expenses[i].name, name) == 0) {
            for (int j = i; j < num_expenses - 1; j++) {
                strcpy(expenses[j].name, expenses[j+1].name);
                expenses[j].amount = expenses[j+1].amount;
                expenses[j].date = expenses[j+1].date;
            }
            num_expenses--;
            break;
        }
    }
    printf("Expense removed.\n");
}

int main() {
    int choice;
    do {
        printf("Expense Tracker\n");
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Remove expense\n");
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
                remove_expense();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= 4);
    return 0;
}