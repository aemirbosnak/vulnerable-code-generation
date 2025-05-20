//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account {
    int acc_no;
    char name[50];
    double balance;
};

struct bank {
    int num_accounts;
    struct account accounts[100];
};

int main() {
    struct bank bank;
    int choice, acc_no, i;
    double amount;

    bank.num_accounts = 0;

    while (1) {
        printf("1. Create account\n");
        printf("2. Deposit money\n");
        printf("3. Withdraw money\n");
        printf("4. Check balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter account number: ");
                scanf("%d", &acc_no);
                printf("Enter name: ");
                scanf("%s", bank.accounts[bank.num_accounts].name);
                printf("Enter initial balance: ");
                scanf("%lf", &bank.accounts[bank.num_accounts].balance);
                bank.num_accounts++;
                break;
            case 2:
                printf("Enter account number: ");
                scanf("%d", &acc_no);
                printf("Enter amount to deposit: ");
                scanf("%lf", &amount);
                for (i = 0; i < bank.num_accounts; i++) {
                    if (bank.accounts[i].acc_no == acc_no) {
                        bank.accounts[i].balance += amount;
                        break;
                    }
                }
                break;
            case 3:
                printf("Enter account number: ");
                scanf("%d", &acc_no);
                printf("Enter amount to withdraw: ");
                scanf("%lf", &amount);
                for (i = 0; i < bank.num_accounts; i++) {
                    if (bank.accounts[i].acc_no == acc_no) {
                        if (bank.accounts[i].balance >= amount) {
                            bank.accounts[i].balance -= amount;
                        } else {
                            printf("Insufficient funds\n");
                        }
                        break;
                    }
                }
                break;
            case 4:
                printf("Enter account number: ");
                scanf("%d", &acc_no);
                for (i = 0; i < bank.num_accounts; i++) {
                    if (bank.accounts[i].acc_no == acc_no) {
                        printf("Balance: %.2lf\n", bank.accounts[i].balance);
                        break;
                    }
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}