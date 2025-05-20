//FormAI DATASET v1.0 Category: Expense Tracker ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct expense {
    char date[20];
    char category[50];
    float amount;
};

void addExpense(struct expense arr[], int *num_expenses) {
    printf("Enter expense date (dd/mm/yyyy format): ");
    fgets(arr[*num_expenses].date, 20, stdin);
    strtok(arr[*num_expenses].date, "\n"); // remove trailing newline character from input
    
    printf("Enter expense category: ");
    fgets(arr[*num_expenses].category, 50, stdin);
    strtok(arr[*num_expenses].category, "\n"); // remove trailing newline character from input
    
    printf("Enter expense amount: ");
    scanf("%f", &arr[*num_expenses].amount);
    getchar(); // clear buffer
    
    *num_expenses += 1; // increase number of expenses
}

void viewExpenses(struct expense arr[], int num_expenses) {
    if(num_expenses == 0) {
        printf("No expenses to display!\n");
        return;
    }
    printf("Date\t\tCategory\tAmount\n");
    for(int i=0; i<num_expenses; i++) {
        printf("%s\t%s\t%.2f\n", arr[i].date, arr[i].category, arr[i].amount);
    }
}

void viewCategoryExpenses(struct expense arr[], int num_expenses) {
    if(num_expenses == 0) {
        printf("No expenses to display!\n");
        return;
    }
    char category[50];
    printf("Enter category to view expenses for: ");
    fgets(category, 50, stdin);
    strtok(category, "\n"); // remove trailing newline character from input
    
    float total = 0.0;
    printf("Date\t\tAmount\n");
    for(int i=0; i<num_expenses; i++) {
        if(strcmp(arr[i].category, category) == 0) {
            printf("%s\t%.2f\n", arr[i].date, arr[i].amount);
            total += arr[i].amount;
        }
    }
    printf("Total expenses for category %s: %.2f\n", category, total);
}

int main() {
    int num_expenses = 0; // initialize number of expenses entered
    int option;
    struct expense expenses[100]; // create array to hold expenses (max 100)
    do {
        printf("\n1. Add expense\n");
        printf("2. View all expenses\n");
        printf("3. View expenses by category\n");
        printf("4. Exit\n");
        printf("Enter option (1-4): ");
        scanf("%d", &option);
        getchar(); // clear buffer
        
        switch(option) {
            case 1:
                addExpense(expenses, &num_expenses);
                break;
            case 2:
                viewExpenses(expenses, num_expenses);
                break;
            case 3:
                viewCategoryExpenses(expenses, num_expenses);
                break;
            case 4:
                printf("Closing expense tracker. Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
        
    } while(option != 4);
    
    return 0;
}