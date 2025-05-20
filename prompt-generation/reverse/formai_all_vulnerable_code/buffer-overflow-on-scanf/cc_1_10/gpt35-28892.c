//FormAI DATASET v1.0 Category: Expense Tracker ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

/* Structure for the expenses */
struct expense {
    char name[20];
    float amount;
};

typedef struct expense Expense;

/* Function prototypes */
void addExpense(Expense exp, Expense expenseArray[], int *expCount);
void displayExpenses(Expense expenseArray[], int expCount);
void totalExpenses(Expense expenseArray[], int expCount);
void deleteExpense(Expense expenseArray[], int *expCount, char name[]);
void clearInputBuffer();

int main() {
    int option, expCount = 0;
    Expense expenses[MAX];

    /* Menu options */
    printf(" Welcome to the Expense Tracker! \n");
    do {
        printf("\n");
        printf("1. Add expense\n");
        printf("2. Delete expense\n");
        printf("3. Display expenses\n");
        printf("4. View total expenses\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        clearInputBuffer();

        switch(option) {
            case 1: {
                Expense exp;
                printf("\nEnter the expense name: ");
                fgets(exp.name, 20, stdin);
                printf("Enter the amount: ");
                scanf("%f", &exp.amount);
                addExpense(exp, expenses, &expCount);
                printf("\n");
                break;
            }
            case 2: {
                char name[20];
                printf("\nEnter the expense name to be deleted: ");
                fgets(name, 20, stdin);
                deleteExpense(expenses, &expCount, name);
                printf("\n");
                break;
            }
            case 3: {
                displayExpenses(expenses, expCount);
                printf("\n");
                break;
            }
            case 4: {
                totalExpenses(expenses, expCount);
                printf("\n");
                break;
            }
            case 5: {
                printf("\nThank you for using the Expense Tracker!\n");
                break;
            }
            default: {
                printf("\nInvalid choice. Try again.\n");
                break;
            }
        }
    } while(option != 5);

    return 0;
}

/* Function to add expense */
void addExpense(Expense exp, Expense expenseArray[], int *expCount) {
    expenseArray[*expCount] = exp;
    (*expCount)++;
    printf("\nExpense added successfully!\n");
}

/* Function to delete expense */
void deleteExpense(Expense expenseArray[], int *expCount, char name[]) {
    int i, j, found = 0;
    for(i=0; i<*expCount; i++) {
        if(strcmp(expenseArray[i].name, name) == 0) {
            found = 1;
            for(j=i; j<*expCount-1; j++) {
                expenseArray[j] = expenseArray[j+1];
            }
            (*expCount)--;
            printf("\nExpense deleted successfully!\n");
            break;
        }
    }
    if(!found) {
        printf("\nExpense not found!\n");
    }
}

/* Function to display expenses */
void displayExpenses(Expense expenseArray[], int expCount) {
    int i;
    if(expCount == 0) {
        printf("\nNo expenses to display!\n");
    }
    else {
        printf("\nExpenses:\n");
        for(i=0; i<expCount; i++) {
            printf("%s: $%.2f\n", expenseArray[i].name, expenseArray[i].amount);
        }
    }
}

/* Function to calculate total expenses */
void totalExpenses(Expense expenseArray[], int expCount) {
    int i;
    float total = 0;
    if(expCount == 0) {
        printf("\nNo expenses to display!\n");
    }
    else {
        for(i=0; i<expCount; i++) {
            total += expenseArray[i].amount;
        }
        printf("\nTotal expenses: $%.2f\n", total);
    }
}

/* Function to clear input buffer */
void clearInputBuffer() {
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}