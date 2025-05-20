//FormAI DATASET v1.0 Category: Banking Record System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account {
    int accountNumber;
    char accountHolderName[30];
    float balance;
}acc[100];

int numOfAccounts = 0;

void displayMenu() {
    printf("\n\nWelcome to C Banking Record System\n");
    printf("----------------------------\n");
    printf("1. Add an account\n");
    printf("2. Display all accounts\n");
    printf("3. Update an account\n");
    printf("4. Delete an account\n");
    printf("5. Quit the program\n");
}

void addAccount() {
    system("clear");
    struct account newAccount;
    printf("Enter account number: ");
    scanf("%d", &newAccount.accountNumber);
    printf("Enter account holder name: ");
    scanf("%s", newAccount.accountHolderName);
    printf("Enter balance: ");
    scanf("%f", &newAccount.balance);
    acc[numOfAccounts++] = newAccount;
    printf("\nAccount added successfully!\n");
}

void displayAccounts() {
    system("clear");
    if (numOfAccounts == 0) {
        printf("\nNo accounts found!\n");
        return;
    }
    printf("Account Number\tAccount Holder Name\tBalance\n");
    for (int i = 0; i < numOfAccounts; i++) {
        struct account currAccount = acc[i];
        printf("%d\t\t%s\t\t%.2f\n", currAccount.accountNumber, currAccount.accountHolderName, currAccount.balance);
    }
}

void updateAccount() {
    system("clear");
    int accountNum, found = 0;
    printf("Enter account number to update: ");
    scanf("%d", &accountNum);
    for (int i = 0; i < numOfAccounts; i++) {
        struct account currAccount = acc[i];
        if (currAccount.accountNumber == accountNum) {
            printf("\nEnter new balance: ");
            scanf("%f", &currAccount.balance);
            acc[i] = currAccount;
            printf("\nAccount updated successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nNo account found with that account number!\n");
    }
}

void deleteAccount() {
    system("clear");
    int accountNum, found = 0;
    printf("Enter account number to delete: ");
    scanf("%d", &accountNum);
    for (int i = 0; i < numOfAccounts; i++) {
        struct account currAccount = acc[i];
        if (currAccount.accountNumber == accountNum) {
            for (int j = i; j < numOfAccounts-1; j++) {
                acc[j] = acc[j+1];
            }
            numOfAccounts--;
            printf("\nAccount deleted successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nNo account found with that account number!\n");
    }
}

int main() {
    while (1) {
        displayMenu();
        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addAccount();
                break;
            case 2:
                displayAccounts();
                break;
            case 3:
                updateAccount();
                break;
            case 4:
                deleteAccount();
                break;
            case 5:
                printf("\nThank you for using C Banking Record System!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}