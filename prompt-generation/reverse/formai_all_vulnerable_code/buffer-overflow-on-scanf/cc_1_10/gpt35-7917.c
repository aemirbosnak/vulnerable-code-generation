//FormAI DATASET v1.0 Category: Banking Record System ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct bankRecord {
    int accountNo;
    char name[30];
    float balance;
};

void createAccount(struct bankRecord *accountPtr) {
    printf("\nEnter Account Number: ");
    scanf("%d", &accountPtr->accountNo);
    while(getchar() != '\n');
    printf("Enter Account Holder Name: ");
    scanf("%[^\n]", accountPtr->name);
    while(getchar() != '\n');
    printf("Enter Initial Balance: ");
    scanf("%f", &accountPtr->balance);
    while(getchar() != '\n');
}

void deposit(struct bankRecord *accountPtr) {
    float amt;
    printf("\nEnter Amount to Deposit: ");
    scanf("%f", &amt);
    while(getchar() != '\n');
    accountPtr->balance += amt;
    printf("Updated Balance: %.2f", accountPtr->balance);
}

void withdraw(struct bankRecord *accountPtr) {
    float amt;
    printf("\nEnter Amount to Withdraw: ");
    scanf("%f", &amt);
    while(getchar() != '\n');
    if(amt > accountPtr->balance) {
        printf("Insufficient Balance!");
        return;
    }
    accountPtr->balance -= amt;
    printf("Updated Balance: %.2f", accountPtr->balance);
}

void display(struct bankRecord *accountPtr) {
    printf("\nAccount Number: %d", accountPtr->accountNo);
    printf("\nAccount Holder Name: %s", accountPtr->name);
    printf("\nAvailable Balance: %.2f\n", accountPtr->balance);
}

int main() {
    struct bankRecord accounts[5];
    int i, accNo;
    int choice;

    printf("\nBank Record System\n");
    do {
        printf("\nAvailable Operations:\n");
        printf("1. Create Account\n");
        printf("2. Deposit Amount\n");
        printf("3. Withdraw Amount\n");
        printf("4. Display Account Details\n");
        printf("0. Exit\n");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);
        while(getchar() != '\n');

        switch (choice) {
            case 1:
                printf("\nCreating Account...\n");
                for(i=0; i<5; i++) {
                    if(accounts[i].accountNo == 0) {
                        createAccount(&accounts[i]);
                        printf("\nAccount Created Successfully!");
                        break;
                    }
                }
                if(i == 5) {
                    printf("\nCannot Create More Accounts!");
                }
                break;

            case 2:
                printf("\nEnter Account Number: ");
                scanf("%d", &accNo);
                while(getchar() != '\n');
                for(i=0; i<5; i++) {
                    if(accounts[i].accountNo == accNo) {
                        deposit(&accounts[i]);
                        break;
                    }
                }
                if(i == 5) {
                    printf("\nInvalid Account Number!");
                }
                break;

            case 3:
                printf("\nEnter Account Number: ");
                scanf("%d", &accNo);
                while(getchar() != '\n');
                for(i=0; i<5; i++) {
                    if(accounts[i].accountNo == accNo) {
                        withdraw(&accounts[i]);
                        break;
                    }
                }
                if(i == 5) {
                    printf("\nInvalid Account Number!");
                }
                break;

            case 4:
                printf("\nEnter Account Number: ");
                scanf("%d", &accNo);
                while(getchar() != '\n');
                for(i=0; i<5; i++) {
                    if(accounts[i].accountNo == accNo) {
                        display(&accounts[i]);
                        break;
                    }
                }
                if(i == 5) {
                    printf("\nInvalid Account Number!");
                }
                break;

            case 0:
                printf("\nExiting...");
                exit(0);
                break;

            default:
                printf("\nInvalid Choice! Please Try Again.");
        }
    } while(1);

    return 0;
}