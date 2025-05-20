//FormAI DATASET v1.0 Category: Banking Record System ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_ACC 100
#define MAX_TRANS 100

//structure for a transaction record
struct Transaction {
    int transID;
    char type[10];
    float amount;
    float currentBalance;
};

//structure for a bank account
struct Account {
    int accNum;
    char name[50];
    float balance;
    struct Transaction transactions[MAX_TRANS];
    int numTrans;
};

//function prototypes 
void addAccount(struct Account *accounts, int *numAccounts);
void displayAccounts(struct Account *accounts, int numAccounts);
void deposit(struct Account *accounts, int numAccounts);
void withdraw(struct Account *accounts, int numAccounts);

int main() {
    struct Account accounts[MAX_ACC];
    int numAccounts = 0;
    int choice;

    do {
        printf("\n\nBank Record System\n");
        printf("-----------------------\n");
        printf("1. Add an account\n");
        printf("2. Display accounts\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Exit\n");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addAccount(accounts, &numAccounts);
                break;
            case 2:
                displayAccounts(accounts, numAccounts);
                break;
            case 3:
                deposit(accounts, numAccounts);
                break;
            case 4:
                withdraw(accounts, numAccounts);
                break;
            case 5:
                printf("\n\nExiting program...\n");
                break;
            default:
                printf("\n\nInvalid choice. Please try again.\n");
        }
    } while(choice != 5);

    return 0;
}

//function to add a new account to the bank record system
void addAccount(struct Account *accounts, int *numAccounts) {
    int accNum;
    char name[50];
    float balance;

    printf("\n\nEnter account number: ");
    scanf("%d", &accNum);

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter balance: ");
    scanf("%f", &balance);

    //create new account
    struct Account tempAccount;
    tempAccount.accNum = accNum;
    strcpy(tempAccount.name, name);
    tempAccount.balance = balance;
    tempAccount.numTrans = 0;

    //add new account to the accounts array
    *(accounts + *numAccounts) = tempAccount;
    (*numAccounts)++;

    printf("\n\nNew account added successfully.\n");
}

//function to display all accounts in the bank record system
void displayAccounts(struct Account *accounts, int numAccounts) {
    if(numAccounts == 0) {
        printf("\n\nThere are no accounts to display.\n");
        return;
    }

    printf("\n\nAccount Details:\n\n");
    printf("Acc No.\tName\tBalance\tNo. of Transactions\n");

    for(int i=0; i<numAccounts; i++) {
        printf("%d\t%s\t%.2f\t%d\n", (accounts+i)->accNum, (accounts+i)->name, (accounts+i)->balance, (accounts+i)->numTrans);
    }
}

//function to deposit money into an account
void deposit(struct Account *accounts, int numAccounts) {
    int accNum;
    float amount;

    printf("\n\nEnter account number: ");
    scanf("%d", &accNum);

    for(int i=0; i<numAccounts; i++) {
        if((accounts+i)->accNum == accNum) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);

            //add transaction record
            struct Transaction tempTrans;
            tempTrans.transID = (accounts+i)->numTrans + 1;
            strcpy(tempTrans.type, "DEPOSIT");
            tempTrans.amount = amount;
            tempTrans.currentBalance = (accounts+i)->balance + amount;

            //add transaction to account
            *((accounts+i)->transactions + (accounts+i)->numTrans) = tempTrans;
            (accounts+i)->numTrans++;
            
            //update account balance
            (accounts+i)->balance += amount;

            printf("\n\nDeposit successful.\n");
            return;
        }
    }

    printf("\n\nAccount not found.\n");
}

//function to withdraw money from an account
void withdraw(struct Account *accounts, int numAccounts) {
    int accNum;
    float amount;

    printf("\n\nEnter account number: ");
    scanf("%d", &accNum);

    for(int i=0; i<numAccounts; i++) {
        if((accounts+i)->accNum == accNum) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);

            if(amount > (accounts+i)->balance) {
                printf("\n\nWithdrawal unsuccessful. Insufficient balance.\n");
                return;
            }

            //add transaction record
            struct Transaction tempTrans;
            tempTrans.transID = (accounts+i)->numTrans + 1;
            strcpy(tempTrans.type, "WITHDRAW");
            tempTrans.amount = amount;
            tempTrans.currentBalance = (accounts+i)->balance - amount;

            //add transaction to account
            *((accounts+i)->transactions + (accounts+i)->numTrans) = tempTrans;
            (accounts+i)->numTrans++;
            
            //update account balance
            (accounts+i)->balance -= amount;

            printf("\n\nWithdrawal successful.\n");
            return;
        }
    }

    printf("\n\nAccount not found.\n");
}