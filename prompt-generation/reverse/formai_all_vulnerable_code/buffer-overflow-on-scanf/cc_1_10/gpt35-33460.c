//FormAI DATASET v1.0 Category: Banking Record System ; Style: brave
#include <stdio.h>
#include <stdlib.h>

struct customer {
    char name[50];
    int account_number;
    float balance;
};

struct transaction {
    int sender_account_number;
    int receiver_account_number;
    float amount;
};

void menu();
void new_account();
void view_account();
void deposit();
void withdraw();
void transfer();

struct customer c[10];
struct transaction t[10];
int counter = 0;

int main() {
    int option;

    do {
        menu();
        printf("\nPlease select an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                new_account();
                break;
            case 2:
                view_account();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdraw();
                break;
            case 5:
                transfer();
                break;
            case 6:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid option, please try again.\n");
                break;
        }
    } while (option != 6);

    return 0;
}

void menu() {
    printf("\n-------------------------\n");
    printf("Banking Record System\n");
    printf("-------------------------\n");
    printf("1. Create a new account\n");
    printf("2. View account information\n");
    printf("3. Deposit money into account\n");
    printf("4. Withdraw money from account\n");
    printf("5. Transfer money between accounts\n");
    printf("6. Exit\n");
}

void new_account() {
    printf("\nCreating a new account...\n");

    printf("\nEnter your name: ");
    scanf("%s", c[counter].name);

    printf("Enter your account number: ");
    scanf("%d", &c[counter].account_number);

    printf("Enter your initial balance: ");
    scanf("%f", &c[counter].balance);

    printf("Account created successfully.\n");
    counter++;
}

void view_account() {
    int account_number, i;

    printf("\nEnter your account number: ");
    scanf("%d", &account_number);

    for (i = 0; i < counter; i++) {
        if (c[i].account_number == account_number) {
            printf("\nName: %s", c[i].name);
            printf("\nAccount number: %d", c[i].account_number);
            printf("\nBalance: $%.2f\n", c[i].balance);
            break;
        }
    }

    if (i == counter) {
        printf("\nAccount not found, please try again.\n");
    }
}

void deposit() {
    int account_number, i;
    float amount;

    printf("\nEnter your account number: ");
    scanf("%d", &account_number);

    for (i = 0; i < counter; i++) {
        if (c[i].account_number == account_number) {
            printf("\nEnter amount to deposit: $");
            scanf("%f", &amount);
            c[i].balance += amount;

            t[i].sender_account_number = account_number;
            t[i].receiver_account_number = account_number;
            t[i].amount = amount;
            printf("\nDeposit successful.\n");
            break;
        }
    }
    
    if (i == counter) {
        printf("\nAccount not found, please try again.\n");
    }
}

void withdraw() {
    int account_number, i;
    float amount;

    printf("\nEnter your account number: ");
    scanf("%d", &account_number);

    for (i = 0; i < counter; i++) {
        if (c[i].account_number == account_number) {
            printf("\nEnter amount to withdraw: $");
            scanf("%f", &amount);

            if (c[i].balance < amount) {
                printf("\nInsufficient balance, withdrawal not possible.\n");
                break;
            }

            c[i].balance -= amount;

            t[i].sender_account_number = account_number;
            t[i].receiver_account_number = account_number;
            t[i].amount = amount;
            printf("\nWithdrawal successful.\n");
            break;
        }
    }
    
    if (i == counter) {
        printf("\nAccount not found, please try again.\n");
    }
}

void transfer() {
    int sender_account_number, receiver_account_number, i;
    float amount;

    printf("\nEnter your account number: ");
    scanf("%d", &sender_account_number);

    printf("\nEnter recipient's account number: ");
    scanf("%d", &receiver_account_number);

    for (i = 0; i < counter; i++) {
        if (c[i].account_number == sender_account_number) {
            printf("\nEnter amount to transfer: $");
            scanf("%f", &amount);

            if (c[i].balance < amount) {
                printf("\nInsufficient balance, transfer not possible.\n");
                break;
            }

            for (int j = 0; j < counter; j++) {
                if (c[j].account_number == receiver_account_number) {
                    c[i].balance -= amount;
                    c[j].balance += amount;

                    t[i].sender_account_number = sender_account_number;
                    t[i].receiver_account_number = receiver_account_number;
                    t[i].amount = amount;
                    printf("\nTransfer successful.\n");
                    return;
                }
            }

            printf("\nRecipient's account not found, please try again.\n");
            break;
        }
    }
        
    if (i == counter) {
        printf("\nAccount not found, please try again.\n");
    }
}