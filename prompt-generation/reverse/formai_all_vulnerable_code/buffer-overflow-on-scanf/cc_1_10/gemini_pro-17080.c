//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

typedef struct customer {
    int account_number;
    char name[100];
    double balance;
} customer;

customer customers[100];
int num_customers = 0;

void create_account() {
    printf("Enter account number: ");
    scanf("%d", &customers[num_customers].account_number);
    printf("Enter name: ");
    scanf("%s", customers[num_customers].name);
    printf("Enter balance: ");
    scanf("%lf", &customers[num_customers].balance);
    num_customers++;
}

void deposit() {
    int account_number;
    double amount;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    printf("Enter amount to deposit: ");
    scanf("%lf", &amount);
    for (int i = 0; i < num_customers; i++) {
        if (customers[i].account_number == account_number) {
            customers[i].balance += amount;
            printf("Deposit successful!\n");
            return;
        }
    }
    printf("Account not found!\n");
}

void withdraw() {
    int account_number;
    double amount;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    printf("Enter amount to withdraw: ");
    scanf("%lf", &amount);
    for (int i = 0; i < num_customers; i++) {
        if (customers[i].account_number == account_number) {
            if (customers[i].balance >= amount) {
                customers[i].balance -= amount;
                printf("Withdrawal successful!\n");
                return;
            } else {
                printf("Insufficient funds!\n");
                return;
            }
        }
    }
    printf("Account not found!\n");
}

void transfer() {
    int account_number1, account_number2;
    double amount;
    printf("Enter account number to transfer from: ");
    scanf("%d", &account_number1);
    printf("Enter account number to transfer to: ");
    scanf("%d", &account_number2);
    printf("Enter amount to transfer: ");
    scanf("%lf", &amount);
    for (int i = 0; i < num_customers; i++) {
        if (customers[i].account_number == account_number1) {
            if (customers[i].balance >= amount) {
                customers[i].balance -= amount;
                for (int j = 0; j < num_customers; j++) {
                    if (customers[j].account_number == account_number2) {
                        customers[j].balance += amount;
                        printf("Transfer successful!\n");
                        return;
                    }
                }
            } else {
                printf("Insufficient funds!\n");
                return;
            }
        }
    }
    printf("Account not found!\n");
}

void print_statement() {
    int account_number;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    for (int i = 0; i < num_customers; i++) {
        if (customers[i].account_number == account_number) {
            printf("Account number: %d\n", customers[i].account_number);
            printf("Name: %s\n", customers[i].name);
            printf("Balance: %lf\n", customers[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

int main() {
    int choice;
    do {
        printf("1. Create account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Transfer\n");
        printf("5. Print statement\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create_account();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                transfer();
                break;
            case 5:
                print_statement();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);
    return 0;
}