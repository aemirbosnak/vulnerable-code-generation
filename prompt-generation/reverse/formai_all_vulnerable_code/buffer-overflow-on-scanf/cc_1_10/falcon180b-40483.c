//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number
int randnum() {
    return rand() % 100;
}

// Function to print menu
void printmenu() {
    printf("1. Add Income\n");
    printf("2. Add Expense\n");
    printf("3. View Balance\n");
    printf("4. View Transactions\n");
    printf("5. Exit\n");
}

// Function to add income
void addincome() {
    int amount;
    printf("Enter the amount of income: ");
    scanf("%d", &amount);
    printf("Income added successfully!\n");
    return;
}

// Function to add expense
void addexpense() {
    int amount;
    printf("Enter the amount of expense: ");
    scanf("%d", &amount);
    printf("Expense added successfully!\n");
    return;
}

// Function to view balance
void viewbalance() {
    int balance = 0;
    printf("Your current balance is: $%d\n", balance);
    return;
}

// Function to view transactions
void viewtransactions() {
    printf("Transactions:\n");
    return;
}

// Main function
int main() {
    srand(time(NULL));
    int choice, amount;
    char input[100];
    while(1) {
        printf("Enter your choice: ");
        scanf("%s", input);
        choice = atoi(input);
        switch(choice) {
            case 1:
                addincome();
                break;
            case 2:
                addexpense();
                break;
            case 3:
                viewbalance();
                break;
            case 4:
                viewtransactions();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}