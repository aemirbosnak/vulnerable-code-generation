//FormAI DATASET v1.0 Category: Banking Record System ; Style: brave
#include <stdio.h>
#include <stdlib.h>

struct BankRecord {
    char name[30];
    int accountNumber;
    double balance;
};

struct BankRecord bank[100];
int numberOfAccounts = 0;

void addAccount() {
    printf("Enter Name: ");
    scanf("%s", bank[numberOfAccounts].name);
    printf("Enter Account Number: ");
    scanf("%d", &bank[numberOfAccounts].accountNumber);
    printf("Enter Balance: ");
    scanf("%lf", &bank[numberOfAccounts].balance);
    numberOfAccounts++;
    printf("Account added successfully!");
}

void deleteAccount() {
    int accountNumberToDelete;
    printf("Enter Account Number to Delete: ");
    scanf("%d", &accountNumberToDelete);
    int accountToDeleteIndex = -1;
    for(int i = 0; i < numberOfAccounts; i++) {
        if(bank[i].accountNumber == accountNumberToDelete) {
            accountToDeleteIndex = i;
            break;
        }
    }
    if(accountToDeleteIndex == -1) {
        printf("Account with Account Number %d not found!", accountNumberToDelete);
    } else {
        for(int i = accountToDeleteIndex; i < numberOfAccounts; i++) {
            bank[i] = bank[i + 1];
        }
        numberOfAccounts--;
        printf("Account Number %d deleted successfully!", accountNumberToDelete);
    }
}

void printAccountDetails() {
    printf("\n\n");

    printf("NAME\t\tACCOUNT NUMBER\t\tBALANCE\n");
    for(int i = 0; i < numberOfAccounts; i++) {
        printf("%s\t\t%d\t\t%.2lf\n", bank[i].name, bank[i].accountNumber, bank[i].balance);
    }

    printf("\n\n");
}

int main() {
    int choice;
    do {
        printf("1. Add Account\n");
        printf("2. Delete Account\n");
        printf("3. Print Account Details\n");
        printf("4. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addAccount();
                break;
            case 2:
                deleteAccount();
                break;
            case 3:
                printAccountDetails();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Choice!\n");
        }

    } while(1);
    return 0;
}