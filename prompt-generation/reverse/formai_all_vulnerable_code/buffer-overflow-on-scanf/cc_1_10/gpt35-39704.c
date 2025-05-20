//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

struct Expense {
    char name[50];
    float amount;
};

struct Budget {
    float income;
    float expenses;
    struct Expense expList[10];
};

void printMenu() {
    printf("\nWelcome to the Personal Finance Planner!\n");
    printf("Please choose an option:\n");
    printf("1. Enter budget\n");
    printf("2. View budget\n");
    printf("3. Exit\n");
}

void enterBudget(struct Budget* ptr) {
    printf("\nEnter your income: Rs ");
    scanf("%f", &(ptr->income));
    printf("Enter your expenses: Rs ");
    scanf("%f", &(ptr->expenses));
    printf("\nEnter your expenses details:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d. Item: ", i+1);
        scanf("%s", ptr->expList[i].name);
        printf("         Amount: Rs ");
        scanf("%f", &(ptr->expList[i].amount));
    }
}

void viewBudget(struct Budget* ptr) {
    float totalExpense = 0;
    printf("\nIncome: Rs %.2f\n", ptr->income);
    printf("Expenses:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d. %s - Rs %.2f\n", i+1, ptr->expList[i].name, ptr->expList[i].amount);
        totalExpense += ptr->expList[i].amount;
    }
    printf("\nTotal expenses: Rs %.2f\n", totalExpense);
    printf("Remaining balance: Rs %.2f\n", ptr->income - totalExpense);
}

int main() {
    struct Budget myBudget;
    int choice;
    do {
        printMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                enterBudget(&myBudget);
                break;
            case 2:
                viewBudget(&myBudget);
                break;
            case 3:
                printf("\nThank you for using Personal Finance Planner!\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    } while(choice != 3);

    return 0;
}