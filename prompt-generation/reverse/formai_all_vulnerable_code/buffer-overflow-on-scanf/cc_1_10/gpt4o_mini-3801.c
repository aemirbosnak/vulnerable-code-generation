//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    float balance;
} Account;

void createAccount(Account *acc, const char *name) {
    strcpy(acc->name, name);
    acc->balance = 0.0;
}

void deposit(Account *acc, float amount) {
    if (amount > 0) {
        acc->balance += amount;
        printf("%s, thou hast deposited %.2f coins into thy account. Balance now is: %.2f\n", acc->name, amount, acc->balance);
    } else {
        printf("Alas! Thou must deposit a positive amount.\n");
    }
}

void withdraw(Account *acc, float amount) {
    if (amount > 0 && amount <= acc->balance) {
        acc->balance -= amount;
        printf("%s, thou hast withdrawn %.2f coins from thy account. Balance now is: %.2f\n", acc->name, amount, acc->balance);
    } else if (amount > acc->balance) {
        printf("Oh no! Thou dost not possess enough coins for such a withdrawal!\n");
    } else {
        printf("Alas! Thou must withdraw a positive amount.\n");
    }
}

void displayBalance(Account *acc) {
    printf("O noble %s, thy current balance is: %.2f coins.\n", acc->name, acc->balance);
}

void transactionMenu(Account *acc) {
    int choice;
    float amount;
    
    do {
        printf("\nAh! What dost thou wish to do, %s?\n", acc->name);
        printf("1. Deposit coins\n");
        printf("2. Withdraw coins\n");
        printf("3. Check balance\n");
        printf("4. Depart from this mortal banking realm\n");
        printf("Choose thy fate (1-4): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the amount to deposit: ");
                scanf("%f", &amount);
                deposit(acc, amount);
                break;
            case 2:
                printf("Enter the amount to withdraw: ");
                scanf("%f", &amount);
                withdraw(acc, amount);
                break;
            case 3:
                displayBalance(acc);
                break;
            case 4:
                printf("Farewell, %s! Until we meet again in interface lands!\n", acc->name);
                break;
            default:
                printf("Pray, choose a valid option!\n");
        }
    } while (choice != 4);
}

int main() {
    Account romeo, juliet;
    createAccount(&romeo, "Romeo");
    createAccount(&juliet, "Juliet");

    printf("In fair Verona, where we lay our scene,\n");
    printf("Two star-cross'd lovers had their coin's sheen.\n\n");

    transactionMenu(&romeo);
    transactionMenu(&juliet);

    printf("Thus ends our tale of banking and finance true,\n");
    printf("With coins and love both, may they flourish anew.\n");

    return 0;
}