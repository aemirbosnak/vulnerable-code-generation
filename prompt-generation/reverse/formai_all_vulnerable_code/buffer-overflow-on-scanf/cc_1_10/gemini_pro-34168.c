//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct customer {
    char name[50];
    char address[100];
    int account_number;
    double balance;
} customer;

void create_account(customer *customers, int *num_customers) {
    printf("Enter customer name: ");
    scanf("%s", customers[*num_customers].name);

    printf("Enter customer address: ");
    scanf(" %[^\n]s", customers[*num_customers].address);

    printf("Enter account number: ");
    scanf("%d", &customers[*num_customers].account_number);

    printf("Enter initial balance: ");
    scanf("%lf", &customers[*num_customers].balance);

    (*num_customers)++;
}

void deposit(customer *customers, int num_customers) {
    int account_number;
    double amount;

    printf("Enter account number: ");
    scanf("%d", &account_number);

    for (int i = 0; i < num_customers; i++) {
        if (customers[i].account_number == account_number) {
            printf("Enter amount to deposit: ");
            scanf("%lf", &amount);

            customers[i].balance += amount;

            printf("Deposit successful!\n");
            return;
        }
    }

    printf("Account not found!\n");
}

void withdraw(customer *customers, int num_customers) {
    int account_number;
    double amount;

    printf("Enter account number: ");
    scanf("%d", &account_number);

    for (int i = 0; i < num_customers; i++) {
        if (customers[i].account_number == account_number) {
            printf("Enter amount to withdraw: ");
            scanf("%lf", &amount);

            if (amount > customers[i].balance) {
                printf("Insufficient funds!\n");
                return;
            } else {
                customers[i].balance -= amount;

                printf("Withdrawal successful!\n");
                return;
            }
        }
    }

    printf("Account not found!\n");
}

void transfer(customer *customers, int num_customers) {
    int from_account_number, to_account_number;
    double amount;

    printf("Enter account number to transfer from: ");
    scanf("%d", &from_account_number);

    printf("Enter account number to transfer to: ");
    scanf("%d", &to_account_number);

    for (int i = 0; i < num_customers; i++) {
        if (customers[i].account_number == from_account_number) {
            for (int j = 0; j < num_customers; j++) {
                if (customers[j].account_number == to_account_number) {
                    printf("Enter amount to transfer: ");
                    scanf("%lf", &amount);

                    if (amount > customers[i].balance) {
                        printf("Insufficient funds!\n");
                        return;
                    } else {
                        customers[i].balance -= amount;
                        customers[j].balance += amount;

                        printf("Transfer successful!\n");
                        return;
                    }
                }
            }

            printf("To account not found!\n");
            return;
        }
    }

    printf("From account not found!\n");
}

void print_customer_info(customer *customers, int num_customers) {
    int account_number;

    printf("Enter account number: ");
    scanf("%d", &account_number);

    for (int i = 0; i < num_customers; i++) {
        if (customers[i].account_number == account_number) {
            printf("Customer Name: %s\n", customers[i].name);
            printf("Customer Address: %s\n", customers[i].address);
            printf("Account Number: %d\n", customers[i].account_number);
            printf("Balance: %.2lf\n", customers[i].balance);

            return;
        }
    }

    printf("Account not found!\n");
}

void print_all_customers(customer *customers, int num_customers) {
    for (int i = 0; i < num_customers; i++) {
        printf("Customer Name: %s\n", customers[i].name);
        printf("Customer Address: %s\n", customers[i].address);
        printf("Account Number: %d\n", customers[i].account_number);
        printf("Balance: %.2lf\n\n", customers[i].balance);
    }
}

int main() {
    customer customers[100];
    int num_customers = 0;
    int choice;

    do {
        printf("\n1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Transfer\n");
        printf("5. Print Customer Info\n");
        printf("6. Print All Customers\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_account(customers, &num_customers);
                break;
            case 2:
                deposit(customers, num_customers);
                break;
            case 3:
                withdraw(customers, num_customers);
                break;
            case 4:
                transfer(customers, num_customers);
                break;
            case 5:
                print_customer_info(customers, num_customers);
                break;
            case 6:
                print_all_customers(customers, num_customers);
                break;
            case 7:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 7);

    return 0;
}