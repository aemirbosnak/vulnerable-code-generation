//FormAI DATASET v1.0 Category: Banking Record System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

struct account {
    char name[50];
    int accNum;
    float balance;
};

void displayAccount(struct account*);
void deposit(struct account*);
void withdraw(struct account*);

int main() {
    struct account a1;
    int choice;

    printf("Enter Account Name: ");
    fgets(a1.name, 50, stdin);
    printf("Enter Account Number: ");
    scanf("%d", &a1.accNum);
    printf("Enter Account Balance: ");
    scanf("%f", &a1.balance);

    while (1) {
        printf("\n\n1. Display Account Info");
        printf("\n2. Deposit Funds");
        printf("\n3. Withdraw Funds");
        printf("\n4. Exit");
        printf("\nEnter Choice: ");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                displayAccount(&a1);
                break;
            case 2:
                deposit(&a1);
                break;
            case 3:
                withdraw(&a1);
                break;
            case 4:
                printf("\nExiting Program...");
                exit(0);
            default:
                printf("\nInvalid Choice");
                break;
        }
    }

    return 0;
}

void displayAccount(struct account* a) {
    printf("\n------------------");
    printf("\nAccount Information");
    printf("\n------------------");
    printf("\nAccount Name: %s", a->name);
    printf("Account Number: %d\nAccount Balance: $%.2f\n", a->accNum, a->balance);
}

void deposit(struct account* a) {
    float amount;

    printf("\nEnter Deposit Amount: $");
    scanf("%f", &amount);

    a->balance += amount;

    printf("\nDeposit Successful!\nNew Balance: $%.2f", a->balance);
}

void withdraw(struct account* a) {
    float amount;

    printf("\nEnter Withdrawal Amount: $");
    scanf("%f", &amount);

    if (a->balance >= amount) {
        a->balance -= amount;

        printf("\nWithdrawal Successful!\nNew Balance: $%.2f", a->balance);
    } else {
        printf("\nInsufficient Funds!");
    }
}