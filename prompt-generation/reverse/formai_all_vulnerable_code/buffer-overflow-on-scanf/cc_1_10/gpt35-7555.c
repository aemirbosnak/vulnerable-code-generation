//FormAI DATASET v1.0 Category: Banking Record System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct customer {
    int account_num;
    char name[30];
    double balance;
};

void add_customer(struct customer* customers, int* total_customers);
void display_customers(struct customer* customers, int total_customers);
void search_customer(struct customer* customers, int total_customers);
void deposit(struct customer* customers, int total_customers);
void withdraw(struct customer* customers, int total_customers);
void delete_customer(struct customer* customers, int* total_customers);

int main() {
    // Declare variables
    int choice, total_customers = 0;
    struct customer* customers = malloc(sizeof(struct customer));

    // Main menu loop
    while (1) {
        printf("\nWelcome to the Banking Record System!\n");
        printf("1. Add a customer\n");
        printf("2. Display all customers\n");
        printf("3. Search for a customer\n");
        printf("4. Deposit money\n");
        printf("5. Withdraw money\n");
        printf("6. Delete a customer\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Switch statement for user choice
        switch (choice) {
            case 1:
                add_customer(customers, &total_customers);
                break;
            case 2:
                display_customers(customers, total_customers);
                break;
            case 3:
                search_customer(customers, total_customers);
                break;
            case 4:
                deposit(customers, total_customers);
                break;
            case 5:
                withdraw(customers, total_customers);
                break;
            case 6:
                delete_customer(customers, &total_customers);
                break;
            case 7:
                printf("\nExiting program...");
                free(customers);
                return 0;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
}

void add_customer(struct customer* customers, int* total_customers) {
    // Prompt user for customer information
    printf("\nEnter account number: ");
    scanf("%d", &customers[*total_customers].account_num);
    printf("Enter customer name: ");
    scanf("%s", customers[*total_customers].name);
    printf("Enter starting balance: ");
    scanf("%lf", &customers[*total_customers].balance);

    // Increase total customers count
    (*total_customers)++;

    // Reallocate memory to fit new customer if necessary
    customers = realloc(customers, (*total_customers + 1) * sizeof(struct customer));

    // Confirm customer added
    printf("\nCustomer added successfully!\n");
}

void display_customers(struct customer* customers, int total_customers) {
    // Check if any customers exist
    if (total_customers == 0) {
        printf("\nNo customers found.\n");
        return;
    }

    // Print table header
    printf("\n%-15s %-30s %-15s\n", "Account Num", "Customer Name", "Balance");

    // Loop through each customer and print their information
    for (int i = 0; i < total_customers; i++) {
        printf("%-15d %-30s $%-14.2f\n", customers[i].account_num, customers[i].name, customers[i].balance);
    }
}

void search_customer(struct customer* customers, int total_customers) {
    // Check if any customers exist
    if (total_customers == 0) {
        printf("\nNo customers found.\n");
        return;
    }

    // Prompt user for search query
    char query[30];
    printf("\nEnter customer name or account number: ");
    scanf("%s", query);

    // Loop through each customer and check if their name or account number matches the search query
    for (int i = 0; i < total_customers; i++) {
        if (strcmp(customers[i].name, query) == 0 || customers[i].account_num == atoi(query)) {
            printf("\nCustomer found!\n");
            printf("Account Number: %d\n", customers[i].account_num);
            printf("Name: %s\n", customers[i].name);
            printf("Balance: $%.2lf\n", customers[i].balance);
            return;
        }
    }

    // If no matching customers found, display error message
    printf("\nNo customers found matching \"%s\".\n", query);
}

void deposit(struct customer* customers, int total_customers) {
    // Check if any customers exist
    if (total_customers == 0) {
        printf("\nNo customers found.\n");
        return;
    }

    // Prompt user for account number and amount to deposit
    int account_num;
    double deposit_amount;
    printf("\nEnter account number: ");
    scanf("%d", &account_num);

    // Find customer with matching account number
    for (int i = 0; i < total_customers; i++) {
        if (customers[i].account_num == account_num) {
            printf("Enter amount to deposit: ");
            scanf("%lf", &deposit_amount);

            // Update customer balance
            customers[i].balance += deposit_amount;
            printf("\nDeposit successful!\n");
            printf("New balance for %s: $%.2lf\n", customers[i].name, customers[i].balance);
            return;
        }
    }

    // If no matching customer found, display error message
    printf("\nNo customer found with account number %d.\n", account_num);
}

void withdraw(struct customer* customers, int total_customers) {
    // Check if any customers exist
    if (total_customers == 0) {
        printf("\nNo customers found.\n");
        return;
    }

    // Prompt user for account number and amount to withdraw
    int account_num;
    double withdraw_amount;
    printf("\nEnter account number: ");
    scanf("%d", &account_num);

    // Find customer with matching account number
    for (int i = 0; i < total_customers; i++) {
        if (customers[i].account_num == account_num) {
            printf("Enter amount to withdraw: ");
            scanf("%lf", &withdraw_amount);

            // Check if requested withdrawal amount is greater than customer balance
            if (withdraw_amount > customers[i].balance) {
                printf("Withdrawal amount exceeds balance! Transaction canceled.\n");
                return;
            }

            // Update customer balance
            customers[i].balance -= withdraw_amount;
            printf("\nWithdrawal successful!\n");
            printf("New balance for %s: $%.2lf\n", customers[i].name, customers[i].balance);
            return;
        }
    }

    // If no matching customer found, display error message
    printf("\nNo customer found with account number %d.\n", account_num);
}

void delete_customer(struct customer* customers, int* total_customers) {
    // Check if any customers exist
    if (*total_customers == 0) {
        printf("\nNo customers found.\n");
        return;
    }

    // Prompt user for account number to delete
    int account_num;
    printf("\nEnter account number to delete: ");
    scanf("%d", &account_num);

    // Find customer with matching account number
    for (int i = 0; i < *total_customers; i++) {
        if (customers[i].account_num == account_num) {
            // Move all customers after this one up one index and reduce total customer count
            for (int j = i; j < *total_customers - 1; j++) {
                customers[j] = customers[j + 1];
            }
            (*total_customers)--;

            // Reallocate memory to fit new customer list size
            customers = realloc(customers, (*total_customers + 1) * sizeof(struct customer));

            printf("\nCustomer account %d deleted successfully!\n", account_num);
            return;
        }
    }

    // If no matching customer found, display error message
    printf("\nNo customer found with account number %d.\n", account_num);
}