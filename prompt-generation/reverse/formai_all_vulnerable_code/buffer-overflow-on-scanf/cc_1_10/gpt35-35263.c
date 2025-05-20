//FormAI DATASET v1.0 Category: Banking Record System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 1000

// Structures
typedef struct {
    int account_number;
    char name[30];
    float balance;
} Customer;

// Function Prototypes
void display_menu();
void create_account(Customer customers[], int *num_customers);
void display_customer(Customer customer);
void display_accounts(Customer customers[], int num_customers);
void deposit(Customer customers[], int num_customers);
void withdraw(Customer customers[], int num_customers);
void save_customers(Customer customers[], int num_customers);
void load_customers(Customer customers[], int *num_customers);

// Global Variables
char filename[] = "customers.dat";

int main() {
    Customer customers[MAX_CUSTOMERS];
    int num_customers = 0;
    int choice;

    load_customers(customers, &num_customers);

    do {
        display_menu();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_account(customers, &num_customers);
                break;
            case 2:
                display_accounts(customers, num_customers);
                break;
            case 3:
                deposit(customers, num_customers);
                break;
            case 4:
                withdraw(customers, num_customers);
                break;
            case 5:
                save_customers(customers, num_customers);
                break;
            case 6:
                // Quit Program
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

// Function Definitions
void display_menu() {
    printf("\nBanking Record System\n");
    printf("1. Create Account\n");
    printf("2. Display Accounts\n");
    printf("3. Deposit\n");
    printf("4. Withdraw\n");
    printf("5. Save Accounts\n");
    printf("6. Quit\n");
}

void create_account(Customer customers[], int *num_customers) {
    if (*num_customers >= MAX_CUSTOMERS) {
        printf("Cannot create account. Maximum number of accounts reached.\n");
        return;
    }

    Customer customer;

    printf("Enter Account Number: ");
    scanf("%d", &customer.account_number);

    printf("Enter Name: ");
    scanf("%s", customer.name);

    printf("Enter Initial Balance: ");
    scanf("%f", &customer.balance);

    customers[*num_customers] = customer;

    printf("Account successfully created.\n");

    (*num_customers)++;
}

void display_customer(Customer customer) {
    printf("Account Number: %d\n", customer.account_number);
    printf("Name: %s\n", customer.name);
    printf("Balance: %.2f\n", customer.balance);
}

void display_accounts(Customer customers[], int num_customers) {
    if (num_customers == 0) {
        printf("No accounts to display.\n");
        return;
    }

    printf("Account Information:\n");

    for (int i = 0; i < num_customers; i++) {
        display_customer(customers[i]);
        printf("\n");
    }
}

void deposit(Customer customers[], int num_customers) {
    int account_number;
    float deposit_amount;
    int found = 0;

    printf("Enter Account Number: ");
    scanf("%d", &account_number);

    for (int i = 0; i < num_customers; i++) {
        if (customers[i].account_number == account_number) {
            found = 1;

            printf("Enter Deposit Amount: ");
            scanf("%f", &deposit_amount);

            customers[i].balance += deposit_amount;

            printf("Deposit successful.\n");

            break;
        }
    }

    if (!found) {
        printf("Account not found.\n");
    }
}

void withdraw(Customer customers[], int num_customers) {
    int account_number;
    float withdraw_amount;
    int found = 0;

    printf("Enter Account Number: ");
    scanf("%d", &account_number);

    for (int i = 0; i < num_customers; i++) {
        if (customers[i].account_number == account_number) {
            found = 1;

            printf("Enter Withdrawal Amount: ");
            scanf("%f", &withdraw_amount);

            if (customers[i].balance >= withdraw_amount) {
                customers[i].balance -= withdraw_amount;
                printf("Withdrawal successful.\n");
            } else {
                printf("Insufficient funds.\n");
            }

            break;
        }
    }

    if (!found) {
        printf("Account not found.\n");
    }
}

void save_customers(Customer customers[], int num_customers) {
    FILE *file = fopen(filename, "wb");

    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fwrite(customers, sizeof(Customer), num_customers, file);

    fclose(file);

    printf("Accounts successfully saved.\n");
}

void load_customers(Customer customers[], int *num_customers) {
    FILE *file = fopen(filename, "rb");

    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fread(customers, sizeof(Customer), MAX_CUSTOMERS, file);

    *num_customers = 0;
    for (int i = 0; i < MAX_CUSTOMERS; i++) {
        if (customers[i].account_number != 0) {
            (*num_customers)++;
        }
    }

    fclose(file);

    printf("Accounts successfully loaded.\n");
}