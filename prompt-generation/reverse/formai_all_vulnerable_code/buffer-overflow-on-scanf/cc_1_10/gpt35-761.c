//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to Personal Finance Planner! \n");

    float balance = 0.00;
    float income, expense;
    char choice;

    do {
        printf("\nChoose an option: \n");
        printf("1. Add income \n");
        printf("2. Add expense \n");
        printf("3. Check balance \n");
        printf("4. Exit \n");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Enter income amount: ");
                scanf("%f", &income);
                balance += income;
                printf("Income added successfully! \n");
                break;

            case '2':
                printf("Enter expense amount: ");
                scanf("%f", &expense);
                if (balance - expense < 0) {
                    printf("Sorry, you don't have enough balance! \n");
                } else {
                    balance -= expense;
                    printf("Expense added successfully! \n");
                }
                break;

            case '3':
                printf("Your current balance: %.2f \n", balance);
                break;

            case '4':
                printf("Thank you for using Personal Finance Planner! \n");
                exit(0);

            default:
                printf("Invalid input! Please try again. \n");
        }
    } while (choice != '4');

    return 0;
}