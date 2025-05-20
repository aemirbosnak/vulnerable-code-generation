//FormAI DATASET v1.0 Category: Banking Record System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_CUSTOMERS 1000
#define MAX_NAME_LEN 50

// Structs
typedef struct {
    char name[MAX_NAME_LEN];
    int account_number;
    float balance;
    int is_active;
} Customer;

typedef struct {
    Customer customers[MAX_CUSTOMERS];
    int num_customers;
} Bank;

// Function prototypes
void add_customer(Bank *bank);
void close_account(Bank *bank, int account_number);
void deposit_money(Bank *bank, int account_number, float amount);
void withdraw_money(Bank *bank, int account_number, float amount);
void display_account_info(Bank *bank, int account_number);
void display_all_accounts(Bank *bank);

// Main function
int main() {
    // Initialize bank
    Bank bank;
    bank.num_customers = 0;

    // Menu loop
    int choice;
    do {
        printf("\nBank Record System\n");
        printf("===================\n");
        printf("1. Add Customer\n");
        printf("2. Close Account\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Display Account Information\n");
        printf("6. Display All Accounts\n");
        printf("7. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume trailing newline

        switch (choice) {
            case 1:
                add_customer(&bank);
                break;
            case 2:
                if (bank.num_customers == 0) {
                    printf("No customers in the bank!\n");
                    break;
                }
                printf("Enter account number to close: ");
                int close_acc_num;
                scanf("%d", &close_acc_num);
                getchar(); // consume trailing newline
                close_account(&bank, close_acc_num);
                break;
            case 3:
                if (bank.num_customers == 0) {
                    printf("No customers in the bank!\n");
                    break;
                }
                printf("Enter account number to deposit: ");
                int dep_acc_num;
                scanf("%d", &dep_acc_num);
                getchar(); // consume trailing newline
                printf("Enter amount to deposit: ");
                float dep_amount;
                scanf("%f", &dep_amount);
                getchar(); // consume trailing newline
                deposit_money(&bank, dep_acc_num, dep_amount);
                break;
            case 4:
                if (bank.num_customers == 0) {
                    printf("No customers in the bank!\n");
                    break;
                }
                printf("Enter account number to withdraw: ");
                int with_acc_num;
                scanf("%d", &with_acc_num);
                getchar(); // consume trailing newline
                printf("Enter amount to withdraw: ");
                float with_amount;
                scanf("%f", &with_amount);
                getchar(); // consume trailing newline
                withdraw_money(&bank, with_acc_num, with_amount);
                break;
            case 5:
                if (bank.num_customers == 0) {
                    printf("No customers in the bank!\n");
                    break;
                }
                printf("Enter account number to display: ");
                int disp_acc_num;
                scanf("%d", &disp_acc_num);
                getchar(); // consume trailing newline
                display_account_info(&bank, disp_acc_num);
                break;
            case 6:
                if (bank.num_customers == 0) {
                    printf("No customers in the bank!\n");
                    break;
                }
                display_all_accounts(&bank);
                break;
            case 7:
                printf("Quitting...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 7);

    return 0;
}

// Add a new customer to the bank
void add_customer(Bank *bank) {
    // Check if bank is full
    if (bank->num_customers == MAX_CUSTOMERS) {
        printf("Maximum number of customers reached!\n");
        return;
    }

    // Get customer info
    Customer new_customer;
    printf("Enter customer name: ");
    fgets(new_customer.name, MAX_NAME_LEN, stdin);
    new_customer.name[strcspn(new_customer.name, "\n")] = '\0'; // remove newline
    printf("Enter account number: ");
    scanf("%d", &new_customer.account_number);
    getchar(); // consume trailing newline
    printf("Enter initial balance: ");
    scanf("%f", &new_customer.balance);
    getchar(); // consume trailing newline
    new_customer.is_active = 1;

    // Add customer to bank
    bank->customers[bank->num_customers] = new_customer;
    bank->num_customers++;
}

// Close an existing customer account
void close_account(Bank *bank, int account_number) {
    int found_customer = 0;
    for (int i = 0; i < bank->num_customers; i++) {
        if (bank->customers[i].account_number == account_number) {
            bank->customers[i].is_active = 0;
            printf("Account closed successfully!\n");
            found_customer = 1;
            break;
        }
    }
    if (!found_customer) {
        printf("Account not found!\n");
    }
}

// Deposit money into an existing customer account
void deposit_money(Bank *bank, int account_number, float amount) {
    int found_customer = 0;
    for (int i = 0; i < bank->num_customers; i++) {
        if (bank->customers[i].account_number == account_number) {
            bank->customers[i].balance += amount;
            printf("Deposit successful! New balance: %.2f\n", bank->customers[i].balance);
            found_customer = 1;
            break;
        }
    }
    if (!found_customer) {
        printf("Account not found!\n");
    }
}

// Withdraw money from an existing customer account
void withdraw_money(Bank *bank, int account_number, float amount) {
    int found_customer = 0;
    for (int i = 0; i < bank->num_customers; i++) {
        if (bank->customers[i].account_number == account_number) {
            if (bank->customers[i].is_active == 0) {
                printf("Account is closed!\n");
                found_customer = 1;
                break;
            }
            if (bank->customers[i].balance < amount) {
                printf("Insufficient balance!\n");
                found_customer = 1;
                break;
            }
            bank->customers[i].balance -= amount;
            printf("Withdrawal successful! New balance: %.2f\n", bank->customers[i].balance);
            found_customer = 1;
            break;
        }
    }
    if (!found_customer) {
        printf("Account not found!\n");
    }
}

// Display account information for an existing customer account
void display_account_info(Bank *bank, int account_number) {
    int found_customer = 0;
    for (int i = 0; i < bank->num_customers; i++) {
        if (bank->customers[i].account_number == account_number) {
            printf("Account Information\n");
            printf("===================\n");
            printf("Name: %s\n", bank->customers[i].name);
            printf("Account Number: %d\n", bank->customers[i].account_number);
            printf("Balance: %.2f\n", bank->customers[i].balance);
            printf("Status: %s\n", bank->customers[i].is_active == 1 ? "Active" : "Closed");
            found_customer = 1;
            break;
        }
    }
    if (!found_customer) {
        printf("Account not found!\n");
    }
}

// Display information for all existing customer accounts
void display_all_accounts(Bank *bank) {
    printf("All Accounts\n");
    printf("============\n");
    for (int i = 0; i < bank->num_customers; i++) {
        printf("[%d] %s (%d): %.2f (%s)\n", 
                i+1,
                bank->customers[i].name, 
                bank->customers[i].account_number, 
                bank->customers[i].balance, 
                bank->customers[i].is_active == 1 ? "Active" : "Closed");
    }
}