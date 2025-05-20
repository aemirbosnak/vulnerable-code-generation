//FormAI DATASET v1.0 Category: Banking Record System ; Style: Dennis Ritchie
#include <stdio.h>

struct Account {
    int accountNo;
    char ownerName[50];
    float balance;
};

void displayMenu() {
    printf("==== Banking Record System ====\n");
    printf("1. Add Account\n");
    printf("2. Display Account by Account Number\n");
    printf("3. Display All Accounts\n");
    printf("4. Exit\n");
    printf("==============================\n");
}

int addAccount(struct Account accounts[], int numAccounts) {
    printf("Enter Account No: ");
    scanf("%d", &accounts[numAccounts].accountNo);
    printf("Enter Owner Name: ");
    scanf("%s", accounts[numAccounts].ownerName);
    printf("Enter Balance: ");
    scanf("%f", &accounts[numAccounts].balance);
    printf("Account Added Successfully!\n");
    return numAccounts + 1;
}

void displayAccountByAccountNo(struct Account accounts[], int numAccounts) {
    int accountNo;
    printf("Enter Account No: ");
    scanf("%d", &accountNo);
    int found = 0;
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNo == accountNo) {
            printf("Account No: %d\n", accounts[i].accountNo);
            printf("Owner Name: %s\n", accounts[i].ownerName);
            printf("Balance: $%.2f\n", accounts[i].balance);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Account Not Found!\n");
    }
}

void displayAllAccounts(struct Account accounts[], int numAccounts) {
    printf("==== All Accounts ====\n");
    for (int i = 0; i < numAccounts; i++) {
        printf("Account No: %d\n", accounts[i].accountNo);
        printf("Owner Name: %s\n", accounts[i].ownerName);
        printf("Balance: $%.2f\n", accounts[i].balance);
    }
}

int main() {
    struct Account accounts[10];
    int numAccounts = 0;
    int choice;
    do {
        displayMenu();
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                numAccounts = addAccount(accounts, numAccounts);
                break;
            case 2:
                displayAccountByAccountNo(accounts, numAccounts);
                break;
            case 3:
                displayAllAccounts(accounts, numAccounts);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid Choice!\n");
        }
    } while (choice != 4);
    return 0;
}