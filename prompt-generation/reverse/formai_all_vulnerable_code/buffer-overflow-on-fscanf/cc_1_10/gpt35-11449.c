//FormAI DATASET v1.0 Category: Expense Tracker ; Style: retro
#include <stdio.h>
#include <stdlib.h>

struct expense {
    char category[20];
    float cost;
};

void addExpense(struct expense expenses[], int *numExpenses) {
    printf("\nEnter category: ");
    scanf("%s", expenses[*numExpenses].category);
    printf("Enter cost: ");
    scanf("%f", &expenses[*numExpenses].cost);
    (*numExpenses)++;
    printf("\nExpense added!\n");
}

void viewExpenses(struct expense expenses[], int numExpenses) {
    printf("\nCategory\tCost\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%s\t\t%.2f\n", expenses[i].category, expenses[i].cost);
    }
}

void saveExpenses(struct expense expenses[], int numExpenses) {
    FILE *fptr;
    fptr = fopen("expenses.txt", "w");
    if (fptr == NULL) {
        printf("\nError opening file.\n");
        return;
    }
    for (int i = 0; i < numExpenses; i++) {
        fprintf(fptr, "%s,%.2f\n", expenses[i].category, expenses[i].cost);
    }
    fclose(fptr);
    printf("\nExpenses saved!\n");
}

void loadExpenses(struct expense expenses[], int *numExpenses) {
    FILE *fptr;
    fptr = fopen("expenses.txt", "r");
    if (fptr == NULL) {
        printf("\nError opening file.\n");
        return;
    }
    while(!feof(fptr)) {
        fscanf(fptr, "%[^,],%f\n", expenses[*numExpenses].category, &expenses[*numExpenses].cost);
        (*numExpenses)++;
    }
    fclose(fptr);
    printf("\nExpenses loaded!\n");
}

void printMenu() {
    printf("\nExpense Tracker\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Save Expenses\n");
    printf("4. Load Expenses\n");
    printf("5. Exit\n");
}

int main(void) {
    struct expense expenses[100];
    int menuChoice, numExpenses = 0;
    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &menuChoice);
        switch(menuChoice) {
            case 1: addExpense(expenses, &numExpenses);
                break;
            case 2: viewExpenses(expenses, numExpenses);
                break;
            case 3: saveExpenses(expenses, numExpenses);
                break;
            case 4: loadExpenses(expenses, &numExpenses);
                break;
            case 5: printf("\nGoodbye!\n");
                break;
            default: printf("\nInvalid menu choice.\n");
                break;
        }
    } while(menuChoice != 5);
    return 0;
}