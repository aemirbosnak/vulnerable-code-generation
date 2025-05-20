//Falcon2-11B DATASET v1.0 Category: Personal Finance Planner ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    float balance;
} Account;

int main() {
    Account accounts[3] = {
        {"Savings", 5000.0},
        {"Checking", 2000.0},
        {"Credit Card", 5000.0}
    };

    int choice;
    int i;

    printf("Welcome to your personal finance planner!\n");
    printf("Please select an option:\n");
    printf("1. View your account balances\n");
    printf("2. Deposit money into an account\n");
    printf("3. Withdraw money from an account\n");
    printf("4. Exit the program\n");

    do {
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Your account balances:\n");
                for (i = 0; i < 3; i++) {
                    printf("%s: $%.2f\n", accounts[i].name, accounts[i].balance);
                }
                break;
            case 2:
                printf("Enter the name of the account to deposit money into: ");
                scanf("%s", accounts[choice].name);
                printf("Enter the amount to deposit: ");
                scanf("%f", &accounts[choice].balance);
                break;
            case 3:
                printf("Enter the name of the account to withdraw money from: ");
                scanf("%s", accounts[choice].name);
                printf("Enter the amount to withdraw: ");
                scanf("%f", &accounts[choice].balance);
                break;
            case 4:
                printf("Thank you for using the personal finance planner!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 4);

    return 0;
}