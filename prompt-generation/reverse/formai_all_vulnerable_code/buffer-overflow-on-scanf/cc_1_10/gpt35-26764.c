//FormAI DATASET v1.0 Category: Banking Record System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account {
    int accountNumber;
    char firstName[20];
    char lastName[20];
    float balance;
};

typedef struct account Account;

void createAccount(Account acc[], int count) {
    acc[count].accountNumber = count+1;
    printf("\nEnter First Name: ");
    scanf("%s", acc[count].firstName);
    printf("Enter Last Name: ");
    scanf("%s", acc[count].lastName);
    acc[count].balance = 0;
    printf("\nAccount created successfully! Your account number is %d\n", acc[count].accountNumber);
}

void displayAccount(Account acc[], int count) {
    printf("\n===========================\n");
    printf("Account Information\n");
    printf("===========================\n");
    printf("Account Number: %d\n", acc[count].accountNumber);
    printf("First Name: %s\n", acc[count].firstName);
    printf("Last Name: %s\n", acc[count].lastName);
    printf("Balance: %.2f\n", acc[count].balance);
}

void deposit(Account acc[], int count) {
    float amount;
    printf("\nEnter amount to deposit: ");
    scanf("%f", &amount);
    acc[count].balance += amount;
    printf("\nDeposit successful! Your new balance is %.2f\n", acc[count].balance);
}

void withdraw(Account acc[], int count) {
    float amount;
    printf("\nEnter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount > acc[count].balance) {
        printf("\nInsufficient balance!\n");
    } else {
        acc[count].balance -= amount;
        printf("\nWithdrawal successful! Your new balance is %.2f\n", acc[count].balance);
    }
}

void menu() {
    printf("\n********** Menu **********\n");
    printf("1. Create Account\n");
    printf("2. Display Account Information\n");
    printf("3. Deposit\n");
    printf("4. Withdraw\n");
    printf("5. Exit\n");
    printf("****************************\n");
}

int main() {
    Account acc[10]; // assumption: maximum of 10 accounts
    int count = 0;
    int choice;
    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (count < 10) {
                    createAccount(acc, count);
                    count++;
                    break;
                } else {
                    printf("\nCannot create more accounts as maximum account limit reached!\n");
                    break;
                }
            case 2:
                if (count > 0) {
                    int acc_num;
                    printf("\nEnter Account Number: ");
                    scanf("%d", &acc_num);
                    displayAccount(acc, acc_num-1);
                    break;
                } else {
                    printf("\nNo accounts available to display!\n");
                    break;
                }
            case 3:
                if (count > 0) {
                    int acc_num;
                    printf("\nEnter Account Number: ");
                    scanf("%d", &acc_num);
                    deposit(acc, acc_num-1);
                    break;
                } else {
                    printf("\nNo accounts available to deposit into!\n");
                    break;
                }
            case 4:
                if (count > 0) {
                    int acc_num;
                    printf("\nEnter Account Number: ");
                    scanf("%d", &acc_num);
                    withdraw(acc, acc_num-1);
                    break;
                } else {
                    printf("\nNo accounts available to withdraw from!\n");
                    break;
                }
            case 5:
                printf("\nThank you for banking with us!\n");
                break;
            default:
                printf("\nInvalid Choice!\n");
                break;
        }
    } while (choice != 5);

    return 0;
}