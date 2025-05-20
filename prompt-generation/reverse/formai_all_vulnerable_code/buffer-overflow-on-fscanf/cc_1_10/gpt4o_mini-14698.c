//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int account_number;
    char name[MAX_NAME_LENGTH];
    float balance;
} Customer;

Customer customers[MAX_CUSTOMERS];
int customer_count = 0;

void addCustomer(int account_number, const char* name, float initial_balance) {
    if (customer_count >= MAX_CUSTOMERS) {
        printf("Error: Maximum customer limit reached.\n");
        return;
    }
    customers[customer_count].account_number = account_number;
    strncpy(customers[customer_count].name, name, MAX_NAME_LENGTH);
    customers[customer_count].balance = initial_balance;
    customer_count++;
    printf("Customer %s added with account number %d.\n", name, account_number);
}

void displayCustomer(int account_number) {
    for (int i = 0; i < customer_count; i++) {
        if (customers[i].account_number == account_number) {
            printf("Account Number: %d\n", customers[i].account_number);
            printf("Name: %s\n", customers[i].name);
            printf("Balance: %.2f\n", customers[i].balance);
            return;
        }
    }
    printf("Error: Customer with account number %d not found.\n", account_number);
}

void deposit(int account_number, float amount) {
    for (int i = 0; i < customer_count; i++) {
        if (customers[i].account_number == account_number) {
            customers[i].balance += amount;
            printf("Deposited %.2f to account number %d. New balance: %.2f\n", amount, account_number, customers[i].balance);
            return;
        }
    }
    printf("Error: Customer with account number %d not found.\n", account_number);
}

void withdraw(int account_number, float amount) {
    for (int i = 0; i < customer_count; i++) {
        if (customers[i].account_number == account_number) {
            if (customers[i].balance < amount) {
                printf("Error: Insufficient funds in account number %d.\n", account_number);
            } else {
                customers[i].balance -= amount;
                printf("Withdrew %.2f from account number %d. New balance: %.2f\n", amount, account_number, customers[i].balance);
            }
            return;
        }
    }
    printf("Error: Customer with account number %d not found.\n", account_number);
}

void displayAllCustomers() {
    if (customer_count == 0) {
        printf("No customers to display.\n");
        return;
    }
    printf("List of Customers:\n");
    for (int i = 0; i < customer_count; i++) {
        printf("Account Number: %d, Name: %s, Balance: %.2f\n",
            customers[i].account_number,
            customers[i].name,
            customers[i].balance);
    }
}

void saveRecordsToFile(const char* filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open file for writing.\n");
        return;
    }
    for (int i = 0; i < customer_count; i++) {
        fprintf(file, "%d,%s,%.2f\n", customers[i].account_number, customers[i].name, customers[i].balance);
    }
    fclose(file);
    printf("Records saved to %s\n", filename);
}

void loadRecordsFromFile(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file for reading.\n");
        return;
    }
    while (fscanf(file, "%d,%49[^,],%f\n", &customers[customer_count].account_number,
                  customers[customer_count].name, &customers[customer_count].balance) == 3) {
        customer_count++;
    }
    fclose(file);
    printf("Records loaded from %s\n", filename);
}

int main() {
    int choice;
    int account_number;
    float amount;
    char name[MAX_NAME_LENGTH];
    const char* filename = "bank_records.txt";

    loadRecordsFromFile(filename);

    while (1) {
        printf("\nBanking System Menu:\n");
        printf("1. Add Customer\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Display Customer\n");
        printf("5. Display All Customers\n");
        printf("6. Save Records\n");
        printf("7. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                printf("Enter name: ");
                scanf(" %[^\n]s", name);
                printf("Enter initial deposit: ");
                scanf("%f", &amount);
                addCustomer(account_number, name, amount);
                break;
            case 2:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                printf("Enter deposit amount: ");
                scanf("%f", &amount);
                deposit(account_number, amount);
                break;
            case 3:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                printf("Enter withdrawal amount: ");
                scanf("%f", &amount);
                withdraw(account_number, amount);
                break;
            case 4:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                displayCustomer(account_number);
                break;
            case 5:
                displayAllCustomers();
                break;
            case 6:
                saveRecordsToFile(filename);
                break;
            case 7:
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}