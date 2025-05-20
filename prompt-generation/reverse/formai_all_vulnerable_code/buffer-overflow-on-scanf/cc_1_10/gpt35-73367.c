//FormAI DATASET v1.0 Category: Banking Record System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char account_no[50];
    char name[50];
    float balance;
} Account;

void openAccount(Account accounts[], int *n) {
    printf("Enter account number: ");
    scanf("%s", accounts[*n].account_no);
    printf("Enter name: ");
    scanf(" %[^\n]s", accounts[*n].name); // allow whitespace in name input
    printf("Enter balance: ");
    scanf("%f", &accounts[*n].balance);
    (*n)++; 
}

void displayAccount(Account accounts[], int n) {
    printf("Account number: %s\n", accounts[n].account_no);
    printf("Name: %s\n", accounts[n].name);
    printf("Balance: %.2f\n", accounts[n].balance);
}

void deposit(Account accounts[], int n) {
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    accounts[n].balance += amount;
}

void withdraw(Account accounts[], int n) {
    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount > accounts[n].balance) {
        printf("Insufficient balance!\n");
    } else {
        accounts[n].balance -= amount;
    }
}

void displayAllAccounts(Account accounts[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d.\n", i+1);
        displayAccount(accounts, i);
        printf("\n");
    }
}

int main() {
    Account accounts[100];
    int n = 0; // number of existing accounts
    while (1) {
        int choice;
        printf("1. Open Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Display Account\n");
        printf("5. Display All Account\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice) {
            case 1:
                openAccount(accounts, &n);
                break;
            case 2:
                if (n == 0) {
                    printf("No account found. Please open account first.\n\n");
                    break;
                }
                int d_index;
                printf("Enter account number to deposit: ");
                char d_account_no[50];
                scanf("%s", d_account_no);
                for (int i = 0; i < n; i++) {
                    if (strcmp(accounts[i].account_no, d_account_no) == 0) {
                        d_index = i;
                        deposit(accounts, d_index);
                        printf("Deposit successful.\n\n");
                        break;
                    } else if (i == n-1) {
                        printf("Invalid account number.\n\n");
                    }
                }
                break;
            case 3:
                if (n == 0) {
                    printf("No account found. Please open account first.\n\n");
                    break;
                }
                int w_index;
                printf("Enter account number to withdraw: ");
                char w_account_no[50];
                scanf("%s", w_account_no);
                for (int i = 0; i < n; i++) {
                    if (strcmp(accounts[i].account_no, w_account_no) == 0) {
                        w_index = i;
                        withdraw(accounts, w_index);
                        printf("Withdrawal successful.\n\n");
                        break;
                    } else if (i == n-1) {
                        printf("Invalid account number.\n\n");
                    }
                }
                break;
            case 4:
                if (n == 0) {
                    printf("No account found. Please open account first.\n\n");
                    break;
                }
                int index;
                printf("Enter account number to display: ");
                char account_no[50];
                scanf("%s", account_no);
                for (int i = 0; i < n; i++) {
                    if (strcmp(accounts[i].account_no, account_no) == 0) {
                        index = i;
                        displayAccount(accounts, index);
                        printf("\n");
                        break;
                    } else if (i == n-1) {
                        printf("Invalid account number.\n\n");
                    }
                }
                break;
            case 5:
                if (n == 0) {
                    printf("No account found. Please open account first.\n\n");
                    break;
                }
                displayAllAccounts(accounts, n);
                break;
            case 6:
                printf("Thank you for using our service.\n");
                exit(0);
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }
    }
    return 0;
}