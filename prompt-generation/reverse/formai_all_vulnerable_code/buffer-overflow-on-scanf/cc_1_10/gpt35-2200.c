//FormAI DATASET v1.0 Category: Banking Record System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct customer {
    char name[50];
    int account_no;
    float balance;
};

typedef struct customer Customer;

void display(Customer c) {
    printf("\nName        : %s\n", c.name);
    printf("Account No. : %d\n", c.account_no);
    printf("Balance     : %.2f\n", c.balance);
}

void deposit(Customer *c, float amount) {
    c->balance += amount;
}

void withdraw(Customer *c, float amount) {
    if (c->balance < amount) {
        printf("\nInsufficient Funds!\n");
    } else {
        c->balance -= amount;
    }
}

int main() {
    int choice, i, n;
    float amount;
    Customer c[50];

    printf("Enter number of customers: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter details of customer %d\n", i + 1);
        printf("Name        : ");
        scanf("%s", c[i].name);
        printf("Account No. : ");
        scanf("%d", &c[i].account_no);
        printf("Balance     : ");
        scanf("%f", &c[i].balance);
    }

    do {
        printf("\nChoose an option: \n1. Display details of a customer.");
        printf("\n2. Deposit money.\n3. Withdraw money.\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter account number: ");
                int acc_no;
                scanf("%d", &acc_no);
                for (i = 0; i < n; i++) {
                    if (c[i].account_no == acc_no) {
                        display(c[i]);
                        break;
                    }
                }
                if (i == n) {
                    printf("\nCustomer not found!\n");
                }
                break;

            case 2:
                printf("\nEnter account number: ");
                scanf("%d", &acc_no);
                for (i = 0; i < n; i++) {
                    if (c[i].account_no == acc_no) {
                        printf("\nEnter amount to be deposited: ");
                        scanf("%f", &amount);
                        deposit(&c[i], amount);
                        printf("\nNew balance: %.2f\n", c[i].balance);
                        break;
                    }
                }
                if (i == n) {
                    printf("\nCustomer not found!\n");
                }
                break;

            case 3:
                printf("\nEnter account number: ");
                scanf("%d", &acc_no);
                for (i = 0; i < n; i++) {
                    if (c[i].account_no == acc_no) {
                        printf("\nEnter amount to be withdrawn: ");
                        scanf("%f", &amount);
                        withdraw(&c[i], amount);
                        printf("\nNew balance: %.2f\n", c[i].balance);
                        break;
                    }
                }
                if (i == n) {
                    printf("\nCustomer not found!\n");
                }
                break;

            case 4:
                printf("\nThank you for using our Banking Record System!\n");
                break;

            default:
                printf("\nInvalid choice!\n");
                break;
        }
    } while (choice != 4);

    return 0;
}