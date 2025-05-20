//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: safe
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[100];
    int budget;
    int income;
    int expense;
    int savings;
} PersonalFinance;

void addTransaction(PersonalFinance *pf, int type, int amount) {
    switch(type) {
        case 1:
            pf->income += amount;
            printf("Income added: $%d\n", amount);
            break;
        case 2:
            pf->expense += amount;
            printf("Expense added: $%d\n", amount);
            break;
        case 3:
            pf->savings += amount;
            printf("Savings added: $%d\n", amount);
            break;
        default:
            printf("Invalid transaction type\n");
            break;
    }
}

void printSummary(PersonalFinance *pf) {
    printf("Budget: $%d\n", pf->budget);
    printf("Income: $%d\n", pf->income);
    printf("Expense: $%d\n", pf->expense);
    printf("Savings: $%d\n", pf->savings);
}

int main() {
    PersonalFinance pf;
    int choice, amount;

    printf("Welcome to Personal Finance Planner\n");
    printf("Enter your name: ");
    scanf("%s", pf.name);
    printf("Enter your monthly budget: $");
    scanf("%d", &pf.budget);

    while(1) {
        printf("\n1. Add income\n2. Add expense\n3. Add savings\n4. Print summary\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter income amount: $");
                scanf("%d", &amount);
                addTransaction(&pf, 1, amount);
                break;
            case 2:
                printf("Enter expense amount: $");
                scanf("%d", &amount);
                addTransaction(&pf, 2, amount);
                break;
            case 3:
                printf("Enter savings amount: $");
                scanf("%d", &amount);
                addTransaction(&pf, 3, amount);
                break;
            case 4:
                printSummary(&pf);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}