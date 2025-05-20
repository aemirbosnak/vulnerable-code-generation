//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 100

typedef struct {
    int day;
    int month;
    int year;
    float amount;
    char category[20];
    char description[50];
} Expense;

int numExpenses = 0;
Expense expenses[MAX_EXPENSES];

void printExpenses() {
    printf("Date \t\t Amount \t Category \t Description\n");
    printf("----------------------------------------------------------\n");
    for(int i = 0; i < numExpenses; i++) {
        printf("%d/%d/%d \t $%.2f \t\t %s \t\t %s\n", 
            expenses[i].day, expenses[i].month, expenses[i].year,
            expenses[i].amount, expenses[i].category, expenses[i].description);
    }
}

void addExpense() {
    if(numExpenses >= MAX_EXPENSES) {
        printf("You have reached the maximum number of expenses. Please delete some expenses before adding new ones.\n");
    }
    else {
        Expense newExpense;
        printf("Please input the following information:\n");
        printf("Date (DD/MM/YYYY): ");
        scanf("%d/%d/%d", &newExpense.day, &newExpense.month, &newExpense.year);
        printf("Amount: $");
        scanf("%f", &newExpense.amount);
        printf("Category: ");
        scanf("%s", newExpense.category);
        printf("Description: ");
        scanf("%s", newExpense.description);
        expenses[numExpenses] = newExpense;
        numExpenses++;
    }
}

void deleteExpense() {
    int indexToDelete = -1;
    printf("Please input the date of the expense you would like to delete: (DD/MM/YYYY)\n");
    int day, month, year;
    scanf("%d/%d/%d", &day, &month, &year);
    for(int i = 0; i < numExpenses; i++) {
        if(expenses[i].day == day && expenses[i].month == month && expenses[i].year == year) {
            indexToDelete = i;
        }
    }
    if(indexToDelete == -1) {
        printf("Expense not found.\n");
    }
    else {
        for(int j = indexToDelete; j < numExpenses - 1; j++) {
            expenses[j] = expenses[j+1];
        }
        numExpenses--;
        printf("Expense successfully deleted.\n");
    }
}

float calculateTotalExpense() {
    float total = 0;
    for(int i = 0; i < numExpenses; i++) {
        total += expenses[i].amount;
    }
    return total;
}

void displayMenu() {
    printf("\n");
    printf("Expense Tracker\n");
    printf("1. Add Expense\n");
    printf("2. Delete Expense\n");
    printf("3. View Expenses\n");
    printf("4. Calculate Total Expense\n");
    printf("5. Exit\n");
    printf("\n");
}

int main() {
    int choice = 0;
    while(choice != 5) {
        displayMenu();
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addExpense();
                break;
            case 2:
                deleteExpense();
                break;
            case 3:
                printExpenses();
                break;
            case 4:
                printf("Total Expense: $%.2f\n", calculateTotalExpense());
                break;
            case 5:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}