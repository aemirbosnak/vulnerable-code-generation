//FormAI DATASET v1.0 Category: Banking Record System ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>

struct Account {
    int accNo;
    char name[20];
    float balance;
};

void getDetails(struct Account *a);
void printDetails(struct Account a);
void deposit(struct Account *a);
void withdraw(struct Account *a);

int main() {
    int n, choice, i, accNo;
    struct Account *accounts;

    printf("Enter the number of accounts: ");
    scanf("%d", &n);

    accounts = (struct Account*) malloc(n * sizeof(struct Account));

    for(i=0; i<n; i++) {
        getDetails(&accounts[i]);
    }

    while(1) {
        printf("\nChoose account operation\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Print Account Details\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 4) {
            break;
        }

        printf("\nEnter account number: ");
        scanf("%d", &accNo);

        for(i=0; i<n; i++) {
            if(accounts[i].accNo == accNo) {
                switch(choice) {
                    case 1:
                        deposit(&accounts[i]);
                        break;
                    case 2:
                        withdraw(&accounts[i]);
                        break;
                    case 3:
                        printDetails(accounts[i]);
                        break;
                    default:
                        printf("Invalid Choice\n");
                }
                break;
            }
        }

        if(i == n) {
            printf("Account not found\n");
        }
    }

    free(accounts);

    return 0;
}

void getDetails(struct Account *a) {
    printf("\nEnter Account Number: ");
    scanf("%d", &a->accNo);
    printf("Enter Name: ");
    scanf("%s", a->name);
    printf("Enter Balance: ");
    scanf("%f", &(a->balance));
}

void printDetails(struct Account a) {
    printf("\nAccount Number: %d\n", a.accNo);
    printf("Name: %s\n", a.name);
    printf("Balance: %.2f\n", a.balance);
}

void deposit(struct Account *a) {
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    a->balance += amount;
    printf("New balance: %.2f\n", a->balance);
}

void withdraw(struct Account *a) {
    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if(amount > a->balance) {
        printf("Insufficient balance\n");
        return;
    }
    a->balance -= amount;
    printf("New balance: %.2f\n", a->balance);
}