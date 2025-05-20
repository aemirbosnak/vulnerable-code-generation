//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char account_number[20];
    double balance;
} account;

int main() {
    account accounts[100];
    int num_accounts = 0;

    while (1) {
        printf("1. Create account\n");
        printf("2. Deposit money\n");
        printf("3. Withdraw money\n");
        printf("4. Transfer money\n");
        printf("5. Print account balance\n");
        printf("6. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter name: ");
                scanf("%s", accounts[num_accounts].name);

                printf("Enter account number: ");
                scanf("%s", accounts[num_accounts].account_number);

                printf("Enter balance: ");
                scanf("%lf", &accounts[num_accounts].balance);

                num_accounts++;
                break;
            }
            case 2: {
                char account_number[20];
                printf("Enter account number: ");
                scanf("%s", account_number);

                int account_index = -1;
                for (int i = 0; i < num_accounts; i++) {
                    if (strcmp(accounts[i].account_number, account_number) == 0) {
                        account_index = i;
                        break;
                    }
                }

                if (account_index == -1) {
                    printf("Account not found!\n");
                } else {
                    double amount;
                    printf("Enter amount to deposit: ");
                    scanf("%lf", &amount);

                    accounts[account_index].balance += amount;
                    printf("Deposit successful!\n");
                }
                break;
            }
            case 3: {
                char account_number[20];
                printf("Enter account number: ");
                scanf("%s", account_number);

                int account_index = -1;
                for (int i = 0; i < num_accounts; i++) {
                    if (strcmp(accounts[i].account_number, account_number) == 0) {
                        account_index = i;
                        break;
                    }
                }

                if (account_index == -1) {
                    printf("Account not found!\n");
                } else {
                    double amount;
                    printf("Enter amount to withdraw: ");
                    scanf("%lf", &amount);

                    if (amount > accounts[account_index].balance) {
                        printf("Insufficient funds!\n");
                    } else {
                        accounts[account_index].balance -= amount;
                        printf("Withdrawal successful!\n");
                    }
                }
                break;
            }
            case 4: {
                char from_account_number[20];
                printf("Enter account number to transfer from: ");
                scanf("%s", from_account_number);

                int from_account_index = -1;
                for (int i = 0; i < num_accounts; i++) {
                    if (strcmp(accounts[i].account_number, from_account_number) == 0) {
                        from_account_index = i;
                        break;
                    }
                }

                if (from_account_index == -1) {
                    printf("Account not found!\n");
                } else {
                    char to_account_number[20];
                    printf("Enter account number to transfer to: ");
                    scanf("%s", to_account_number);

                    int to_account_index = -1;
                    for (int i = 0; i < num_accounts; i++) {
                        if (strcmp(accounts[i].account_number, to_account_number) == 0) {
                            to_account_index = i;
                            break;
                        }
                    }

                    if (to_account_index == -1) {
                        printf("Account not found!\n");
                    } else {
                        double amount;
                        printf("Enter amount to transfer: ");
                        scanf("%lf", &amount);

                        if (amount > accounts[from_account_index].balance) {
                            printf("Insufficient funds!\n");
                        } else {
                            accounts[from_account_index].balance -= amount;
                            accounts[to_account_index].balance += amount;
                            printf("Transfer successful!\n");
                        }
                    }
                }
                break;
            }
            case 5: {
                char account_number[20];
                printf("Enter account number: ");
                scanf("%s", account_number);

                int account_index = -1;
                for (int i = 0; i < num_accounts; i++) {
                    if (strcmp(accounts[i].account_number, account_number) == 0) {
                        account_index = i;
                        break;
                    }
                }

                if (account_index == -1) {
                    printf("Account not found!\n");
                } else {
                    printf("Account balance: %.2lf\n", accounts[account_index].balance);
                }
                break;
            }
            case 6: {
                exit(0);
            }
            default: {
                printf("Invalid choice!\n");
            }
        }
    }

    return 0;
}