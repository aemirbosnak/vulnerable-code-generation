//Falcon2-11B DATASET v1.0 Category: Personal Finance Planner ; Style: random
#include <stdio.h>

int main() {
    printf("Personal Finance Planner\n");
    printf("------------------------\n");
    printf("Welcome to the Personal Finance Planner!\n");
    printf("Please enter your name:\n");
    char name[50];
    fgets(name, 50, stdin);
    printf("Hello %s, and welcome to the Personal Finance Planner!\n", name);
    printf("What would you like to do today?\n");
    printf("1. Add a new expense\n");
    printf("2. View expenses\n");
    printf("3. View income\n");
    printf("4. View net worth\n");
    printf("5. Quit\n");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Please enter the expense details:\n");
            printf("Amount: ");
            int amount;
            scanf("%d", &amount);
            printf("Description: ");
            char desc[100];
            fgets(desc, 100, stdin);
            printf("Added new expense: $%d - %s\n", amount, desc);
            break;
        case 2:
            printf("Expenses:\n");
            printf("---------------------\n");
            printf("Amount - Description\n");
            printf("---------------------\n");
            for (int i = 0; i < 10; i++) {
                printf("%d - %s\n", i, "Expense " + i);
            }
            break;
        case 3:
            printf("Income:\n");
            printf("---------------------\n");
            printf("Amount - Description\n");
            printf("---------------------\n");
            printf("Income: $0\n");
            break;
        case 4:
            printf("Net Worth:\n");
            printf("---------------------\n");
            printf("Assets - Liabilities\n");
            printf("---------------------\n");
            printf("Net Worth: $0\n");
            break;
        case 5:
            printf("Goodbye!\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}