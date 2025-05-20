//Code Llama-13B DATASET v1.0 Category: Personal Finance Planner ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Finance {
    char name[20];
    int balance;
    int goal;
};

void print_menu() {
    printf("---------------------------------------\n");
    printf("Finance Planner\n");
    printf("1. Create a new account\n");
    printf("2. View all accounts\n");
    printf("3. Deposit money\n");
    printf("4. Withdraw money\n");
    printf("5. Check balance\n");
    printf("6. Exit\n");
    printf("---------------------------------------\n");
}

int main() {
    struct Finance account[10];
    int n, ch, balance;

    printf("Enter the number of accounts: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter the name of account %d: ", i+1);
        scanf("%s", &account[i].name);
        printf("Enter the balance of account %d: ", i+1);
        scanf("%d", &account[i].balance);
        printf("Enter the goal of account %d: ", i+1);
        scanf("%d", &account[i].goal);
    }

    while (1) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the name of the new account: ");
                scanf("%s", &account[n].name);
                printf("Enter the balance of the new account: ");
                scanf("%d", &account[n].balance);
                printf("Enter the goal of the new account: ");
                scanf("%d", &account[n].goal);
                n++;
                break;
            case 2:
                for (int i = 0; i < n; i++) {
                    printf("%s: %d\n", account[i].name, account[i].balance);
                }
                break;
            case 3:
                printf("Enter the account number: ");
                scanf("%d", &n);
                printf("Enter the amount to deposit: ");
                scanf("%d", &balance);
                account[n].balance += balance;
                break;
            case 4:
                printf("Enter the account number: ");
                scanf("%d", &n);
                printf("Enter the amount to withdraw: ");
                scanf("%d", &balance);
                account[n].balance -= balance;
                break;
            case 5:
                printf("Enter the account number: ");
                scanf("%d", &n);
                printf("Balance: %d\n", account[n].balance);
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid input\n");
                break;
        }
    }

    return 0;
}